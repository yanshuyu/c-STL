#include"strEncodingCvt.h"

std::string wstring_to_utf8(const std::wstring& wstr){
    std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
    return cvt.to_bytes(wstr);
}

std::wstring utf8_to_wstring(const std::string& str){
    std::wstring_convert<std::codecvt_utf8<wchar_t>> cvt;
    return cvt.from_bytes(str);
}


