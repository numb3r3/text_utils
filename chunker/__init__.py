# coding=utf-8

import os

from trie import Trie

resource_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), '../resources')

class Chunker:
    def __init__(self, dict_file=None):
        if not dict_file:
            dict_file = os.path.join(resource_path, "ner_dict.txt")

        self.trie = Trie()

        with open(dict_file, 'r') as fin:
            for line in fin:
                k = line.strip().split('\t')[0]
                self.trie.insert(k, k)

    def extract_keywords(self, content):
        ret = self.trie.translate(content, with_not_found=False)
        return ret


if __name__ == '__main__':
    print("##### start now !")
    chunker = Chunker()
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
    res = chunker.extract_keywords(content)
    print(res)
    print("##### finnish now !")
