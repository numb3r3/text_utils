# coding=utf-8

import sys

def is_chinese(uchar):
    if 0x4e00 <= ord(uchar) <= 0x9fff:
        return True
    else:
        return False


def is_number(uchar):
    if 0x0030 <= ord(uchar) <= 0x0039:
        return True
    else:
        return False


def is_alphabet(uchar):
    if (0x0041 <= ord(uchar) <= 0x005a) or (0x0061 <= ord(uchar) <= 0x007a):
        return True
    else:
        return False


def is_other(uchar):
    if not (is_chinese(uchar) or is_number(uchar) or is_alphabet(uchar)):
        return True
    else:
        return False

