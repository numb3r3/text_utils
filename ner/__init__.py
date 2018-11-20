# coding=utf-8

import os
import collections
from ..trie import Trie

resource_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), '../resources')


class Entity:
    def __init__(self, text, start=0, end=0, labels=['MISC']):
        self.text = text
        self.labels = labels
        self.start = start
        self.end = end

    def __str__(self):
        return ('(%s - %s [%d~%d])' % (self.text, '/'.join(self.labels), self.start, self.end))


class NameEntityRecognizer:
    def __init__(self, dict_file=None):
        self.trie = Trie()
        if not dict_file:
            dict_file = os.path.join(resource_path, "ner_dict.txt")

        self.ner_labels = collections.defaultdict(list)

        with open(dict_file, 'r') as fin:
            for line in fin:
                items = line.strip().split('\t')
                k = items[0]
                self.trie.insert(k, k)
                if len(items) == 2:
                    l = items[1]
                    self.ner_labels[k].append(l)

    def extract(self, text):
        n = len(text)
        pos = 0
        ret = []
        while pos < n:
            tmp = self.trie.find(text, pos)
            if tmp:
                k = tmp[0]
                t = tmp[1]
                labels = self.ner_labels[t]
                ent = Entity(text=t, start=pos, end=pos + len(t), labels=labels)
                ret.append(ent)
                pos += len(k)
                continue
            pos += 1
        return ret

if __name__ == '__main__':
    print("##### start now !")
    ner = NameEntityRecognizer(dict_file='resources/new_ner_dict.txt')
    # chunker.phrase_dict = {
    #     "stock1": set(["stock", "finance", "finance12", "fin"]),
    #     "stock2": set(["finance", "please"]),
    #     "stock3": set(["don"])
    # }
    # chunker.tri_tree = chunker.build_tri_tree()
    # print(chunker.tri_tree)
    content = "我来到北京清华大学大卫路易斯踢球吧大卫路易斯超高智能进化机器人小罗伯特唐尼苏州金龙团小罗伯特他们团不过我们邪神洛基"
    # tri_tree = build_tri_tree(keywords_dict)
    print(content)
    res = ner.extract(content)
    for ent in res:
        print(ent)
    print("##### finnish now !")
