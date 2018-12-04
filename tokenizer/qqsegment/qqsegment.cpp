#include <stdio.h>
#include <string>
#include <fstream>
#include <assert.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include "tc_def_pub.h"
#include "tc_fun_pub.h"

#include "qqsegment.h"

std::string trim(const std::string& in_str);

int QQSegmenter::Init(const std::string& data_dir, int32_t mode) {
    fprintf(stderr, "init segment [%s] ...\n", data_dir.c_str());
    m_data_dir = data_dir;
    m_seg_mode = mode;

    //加载词典资源，每个进程只需加载一次即可，所有线程共享
    if(!new_seg::TCInitSeg(data_dir.c_str())) {
        fprintf(stderr, "%s:init seg from \"%s\" failed!\n", __FUNCTION__, data_dir.c_str());
        return -1;
    }

    m_seg_handle = new_seg::TCCreateSegHandle(mode);
    if(NULL == m_seg_handle) {
            fprintf(stderr, "%s:create seg handle failed!\n", __FUNCTION__);
            return -2;
    }

    return 0;
}

std::vector<std::string> QQSegmenter::Segment(const std::string& text, bool seg_pos = false, bool result_upper_case = false, int upper_begin_index = 0, bool is_gbk = true) {
    std::string in_text = text;

    std::vector<std::string> seg_result;

    if (is_gbk) {
        if (!new_seg::TCSegment(m_seg_handle, in_text.c_str(), text.length())) {
            // return -1;
            return seg_result;
        }
    }
    else {
        if (!new_seg::TCSegment(m_seg_handle, in_text.c_str(), text.length(), TC_UTF8)) {
            // return -1;
            return seg_result;
        }
    }

    char buf[128] = {0};
    // std::vector<std::string> seg_result;
    seg_result.clear();
    size_t word_num = new_seg::TCGetMixWordCnt(m_seg_handle);
    new_seg::pWP wp_point;
    for (size_t i = 0; i < word_num; ++i)
    {
        std::string s = trim(new_seg::TCGetMixWordAt(m_seg_handle, i));
        if (s.empty())
        {
            continue;
        }
        if (result_upper_case && i >= upper_begin_index)
        {
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
        seg_result.push_back(s);
    }
    return seg_result;
}

void trim(char* str)
{
    int beg = 0;
    int end = strlen(str);

    for (; str[beg] == ' '; ++beg);
    for (; end > 0 && str[end-1] == ' '; --end);

    int j = 0;
    for (int i = beg; i < end; ++i)
    {
        str[j++] = str[i];
    }

    str[j] = '\0';
}

std::string trim(const std::string& in_str)
{
    std::string s = in_str;
    trim((char*)s.data());
    std::string ret = s.data();
    return ret;
}
