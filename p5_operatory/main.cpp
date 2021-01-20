#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include "Samochod.h"

struct cmp {
    bool operator() (const Samochod &a, const Samochod &b) const {
        return a.readPojemnosc() < b.readPojemnosc();
    }
};


int main() {
    Samochod s1(123, "bwm");
    Samochod s2(200, "");
    Samochod s3(112, "audi");

    if(!s1) std::cout<<"s1\n";
    if(!s2) std::cout<<"s1\n";

    std::vector<Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    std::sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Set: \n";

    std::set<Samochod, cmp>s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it = s.begin(); it != s.end(); ++it)
        std::cout << *it << std::endl;

    ++s1;
    std::cout<<(s1,s2)<<std::endl;
    s1=s2;
}