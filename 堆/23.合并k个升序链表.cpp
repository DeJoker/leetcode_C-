/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

#include "../common/debugger.h"

// @lc code=start

class Solution {
    static bool cmp(ListNode* a, ListNode* b) { return a->val > b->val; };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // lambda表达式并不能作为cmp
        // std::function<bool(ListNode* a, ListNode* b)> cmp = []

        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> pq(cmp);
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // 创建一个虚拟节点，秒啊！
        ListNode head(-1), *tail = &head;

        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            tail->next = node;
            tail = node;
            if (node->next)
                pq.push(node->next);
        }
        return head.next;
    }
};

class Solution2 {
    static bool cmp(ListNode* a, ListNode* b) { return a->val > b->val; };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head, *cur;
        // lambda表达式并不能作为cmp
        // std::function<bool(ListNode* a, ListNode* b)> cmp = []

        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> pq(cmp);
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        if (pq.empty()) {
            return nullptr;
        } else {
            head = pq.top(); pq.pop();  // 这样弹出还需要把这个节点接下来的地址补上
            cur = head;
            if (cur->next)
                pq.push(cur->next);
        }

        while(!pq.empty()) {
            auto node = pq.top(); pq.pop();
            cur->next = node;
            cur = node;
            if (node->next)
                pq.push(node->next);
        }
        return head;
    }
};
// @lc code=end

int main() {
    vector<ListNode*> p;
    p.push_back(CreateList({1,4,5,}));
    p.push_back(CreateList({1,3,4,}));
    p.push_back(CreateList({2,6,}));

    auto k = Solution().mergeKLists(p);
    DebugNode(k);
    return 0;
}

