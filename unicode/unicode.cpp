#include<iostream>
#include<string>
#include<iomanip>

using std::cout;
using std::wcout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
    /*  encoding        code unit type          string type
        utf-8               char                std::string
        utf-16              char16_t            std::u16string
        utf-32              char32_t            std::u32string

     */
    char charArr[]{"hello 你好"};
    cout << "charArr: " << charArr << endl;
    cout << "bytes of charArr: ";
    cout << "size of charArr: " << sizeof(charArr) << endl;
    for (int i = 0 ; charArr[i] != NULL; ++i){
        cout << std::showbase << std::hex << static_cast<int>(charArr[i]) << endl;
    }
    cout << endl;

    char utf8CharArr[]{u8"hello 你好"};
    cout << "utf8CharArr: " << utf8CharArr << endl;
    cout << "size of utf8CharArr: " << sizeof(utf8CharArr) << endl;
    cout << "bytes of utf8CharArr: ";
    for (int i = 0 ; utf8CharArr[i] != NULL; ++i){
        cout << std::showbase << std::ios::hex << static_cast<int>(utf8CharArr[i]) << endl;
    }
    cout << endl;

    std::string utf8Str(u8"hello 你好");
    cout << "utf8Str: " << utf8Str << endl;
    cout << "size of utf8Str: " << utf8Str.size() << endl;
    cout << "bytes of utf8Str: ";
    for (auto& c : utf8Str){
        cout << std::showbase << std::ios::hex << c << endl;
    }
    cout << endl;
   
   
    // char16_t utf16CharArr[]{"hello 你好"};
    // wcout << "utf16CharArr: " << utf16CharArr << endl;
    // cout << "bytes of utf16CharArr: ";
    // for (int i = 0 ; utf16CharArr[i] != NULL; ++i){
    //     cout << std::showbase << std::ios::hex << static_cast<int>(utf16CharArr[i]) << endl;
    // }
    // cout << endl;

    cout << std::showbase << std::hex << 16 << endl;
    system("pause");
    return 0;
}
