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
    }
}

class Solution {
public:
void reverseWord(string& s, string::iterator l_it, string::iterator r_it) {
        if(s.size() == 1) {
            return;
        }
        auto l = l_it;
        auto r = r_it;
        cout << "To reverseWord: ";
        for(auto it = l_it; it != r_it; ++it) {
            cout << *it;
        }
        cout << endl;
        while(l <= r) {
            char tmp = *l;
            *l = *r;
            *r = tmp;
            l++;
            r--;
        }
        cout << "From reverseWord: ";
        for(auto it = l_it; it != r_it; ++it) {
            cout << *it;
        }
        cout << endl;
    }
    string reverseWords(string s) {
        string res = s;
        auto space_it_f = find(begin(res), end(res), ' ');
        auto space_it_l = find(space_it_f+1, end(res), ' ');
        while(space_it_l < end(res)) {
            reverseWord(res, space_it_f, space_it_l);
            space_it_f = space_it_l;
            space_it_l = find(space_it_f+1, end(res), ' ');
        }
        cout << "res: " << res << endl;
        return res;
    }
};

void TestAll() {
    {
        Solution sol;
        string s = "da ad";
        string res = "ad da";
        AssertEqual(sol.reverseWords(s), res);
    }
    {
        Solution sol;
        string s = "No oh";
        string res = "oN ho";
        AssertEqual(sol.reverseWords(s), res);
    }
    {
        Solution sol;
        string s = "Let's take LeetCode contest";
        string res = "s'teL ekat edoCteeL tsetnoc";
        AssertEqual(sol.reverseWords(s), res);
    }
    {
        Solution sol;
        string s = "God Ding";
        string res = "doG gniD";
        AssertEqual(sol.reverseWords(s), res);
    }
}

int main() {
    TestAll();
    return 0;
}