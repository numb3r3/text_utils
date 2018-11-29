# coding=utf-8

import sys
import os


from itertools import groupby
from .symbols import punctuation


def remove_dumplicates(text):
    newtext = []
    for k, g in groupby(text):
        if k in punctuation:
            newtext.append(k)
        else:
            newtext.extend(g)
    return ''.join(newtext)


def filter_whitespace(tokens):
    filtered_tokens = tokens
    while ' ' in filtered_tokens:
        filtered_tokens.remove(' ')
    while '' in filtered_tokens:
        filtered_tokens.remove('')
    return filtered_tokens


def load_dict(file_path):
    words = set([])
    with open(file_path, 'r') as fin:
        for line in fin:
            if len(line.strip()) > 0:
                words.add(line.strip())
    return words


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

