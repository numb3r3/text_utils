#!/usr/bin/env python
# Learn more: https://github.com/kennethreitz/setup.py

import os
from distutils.core import setup, Extension

qqsegment_dir = './text_utils/tokenizer/qqsegment'
qqsegment_static_libraries = ['segmentor']
qqsegment_static_lib_dir = os.path.join(qqsegment_dir, 'lib')

extra_objects = [
    '{}/lib{}.a'.format(qqsegment_static_lib_dir, l)
    for l in qqsegment_static_libraries
]

qqsegment_module = Extension(
    '_qqsegment',
    sources=[
        os.path.join(qqsegment_dir, 'qqsegment.cpp'),
        os.path.join(qqsegment_dir, 'qqsegment_wrap.cxx')
    ],
    include_dirs=[os.path.join(qqsegment_dir, 'include')],
    extra_objects=extra_objects,
    #extra_link_args = ['-lsegmentor', '-lpthread'],
    extra_compile_args=["-O2"])

setup(
    name='text_utils',
    version='1.0.0',
    author='Feng Wang',
    author_email='wangfelix87@gmail.com',
    ext_modules=[qqsegment_module],
    # py_modules=["qqsegment"],
    packages=['text_utils'],
    license='LICENSE',
    description='Text Pre-processing Utils.',
    long_description=open('README').read())
