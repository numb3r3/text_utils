# coding=utf-8

from .sign import SPLIT_SIGN, MAYBE_SPLIT_SIGN
from .context import Context

class ContextState(object):
    def execute(self, context):
        pass


class CharCheckContextState(ContextState):

    def execute(self, context):

        global CONTEXT_STATE_MANAGER

        current_char = context.current_char

        if context.current_index > 0 and current_char.isspace():
            context.token_num += 1

        if (not context.is_pair_sign_opened) and (current_char in context.pair_signs):
            context.state = CONTEXT_STATE_MANAGER["PAIR_SIGN_CONTEXT_STATE"]
        elif context.is_too_long() and current_char in MAYBE_SPLIT_SIGN:
            context.current_sentence_builder.append(current_char)
            context.state = CONTEXT_STATE_MANAGER["SPLIT_CONTEXT_STATE"]
        elif current_char in context.split_signs:
            context.current_sentence_builder.append(current_char)
            context.state = CONTEXT_STATE_MANAGER["SPLIT_CONTEXT_STATE"]
        elif context.is_pair_sign_opened and current_char in context.back_pair_sign:
            context.state = CONTEXT_STATE_MANAGER["PAIR_SIGN_CLOSE_CONTEXT_STATE"]
        else:
            context.current_sentence_builder.append(current_char)
            context.state = CONTEXT_STATE_MANAGER["FINISH_CHECK_CONTEXT_STATE"]

class FinishCheckContextState(ContextState):

    def execute(self, context):
        if context.current_index + 1 == len(context.text):
            if len(context.current_sentence_builder) != 0:
                sen = ''.join(context.current_sentence_builder)
                context.sentences.append(sen)
                # context.current_sentence_builder = []
                context.clear_local_state()
            context.finish()
            return
        else:
            context.current_index += 1
            context.state = CONTEXT_STATE_MANAGER["CHAR_CHECK_CONTEXT_STATE"]


class PairSignContextState(ContextState):

    def execute(self, context):

        if context.current_index + 1 == len(context.text):
            context.current_sentence_builder.append(context.current_char)
        else:
            pair_sign_context = Context(context.text, CONTEXT_STATE_MANAGER["CHAR_CHECK_CONTEXT_STATE"],
                                        context.split_signs, context.pair_signs, context.maybe_split_signs, context.token_limits)
            pair_sign_context.sentences.append(context.current_char)

            pair_sign_context.current_index = context.current_index + 1
            pair_sign_context.pair_sign = context.current_char
            pair_sign_context.back_pair_sign = context.pair_signs[pair_sign_context.pair_sign]
            pair_sign_context.is_pair_sign_opened = True
            pair_sign_context.execute()
            res = pair_sign_context.sentences

            if len(res) == 3 and \
                    res[2] in pair_sign_context.back_pair_sign and \
                    res[0] == pair_sign_context.pair_sign and \
                    ((res[1] and res[1][-1] not in SPLIT_SIGN) or (len(res[1]) < 20)):
                context.current_sentence_builder.append(''.join(res))
            else:
                if len(context.current_sentence_builder) != 0:
                    sen = ''.join(context.current_sentence_builder)
                    context.sentences.append(sen)
                    # context.current_sentence_builder = []
                    context.clear_local_state()
                context.sentences += res

            context.current_index = pair_sign_context.current_index

        context.state = CONTEXT_STATE_MANAGER["FINISH_CHECK_CONTEXT_STATE"]

class PairSignCloseContextState(ContextState):

    def execute(self, context):

        if len(context.current_sentence_builder) != 0:
            sen = ''.join(context.current_sentence_builder)
            context.sentences.append(sen)
            # context.current_sentence_builder = []
            context.clear_local_state()
        context.sentences.append(context.current_char)
        context.finish()
        return


class SplitContextState(ContextState):

    def execute(self, context):

        context.has_split_sign = True

        while context.current_index < len(context.text) - 1:
            context.current_index += 1
            tmp = context.text[context.current_index]
            if tmp in context.split_signs or tmp in context.maybe_split_signs:
                context.current_sentence_builder.append(tmp)
            else:
                context.current_index -= 1
                break

        if len(context.current_sentence_builder) != 0:
            sen = ''.join(context.current_sentence_builder)
            context.sentences.append(sen)
            # context.current_sentence_builder = []
            context.clear_local_state()

        context.state = CONTEXT_STATE_MANAGER["FINISH_CHECK_CONTEXT_STATE"]


CONTEXT_STATE_MANAGER = {
    "SPLIT_CONTEXT_STATE": SplitContextState(),
    "PAIR_SIGN_CONTEXT_STATE": PairSignContextState(),
    "CHAR_CHECK_CONTEXT_STATE": CharCheckContextState(),
    "FINISH_CHECK_CONTEXT_STATE": FinishCheckContextState(),
    "PAIR_SIGN_CLOSE_CONTEXT_STATE": PairSignCloseContextState()
}