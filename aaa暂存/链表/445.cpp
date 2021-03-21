#include "../common/debugger.h"
#include "../util/list_util.h"

class Solution {
public:
    // 逆序应该直接想到用栈
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        for(ListNode* it=l1; it!=nullptr; it=it->next)
            st1.push(it->val);
        for(ListNode* it=l2; it!=nullptr; it=it->next)
            st2.push(it->val);
        
        ListNode *tail(nullptr);
        int digit(0);

        auto ff = [&](ListNode* iter) {
            if(st1.empty()) {
                iter = new ListNode(st2.top());
                st2.pop();
            } else if (st2.empty()) {
                iter = new ListNode(st1.top());
                st1.pop();
            } else {
                digit += st2.top() + st1.top();
                iter = new ListNode(digit%10);
                digit /= 10;
                st1.pop(); st2.pop();
            }
        };
        ff(tail);
        ListNode *p=tail;

        while(!st1.empty() || !st2.empty()) {
            ListNode *cur;
            ff(cur);
            cur->next = p;
            p = cur;
        }
        if (digit) {
            ListNode* cur = new ListNode(digit);
            cur->next = p;
            p = cur;
        }
        return p;
    }
};


// 使用lambda表达式有误？？？
// [8,2,4,3,4,6,7,5,3]
// 我的答案[1,7,2,4,3,4,6,7,5,3]
class Solution33 {
public:
    // 逆序应该直接想到用栈
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        for(ListNode* it=l1; it!=nullptr; it=it->next)
            st1.push(it->val);
        for(ListNode* it=l2; it!=nullptr; it=it->next)
            st2.push(it->val);
        
        ListNode *tail(nullptr);
        int digit(0);

        auto ff = [&](ListNode*& iter) {
            if(st1.empty()) {
                iter = new ListNode(st2.top());
                st2.pop();
            } else if (st2.empty()) {
                iter = new ListNode(st1.top());
                st1.pop();
            } else {
                digit += st2.top() + st1.top();
                iter = new ListNode(digit%10);
                digit /= 10;
                st1.pop(); st2.pop();
            }
        };
        ff(tail);
        ListNode *p=tail;

        while(!st1.empty() || !st2.empty()) {
            ListNode *cur;
            ff(cur);
            cur->next = p;
            p = cur;
        }
        if (digit) {
            ListNode* cur = new ListNode(digit);
            cur->next = p;
            p = cur;
        }
        return p;
    }
};

