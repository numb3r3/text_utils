# coding=utf-8

import sys
import os
import re
import time

from itertools import groupby
from .symbols import punctuation
from ftfy import fix_text


def clean_html(x):
    return re.sub(u'</?[a-z]+[0-9]?(\s[^>\u4e00-\u9fa5]+)?>?', '',
                  x.replace("&nbsp;", " "))

def fix_text(text):
    return fix_text(text)


def timeit(method):

    def timed(*args, **kw):
        ts = time.time()
        result = method(*args, **kw)
        te = time.time()
        if 'log_time' in kw:
            name = kw.get('log_name', method.__name__.upper())
            kw['log_time'][name] = int((te - ts) * 1000)
        else:
            print('%r  %2.2f ms' % (method.__name__, (te - ts) * 1000))
        return result

    return timed


def multiple_replace(dictobj, text):
    """ Replace in 'text' all occurences of any key in the given
    dictionary by its corresponding value.  Returns the new tring.
    """

    # Sort keys by length, longest first
    keys = sorted(dictobj.keys(), key=lambda a: len(a), reverse=True)

    # Create a regular expression  from the dictionary keys
    regex = re.compile("(%s)" % "|".join(map(re.escape, keys)))

    # For each match, look-up corresponding value in dictionary
    return regex.sub(lambda mo: dictobj[mo.string[mo.start():mo.end()]], text)


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
    with open(file_path, 'r', encoding='utf-8') as fin:
        for line in fin:
            if len(line.strip()) > 0:
                words.add(line.strip())
    return words

def is_chinese_word(word):
    cn_reg = '^[\u4e00-\u9fa5]+$'
    return re.search(cn_reg, word)

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

def is_puncutation(uchar):
    if uchar in punctuation:
        return True
    return False


def is_other(uchar):
    if not (is_chinese(uchar) or is_number(uchar) or is_alphabet(uchar)):
        return True
    else:
        return False
