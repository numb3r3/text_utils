# coding=utf-8

import os
from . import Tokenizer
from .qqsegment.qqsegment import QQSegmenter

resource_path = os.path.join(
    os.path.dirname(os.path.abspath(__file__)), '../resources/qqseg_dict')


class QQTokenizer(Tokenizer):

    def __init__(self, model_path=None):
        self.dict_path = model_path or resource_path
        self._qq_seg = QQSegmenter()
        seg_mode = QQSegmenter.GetDefaultMode()
        self._load(seg_mode)

    def _load(self, seg_mode):
        self._qq_seg.Init(self.dict_path, seg_mode)

    def tokenize(self, text):
        tokens = list(self._qq_seg.Segment(text, 0, False, 0, False))
        return tokens
