# coding=utf-8

import os
# import sys
# import json
# import time

resource_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), '../resources')


class Chunker:

    phrase_dict = {}

    def __init__(self, dict_file=None):
        if not dict_file:
            dict_file = os.path.join(resource_path, "ner_dict.txt")

        phrase_set = set([])
        with open(dict_file, 'r') as fin:
            for line in fin:
                items = line.strip().split('\t')
                phrase_set.add(items[0])

        self.phrase_dict["stock"] = phrase_set
        self.tri_tree = self.build_tri_tree()


    def build_tri_tree(self):
        """根据关键词表搭建tri树，方便快速查;
        """
        tri_tree = {}
        for ktype, keywords in self.phrase_dict.items():
            for key in keywords:
                root = tri_tree
                for ch in key:
                    if ch not in root:
                        root[ch] = {}
                    root = root[ch]
                root.setdefault(u"##", {})
                root[u"##"].setdefault(u"type", [])
                root[u"##"][u"type"].append(ktype)
        return tri_tree


    def extract_keywords(self, content, long=0):
        """抽取包含关键词；
        Args:
            content: 文本内容；
            tri_tree： 关键字构成的tri-tree；

        Returns:
            包含的关键词；
        """

        if len(content) == 0:
            return {}
        # 从tri-tree 过滤关键词；
        keywords = {}

        start = 0
        size = len(content)

        while start < size:
            root = self.tri_tree
            end = start
            while end < size and content[end] in root:
                if long == 0:
                    if u"##" in root:
                        k = content[start:end]
                        keywords[k] = root[u"##"][u"type"]

                root = root[content[end]]
                end += 1

            if end > start and (u"##" in root):
                k = content[start:end]
                keywords[k] = root[u"##"][u"type"]

            start += 1

        # out second format:
        type_keywords_dict = {}
        for k, v in keywords.items():
            for e in v:
                type_keywords_dict.setdefault(e, [])
                type_keywords_dict[e].append(k)
        return type_keywords_dict


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
    content = "大卫路易斯踢球吧超高智能进化机器人苏州金龙团他们团不过我们"
    # tri_tree = build_tri_tree(keywords_dict)
    print(content)
    res = chunker.extract_keywords(content)
    print(res)
    print("##### finnish now !")
