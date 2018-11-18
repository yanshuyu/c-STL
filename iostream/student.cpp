#include"student.h"
#include<sstream>
#include<limits>

Student::Student(){
    this->set("unKnown", 0, 0, "unKnown");
}

Student::Student(const char* name, int age, int id, const char* profession){
    this->set(name, age, id, profession);
}

Student::Student(const std::string& name, int age, int id, const std::string& profession){
    this->set(name, age, id, profession);
}

void Student::set(const std::string& name, int age, int id, const std::string& profession){
    this->m_name = name;
    this->m_age = age;
    this->m_id = id;
    this ->m_profession = profession;
}

std::tuple<std::string, int, int, std::string> Student::get()const {
    return std::make_tuple(this->m_name, this->m_age, this->m_id, this->m_profession);
}

std::string Student::toString()const{
    std::ostringstream str_buf;
    std::ios::fmtflags oldflags = str_buf.flags();
    str_buf << "Student object at: " << std::hex << std::uppercase << static_cast<const void* const>(this) << std::endl;
    str_buf.flags(oldflags);
    str_buf << "name: " << this->m_name << std::endl;
    str_buf << "age: " << this->m_age << std::endl;
    str_buf << "id: " << this->m_id << std::endl;
    str_buf << "profession: " << this->m_profession << std::endl;
    return str_buf.str();
}

bool Student::fromString(const std::string& str){
    std::string temp_name;
    int temp_age;
    int temp_id;
    std::string temp_profession;
    std::string ignore;

    std::istringstream str_buf(str);
    if(str.find("Student object at:") != std::string::npos){
        str_buf.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    if(!(str_buf >> ignore >> temp_name))
        return false;
    if(!(str_buf >> ignore >> temp_age))
        return false;
    if(!(str_buf >> ignore >> temp_id))
        return false;
    if(!(str_buf >> ignore >> temp_profession))
        return false;

    this->set(temp_name, temp_age, temp_id, temp_profession);
    return true;
}
