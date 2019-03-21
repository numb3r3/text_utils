from typing import List, Dict

from collections import defaultdict

import logging

log = logging.getLogger(__name__)


class Vocab:

    def __init__(self, add_unk=True):
        self._token2idx: Dict[str, int] = {}
        self._idx2token: List[str] = []

        if add_unk:
            self._unk_token = '<UNK>'
            self.add_token(self._unk_token)

    def add_token(self, token: str) -> int:
        idx = self._token2idx.get(token, None)
        if idx is None:
            idx = len(self._idx2token)
            self._token2idx[token] = idx
            self._idx2token.append(token)
        return idx

    def token2id(self, token: str) -> int:
        return self._token2idx.get(token, None)

    def idx2token(self, idx: int) -> str:
        assert idx < len(self._idx2token)
        return self._idx2token[idx]

    def __len__(self) -> int:
        return len(self._idx2token)

    def dump(self, dumpfile):
        import pickle
        with open(dumpfile, 'wb') as f:
            data = {'idx2token': self._idx2token, 'token2idx': self._token2idx}
            pickle.dump(data, f)

    @staticmethod
    def load(filename: string):
        import pickle
        vocab: Vocab = Vocab()
        with open(filename, 'rb') as f:
            data = pickle.load(f)
            vocab._idx2token = data['idx2token']
            vocab._token2idx = data['token2idx']
        return vocab
