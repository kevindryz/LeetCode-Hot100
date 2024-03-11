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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head,*now;
        head=now=nullptr;
        int flag=0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int a,b;
            if (l1 == nullptr) a=0;
            else a=l1->val;
            if (l2 == nullptr) b=0;
            else b=l2->val;
            if (head == nullptr)
            {
//            	只有一个int，直接给val赋初值就行
                head=now=new ListNode((a+b+flag)%10);
            }
            else{
                now->next=new ListNode((a+b+flag)%10);
                now=now->next;
            }
            flag=(a+b+flag)/10;
            if (l1 != nullptr) l1=l1->next;
            if (l2 != nullptr) l2=l2->next;
        }
        if (flag) now->next=new ListNode(flag);
        return head;
    }
};