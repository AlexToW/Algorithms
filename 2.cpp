/*
    https://leetcode.com/problems/binary-search/
*/

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, finish = static_cast<int>(nums.size()) - 1;
        int res = -1;
        while(finish >= start) {
            size_t middle = (finish + start) / 2;
            if(target == nums[middle]) {
                res = middle;
                break;
            } else if(target > nums[middle]) {
                start = middle + 1;
            } else {
                finish = middle - 1;
            }
        }
        return res;
    }
};


void TestAll() {
    {
        cout << "Test 1\n";
        Solution sol;
        vector<int> v = {1, 2, 3, 4, 5};
        int target = 2;
        assert(sol.search(v, target) == 1);
    }
    {
        cout << "Test 2\n";
        Solution sol;
        vector<int> v = {-1,0,3,5,9,12};
        int target = 9;
        assert(sol.search(v, target) == 4);
    }
    {
        cout << "Test 3\n";
        Solution sol;
        vector<int> v = {-1,0,3,5,9,12};
        int target = 2;
        assert(sol.search(v, target) == -1);
    }
    {
        cout << "Test 4\n";
        Solution sol;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
        int target = 1;
        assert(sol.search(v, target) == 0);
    }
    {
        cout << "Test 5\n";
        Solution sol;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
        int target = 11;
        assert(sol.search(v, target) == 9);
    }
}


int main() {
    TestAll();
}