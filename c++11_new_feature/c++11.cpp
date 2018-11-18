#include<iostream>
#include<string>
#include<vector>
#include"bigResource.h"
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[])
{
    cout << "some c++11 language feature." << endl;

    //auto key word
    cout << "(1) auto keyworld for type deduce" << endl;
    auto f = 3.14;
    auto l = [](const char* msg) -> void {
        cout << msg << " from lambda." <<endl;
    };
    cout << f <<endl;
    l("hello c++11");
    cout << endl;

    //uniform initalization
    cout << "(2)uniform initalization" << endl;
    double d{1.56656612616};
    const char* msg{"the weather of today is nice."};
    string str{"python is an computer programming language."};
    cout << d << "\n" << msg << "\n" << str << endl; 
    cout << endl;

    //range-base for loop
    cout << "(3)range-base for loop" << endl;
    vector<int> intArr{1,2,3,4,5};
    for(auto& num : intArr)
    {
        cout << num << " ";
    }
    cout << endl << endl;

    //rvalue refrence and move semantic
    BigResource r1;
    BigResource r2(str);
    r1.showResource("r1");
    r2.showResource("r2");
    cout<<"str: "<< str << endl;

    BigResource r3(std::move(str));
    r3.showResource("r3");
    cout<<"str: "<< str << endl;

    BigResource r4(std::move(r2));
    r4.showResource("r4");
    r3.showResource("r3");
    cout << endl;

    //lambda expression
    auto lambda = [](){
        cout << "this is a lanmda expression." << endl;
    };
    lambda();

    system("PAUSE");
    return 0;
}
