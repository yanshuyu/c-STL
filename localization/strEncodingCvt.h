#pragma once
#include<string>
#include<codecvt>
#include<locale>


std::string wstring_to_utf8(const std::wstring& wstr);

std::wstring utf8_to_wstring(const std::string& str);

int strlen_multibyte(const std::string& str);

int strlen_multibyte(const char* cstr);


