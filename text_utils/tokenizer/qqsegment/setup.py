#!/usr/bin/env python

"""
setup.py file for SWIG C++/Python example
"""
from distutils.core import setup, Extension

static_libraries = ['segmentor']
static_lib_dir = './lib'

extra_objects = ['{}/lib{}.a'.format(static_lib_dir, l) for l in static_libraries]


qqsegment_module = Extension('_qqsegment',
                             sources=['qqsegment.cpp', 'qqsegment_wrap.cxx'],
                             include_dirs = ['./include'],
                             #library_dirs = ['/data1/madwang/workspace/qqseg/qqsegment/lib/qqseg_new.2018/lib64'],
                             extra_objects=extra_objects,
                             #extra_link_args = ['-lsegmentor', '-lpthread'],
                             extra_compile_args = ["-O2"])
setup (
    name = 'qqsegment',
    version = '0.1',
    author = "Felix",
    description = """Simple swig binding for qqsegment""",
    ext_modules = [qqsegment_module],
    py_modules = ["qqsegment"],
)
