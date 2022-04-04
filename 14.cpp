/*
    https://leetcode.com/problems/flood-fill/
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

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc]) {
            return image;
        }
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int old_color = image[sr][sc];
        while(!q.empty()) {
            auto p = q.front();
            image[p.first][p.second] = newColor;
            q.pop();
            int x = p.first, y = p.second;
            if(InRange(image, x+1, y) && image[x+1][y] == old_color) {
                q.push({x+1, y});
            }
            if(InRange(image, x-1, y) && image[x-1][y] == old_color) {
                q.push({x-1, y});
            }
            if(InRange(image, x, y+1) && image[x][y+1] == old_color) {
                q.push({x, y+1});
            }
            if(InRange(image, x, y-1) && image[x][y-1] == old_color) {
                q.push({x, y-1});
            }
            //cout << image << endl;
        }
        return image;
    }
};

//#define TESTDESCR
void TestAll() {
    int failed = 0;

    {
        Solution sol;
        vector<vector<int>> image = {
            {1, 1, 1},
            {1, 1, 0},
            {1, 0, 1}
        };
        int sr = 1, sc = 1;
        vector<vector<int>> res = {
            {2, 2, 2},
            {2, 2, 0},
            {2, 0, 1}
        };
        int NewColor = 2;
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.floodFill(image,sr, sc, NewColor), res);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        vector<vector<int>> image = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        };
        int sr = 1, sc = 1;
        vector<vector<int>> res = {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}
        };
        int NewColor = 2;
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.floodFill(image,sr, sc, NewColor), res);
        } catch (runtime_error& e) {
            failed++;
        }
    }
    {
        Solution sol;
        vector<vector<int>> image = {
            {0, 0, 0},
            {0, 1, 1}
        };
        int sr = 1, sc = 1;
        vector<vector<int>> res = {
            {0, 0, 0},
            {0, 1, 1}
        };
        int NewColor = 1;
        #ifdef TESTDESCR
            cout << "Test: s1 = '" << s1 << "', s2 = '" << s2 << "'" << endl;
        #endif
        try {
            AssertEqual(sol.floodFill(image,sr, sc, NewColor), res);
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