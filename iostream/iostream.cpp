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
using namespace std;


int main(int argc, char const *argv[])
{
    
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
    
    //loose coupling(松耦合), stream objects sync stream bufs
    //cin.tie(&cout);
    //wcin.tie(&wcout);
    
    //tight coupling(紧耦合), strem objects share strem buf
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

    
    
    return 0;
}
