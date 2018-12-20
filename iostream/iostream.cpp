#include<iostream>
#include<limits>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<memory.h>
#include<streambuf>
#include<locale>
#include<string>
#include<codecvt>                   
#include"student.h"
#include"strEncodingCvt.h"
using namespace std;


int main(int argc, char const *argv[])
{
    /*
    //*********************************************std stream***********************************************    
    // stream link to std io channel, stdin/stdout/stderr
    // header<iostrem>
    //print all ascci char
    ios::fmtflags oldFmt = cout.flags();
    cout << setw(10) << std::setfill(' ') << std::left << "ascii";
    cout << setw(12) << std::setfill(' ') << std::left << "charater";
    cout << setw(10) << std::setfill(' ') << std::left << "streamstate" << endl;
    for(unsigned char c = 0; static_cast<unsigned>(c) < numeric_limits<unsigned char>::max()/2; ++c){
        cout.clear(ios::goodbit);
        cout << std::setw(12) << std::setfill(' ') << static_cast<unsigned>(c);
        cout << std::setw(12) << std::setfill(' ') << c;
        cout << std::setw(12) << std::setfill(' ') << std::boolalpha << cout.good() << endl;
    }

    //io formating
    //width and fill
    cout.setf(ios::right, ios::adjustfield);
    cout << std::setw(6) << std::setfill('_') << 3.14 << endl;
    cout << 3.14 << endl;

    cout.setf(ios::left, ios::adjustfield);
    cout << std::setw(20)  << "hello world" << endl;
    cout << "hello world" << endl;
    cout.flags(oldFmt);

    //number base, sign pos, pricision
    cout << endl;
    cout << std::showpos << std::showbase << std::showpoint << std::setprecision(6) << 3.14 << endl;
    cout << 3.14 << endl; 
    
    cout.setf(ios::hex, ios::basefield);
    cout << std::uppercase << 16 << endl;
    cout << 16 << endl;
    cout << 3.14 << endl; 
    cout.setf(oldFmt);

    char charBuf[10]{0};
    cin.width(sizeof charBuf);
    cout << "please input some text" << endl;
    cin >> charBuf;
    cout << "the text is: " << charBuf << endl;

    char sb[1024] = {0};
    cin.get(sb, sizeof sb);
    cout << "the remainder text is: " << sb << endl;


    //************************************************file stream***************************************************
    //stream link to file object in os file system
    //header <fstrem>
    //read source file
    cout << endl << endl;
    ifstream i_fd("iostream.cpp", ios::ate);
    if(i_fd){
        streampos pos = i_fd.tellg();
        i_fd.seekg(0, ios::beg);
        char* read_buf = new char[pos];
        i_fd.read(read_buf, pos);
        cout << "content of iostream.cpp is: " << read_buf;
        delete[] read_buf;
        i_fd.close();
    }

    //copy executable
    ifstream ib_fd("a.exe", ios::binary | ios::ate);
    ofstream o_fd("a_copy.exe", ios::binary);
    if(o_fd){
        streampos i_sz = ib_fd.tellg();
        ib_fd.seekg(0, ios::beg);
        char* data = new char[i_sz];
        ib_fd.read(data, i_sz);
        o_fd.write(data, i_sz);

        ib_fd.close();
        i_fd.close();
    }

    //read and write using the same fstream
    fstream fd;
    fd.open("XAQA2884.JPG", ios::in | ios::binary);
    if(fd){
        fd.seekg(0, ios::end);
        streampos sz = fd.tellg();
        fd.seekg(0, ios::beg);
        char* data = new char[sz];
        fd.read(data, sz);
        fd.close();

        fd.open("XAQA2884_copy.JPG", ios::out | ios::binary);
        if(fd){
            fd.write(data, sz);
            fd.close();
        }
    }


    //************************************************string stream***************************************************
    // has stream buffer but no io channel
    //header <sstream>
    cout << endl << endl;
    ostringstream o_str_stream;
    o_str_stream << "dec: " << std::showbase << std::showpos << std::showpoint << std::setprecision(8) << 3.14 << endl;
    o_str_stream << "hex: " << std::hex << std::uppercase << 1024 << endl;
    cout << o_str_stream.str();

    
    float pi;
    int x;
    string ignore;

    istringstream i_str_stream(o_str_stream.str());
    i_str_stream >> ignore >> pi;
    i_str_stream >> ignore >> std::hex >> x;
    cout << "pi: " << pi << endl;
    cout << "x: " << x << endl;
    cout << "ignore: " << ignore << endl;
    
    //ueser define type io
    cout.flags(oldFmt);
    cin.width(0);
    Student s;
    cout << "please input student's info: " << endl;
    cin >> s;
    cout << "info about the student is: " << endl;
    cout << s << endl;

    auto s_info = s.get();
    s.set(std::get<0>(s_info), std::get<1>(s_info), std::get<2>(s_info), "computer science");

    Student s_copy;
    s_copy.fromString(s.toString());
    std::cout << "s: " << s << std::endl;
    std::cout << "s_copy: " << s_copy << std::endl;

    

    //************************************************stream connecting and io redirection****************************************
    //connect stream buf: loose coupling or tight coupling
    
    //loose coupling(�����), stream objects sync stream bufs
    //cin.tie(&cout);
    //wcin.tie(&wcout);
    
    //tight coupling(�����), strem objects share strem buf
    cout << endl << endl;
    ostream hexcout(cout.rdbuf());
    hexcout.setf(ios::hex, ios::basefield);
    hexcout.setf(ios::showbase);
    hexcout << "hex: " << 1024 << endl;
    cout << "dec: " << 1024 << endl;

    hexcout.setf(ios::dec, ios::basefield);
    hexcout.setf(ios::showpoint, ios::floatfield);
    hexcout.precision(8);
    hexcout << "high precision: " << 3.14 << endl;
    cout << "default precision: " << 3.14 << endl;
    */
    
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
    cout << std::boolalpha << "always_noconv: " << cvt_f.always_noconv() << endl;
    cout << "encoding: " << cvt_f.encoding() << endl;

    //codecvt: converts between character encodings, including UTF-8, UTF-16, UTF-32 
    std::string narrowStr("hello, 你好"); //utf-8
    std::wstring wideStr(L"hello, 你好"); //usc-2
    std::string w2nStr;
    cout << "narrowStr: " << narrowStr << endl;
    wcout << "wideStr: " << wideStr << endl; 
    cout << endl << endl;
    wcout.clear(std::ios::goodbit);

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
 
    //collate: defines lexicographical comparison and hashing of strings 
    std::string s1{"today is diffecult, tomorrow is beautiful."};
    std::string s2{"today is diffecult, Tomorrow is beautiful."};
    const std::collate<char>& col_f = std::use_facet<std::collate<char>>(loc_c);
    int comp_result = col_f.compare(&s1[0], &s1[s1.size()], &s2[0], &s2[s2.size()]);
    cout << s1 << " compare " << s2 <<": " << comp_result << endl;
    cout << s1 << " hash: " << col_f.hash(&s1[0], &s1[s1.size()]) << endl;
    cout << s2 << " hash: " << col_f.hash(&s2[0], &s2[s2.size()]) << endl;
    


	system("pause");
    return 0;
}
