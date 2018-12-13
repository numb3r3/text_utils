# coding=utf-8

# import sign
from .sign import SPLIT_SIGN, PAIR_SIGN, SOFTEN_SPLIT_SIGN
from .context import Context
from .state import CONTEXT_STATE_MANAGER


class SentenceSegmenter(object):

    def __init__(self, split_signs=None, pair_signs=None, soften_split_signs=None, token_limits=None):
        self.split_signs = split_signs if split_signs else SPLIT_SIGN
        self.pair_signs = pair_signs if pair_signs else PAIR_SIGN
        self.soften_split_signs = soften_split_signs if soften_split_signs else SOFTEN_SPLIT_SIGN
        self.token_limits = token_limits


    def segment(self, text):
        if not text:
            return []

        context = Context(text, CONTEXT_STATE_MANAGER[
                          "CHAR_CHECK_CONTEXT_STATE"], self.split_signs, self.pair_signs, self.soften_split_signs, self.token_limits)
        context.execute()
        return [x.strip() for x in context.sentences]
