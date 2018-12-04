#include <iostream>
#include <vector>
#include <string.h>

#include "tc_def_pub.h"
#include "tc_fun_pub.h"

class QQSegmenter
{
private:
    std::string m_data_dir;
    int32_t m_seg_mode;
    new_seg::HANDLE m_seg_handle;

public:
    QQSegmenter() : m_seg_mode(0), m_seg_handle(NULL) {};
    static int32_t GetDefaultMode() {
        int32_t mode = TC_CRF | TC_PER_W | TC_S2D | TC_T2S | TC_CUT | TC_POS | TC_SIM | TC_UTF8;
        return mode;
    };
    virtual ~QQSegmenter() {
        if (NULL != m_seg_handle)
        {
            new_seg::TCCloseSegHandle(m_seg_handle);
            m_seg_handle = NULL;
        }
        new_seg::TCUnInitSeg();
    };
    int Init(const std::string& data_dir, int32_t mode);
    std::vector<std::string> Segment(const std::string& text, bool seg_pos, bool result_upper_case, int upper_begin_index, bool is_gbk);
};
