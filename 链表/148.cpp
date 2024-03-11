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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *s=head,*f=head->next;
        ListNode *tem=new ListNode(0);
//        快慢指针找中点
        while (f != nullptr && f->next != nullptr)
        {
            s=s->next;
            f=f->next->next;
        }
        tem=s->next;
        s->next=nullptr;
//        nlog(n)用归并排序思想进行递归
        ListNode *left=sortList(head);
        ListNode *right=sortList(tem);
        ListNode *chead=new ListNode(0);
        ListNode *now=chead;
        while (left != nullptr && right != nullptr)
        {
            if (left->val <= right->val)
            {
                now->next=left;
                left=left->next;
            }
            else
            {
                now->next=right;
                right=right->next;
            }
            now=now->next;
        }
        if (left != nullptr) now->next=left;
        else now->next=right;
        return chead->next;
    }
};