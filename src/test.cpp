#include <bits/stdc++.h>
#include "bloom_filters.cpp"

using namespace std;

string list_of_strings[] = { "horse", "cantaloupe", "apple", "orange", "prepostrous", "banana", "yikes", "bounded", "boundless", "entropy", "stock", "empathy" };

string test_strings[] = { "cheat", "lie", "horse", "illegal", "law", "enforcementP", "agency", "bounded", "expectopatronam", "wingardiumleviosa", "stock", "empathy"};

int main(){
    BloomFilter bf(100, 3);
    for(int i = 0; i < sizeof(list_of_strings)/sizeof(list_of_strings[0]); i++) {
        bf.add(list_of_strings[i]);
    }
    for(int i = 0; i < sizeof(test_strings)/sizeof(list_of_strings[0]); i++) {
        cout << "Test String: " << test_strings[i] << "\t" << "Probability of already existing: " << bf.probability(test_strings[i]) << "%" << endl;
    }
    return 0;
}
