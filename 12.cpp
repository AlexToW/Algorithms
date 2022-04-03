/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <unordered_set>

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
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        if(s.length() == 1) {
            return 1;
        }
        // Sliding Window
        size_t max_l = 0;
        //size_t wind_size = 2;
        unordered_set<char> wind;
        size_t left = 0, right = 0;
        while(left < s.length() && right < s.length()) {
            if(wind.find(s[right]) == wind.end()) {
                wind.insert(s[right]);
                right++;
                max_l = max(max_l, wind.size());
            } else {
                wind.erase(s[left]);
                left++;
            }
        }
        return max_l;
    }
};


//#define TESTDESCR
void TestAll() {
    int failed = 0;
    {
        Solution sol;
        string s = "aab";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 2);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 0);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "abcabcbb";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 3);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "aaaaa";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 1);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "asdfgh";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 6);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "pwwkew";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 3);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        string s = "a";
        #ifdef TESTDESCR
            cout << "Test: s = '" << s << "'" << endl;
        #endif
        try {
            AssertEqual(sol.lengthOfLongestSubstring(s), 1);
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