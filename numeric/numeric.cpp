#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<sstream>
#include<map>

std::vector<int> invoke_random_engine_n(std::default_random_engine& eng, size_t n=10); 

template<typename distruType, typename engType>
std::map<long, int> random_distrubited(distruType& distru, engType& eng, const size_t max=200000);

int main(int argc, char const *argv[])
{
    //*************************************【random engine】*************************************
    //random engine provide randomness(source of randomness)
    //random engine object has internal state, who's each () operation yield a unsigned interger number.
    //random endine objects with same internal state(set seed of it can change internal state) yield same
    //random value sequence


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

    std::default_random_engine def_rand_end_with_seed(std::time(nullptr));
    std::cout << "10 random value of def_rand_end_with_seed: [ ";
    for( auto& num : invoke_random_engine_n(def_rand_end_with_seed)){
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    //save and restore random engine internal state
    std::stringstream ss;
    ss << def_rand_end_with_seed;
    std::cout << "internal state of def_rand_end_with_seed: " << ss.str() << std::endl;

    std::cout << "5 random value of def_rand_end_with_seed: [ ";
    for( auto& num : invoke_random_engine_n(def_rand_end_with_seed, 5)){
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl; 
    
    ss >> def_rand_end_with_seed;

    std::cout << "5 random value of def_rand_end_with_seed: [ ";
    for( auto& num : invoke_random_engine_n(def_rand_end_with_seed, 5)){
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl; 

    //random number distrubition
    const size_t MAX = 200000;
    std::uniform_int_distribution<> int_distru(0,10);
    std::uniform_real_distribution<> real_distru(0, 10);
    std::normal_distribution<> normal_distru;
    std::exponential_distribution<> expo_distru;
    std::gamma_distribution<> gama_distru;


    std::cout << std::endl;
    std::cout << "线性分布:" << std::endl;
    std::cout << " -min: " << int_distru.min() << std::endl; 
    std::cout << " -max: " << int_distru.max() << std::endl; 
    std::cout << " -distrubition: " << std::endl;
    for (auto& counter : random_distrubited(int_distru, def_rand_end_with_seed, MAX)){
        std::cout << counter.first << "   " << counter.second << "  " << counter.second / double(MAX) << std::endl;
    } 
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "线性分布:" << std::endl;
    std::cout << " -min: " << real_distru.min() << std::endl; 
    std::cout << " -max: " << real_distru.max() << std::endl; 
    std::cout << " -distrubition: " << std::endl;
    for (auto& counter : random_distrubited(real_distru, def_rand_end_with_seed, MAX)){
        std::cout << counter.first << "   " << counter.second << "  " << counter.second / double(MAX) << std::endl;
    } 

    std::cout << std::endl;
    std::cout << "正太分布:" << std::endl;
    std::cout << " -min: " << normal_distru.min() << std::endl; 
    std::cout << " -max: " << normal_distru.max() << std::endl; 
    std::cout << " -distrubition: " << std::endl;
    for (auto& counter : random_distrubited(normal_distru, def_rand_end_with_seed, MAX)){
        std::cout << counter.first << "   " << counter.second << "  " << counter.second / double(MAX) << std::endl;
    } 
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "泊松分布:" << std::endl;
    std::cout << " -min: " << expo_distru.min() << std::endl; 
    std::cout << " -max: " << expo_distru.max() << std::endl; 
    std::cout << " -distrubition: " << std::endl;
    for (auto& counter : random_distrubited(expo_distru, def_rand_end_with_seed, MAX)){
        std::cout << counter.first << "   " << counter.second << "  " << counter.second / double(MAX) << std::endl;
    } 
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "泊松分布(gama):" << std::endl;
    std::cout << " -min: " << gama_distru.min() << std::endl; 
    std::cout << " -max: " << gama_distru.max() << std::endl; 
    std::cout << " -distrubition: " << std::endl;
    for (auto& counter : random_distrubited(gama_distru, def_rand_end_with_seed, MAX)){
        std::cout << counter.first << "   " << counter.second << "  " << counter.second / double(MAX) << std::endl;
    } 
    std::cout << std::endl;


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


template<typename distruType, typename engType>
std::map<long, int> random_distrubited(distruType& distru, engType& eng, const size_t max){
    std::map<long, int> counter;
    for(size_t i=0; i< max; ++i){
        counter[distru(eng)]++;
    }
    return std::move(counter);
}


