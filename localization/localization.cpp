#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<locale>
#include<iomanip>
#include<codecvt>                   
#include"strEncodingCvt.h"
using namespace std;

main(int argc, char const *argv[])
{
    //***********************************************************internationaliztion(locale and facet)***************************************************
   	/*  encoding        code unit type          string type
	utf-8               char                std::string
	utf-16              char16_t            std::u16string
	utf-32              char32_t            std::u32string

	*/
	const std::locale loc_c = std::locale::classic();
	std::cout << "classic c locale: " << std::endl;
	std::cout << "	name: " << loc_c.name() << std::endl;
	std::cout << "	decimal point: " << std::use_facet<std::numpunct<char>>(loc_c).decimal_point() << std::endl;
	std::cout << "	thousands sep: " << std::use_facet<std::numpunct<char>>(loc_c).thousands_sep() << std::endl;
	std::cout << "	true name: " << std::use_facet<std::numpunct<char>>(loc_c).truename() << std::endl;
	std::cout << "	false name: " << std::use_facet<std::numpunct<char>>(loc_c).falsename() << std::endl; 
    
    
    /////////////////////////////////////////////////////////////////
    //charater classification and encoding convert
    /////////////////////////////////////////////////////////////////
    //ctype: defines character classification tables 
    const std::ctype<char>& ct_f = std::use_facet<ctype<char>>(loc_c);
    cout << "? is number: " << ct_f.is(ct_f.digit, '?') << endl;
    cout << "? is alpha: " << ct_f.is(ct_f.alpha, '?') << endl;
    cout << "? is punct: " << ct_f.is(ct_f.punct, '?') << endl;
    cout << "a is upper: " << ct_f.is(ct_f.upper, 'a') << endl;
    cout << "a to upper: " << ct_f.toupper('a') << endl;

    std::string l_s{"abcDEfgHijKLmN"};
    std::wstring w_s;
    std::vector<wchar_t> str_buf;
    for(const auto& c : l_s){
        w_s.push_back(std::use_facet<std::ctype<wchar_t>>(loc_c).widen(c));
    }
    //w_s.assign(str_buf.begin(), str_buf.end());
    cout << "l_s: " << l_s << endl;
    wcout << "w_s: " << w_s << endl;
    for(auto& c : w_s){
        c = std::use_facet<std::ctype<wchar_t>>(loc_c).toupper(c);
    }
    wcout << "w_s to upper: " << w_s << endl;

    const auto& cvt_f = std::use_facet<std::codecvt<char, char, std::mbstate_t>>(loc_c);
    cout << std::boolalpha << "codecvt<char, char, std::mbstate_t> always_noconv: " << cvt_f.always_noconv() << endl;
    cout << "codecvt<char, char, std::mbstate_t> encoding: " << cvt_f.encoding() << endl;

    //codecvt: converts between character encodings, including UTF-8, UTF-16, UTF-32 
    std::string narrowStr(u8"hello, 你好"); //utf-8
    std::wstring wideStr(L"hello, 你好"); //usc-2
    std::string w2nStr;
    cout << "narrowStr: " << narrowStr << endl;
    wcout << "wideStr: " << wideStr << endl; 
    wcout.clear(std::ios::goodbit);
    //cout << "narrow string charater cnt: " << strlen_multibyte(narrowStr) << endl;
    cout << endl << endl;


    std::mbstate_t mb_state{};
    std::codecvt_utf8<wchar_t> utf8_cvt_f;
    const wchar_t*  fromNext;
    char* toNext;

    cout << "before encoding cvt, w2nStr: " << w2nStr << endl;
    w2nStr.resize(wideStr.size() * utf8_cvt_f.max_length());
    std::codecvt_utf8<wchar_t>::result cvt_result = utf8_cvt_f.out( mb_state,
                                                                    &wideStr[0],
                                                                    &wideStr[wideStr.size()], 
                                                                    fromNext,
                                                                    &w2nStr[0],
                                                                    &w2nStr[w2nStr.size()],
                                                                    toNext);

    if (cvt_result == std::codecvt_utf8<wchar_t>::ok){
        cout << "after encoding cvt, before trim, w2nStr: " << w2nStr << "      " << "size: " << w2nStr.size() << endl;
        w2nStr.resize(toNext - &w2nStr[0]);
        cout << "before encoding cvt, after trim, w2nStr: " << w2nStr << "      " << "size: " << w2nStr.size() << endl;
    }
    else{
        cout << "encoding convert failde!" << endl;
    }

    std::string str = wstring_to_utf8(wideStr);
    cout<< "str: " << str << "  size: " << str.size() << endl;
    std::wstring wstr = utf8_to_wstring(str);
    wcout << L"wstr: " << wstr << L"  size： "<< wstr.size() << endl;
    wcout.clear(std::ios::goodbit);
    cout << endl << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////
    //Collation sequence
    //////////////////////////////////////////////////////////////////////////////////////////
    //collate: defines lexicographical comparison and hashing of strings 
    std::string s1{"today is diffecult, tomorrow is beautiful."};
    std::string s2{"today is diffecult, Tomorrow is beautiful."};
    const std::collate<char>& col_f = std::use_facet<std::collate<char>>(loc_c);
    int comp_result = col_f.compare(&s1[0], &s1[s1.size()], &s2[0], &s2[s2.size()]);
    cout << s1 << " compare " << s2 <<": " << comp_result << endl;
    cout << s1 << " hash: " << col_f.hash(&s1[0], &s1[s1.size()]) << endl;
    cout << s2 << " hash: " << col_f.hash(&s2[0], &s2[s2.size()]) << endl;
    

    ///////////////////////////////////////////////////////////////////////////////////////////
    //Rules and symbols for monetary information
    //////////////////////////////////////////////////////////////////////////////////////////
    const std::money_put<char>& monp_f = std::use_facet<std::money_put<char>>(loc_c);
    std::locale old = cout.imbue(loc_c);
    monp_f.put(ostreambuf_iterator<char>(cout), false, cout, ' ', 1000000.10);
    cout.imbue(old);
    cout << endl;
    cout << "money symbol: " << std::use_facet<std::moneypunct<char>>(loc_c).curr_symbol() << endl;



    

	system("pause");
    return 0;
}
