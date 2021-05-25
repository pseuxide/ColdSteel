#pragma once
#include <Windows.h>

#define STR_MERGE_IMPL(x, y)                x##y
#define STR_MERGE(x,y)                        STR_MERGE_IMPL(x,y)
#define MAKE_PAD(size)                        BYTE STR_MERGE(pad_, __COUNTER__) [ size ]

#define DEFINE_MEMBER_0(x, y)                x
#define DEFINE_MEMBER_N(x,offset)            struct { MAKE_PAD(offset); x; }