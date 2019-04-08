# coding=utf-8


class Trie(object):

    def __init__(self):
        self.d = {}

    def insert(self, key, value):
        now = self.d
        for k in key:
            if not k in now:
                now[k] = {}
            now = now[k]
        now['value'] = value

    def find(self, text, start=0):
        now = self.d
        n = len(text)
        ret = None
        pos = start
        while pos < n:
            if text[pos] in now:
                now = now[text[pos]]
            else:
                return ret
            if 'value' in now:
                ret = (text[start:pos + 1], now['value'])
            pos += 1
        return ret

    def extract(self, text, with_position=False, with_not_found=True):
        n = len(text)
        pos = 0
        ret = []
        while pos < n:
            now = self.d
            if text[pos] in now:
                tmp = self.find(text, pos)
                if tmp:
                    _ret = tmp[1]
                    if with_position:
                        end = pos + len(tmp[0])
                        _ret = (tmp[1], pos, end)

                    ret.append(_ret)
                    pos += len(tmp[0])
                    continue
            if with_not_found:
                ret.append(text[pos])
            pos += 1
        return ret
