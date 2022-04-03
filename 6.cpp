/*
    https://leetcode.com/problems/rotate-array/
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

/*
template <class T>
bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
    if(lhs.size() != rhs.size()) {
        return false;
    }
    for(size_t i = 0; i < lhs.size(); i++) {
        if(lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= static_cast<int>(nums.size());
        if(k == 0) {
            return;
        }
        nums.insert(begin(nums), end(nums) - k, end(nums));
        nums.erase(end(nums) - k, end(nums));
    }

    void rotate_accepted(vector<int>& nums, int k) 
        {
            int n = nums.size();
            k = k%n;
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            reverse(begin(nums), begin(nums) + n - k);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
            reverse(begin(nums) + n - k, begin(nums) + n);
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            reverse(begin(nums), begin(nums) + n);
        }
};


void TestAll() {
    {
        Solution sol;
        vector<int> nums = {1, 2, 3, 4, 5, 6};
        vector<int> res = {5, 6, 1, 2, 3, 4};
        sol.rotate(nums, 2);
        assert(nums == res);
    }
    {
        Solution sol;
        vector<int> nums = {1,2,3,4,5,6,7};
        vector<int> res = {5,6,7,1,2,3,4};
        sol.rotate(nums, 3);
        assert(nums == res);
    }
    {
        Solution sol;
        vector<int> nums = {-1, -100, 3, 99};
        vector<int> res = {3, 99, -1, -100};
        sol.rotate(nums, 2);
        assert(nums == res);
    }
    {
        Solution sol;
        vector<int> nums = {1, 2, 3};
        vector<int> res = {3, 1, 2};
        sol.rotate(nums, 1);
        assert(nums == res);
    }
}


int main() {
    TestAll();
    return 0;
}