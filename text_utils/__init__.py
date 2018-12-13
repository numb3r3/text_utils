# coding=utf-8

"""
Text Pre-processing Utils
~~~~~~~~~~~~~~~~~~~~~~~

`text_utils` is an Python library for pre-processing text.
usage:

    >>> import text_utils
    >>>

:copyright: (c) 2018 by Feng Wang.
"""


from . import utils
from . import stopwords
from . import symbols
from . import trie
from .tokenizer import Tokenizer
from .tokenizer.qq_tokenizer import QQTokenizer
from .segmenter import SentenceSegmenter
from .ner import Entity, NameEntityRecognizer
from .chunker import Chunker


# Set default logging handler to avoid "No handler found" warnings.
import logging
from logging import NullHandler

logging.getLogger(__name__).addHandler(NullHandler())