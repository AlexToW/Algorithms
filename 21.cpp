/*
    https://leetcode.com/problems/climbing-stairs/
*/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        vector<int> v(n);
        v[0] = 1;
        v[1] = 2;
        for(int i = 2; i < n; i++) {
            v[i] = v[i-1] + v[i-2];
        }
        cout << v[v.size()-1] << endl;
        return v.back();
    }
};


void TestAll() {
    {
        Solution sol;
        int n = 2;
        assert(sol.climbStairs(n) == 2);
    }
    {
        Solution sol;
        int n = 3;
        assert(sol.climbStairs(n) == 3);
    }
    {
        Solution sol;
        int n = 4;
        assert(sol.climbStairs(n) == 3);
    }
}


int main() {
    TestAll();
    return 0;
}