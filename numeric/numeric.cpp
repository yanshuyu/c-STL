#include<iostream>
#include<vector>
#include<random>

std::vector<int> invoke_random_engine_n(std::default_random_engine& eng, size_t n=10); 

int main(int argc, char const *argv[])
{
    //*************************************【random engine】*************************************
    //random engine provide randomness(source of randomness)
    //random engine object has internal state, who's each () operation yield a unsigned interger number.
    std::default_random_engine def_rand_eng_a;
    std::default_random_engine def_rand_eng_b;
    std::cout << "10 random value of def_rand_eng_a: [ ";
    for( auto& num : invoke_random_engine_n(def_rand_eng_a)){
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "10 random value of def_rand_eng_b: [ ";
    for( auto& num : invoke_random_engine_n(def_rand_eng_b)){
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;



    return 0;
}



std::vector<int> invoke_random_engine_n(std::default_random_engine& eng, size_t n){
    std::vector<int> seq;
    seq.reserve(n);
    for(size_t i=1; i<=n; ++i){
        seq.push_back(eng());
    }

    return std::move(seq);
}
