import os
import math
from operator import itemgetter
from tqdm import tqdm

from ..tokenizer import Tokenizer
from ..stop_words import is_stopword

resource_path = os.path.join(
    os.path.dirname(os.path.abspath(__file__)), '../resources')


class IDFLoader(object):
    _is_init = False

    def __init__(self, model_path=None, name=None):
        self.idf_freq = {}
        self.median_idf = 0.0
        self.name = name
        self._load(model_path=model_path, name=name)

    def _load(self, model_path=None, name=None):
        if self._is_init:
            return

        idf_filename = 'idf.txt'
        if name:
            idf_filename = '%s_idf.txt' % name

        if not model_path:
            model_path = resource_path

        idf_path = os.path.join(model_path, idf_filename)

        with open(idf_path, 'r') as f:
            for line in f:
                word, freq = line.strip().split(' ')
                self.idf_freq[word] = float(freq)
            self.median_idf = sorted(
                self.idf_freq.values())[len(self.idf_freq) // 2]

        self._is_init = True

    def get_idf(self):
        return self.idf_freq, self.median_idf

    @staticmethod
    def compute_idf(sentence_iters):
        d = {}
        total = 0
        for words in tqdm(sentence_iters):
            words = set(words)
            for w in words:
                d[w] = d.get(w, 0.0) + 1.0
            total += 1

        idf_freq = {k: math.log(v / total) * -1 for k, v in d.items()}
        return idf_freq

    @staticmethod
    def dumps(idf_freq, model_path=None, name=''):
        if model_path is None:
            model_path = resource_path
        idf_filename = 'idf.txt'
        if name:
            idf_filename = '%s_idf.txt' % name
        idf_path = os.path.join(model_path, idf_filename)
        with open(idf_path, 'w') as f:
            for w, v in idf_freq.items():
                f.write('%s %.5f\n' % (w, v))


class TFIDF():

    def __init__(self, model_path=None):
        self.tokenizer = Tokenizer(model_path=model_path)
        self.idf_loader = IDFLoader(model_path=model_path)
        self.idf_freq, self.median_idf = self.idf_loader.get_idf()

    def extract_tags(self, sentence, topK=20, with_weight=False):
        """
        Extract keywords from sentence using TF-IDF algorithm.
        Parameter:
            - topK: return how many top keywords. `None` for all possible words.
            - with_weight: if True, return a list of (word, weight);
                          if False, return a list of words.
        """
        words = self.tokenizer.tokenize(sentence)

        freq = {}
        for w in words:
            if len(w.strip()) < 2 or is_stopword(w.lower()):
                continue
            freq[w] = freq.get(w, 0.0) + 1.0

        total = sum(freq.values())
        for w in freq:
            freq[w] *= self.idf_freq.get(w, self.median_idf) / total

        if with_weight:
            tags = sorted(freq.items(), key=itemgetter(1), reverse=True)
        else:
            tags = sorted(freq, key=freq.__getitem__, reverse=True)

        if topK:
            return tags[:topK]
        else:
            return tags
