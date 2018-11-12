# coding=utf-8

import os
import jieba
from utils import is_chinese

resource_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), '../resources')

class Tokenizer:
    _is_init = False

    def __init__(self):
        self._jieba = jieba.Tokenizer()
        self._jieba.cache_file = "qqnews.jieba_wrapper.cache"

    def load(self, model_path=None):
        if self._is_init:
            return
        if not model_path:
            self._jieba.load_userdict(os.path.join(resource_path, "dict.txt"))
        else:
            self._jieba.load_userdict(os.path.join(model_path, "user_dict.txt"))
        self._is_init = True

    def tokenize(self, text, with_position=False):
        if not self._is_init:
            raise Exception('Tokenizer does not init.')
        if not with_position:
            return self._jieba.lcut(text)  # resulted token list
        else:
            return self._jieba.tokenize(text)  # triple data consisting of (token, start_pos, end_pos)


    def _add_user_dict(self, dict_path, pos):
        with open(dict_path, "r") as fr:
            for line in fr.readlines():
                word = line.decode("utf8").strip("\r\n").split("\t")[0]
                if self._contains_chinese(word):
                    self._jieba.add_word(word, tag=pos)

    def _delete_user_dict(self, dict_path):
        with open(dict_path, "r") as fr:
            for line in fr.readlines():
                word = line.decode("utf8").strip("\r\n").split("\t")[0]
                self._jieba.del_word(word)

    @staticmethod
    def _contains_chinese(s):
        for c in s:
            if is_chinese(c):
                return True
        return False

if __name__ == '__main__':
    tokenizer = Tokenizer()

    res = tokenizer.tokenize(u"据美国《侨报》报道，近日，美国各大高校纷纷迎来毕业典礼，又有一批中国留学生将迎来一次人生转折的抉择：回国就业还是留美打拼？走向社会还是留校深造？这些问题几乎是所有留学生在毕业季都要面临的困扰。")
    print(res)
    # res = segmentor.segment_pos(u"据美国《侨报》5月6日报道，近日，美国各大高校纷纷迎来毕业典礼，又有一批中国留学生将迎来一次人生转折的抉择：回国就业还是留美打拼？走向社会还是留校深造？这些问题几乎是所有留学生在毕业季都要面临的困扰。")
    # print ' '.join([str(word)+'/'+str(pos) for word, pos in res])