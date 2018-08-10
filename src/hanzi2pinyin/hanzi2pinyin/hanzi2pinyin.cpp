
#include "hanzi2pinyin.h"
#include "Hanz2Piny.h"
#include <string.h>

__DLLEXPORT int hanz2pinyin(const char* in, int size, char* out)
{
    Hanz2Piny h2p;
    auto r = h2p.toPinyinFromUtf8(in, false);
    int len = 0;
    for (auto& s : r)
    {
        memcpy(out + len, s.second[0].c_str(), s.second[0].size());
        len += s.second[0].size();
        *(out + len) = ' ';
        len++;
    }
    return len;
}

#ifndef _WINDLL
int main()
{
    const char* in = u8"测试数据";
    char out[100] = "\0";
    hanz2pinyin(in, 13, out);
    printf("%s", out);
    return 0;
}
#endif

