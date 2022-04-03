/*
    https://leetcode.com/problems/reverse-string/
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
    }
}

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() == 1) {
            return;
        }
        size_t l = 0, r = s.size() - 1;
        while(l <= r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};


void TestAll() {
    {
        Solution sol;
        vector<char> s = {'a', 'b'};
        vector<char> res = {'b', 'a'};
        sol.reverseString(s);
        AssertEqual(s, res);
    }
    {
        Solution sol;
        vector<char> s = {'a', 'b', 'c'};
        vector<char> res = {'c', 'b', 'a'};
        sol.reverseString(s);
        AssertEqual(s, res);
    }
    {
        Solution sol;
        vector<char> s = {'h','e','l','l','o'};
        vector<char> res = {'o', 'l', 'l', 'e', 'h'};
        sol.reverseString(s);
        AssertEqual(s, res);
    }
    {
        Solution sol;
        vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
        vector<char> res = {'h', 'a', 'n', 'n', 'a', 'H'};
        sol.reverseString(s);
        AssertEqual(s, res);
    }
    {
        Solution sol;
        vector<char> s = {'\''};
        vector<char> res = {'\''};
        sol.reverseString(s);
        AssertEqual(s, res);
    }
}


int main() {
    TestAll();
    return 0;
}