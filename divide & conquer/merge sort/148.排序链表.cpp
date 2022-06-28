/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;

        int len = 0;
        auto t = head;
        while(t){
            ++len;
            t = t->next;
        }

        ListNode dummy_node;
        dummy_node.next = head;

        ListNode* left = nullptr;
        ListNode* right = nullptr;
        ListNode* cur = nullptr;
        auto node = &dummy_node;

        for (int i = 1; i < len; i *= 2){
            cur = node->next;
            auto tail = node;
            while(cur){
                left = cur;
                right = Cut(left, i);
                cur = Cut(right, i);

                auto res = Merge(left, right);
                tail->next = res;
                while(tail->next){
                    tail = tail->next;
                }
            }
        }
        return dummy_node.next;
    }
    /**
     * @brief 切链函数
     * 
     * @param node 起始链表位置
     * @param size 所需要切的长度
     * @return ListNode* 切完传入链表后的下一个指针位置
     */

    ListNode* Cut(ListNode* node, size_t size){
        auto p = node;
        while(--size && p){
            p = p->next;
        }

        if (!p) return nullptr;

        auto p_1 = p->next;
        p->next = nullptr;
        return p_1;
    }

    /**
     * @brief 合并函数
     * 
     * @param left 左区间链表
     * @param right 右区间链表
     * @return ListNode* 合并后的链表
     */

    ListNode* Merge(ListNode* left, ListNode* right){
        ListNode dummy_node;
        auto node_tmp = &dummy_node;

        while(left && right){
            if (left->val >= right->val){
                node_tmp->next = right;
                right = right->next;
            }else{
                node_tmp->next = left;
                left = left->next;
            }
            node_tmp = node_tmp->next;
        }
        if (left)
            node_tmp->next = left;
        else
            node_tmp->next = right;

        return dummy_node.next;
    }
};
// @lc code=end