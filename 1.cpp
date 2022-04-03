/*
    https://leetcode.com/problems/isomorphic-strings/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <map>

using namespace std;


class Solution {
public:
    bool isIsomorOrder(string s, string t) {
        if(s.size() != t.size()) {
            // strings of different lengths are not exactly isomorphic
            return false;
        }

        for(size_t i = 0; i < s.size(); i++) {
            char tmp = s[i];
            vector<size_t> inds;
            inds.emplace_back(i);
            for(size_t j = i+1; j < s.size(); ++j) {
                if(s[j] == tmp) {
                    inds.emplace_back(j);
                }
            }
            if(inds.size() > 1) {
                char tmp_t = t[inds[0]];
                for(const auto ind : inds) {
                    if(t[ind] != tmp_t) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isIsomorOrder2(string s, string t) {
        if(s.size() != t.size()) {
            // strings of different lengths are not exactly isomorphic
            return false;
        }

        map<char, char> delta; // isomorphism
        size_t len = s.size();
        for(size_t i = 0; i < len; i++) {
            if(!delta.count(s[i])) {
                delta[s[i]] = t[i];
            }
        }

        for(size_t i = 0; i < len; i++) {
            s[i] = delta[s[i]];
        }
        return s == t;
    }

    bool isIsomorphic(string s, string t) {
        return isIsomorOrder2(s, t) && isIsomorOrder2(t, s);
    }
};


void TestAll() {
    {
        Solution sol;
        string s = "egg", t = "add";
        assert(sol.isIsomorphic(s, t) == true);
    }
    {
        Solution sol;
        string s = "foo", t = "bar";
        assert(sol.isIsomorphic(s, t) == false);
    }
    {
        Solution sol;
        string s = "paper", t = "title";
        assert(sol.isIsomorphic(s, t) == true);
    }
    {
        Solution sol;
        string s = "badc", t = "baba";
        assert(sol.isIsomorphic(s, t) == false);
    }
}


int main() {
    TestAll();
    return 0;
}