/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        if (n == 1) return lists[0];

        auto cmp = [](const ListNode *a, const ListNode *b) { 
            if (a->val >= b->val)
                return true;
            return false;
            };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        ListNode* p = nullptr;
        
        for(int i = 0; i < n; ++i){
            p = lists[i];
            while(p){
                auto tmp = p;
                p = p->next;
                tmp->next = nullptr;
                heap.push(tmp);
            }
        }
        ListNode res;
        p = &res;
        while(!heap.empty()){
            p->next = heap.top();
            heap.pop();
            p = p->next;
        }
        return res.next;
    }
};
// @lc code=end

