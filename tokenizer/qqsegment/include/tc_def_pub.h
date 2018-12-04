#ifndef _TC_DEF_PUB_H_
#define _TC_DEF_PUB_H_

namespace new_seg
{

////////////////////////////////////////////////////////////////////////////////////
//                             ʵ�������                                       //
////////////////////////////////////////////////////////////////////////////////////
#define PHRASE_NAME_IDX         100000010       //�й�����
#define PHRASE_NAME_FR_IDX      100000011       //�������
#define PHRASE_LOCATION_IDX     100000012       //����
#define PHRASE_ORGANIZATION_IDX 100000013       //������

#define PHRASE_VIDEO_IDX        100000014       //Ӱ�ӣ�������Ӱ�����Ӿ硢��ͨ��������Ŀ
#define PHRASE_NOVEL_IDX        100000015       //С˵�������鼮������
#define PHRASE_SOFTWARE_IDX     100000016       //���
#define PHRASE_GAME_IDX         100000017       //��Ϸ������������Ϸ��������Ϸ���ֻ���Ϸ����ҳ��Ϸ
#define PHRASE_MUSIC_IDX        100000018       //���֣�����������ר��

#define PHRASE_FOOD_IDX         100000019       //����
#define PHRASE_ILL_IDX          100000020       //����
#define PHRASE_DRUG_IDX         100000021       //ҩƷ
#define PHRASE_CAR_IDX          100000022       //����
#define PHRASE_TIME_IDX         100000023       //ʱ�����

#define PHRASE_MIX_IDX          100000200
#define PHRASE_UNKNOWN_IDX      100000201       //δ֪����ʵ��
#define ITEM_NULL_IDX           100000202       //

//NOTE: �������ͽ��������ִ�ֱ���
#define PHRASE_MUSIC_DOWNLOAD_ADDR_IDX      100000301   //���֣����ص�ַ
#define PHRASE_MUSIC_INSTRUMENT_IDX         100000302   //���֣�����
#define PHRASE_MUSIC_STYLE_IDX              100000303   //���֣����
#define PHRASE_MUSIC_SONG_IDX               100000304   //���֣�����
#define PHRASE_MUSIC_LYRIC_IDX              100000305   //���֣����
#define PHRASE_MUSIC_ALBUM_IDX              100000306   //���֣�ר��

#define PHRASE_NAME_BAND_IDX                100000307   //�������ֶ�

#define PHRASE_LOCATION_VIEW_IDX            100000308   //����������
#define PHRASE_LOCATION_MOUNTAIN_IDX        100000309   //������ɽ
#define PHRASE_LOCATION_LAKE_IDX            100000310   //��������

#define PHRASE_VIDEO_MOVIE_IDX              100000311   //Ӱ�ӣ���Ӱ
#define PHRASE_VIDEO_TVSERIES_IDX           100000312   //Ӱ�ӣ����Ӿ�
#define PHRASE_VIDEO_TVSHOW_IDX             100000313   //Ӱ�ӣ����ս�Ŀ

#define PHRASE_NUMBER_IDX                   100000314   //����
#define PHRASE_SEQ_NUMBER_IDX               100000315   //����
#define PHRASE_NATION_IDX                   100000316   //����
#define PHRASE_BAIKE_IDX                    100000317   //�ٿ�ͨ�����


////////////////////////////////////////////////////////////////////////////////////
//                             �ִ��зֿ���                                       //
////////////////////////////////////////////////////////////////////////////////////
// @Deprecated ʹ������ʶ���Ƽ�ʹ�� TC_CRF �������
#define TC_CN               0x00000100
// ����neʶ�𣬲��һ���CRFʶ��������������������
#define TC_CRF               0x00000100

// ���ڴʵ�ƥ��ʶ����������ʵ�壺Ӱ�ӡ�С˵���������Ϸ�����ֵ�
// NOTE: ����ͬʱ����TC_CRF������Ч
#define TC_OTHER_NE         0x40000000

// ���д��Ա�ע
#define TC_POS              0x00000004

// ʹ�÷���ת����
#define TC_T2S              0x00000200

// ����Ӣ�Ĵ�Сдת��
#define TC_U2L              0x00000020

// ����ȫ�ǰ��ת��
#define TC_S2D              0x00000010

// @Deprecated ������Ϊһ��������������Ƽ�ʹ�� TC_PER_W ���
#define TC_CN_W             0x00010000
// ���� person ��Ϊһ�����������
// NOTE: �˿�����TC_ANE���⣬����ͬʱʹ��
#define TC_PER_W             0x00010000

// ������ organization ��Ϊһ�����������
#define TC_ORG_W             0x00020000

// ���� location ��Ϊһ�����������
#define TC_LOC_W             0x00040000

// @Deprecated ʹ���Զ���ʵ䣬�Ƽ�ʹ�� TC_CUS���
#define TC_USR              0x00000008
// ʹ���Զ���ʵ�
#define TC_CUS              0x00000008

// �������Ӵ��з�
#define TC_ADD              0x10000000

// ������������
// NOTE: �˿��غ�TC_CN_W/TC_PER_W���⣬����ͬʱʹ��
#define TC_ANE              0x20000000

// use simple mode in ascii for weixin
#define TC_SIM              0x08000000

// �ַ��������ʽ
// GBK����
#define TC_GBK              0x00100000
 
// UTF-8����
#define TC_UTF8             0x00200000

// ʹ�ù���
#define TC_RUL              0x00000080

// ASCII�ַ�����Ϊ�����з�
#define TC_ASC              0x00080000

// �����д�
#define TC_SIG              0x00000002

// ASCII�ַ���ʹ������ģ���з�
#define TC_ASCII_LM         0x01000000

// ASCII�ַ���ʶ���ƴ������Ҫ��TC_ASCII_LM����
#define TC_ASCII_LM_PINYIN  0x02000000

////////////////////////////////////////////////////////////////////////////////////
//                            ��ʧЧ�ľɰ�ִ��зֿ���                            //
////////////////////////////////////////////////////////////////////////////////////
// ��ʧЧ������ģʽ�зֿ���
#define TC_CUT              0x00002000

// ��ʧЧ, ����Ӣ�Ĵ�����ʱʹ��С����ģʽ�����ȼ�����TC_GU)
#define TC_ENGU             0x00000001

// ��ʧЧ, �����ִ�ϵͳʹ��С����ģʽ
#define TC_GU               0x00000001

// ��ʧЧ, ��ע�û��Զ���ʷ����
#define TC_CLS              0x00000001

// ��ʧЧ, ����С���ȿ���
#define TC_PGU              0x00000001

// ��ʧЧ, ����С��������
#define TC_LGU              0x00000001

// ��ʧЧ, ����׺�ֵĴ�С���ȿ���
#define TC_SGU              0x00000001

// ��ʧЧ, ƪ����Ϣ�ִʿ���
#define TC_TEXT             0x00000001

// ��ʧЧ, �ַ������� ����ȫ���ת���رտ���
#define TC_CONV             0x00000001

// ��ʧЧ, ������Ƭ�β���Multi-Seg
#define TC_WMUL             0x00000001

// ��ʧЧ, ���������Ƭ�β���Multi-Seg
#define TC_PMUL             0x00000001

// ��ʧЧ, ʹ�ö�������
#define TC_SECPOS           0x00000001

// ��ʧЧ, ���������µĽӿ���ʽ����ͬʱ����
// ��ʧЧ, ϸ�з֡����з֡��û��Զ���ʡ�����ʡ�ͬ���
#define TC_NEW_RES          0x00000001

// ��ʧЧ, ��������ͬ���
#define TC_SYN              0x00000001

// ��ʧЧ, ����ʶ�𿪹�
#define TC_LN               0x00000001

// ��ʧЧ, ������Ƭ�β���ϸ�з�
#define TC_WGU              0x00000001


///////////////////////////////////////////////////////////////////////////////////////////////////
//                            �ִʴ���                                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////
#define TC_A    1   // ���ݴ�
#define TC_AD   2   // ���δ�
#define TC_AN   3   // ���δ�
#define TC_B    4   // �����
#define TC_C    5   // ����
#define TC_D    6   // ����
#define TC_E    7   // ̾��
#define TC_F    8   // ��λ��
#define TC_G    9   // ���ش�
#define TC_H    10  // ǰ�ӳɷ�
#define TC_I    11  // ����
#define TC_J    12  // �������
#define TC_K    13  // ��ӳɷ�
#define TC_L    14  // ϰ����
#define TC_M    15  // ����
#define TC_N    16  // ����
#define TC_NR   17  // ����
#define TC_NRF  18  // ��
#define TC_NRG  19  // ��
#define TC_NS   20  // ����
#define TC_NT   21  // ��������
#define TC_NZ   22  // ����ר[m
#define TC_NX   23  // �Ǻ��ִ�
#define TC_O    24  // ������
#define TC_P    25  // ���
#define TC_Q    26  // ����
#define TC_R    27  // ����
#define TC_S    28  // ������
#define TC_T    29  // ʱ���
#define TC_U    30  // ����
#define TC_V    31  // ����
#define TC_VD   32  // ������
#define TC_VN   33  // ������
#define TC_W    34  // ������
#define TC_X    35  // ��������
#define TC_Y    36  // ������
#define TC_Z    37  // ״̬��
#define TC_AG   38  // ������
#define TC_BG   39  // ��������
#define TC_DG   40  // ������
#define TC_MG   41  // ����������
#define TC_NG   42  // ������
#define TC_QG   43  // ������
#define TC_RG   44  // ������
#define TC_TG   45  // ʱ����
#define TC_VG   46  // ������
#define TC_YG   47  // ����������
#define TC_ZG   48  // ״̬������
#define TC_SOS  49  // ��ʼ��
#define TC_EOS  55  // ������
#define TC_UNK  0   // δ֪����

#define TC_WWW      50  // URL
#define TC_TELE     51  // �绰����
#define TC_EMAIL    52  // email

}  // namespace new_seg

#endif
