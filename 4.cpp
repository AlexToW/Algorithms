/*
    https://leetcode.com/problems/search-insert-position/
*/
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return (res == -1) ? start : res;
    }
};


void TestAll() {
    {
        Solution sol;
        vector<int> v = {1, 2, 4, 5, 88};
        assert(sol.searchInsert(v, 77) == 4);
    }
    {
        Solution sol;
        vector<int> v = {1, 2, 4, 5, 6, 8, 9, 12, 15};
        assert(sol.searchInsert(v, 10) == 7);
    }
    {
        Solution sol;
        vector<int> v = {1, 2, 4, 5};
        assert(sol.searchInsert(v, 3) == 2);
    }
    {
        Solution sol;
        vector<int> v = {1, 2, 4, 5};
        assert(sol.searchInsert(v, 2) == 1);
    }
}

int main() {
    TestAll();
    return 0;
}