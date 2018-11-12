# coding=utf-8

import os
from .utils import load_dict

stopwords_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'resources', 'stopwords.txt')

_stopword_set = load_dict(stopwords_path)

def is_stopword(term):
    return (term in _stopword_set)

def filter_stopwords(tokens):
    return [t for t in tokens if not is_stopword(t)]