#include"bigResource.h"
#include<iostream>
using std::cout;
using std::endl;

BigResource::BigResource(){
    cout << "BigResource()" << endl;
    m_theResource.clear();
}

BigResource::BigResource(const std::string& res){
    cout << "BigResource(const std::string& res)" <<endl;
    m_theResource = res;
}

BigResource::BigResource(std::string&& res){
    cout << "BigResource(std::string&& res)" << endl;
    m_theResource = std::move(res);
}

BigResource::BigResource(const BigResource& other){
    cout << "BigResource(const BigResource& other)" << endl;
    m_theResource = other.m_theResource;
}

BigResource::BigResource(BigResource&& other){
    cout << "BigResource(BigResource&& other)" <<endl;
    m_theResource = std::move(other.m_theResource);
}

BigResource& BigResource::operator = (const BigResource& other){
    cout << "BigResource::operator = (const BigResource& other)" << endl;
    m_theResource = other.m_theResource;
}

BigResource& BigResource::operator = (BigResource&& other){
    cout << "BigResource::operator = (BigResource&& other)" << endl;
    m_theResource = std::move(other.m_theResource);
}

void BigResource::showResource(const char* tag){
    cout << "object: " << tag << "(" << this << ")" << " rescource: " << m_theResource << endl;
}