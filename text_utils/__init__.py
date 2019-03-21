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

from .__version__ import __title__, __description__, __version__
from .__version__ import __author__, __author_email__, __copyright__

from .utils import *
from .stopwords import (is_stopword, filter_stopwords)
from . import symbols
from .trie import Trie
from .tokenizer import Tokenizer
from .segmenter import SentenceSegmenter
from .ner import (Entity, NameEntityRecognizer)
from .chunker import Chunker
from .vocab import Vocab
from .simhash import SimHash

# Set default logging handler to avoid "No handler found" warnings.
import logging
from logging import NullHandler

logging.getLogger(__name__).addHandler(NullHandler())
