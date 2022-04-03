/*
    https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
        throw std::runtime_error("");
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // необходим 1 проход по списку
        if(!head) {
            return nullptr;
        }
        ListNode head_of_head(-1);
        head_of_head.next = head;
        
        ListNode* first = &head_of_head;
        ListNode* last = &head_of_head;
        for(int i = 0; i < n; i++) {
            first = first->next;
        }
        while(first->next) {
            first = first->next;
            last = last->next;
        }
        last->next = last->next->next;
        return head_of_head.next;
    }
};


void TestAll() {
    int failed = 0;
    {
        Solution sol;
        ListNode head(1);
        ListNode n1(2);
        ListNode n2(3);
        ListNode n3(4);
        ListNode n4(5);
        head.next = &n1;
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        try {
            AssertEqual(sol.removeNthFromEnd(&head, 2), &head);
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