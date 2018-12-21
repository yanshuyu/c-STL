#include"strEncodingCvt.h"
#include<cstring>
#include<cstdlib>
#include<exception>
#include<iostream>

std::string wstring_to_utf8(const std::wstring& wstr){
    std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
    return cvt.to_bytes(wstr);
}

std::wstring utf8_to_wstring(const std::string& str){
    std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
    return cvt.from_bytes(str);
}

int strlen_multibyte(const std::string& str){
    return strlen_multibyte(str.data());
}

int strlen_multibyte(const char* cstr){
    if (cstr == nullptr)
        return 0;

    std::size_t mbCnt = 0;
    std::mblen(nullptr, 0);
    const char* cur = cstr;
    const char* end = cstr + strlen(cstr);
    std::locale old_loc = std::locale::global(std::locale("Chinese (Simplified)_China.936"));
    std::cout << "c++ glolbe locale: " << std::locale().name() << std::endl;
    while( cur < end){
        int thisCharByteCnt = std::mblen(cur, end - cur);
        if (thisCharByteCnt == -1){
            std::locale::global(old_loc);
            throw std::runtime_error("strlen_mb(): conversion error.");
        }
        cur += thisCharByteCnt;
        mbCnt++;
    }
    
    std::locale::global(old_loc);
    return mbCnt;
}



