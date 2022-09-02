#include<bits/stdc++.h>

class BloomFilter {
        std::vector<bool> bits;
        int num_hashes;
        int num_of_elements;
    public:
        BloomFilter(int m, int k);
        ~BloomFilter();
        void add(std::string s);
        bool contains(std::string s);
        void print();
        double probability(std::string s);
};
