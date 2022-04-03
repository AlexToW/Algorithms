/*
    https://leetcode.com/problems/squares-of-a-sorted-array/
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


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        int l_ind = 0, r_ind = len - 1;
        vector<int> sq;
        while(l_ind <= r_ind) {
            //cout << sq << endl;
            if(abs(nums[l_ind]) < abs(nums[r_ind])) {
                sq.emplace_back(nums[r_ind] * nums[r_ind]);
                r_ind--;
            } else {
                sq.emplace_back(nums[l_ind] * nums[l_ind]);
                l_ind++;
            }
        }
        //cout << sq << endl;
        reverse(begin(sq), end(sq));
        //cout << sq << endl;
        return sq;
    }
};

void TestAll() {
    {
        Solution sol;
        vector<int> v = {-4, -1, 0, 3, 10};
        auto x = sol.sortedSquares(v);
        vector<int> res = {0, 1, 9, 16, 100};
        assert(x == res);
    }
    {
        Solution sol;
        vector<int> v = {-7,-3,2,3,11};
        auto x = sol.sortedSquares(v);
        vector<int> res = {4,9,9,49,121};
        assert(x == res);
    }
    {
        Solution sol;
        vector<int> v = {-3, 4};
        auto x = sol.sortedSquares(v);
        vector<int> res = {9, 16};
        assert(x == res);
    }
}

int main() {
    TestAll();
    return 0;
}