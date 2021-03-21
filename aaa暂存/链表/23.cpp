#include "../util/list_util.h"
#include "../common/debugger.h"


class Solution {
public:
    FindMin() {
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minData(INT_MAX), pos(-1);
        ListNode* head;
        for(int i=0; i<lists.size(); ++i) {
            if(lists[i] && minData>lists[i]->val) {
                minData =  lists[i]->val;
                head = lists[i];
                pos = i;
            }
        }
        if (minData == INT_MAX) return nullptr;
        ListNode *cur = head;
        lists[pos] = lists[pos]->next;

        for(int i=0; i<lists.size(); ++i) {
            if(lists[i] && minData>lists[i]->val) {
                minData =  lists[i]->val;
                head = lists[i];
                pos = i;
            }
        }
    }
};



