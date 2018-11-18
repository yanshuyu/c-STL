#include<iostream>
#include<utility>
#include<string>
#include<tuple>

template<typename T1, typename T2>
std::ostream& operator << (std::ostream& ostream, const std::pair<T1, T2>& p){
    ostream << "[ " << p.first << "," << p.second << " ]";
}


template<int MIN, int MAX,  typename... TYPES>
struct TuplePrinter{
    static void printTuple(std::ostream& ostream, const std::tuple<TYPES...>& t){
        ostream << std::get<MIN>(t) << ((MIN+1 == MAX) ? "":",");
        TuplePrinter<MIN+1, MAX, TYPES...>::printTuple(ostream, t);
    }
};


template<int MAX, typename... TYPES>
struct TuplePrinter<MAX, MAX, TYPES...>{
    static void printTuple(std::ostream& ostream, const std::tuple<TYPES...>& t){
    }
};

template<typename... TYPES>
std::ostream& operator << (std::ostream& ostrem, const std::tuple<TYPES...>& t){
    ostrem << "<";
    TuplePrinter<0, sizeof...(TYPES), TYPES...>::printTuple(ostrem, t);
    ostrem << ">";
}

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << "----------------------------- pair -----------------------------" << std::endl;
    
    typedef std::pair<char*, int> name_age_pair; 
    name_age_pair p1("yanshuyu", 26);
    name_age_pair p2("mengsiying", 26);
    
    std::cout << "my name and age is: " << p1 << std::endl;
    std::cout << "is " << p1 << " > " << p2 << "?    " << (p1 > p2) << std::endl;
    std::cout << "before swap, p1 is: " << p1 << " ,p2 is: " << p2 << std::endl;
    p1.swap(p2);
    std::cout << "after swap, p1 is: " << p1 << " ,p2 is: " << p2 << std::endl;
    std::cout << "is " << p1 << " > " << p2 << "?    " << (p1 > p2) << std::endl;
    std::cout << "first element of p1 is: " << std::get<0>(p1) << " ,second element of p2 is: " << std::get<1>(p2) << std::endl;
    std::cout << std::make_pair(p1.first, p2.first) << std::endl;

    std::cout <<"\n------------------------------------tuple------------------------------"<<std::endl;
    //typedef std::tuple<char*, int, char*> t1("sfsfsg",78,"687687689");
    typedef std::tuple<char*, int, char*> name_age_phone_tuple;
    name_age_phone_tuple t1("yanshuyu", 26, "15977337030");
    std::cout << t1 << std::endl;
    //std::cout << "[ " << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << " ]" << std::endl;
    system("pause");
    return 0;
}
