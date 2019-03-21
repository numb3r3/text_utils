#!/usr/bin/env python

import os

from setuptools import setup, find_packages
from setuptools.extension import Extension

setup(
    name='text_utils',
    version='1.0.0',
    author='Feng Wang',
    author_email='wangfelix87@gmail.com',
    packages=find_packages(),
    package_data={'text_utils': ['resources/*']},
    license='LICENSE',
    description='Text Pre-processing Utils.',
    long_description=open('README.md').read())
