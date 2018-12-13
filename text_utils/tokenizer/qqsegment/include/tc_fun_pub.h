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
* 添加一个新的自定义词典
* dict_path：新词典明文文件所在目录
* return：新词典的ID, 从1开始；如果返回0，说明添加不成功
**********************************/
size_t TCAddCustomDict(const char* dict_path);

/**********************************
* 删除用户自定义词典
* id：要删除的词典的ID, 正在使用的词典不允许删除
**********************************/
void TCDelCustomDict(size_t id);


/**********************************
* 更新自定义词典
* dict_path：新词典明文文件所在目录
* id：要更新的词典的ID
**********************************/
void TCUpdateCustomDict(const char* dict_path, size_t id);


/**********************************
* 切换正在使用的词典
* id：目标词典的ID
**********************************/
void TCSwitchCustomDictTo(size_t id);

/**********************************
* 获取当前正在使用的自定义词典
* return：正在使用的词典的ID
**********************************/
size_t TCGetWorkingCustomDictID();

}  // namespace new_seg

#endif
