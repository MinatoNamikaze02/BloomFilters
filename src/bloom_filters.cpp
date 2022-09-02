#include "bloom_filters.h"
#include "murmur.cpp"
#include<bits/stdc++.h>

BloomFilter::BloomFilter(int m, int k) {
    this->bits = std::vector<bool>(m, false);
    this->num_hashes = k;
    this->num_of_elements = 0;
}

BloomFilter::~BloomFilter(){
    this->bits.clear();
}

void BloomFilter::add(std::string s) {
    for(uint32_t count = 0; count < this->num_hashes; count++) {
        int hash = MurMurHash::murmur3_32((uint8_t*)s.c_str(), s.length(), count) % this->bits.size();
        this->bits[hash] = true;
    }
    this->num_of_elements++;
}

bool BloomFilter::contains(std::string s){
    for(uint32_t count = 0; count < this->num_hashes; count++) {
        int hash = MurMurHash::murmur3_32((uint8_t*)s.c_str(), s.length(), count) % this->bits.size();
        if(!this->bits[hash]) {
            return false;
        }
    }
    return true;
}

void BloomFilter::print() {
    for(int i = 0; i < this->bits.size(); i++) {
        std::cout << this->bits[i] << " ";
    }
    std::cout << std::endl;
}

double BloomFilter::probability(std::string s){
    bool is_contains = this->contains(s);
    if(is_contains) {
        int m = this->bits.size();
        int k = this->num_hashes;
        int n = this->num_of_elements;
        return (1.0 - pow((1.0 - 1.0/m), k * n)) * 100;
    }
    return 0.0;
}
