%module qqsegment

%include "stl.i"
%include "std_string.i"
%include "stdint.i"
%include "std_vector.i"

namespace std {
    %template(StringVector) vector<string>;
}

%{
#include "qqsegment.h"
%}

%include "qqsegment.h"
