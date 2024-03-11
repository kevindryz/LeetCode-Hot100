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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dhead=new ListNode(0,head);
        ListNode *now=dhead;
//        用了迭代的方法
        while (now->next !=  nullptr && now->next->next != nullptr)
        {
            ListNode *a,*b;
            a=now->next;
            b=now->next->next;
            now->next=b;
            a->next=b->next;
            b->next=a;
            now=a;
        }
        return dhead->next;

    }
};