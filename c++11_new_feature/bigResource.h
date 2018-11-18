#pragma once
#include<string>
class BigResource
{
    private:
        std::string m_theResource;
    public:
        BigResource();
        BigResource(const std::string& res);
        BigResource(std::string&& res);
        BigResource(const BigResource& other);
        BigResource(BigResource&& other);
        BigResource& operator = (const BigResource& other);
        BigResource& operator = (BigResource&& other);        

    public:
        void showResource(const char* tag);
};