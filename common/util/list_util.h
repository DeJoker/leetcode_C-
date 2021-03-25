#ifndef __LIST_UTIL_H_
#define __LIST_UTIL_H_

#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


inline ListNode* CreateList(std::vector<int> path)
{
    ListNode *head, *cur(nullptr);
    for(auto n : path) {
        ListNode* p = new ListNode(n);
        if (cur==nullptr) {
            head = p;
            cur = p;
        } else {
            cur->next = p;
            cur = p;
        }
    }
    return head;
}



#endif
