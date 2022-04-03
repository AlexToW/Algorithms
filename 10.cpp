/*
    https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/


#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>

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
void AssertEqual(const A& a, const B& b) {
    if(a != b) {
        std::cerr << a << " != " << b << std::endl;
        throw std::runtime_error("");
    }
}

class Solution {
public:
    string reverseWords(string s) {
        for(size_t i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                size_t j = i;
                while(j < s.length() && s[j] != ' ') {
                    j++;
                }
                reverse(begin(s) + i, begin(s) + j);
                i = j - 1;
            }
        }
        return s;
    }
};


void TestAll() {
    int failed = 0;
    {
        Solution sol;
        string s = "da ad";
        string res = "ad da";
        try {
            AssertEqual(sol.reverseWords(s), res);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "No oh";
        string res = "oN ho";
        try {
            AssertEqual(sol.reverseWords(s), res);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "Let's take LeetCode contest";
        string res = "s'teL ekat edoCteeL tsetnoc";
        try {
            AssertEqual(sol.reverseWords(s), res);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "God Ding";
        string res = "doG gniD";
        try {
            AssertEqual(sol.reverseWords(s), res);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    if(failed == 0) {
        std::cerr << "All test passed!" << std::endl;
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