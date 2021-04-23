#include "common/debugger.h"

// 返回int -1失败？
void my_memcpy(void* dst, const void*src, size_t n)
{
    if (!src) return;

    dst = malloc(n);
    if (dst == nullptr) {
        return;
    }

    char *ret((char*)dst), *srcc((char*)src);
    for(int i=0; i<n; i++) {
        ret = srcc;
        ++ret;
        ++srcc;
    }

}