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
    ListNode* removeNthfromBegin(ListNode* head, int n) {
        if(n == 0) {
            return head->next;
        }
        int cnt = 0;
        ListNode* prev = head;
        ListNode* tmp = head;
        while(cnt != n) {
            prev = tmp;
            tmp = tmp->next;
            cnt++;
        }
        prev->next = tmp->next;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 1;
        ListNode* h = head;
        while(h->next) {
            l++;
            h = h->next;
        }
        //cout << l << endl;
        //cout << l - n << endl;
        if(l == 1) {
            return NULL;
        }
        return removeNthfromBegin(head, l - n);
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