#include<iostream>
#include<string>
#include<regex>


int main(int argc, char const *argv[])
{
    std::string data;
    data.assign("<person>\n\t<Alice>name:Alice age:20</Alice>\n\t<Peter>name:Peter age:18</Peter>\n</person>\n");
    std::cout << "data:\n" << data << std::endl;

    std::string regEx("<(.*)>(.*)</(\\1)>");
    std::regex reg (regEx);
    std::cout << "reg:\n" << regEx << std::endl << std::endl;

    //***********************************************match pattern in charater sequences*******************************
    if(std::regex_match(data, reg)){  //full match
        std::cout << "regex_match found match!" << std::endl;
    }
    else{
        std::cout << "regex_match don't found match!" << std::endl;
    }

    if(std::regex_search(data, reg)){ //partially match
        std::cout << "regex_search found match!" << std::endl;
    }
    else{
        std::cout << "regex_search don't found match!" << std::endl;
    }
    std::cout << std::endl << std::endl; 

    //*******************************match parttern detial info(matched subsequence, matched pos)**************************
    //typedef std::match_results<char> std::smatch
    std::smatch match_result;
    bool found = std::regex_search(data, match_result, reg);
    if(found){
        std::cout << "regex_search  matched detail: " << std::endl;
        std::cout << "str: " << match_result.str() << std::endl;
        std::cout << "lenth: " << match_result.length() << std::endl;
        std::cout << "pos: " << match_result.position() << std::endl;
        std::cout << "prefix str: " << match_result.prefix().str() << std::endl;
        std::cout << "suffix str: " << match_result.suffix().str() << std::endl;
        for (std::size_t i=0; i < match_result.size(); ++i){
            std::cout << "str[" << i << "]: " << match_result.str(i) << std::endl;
            std::cout << "length[" << i << "]: " << match_result.length(i) << std::endl;
            std::cout << "pos[" << i << "]: " << match_result.position(i) << std::endl;
        }
    }
    std::cout << std::endl << std::endl; 

    //**************************************************iterate all matcheds****************************************************
    //sregex_iterator
    //sregex_token_iterator
    std::string::const_iterator pos = data.cbegin();
    std::string::const_iterator end = data.cend();
    std::size_t match_cnt = 0;
    for (; std::regex_search(pos, end, match_result, reg); pos += (match_result.prefix().length() + match_result.length())){
        match_cnt++;
        std::cout << "match " << match_cnt << " detail: " << std::endl;
        std::cout << "str: " << match_result.str() << std::endl;
        std::cout << "length: " << match_result.length() << std::endl;
        std::cout << "pos: " << match_result.position() << std::endl;
        std::cout << "prefix str: " << match_result.prefix().str() << std::endl;
        std::cout << "suffix str: " << match_result.suffix().str() << std::endl;
    }
    std::cout << std::endl << std::endl; 

    std::cout << "iterate over all match using sregex_iterator:" << std::endl;
    match_cnt = 0;
    std::sregex_iterator reg_itr(data.cbegin(), data.cend(), reg);
    std::sregex_iterator reg_itr_end;
    for (; reg_itr != reg_itr_end; reg_itr++){
        match_cnt++;
        std::cout << "match " << match_cnt << " detail: " << std::endl;
        std::cout << "str: " << reg_itr->str() << std::endl;
        std::cout << "length: " << reg_itr->length() << std::endl;
        std::cout << "pos: " << reg_itr->position() << std::endl;
        std::cout << "prefix str: " << reg_itr->prefix().str() << std::endl;
        std::cout << "suffix str: " << reg_itr->suffix().str() << std::endl;
    }
    std::cout << std::endl << std::endl;

    match_cnt = 0;
	std::cout << "iterate over all match using sregex_token_iterator:" << std::endl;
	std::sregex_token_iterator reg_token_itr(data.cbegin(), data.cend(), reg, {0, 2});
	std::sregex_token_iterator reg_tokent_itr_end;
	for (; reg_token_itr != reg_tokent_itr_end; ++reg_token_itr){
		match_cnt++;
        std::cout << "match " << match_cnt << " detail: " << std::endl;
        std::cout << "str: " << reg_token_itr->str() << std::endl;
        std::cout << "length: " << reg_token_itr->length() << std::endl;
	}

    std::cout << std::endl << std::endl;
    std::string names = R"(Alice , 
    Peter, Bob; Carl,   David,      Jack,   Lee. Loren ; Michael    )";
    std::regex name_split_reg("[ \t\n]*[,;.、][ \t\n]*");
    std::cout << "split names: " << names << std::endl;
    std::sregex_token_iterator name_token_itr = std::sregex_token_iterator(names.cbegin(), names.cend(), name_split_reg, {-1});
    std::sregex_token_iterator name_token_end;
    match_cnt = 0;
    for (; name_token_itr != name_token_end; name_token_itr++){
        match_cnt++;
        std::cout << "match " << match_cnt << " detail: " << std::endl;
        std::cout << "str: " << name_token_itr->str() << std::endl;
        std::cout << "length: " << name_token_itr->length() << std::endl;
    }
    std::cout << std::endl << std::endl;

    //*************************************************replace match pattern*******************************************
    //regex_replace
    std::cout << "before replace, src str: " << data << std::endl;
    std::string replace_1  = std::regex_replace(data, reg, R"(<$1 $2 replace_1 $1/>)");
    std::cout << "after replace, dst str: " << replace_1 << std::endl;
    
    std::cout << "before replace, src str: " << data << std::endl;
    std::string replace_2 = std::regex_replace(data, reg, R"(<\1 \2 replace_2 \1/>)", std::regex_constants::format_first_only | std::regex_constants::format_sed);
    std::cout << "after replace, dst str: " << replace_2 << std::endl;

    return 0;
}
