#ifndef Student_H
#define Student_H
#include<string>
#include<tuple>
#include<iostream>

class Student {
    public:
        Student();
        Student(const std::string& name, int age, int id, const std::string& profession);
        Student(const char* name, int age, int id, const char* profession);

        void set(const std::string& name, int age, int id, const std::string& profession);
        std::tuple<std::string, int, int, std::string> get()const;
        std::string toString()const;
        bool fromString(const std::string& str);
    private:
        std::string m_name;
        int m_age;
        int m_id;
        std::string m_profession;  
};


template<typename charT>
std::basic_ostream<charT>& operator << (std::basic_ostream<charT>& ostrm, const Student& s){
    ostrm << s.toString();
   
    return ostrm;
}

template<typename charT>
std::basic_istream<charT>& operator >> (std::basic_istream<charT>& istrm, Student& s){
    std::string name;
    int age;
    int id;
    std::string profession;
    bool input_is_valide = true;

    if(!(istrm >> name))
        input_is_valide = false;

    if(!(istrm >> age))
        input_is_valide = false;
    
    if(!(istrm >> id))
        input_is_valide = false;
    
    if(!(istrm >> profession))
        input_is_valide = false;

    if(input_is_valide)
        s.set(name, age, id, profession);

    return istrm;
}



#endif //Student_H