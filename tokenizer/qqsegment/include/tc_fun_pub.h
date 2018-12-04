#ifndef _TC_FUN_PUB_H_
#define _TC_FUN_PUB_H_

#include <stdint.h>

#include "tc_def_pub.h"
#include "tc_res_pub.h"

namespace new_seg
{

typedef void* HANDLE;

bool TCInitSeg(const char* data_path);
void TCUnInitSeg();

HANDLE TCCreateSegHandle(int32_t seg_mode);
void TCCloseSegHandle(HANDLE seg_handle);

void ResetSegMode(HANDLE seg_handle, int32_t seg_mode_value);

bool TCSegment(HANDLE seg_handle, const char* text, size_t len, size_t charset = TC_GBK);

size_t TCGetResultCnt(HANDLE seg_handle);
const char * TCGetWordAt(HANDLE seg_handle, size_t index);
pWP TCGetAt(HANDLE hHandle, int index);
void TCPosId2Str(unsigned char pos_id, char* pos_str);

size_t TCGetPhraseCnt(HANDLE seg_handle);
const char * TCGetPhraseAt(HANDLE seg_handle, size_t index);
const token_t * TCGetBasicTokenAt(HANDLE seg_handle, int32_t idx);
const comb_token_t * TCGetPhraseTokenAt(HANDLE seg_handle, int32_t idx);

size_t TCGetAdditionalTokenCnt(HANDLE seg_handle);
const additional_token_t * TCGetAdditionalTokenAt(HANDLE seg_handle, size_t idx);

void TCGetAllSegInfo(HANDLE seg_handle, seg_tokens_t &seg_tokens);

size_t TCGetMixWordCnt(HANDLE seg_handle);
const token_t * TCGetMixTokenAt(HANDLE seg_handle, int32_t idx);
const char * TCGetMixWordAt(HANDLE seg_handle, size_t index);

/**********************************
* ���һ���µ��Զ���ʵ�
* dict_path���´ʵ������ļ�����Ŀ¼
* return���´ʵ��ID, ��1��ʼ���������0��˵����Ӳ��ɹ�
**********************************/
size_t TCAddCustomDict(const char* dict_path);

/**********************************
* ɾ���û��Զ���ʵ�
* id��Ҫɾ���Ĵʵ��ID, ����ʹ�õĴʵ䲻����ɾ��
**********************************/
void TCDelCustomDict(size_t id);


/**********************************
* �����Զ���ʵ�
* dict_path���´ʵ������ļ�����Ŀ¼
* id��Ҫ���µĴʵ��ID
**********************************/
void TCUpdateCustomDict(const char* dict_path, size_t id);


/**********************************
* �л�����ʹ�õĴʵ�
* id��Ŀ��ʵ��ID
**********************************/
void TCSwitchCustomDictTo(size_t id);

/**********************************
* ��ȡ��ǰ����ʹ�õ��Զ���ʵ�
* return������ʹ�õĴʵ��ID
**********************************/
size_t TCGetWorkingCustomDictID();

}  // namespace new_seg

#endif
