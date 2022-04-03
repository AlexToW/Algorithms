/*
    https://leetcode.com/problems/first-bad-version/
*/

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

#define DEBUG
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    bool isBadVersion(int n) {
        return n >= target;
    }

    int firstBadVersion(int n) {
        int start = 1, finish = n;
        int middle = 0;
        while(start < finish) {
            middle = static_cast<int>((static_cast<int64_t>(start) + static_cast<int64_t>(finish)) / 2);
            bool isBad = isBadVersion(middle);
            if(isBad) {
                finish = middle;
            } else {
                start = middle + 1;
            }
        }
        #ifdef DEBUG
            cout << start << endl;
        #endif
        return start;
    }
    int target;
};

void TestAll() {
    {
        Solution sol;
        sol.target = 4;
        assert(sol.firstBadVersion(6) == sol.target);
    }
    {
        Solution sol;
        sol.target = 2;
        assert(sol.firstBadVersion(6) == sol.target);
    }
    {
        Solution sol;
        sol.target = 17;
        assert(sol.firstBadVersion(2576) == sol.target);
    }
}


int main() {
    TestAll();
    return 0;
}