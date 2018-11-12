# coding=utf-8

class Context(object):

    is_finished = False

    text = None
    state = None
    current_index = 0
    is_pair_sign_opened = False
    has_split_sign = False
    pair_sign = None
    back_pair_sign = None

    def __init__(self, text, state, split_signs, pair_signs):
        self.text = text
        self.state = state
        self.current_sentence_builder = []
        self.sentences = []
        self.split_signs = split_signs
        self.pair_signs = pair_signs

    @property
    def current_char(self):
        return self.text[self.current_index]

    def finish(self):
        self.is_finished = True

    def execute(self):
        while not self.is_finished:
            self.state.execute(self)