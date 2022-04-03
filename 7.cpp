/*
    https://leetcode.com/problems/move-zeroes/
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
    void moveZeroes(vector<int>& nums) {
        auto zero_it = find(begin(nums), end(nums), 0);
        int cnt = 0;
        while(zero_it != end(nums)) {
            cnt++;
            nums.erase(zero_it);
            zero_it = find(begin(nums), end(nums), 0);
        }
        for(int i = 0; i < cnt; i++) {
            nums.push_back(0);
        }
    }

    void moveZeroesBetter(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        // If the current element is not 0, then we need to
        // append it just in front of last non 0 element we found. 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        // After we have finished processing new elements,
        // all the non-zero elements are already at beginning of array.
        // We just need to fill remaining array with 0's.
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    void moveZeroesOptimal(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};



void TestAll() {
    {
        Solution sol;
        vector<int> v = {0, 1, 0, 3, 12};
        vector<int> res = {1, 3, 12, 0, 0};
        sol.moveZeroes(v);
        AssertEqual(v, res);
    }
    {
        Solution sol;
        vector<int> v = {0};
        vector<int> res = {0};
        sol.moveZeroes(v);
        AssertEqual(v, res);
    }
}


int main() {
    TestAll();
    return 0;
}