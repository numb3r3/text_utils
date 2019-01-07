# coding=utf-8

# import os
# import sys
# import argparse
# import logging
# import jieba

class SimHash(object):
    def __init__(self, tokens='', hashbits=128):
        """

        :param tokens:
        :param hashbits:
        """
        self.hashbits = hashbits
        self.hash = self.simhash(tokens)

    def __str__(self):
        """

        :return:
        """
        return str(self.hash)

    def simhash(self, tokens):
        """
        生成simhash值
        :param tokens:
        :return:
        """
        v = [0] * self.hashbits
        # 暂时不考虑权重问题。 把分出的词同等看待
        for t in [self._string_hash(x) for x in tokens]:
            for i in range(self.hashbits):
                bitmask = 1 << i
                if t & bitmask:
                    v[i] += 1
                else:
                    v[i] -= 1
        fingerprint = 0
        for i in range(self.hashbits):
            if v[i] >= 0:
                fingerprint += 1 << i
        return fingerprint

    def hamming_distance(self, other):
        x = (self.hash ^ other.hash) & ((1 << self.hashbits) - 1)
        total = 0
        while x:
            total += 1
            x &= x - 1
        return total

    def similarity(self, other):
        """
        计算两个标题的相似度。 这个计算稍微有点问题。
        :param other:
        :return:
        """
        a = float(self.hash)
        b = float(other.hash)
        if a > b:
            return b / a
        else:
            return a / b

    def _string_hash(self, source):
        """
        对词进行string 哈希
        :param source:
        :return:
        """
        if source == "":
            return 0
        else:
            x = ord(source[0]) << 7
            m = 1000003
            mask = 2 ** self.hashbits - 1
            for c in source:
                x = ((x * m) ^ ord(c)) & mask
            x ^= len(source)
            if x == -1:
                x = -2
            return x


# def main():
#     s1 = '白百何给范冰冰颁奖'
#     seg = [x for x in jieba.cut(s1)]
#     hash1 = SimHash(s1.split())
#     s2 = '范冰冰从白百何手里面拿奖'
#     hash2 = SimHash(s2.split())
#     s3 = 'nai nai ge xiong cao'
#     hash3 = SimHash(s3.split())

#     print "%s %s" % (hash1.hamming_distance(hash2), hash1.hamming_distance(hash3))


# if __name__ == "__main__":
#     main()