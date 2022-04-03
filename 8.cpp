/*
    https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
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
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res = {0, 0};
        size_t l = 0, r = numbers.size() - 1;
        while(l < r) {
            if(numbers[l] + numbers[r] == target) {
                res[0] = l+1;
                res[1] = r+1;
                return res;
            } else if(numbers[l] + numbers[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};


void TestAll() {
    {
        Solution sol;
        vector<int> v = {2, 7, 11, 15};
        int target = 9;
        vector<int> res = {1, 2};
        AssertEqual(sol.twoSum(v, target), res);
    }
    {
        Solution sol;
        vector<int> v = {2, 3, 4};
        int target = 6;
        vector<int> res = {1, 3};
        AssertEqual(sol.twoSum(v, target), res);
    }
    {
        Solution sol;
        vector<int> v = {-1, 0};
        int target = -1;
        vector<int> res = {1, 2};
        AssertEqual(sol.twoSum(v, target), res);
    }
    {
        Solution sol;
        vector<int> v = {0, 0, 1, 2};
        int target = 0;
        vector<int> res = {1, 2};
        AssertEqual(sol.twoSum(v, target), res);
    }
    {
        Solution sol;
        vector<int> v = {5, 25, 75};
        int target = 100;
        vector<int> res = {2, 3};
        AssertEqual(sol.twoSum(v, target), res);
    }
    {
        Solution sol;
        vector<int> v(9, -1);
        v.push_back(1);
        v.push_back(1);
        int target = 2;

        vector<int> res = {static_cast<int>(v.size())-1, static_cast<int>(v.size())};
        AssertEqual(sol.twoSum(v, target), res);
    }
}

int main() {
    TestAll();
    return 0;
}