/*
    https://leetcode.com/problems/max-area-of-island/
*/

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>

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
ostream& operator<<(ostream& os, const std::map<A, B>& m) {
    os << "{";
    auto en = end(m);
    en--;
    for(auto it = begin(m); it != end(m); ++it) {
        os << "{" << (*it).first << "," << (*it).second << "}";
        if(it != en) {
            os << ",";
        }
    }
    os << "}";
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
    bool InRange(vector<vector<int>>& image, int i, int j) {
        return !(i < 0 || (size_t)i >= image.size() || j < 0 || (size_t)j >= image[0].size());
    }

    int MaxArea(vector<vector<int>>& grid, int x0, int y0) {
        if(grid[x0][y0] == 0 || grid[x0][y0] == 2) {
            return 0;
        }
        int res = 1;
        queue<pair<int, int>> q;
        q.push({x0, y0});

        while(!q.empty()) {
            auto p = q.front();
            grid[p.first][p.second] = 2; // 2 <==> already visited
            q.pop();
            int x = p.first, y = p.second;
            if(InRange(grid, x+1, y) && grid[x+1][y] == 1) {
                res++;
                grid[x+1][y] = 2;
                q.push({x+1, y});
            }
            if(InRange(grid, x-1, y) && grid[x-1][y] == 1) {
                res++;
                grid[x-1][y] = 2;
                q.push({x-1, y});
            }
            if(InRange(grid, x, y+1) && grid[x][y+1] == 1) {
                res++;
                grid[x][y+1] = 2;
                q.push({x, y+1});
            }
            if(InRange(grid, x, y-1) && grid[x][y-1] == 1) {
                res++;
                grid[x][y-1] = 2;
                q.push({x, y-1});
            }
            //cout << grid << endl;
            //cout << res << endl;
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for(int x = 0; x < (int)grid.size(); x++) {
            for(int y = 0; y < (int)grid[0].size(); y++) {
                if(grid[x][y] == 1) {
                    int tmp = MaxArea(grid, x, y);
                    if(tmp > max) {
                        max = tmp;
                    }
                }
            }
        }
        return max;
    }
};

//#define TESTDESCR
void TestAll() {
    int failed = 0;

    {
        Solution sol;
        vector<vector<int>> grid = {
            {0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,1,1,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0}
        };
        try {
            AssertEqual(sol.maxAreaOfIsland(grid), 6);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        vector<vector<int>> grid = {
            {0,0,1,0,0,0,0,1,0,0,0,0,0}
        };
        try {
            AssertEqual(sol.maxAreaOfIsland(grid), 1);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        vector<vector<int>> grid = {
            {0,0,0,0,0,0,0,0,0,0,0,0,0}
        };
        try {
            AssertEqual(sol.maxAreaOfIsland(grid), 0);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        vector<vector<int>> grid = {
            {1,1,0,0,0},
            {1,1,0,1,1},
            {0,0,0,1,1},
            {0,0,0,1,1}
        };
        try {
            AssertEqual(sol.maxAreaOfIsland(grid), 6);
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