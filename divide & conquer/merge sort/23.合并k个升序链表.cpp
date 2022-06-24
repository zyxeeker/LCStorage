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
        if (n == 0) return {};
        if (n == 1) return lists[0];

        ListNode* p = nullptr;
        ListNode* q = nullptr;
        ListNode* node_tmp = nullptr;

        for (int i = 1; i < n; ++i){
            p = lists[i-1];
            q = lists[i];

            ListNode node;
            node_tmp = &node;
            while(p != nullptr && q != nullptr){
                if (p->val <= q->val){
                    node_tmp->next = p;
                    p = p->next;
                }else{
                    node_tmp->next = q;
                    q = q->next;
                }
                node_tmp = node_tmp->next;
            }
            if (p != nullptr){
                node_tmp->next = p;
            }else{
                node_tmp->next = q;
            }
            lists[i] = node.next;
        }
        return lists[n-1];
    }
};
// @lc code=end

