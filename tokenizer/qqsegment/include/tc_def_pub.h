#ifndef _TC_DEF_PUB_H_
#define _TC_DEF_PUB_H_

namespace new_seg
{

////////////////////////////////////////////////////////////////////////////////////
//                             实体类别定义                                       //
////////////////////////////////////////////////////////////////////////////////////
#define PHRASE_NAME_IDX         100000010       //中国人名
#define PHRASE_NAME_FR_IDX      100000011       //外国人名
#define PHRASE_LOCATION_IDX     100000012       //地名
#define PHRASE_ORGANIZATION_IDX 100000013       //机构名

#define PHRASE_VIDEO_IDX        100000014       //影视，包括电影、电视剧、卡通动漫、节目
#define PHRASE_NOVEL_IDX        100000015       //小说，包括书籍、漫画
#define PHRASE_SOFTWARE_IDX     100000016       //软件
#define PHRASE_GAME_IDX         100000017       //游戏，包括单机游戏、网络游戏、手机游戏、网页游戏
#define PHRASE_MUSIC_IDX        100000018       //音乐，包括歌曲、专辑

#define PHRASE_FOOD_IDX         100000019       //菜谱
#define PHRASE_ILL_IDX          100000020       //疾病
#define PHRASE_DRUG_IDX         100000021       //药品
#define PHRASE_CAR_IDX          100000022       //汽车
#define PHRASE_TIME_IDX         100000023       //时间节日

#define PHRASE_MIX_IDX          100000200
#define PHRASE_UNKNOWN_IDX      100000201       //未知类别的实体
#define ITEM_NULL_IDX           100000202       //

//NOTE: 以下类型仅用于音乐垂直类别
#define PHRASE_MUSIC_DOWNLOAD_ADDR_IDX      100000301   //音乐：下载地址
#define PHRASE_MUSIC_INSTRUMENT_IDX         100000302   //音乐：乐器
#define PHRASE_MUSIC_STYLE_IDX              100000303   //音乐：风格
#define PHRASE_MUSIC_SONG_IDX               100000304   //音乐：歌曲
#define PHRASE_MUSIC_LYRIC_IDX              100000305   //音乐：歌词
#define PHRASE_MUSIC_ALBUM_IDX              100000306   //音乐：专辑

#define PHRASE_NAME_BAND_IDX                100000307   //人名：乐队

#define PHRASE_LOCATION_VIEW_IDX            100000308   //地名：景点
#define PHRASE_LOCATION_MOUNTAIN_IDX        100000309   //地名：山
#define PHRASE_LOCATION_LAKE_IDX            100000310   //地名：湖

#define PHRASE_VIDEO_MOVIE_IDX              100000311   //影视：电影
#define PHRASE_VIDEO_TVSERIES_IDX           100000312   //影视：电视剧
#define PHRASE_VIDEO_TVSHOW_IDX             100000313   //影视：综艺节目

#define PHRASE_NUMBER_IDX                   100000314   //数字
#define PHRASE_SEQ_NUMBER_IDX               100000315   //序数
#define PHRASE_NATION_IDX                   100000316   //民族
#define PHRASE_BAIKE_IDX                    100000317   //百科通用类别


////////////////////////////////////////////////////////////////////////////////////
//                             分词切分开关                                       //
////////////////////////////////////////////////////////////////////////////////////
// @Deprecated 使用人名识别，推荐使用 TC_CRF 开关替代
#define TC_CN               0x00000100
// 开启ne识别，并且基于CRF识别人名、地名、机构名
#define TC_CRF               0x00000100

// 基于词典匹配识别其他类别的实体：影视、小说、软件、游戏、音乐等
// NOTE: 必须同时开启TC_CRF才能生效
#define TC_OTHER_NE         0x40000000

// 进行词性标注
#define TC_POS              0x00000004

// 使用繁体转简体
#define TC_T2S              0x00000200

// 进行英文大小写转换
#define TC_U2L              0x00000020

// 进行全角半角转换
#define TC_S2D              0x00000010

// @Deprecated 人名作为一个词整体输出，推荐使用 TC_PER_W 替代
#define TC_CN_W             0x00010000
// 人名 person 作为一个词整体输出
// NOTE: 此开关与TC_ANE互斥，不能同时使用
#define TC_PER_W             0x00010000

// 机构名 organization 作为一个词整体输出
#define TC_ORG_W             0x00020000

// 地名 location 作为一个词整体输出
#define TC_LOC_W             0x00040000

// @Deprecated 使用自定义词典，推荐使用 TC_CUS替代
#define TC_USR              0x00000008
// 使用自定义词典
#define TC_CUS              0x00000008

// 开启附加词切分
#define TC_ADD              0x10000000

// 开启人名调整
// NOTE: 此开关和TC_CN_W/TC_PER_W互斥，不能同时使用
#define TC_ANE              0x20000000

// use simple mode in ascii for weixin
#define TC_SIM              0x08000000

// 字符串编码格式
// GBK编码
#define TC_GBK              0x00100000
 
// UTF-8编码
#define TC_UTF8             0x00200000

// 使用规则
#define TC_RUL              0x00000080

// ASCII字符串作为整体切分
#define TC_ASC              0x00080000

// 单字切词
#define TC_SIG              0x00000002

// ASCII字符串使用语言模型切分
#define TC_ASCII_LM         0x01000000

// ASCII字符串识别出拼音，需要打开TC_ASCII_LM开关
#define TC_ASCII_LM_PINYIN  0x02000000

////////////////////////////////////////////////////////////////////////////////////
//                            已失效的旧版分词切分开关                            //
////////////////////////////////////////////////////////////////////////////////////
// 已失效，短语模式切分开关
#define TC_CUT              0x00002000

// 已失效, 数字英文串连续时使用小粒度模式（优先级高于TC_GU)
#define TC_ENGU             0x00000001

// 已失效, 整个分词系统使用小粒度模式
#define TC_GU               0x00000001

// 已失效, 标注用户自定义词分类号
#define TC_CLS              0x00000001

// 已失效, 人名小粒度开关
#define TC_PGU              0x00000001

// 已失效, 地名小粒读开关
#define TC_LGU              0x00000001

// 已失效, 带后缀字的词小粒度开关
#define TC_SGU              0x00000001

// 已失效, 篇章信息分词开关
#define TC_TEXT             0x00000001

// 已失效, 字符！，： ；？全半角转换关闭开关
#define TC_CONV             0x00000001

// 已失效, 共享单字片段采用Multi-Seg
#define TC_WMUL             0x00000001

// 已失效, 真组合歧义片段采用Multi-Seg
#define TC_PMUL             0x00000001

// 已失效, 使用二级词性
#define TC_SECPOS           0x00000001

// 已失效, 用于生成新的接口形式即可同时返回
// 已失效, 细切分、粗切分、用户自定义词、短语词、同义词
#define TC_NEW_RES          0x00000001

// 已失效, 用于生成同义词
#define TC_SYN              0x00000001

// 已失效, 地名识别开关
#define TC_LN               0x00000001

// 已失效, 共享单字片段采用细切分
#define TC_WGU              0x00000001


///////////////////////////////////////////////////////////////////////////////////////////////////
//                            分词词性                                                           //
///////////////////////////////////////////////////////////////////////////////////////////////////
#define TC_A    1   // 形容词
#define TC_AD   2   // 副形词
#define TC_AN   3   // 名形词
#define TC_B    4   // 区别词
#define TC_C    5   // 连词
#define TC_D    6   // 副词
#define TC_E    7   // 叹词
#define TC_F    8   // 方位词
#define TC_G    9   // 语素词
#define TC_H    10  // 前接成分
#define TC_I    11  // 成语
#define TC_J    12  // 简称略语
#define TC_K    13  // 后接成分
#define TC_L    14  // 习用语
#define TC_M    15  // 数词
#define TC_N    16  // 名词
#define TC_NR   17  // 人名
#define TC_NRF  18  // 姓
#define TC_NRG  19  // 名
#define TC_NS   20  // 地名
#define TC_NT   21  // 机构团体
#define TC_NZ   22  // 其他专[m
#define TC_NX   23  // 非汉字串
#define TC_O    24  // 拟声词
#define TC_P    25  // 介词
#define TC_Q    26  // 量词
#define TC_R    27  // 代词
#define TC_S    28  // 处所词
#define TC_T    29  // 时间词
#define TC_U    30  // 助词
#define TC_V    31  // 动词
#define TC_VD   32  // 副动词
#define TC_VN   33  // 名动词
#define TC_W    34  // 标点符号
#define TC_X    35  // 非语素字
#define TC_Y    36  // 语气词
#define TC_Z    37  // 状态词
#define TC_AG   38  // 形语素
#define TC_BG   39  // 区别语素
#define TC_DG   40  // 副语素
#define TC_MG   41  // 数词性语素
#define TC_NG   42  // 名语素
#define TC_QG   43  // 量语素
#define TC_RG   44  // 代语素
#define TC_TG   45  // 时语素
#define TC_VG   46  // 动语素
#define TC_YG   47  // 语气词语素
#define TC_ZG   48  // 状态词语素
#define TC_SOS  49  // 开始词
#define TC_EOS  55  // 结束词
#define TC_UNK  0   // 未知词性

#define TC_WWW      50  // URL
#define TC_TELE     51  // 电话号码
#define TC_EMAIL    52  // email

}  // namespace new_seg

#endif
