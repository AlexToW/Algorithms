/*
    https://leetcode.com/problems/permutation-in-string/
*/
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    if(v.empty()) {
        return os << "Empty!";
    }
    os << "{";
    for(size_t i = 0; i < v.size(); i++) {
        os << v[i];
        if(i == v.size() - 1) {
            os << "}";
        } else {
            os << ", ";
        }
    }
    return os;
}

template <class A, class B>
ostream& operator<<(ostream& os, const std::map<A, B>& m) {
    os << "{";
    auto en = end(m);
    en--;
    for(auto it = begin(m); it != end(m); ++it) {
        os << "{" << (*it).first << "," << (*it).second << "}";
        if(it != en) {
            os << ",";
        }
    }
    os << "}";
    return os;
}


template <class A, class B>
void AssertEqual(const A& a, const B& b) {
    if(a != b) {
        std::cerr << a << " != " << b << std::endl;
        throw std::runtime_error("");
    }
}

class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) {
            return false;
        }
        vector<int> v1(26, 0), v2(26, 0);
        for(size_t i = 0; i < s1.length(); i++) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        for(size_t i = 0; i < s2.length() - s1.length(); ++i) {
            if(v1 == v2) {
                return true;
            }
            v2[s2[i + s1.length()] - 'a']++;
            v2[s2[i] - 'a']--;
        }
        return v1 == v2;
    }
};

#define TESTDESCR
void TestAll() {
    int failed = 0;

    {
        Solution sol;
        string s1 = "dinitrophenylhydrazine", s2 = "dimethylhydrazine";
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.checkInclusion(s1, s2), false);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s1 = "adc", s2 = "dcda";
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.checkInclusion(s1, s2), true);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s1 = "ba", s2 = "eidbaooo";
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.checkInclusion(s1, s2), true);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s1 = "ba", s2 = "eidboaooo";
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.checkInclusion(s1, s2), false);
        } catch (runtime_error& e) {
            failed++;
        }
    }

    if(failed == 0) {
        std::cerr << "All tests passed!" << std::endl;
    } else if(failed == 1){
        std::cerr << failed << " test failed!" << std::endl;
        exit(1);
    } else {
        std::cerr << failed << " test failed!" << std::endl;
        exit(1);
    }
}


int main() {
    TestAll();
    return 0;
}