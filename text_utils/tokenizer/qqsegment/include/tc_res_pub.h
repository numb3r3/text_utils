#ifndef _TC_RES_PUB_H_
#define _TC_RES_PUB_H_

#include <cstddef>

namespace new_seg
{

/////////////////////////////////////////////////////////////////////////////////////////////
//                        新的分词结果获取接口                                             //
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _token_t
{
    const char      *word; // 词条
    unsigned char   pos;   // 词性
    size_t          wlen;  // 词长
    unsigned char   wtype; // 词类(0-普通词 1-multiseg第一种切分形式 2-multiseg第二种切分形式)
}token_t;

typedef struct _comb_token_t
{
    const char      *word; // 词条
    unsigned char   pos;   // 词性
    size_t          wlen;  // 词长
    int             cls;   // 分类号 （该信息只对用户自定义词、短语词有效）
    size_t          sidx;  // 在细切分中开始词索引
    size_t          eidx;  // 在细切分中结束词索引
}comb_token_t;

typedef struct _additional_token_t
{
	const char      *word; // 词条
	unsigned char   pos;   // 词性
	size_t          wlen;  // 词长
	size_t          start_idx; // 源词起始索引
	size_t          end_idx; // 源词结束索引

	size_t          next_group_additional_idx; // 下一组词的起始位置，如没有下组则为0
}additional_token_t;

typedef struct _seg_tokens_t
{
    // 细粒度切分词条
    token_t        *fine_grain_seg_tokens;
    size_t          fine_grain_tokens_num;
    
    // 粗粒度切分词条
    comb_token_t   *thick_seg_tokens;
    size_t          thick_seg_tokens_num;

    // 混合粒度切分词条
    token_t        *mix_seg_tokens;
    size_t          mix_seg_tokens_num;
}seg_tokens_t;


/////////////////////////////////////////////////////////////////////////////////////////////
//                        兼容旧版分词结果获取接口                                         //
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct wordpos
{
    const char* word;
    int         pos;
    bool        bcw;  // 用户自定义词 ? true : false
    int         cls;  // (用户自定义词 && TC_CLS) ? 用户自定义词分类号 : NULL
}WP, *pWP;;

}  // namespace new_seg

#endif
