#ifndef _TC_RES_PUB_H_
#define _TC_RES_PUB_H_

#include <cstddef>

namespace new_seg
{

/////////////////////////////////////////////////////////////////////////////////////////////
//                        �µķִʽ����ȡ�ӿ�                                             //
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct _token_t
{
    const char      *word; // ����
    unsigned char   pos;   // ����
    size_t          wlen;  // �ʳ�
    unsigned char   wtype; // ����(0-��ͨ�� 1-multiseg��һ���з���ʽ 2-multiseg�ڶ����з���ʽ)
}token_t;

typedef struct _comb_token_t
{
    const char      *word; // ����
    unsigned char   pos;   // ����
    size_t          wlen;  // �ʳ�
    int             cls;   // ����� ������Ϣֻ���û��Զ���ʡ��������Ч��
    size_t          sidx;  // ��ϸ�з��п�ʼ������
    size_t          eidx;  // ��ϸ�з��н���������
}comb_token_t;

typedef struct _additional_token_t
{
	const char      *word; // ����
	unsigned char   pos;   // ����
	size_t          wlen;  // �ʳ�
	size_t          start_idx; // Դ����ʼ����
	size_t          end_idx; // Դ�ʽ�������

	size_t          next_group_additional_idx; // ��һ��ʵ���ʼλ�ã���û��������Ϊ0
}additional_token_t;

typedef struct _seg_tokens_t
{
    // ϸ�����зִ���
    token_t        *fine_grain_seg_tokens;
    size_t          fine_grain_tokens_num;
    
    // �������зִ���
    comb_token_t   *thick_seg_tokens;
    size_t          thick_seg_tokens_num;

    // ��������зִ���
    token_t        *mix_seg_tokens;
    size_t          mix_seg_tokens_num;
}seg_tokens_t;


/////////////////////////////////////////////////////////////////////////////////////////////
//                        ���ݾɰ�ִʽ����ȡ�ӿ�                                         //
/////////////////////////////////////////////////////////////////////////////////////////////
typedef struct wordpos
{
    const char* word;
    int         pos;
    bool        bcw;  // �û��Զ���� ? true : false
    int         cls;  // (�û��Զ���� && TC_CLS) ? �û��Զ���ʷ���� : NULL
}WP, *pWP;;

}  // namespace new_seg

#endif
