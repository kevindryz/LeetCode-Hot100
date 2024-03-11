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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
//    	还是用双指针
        ListNode *s,*f;
        f=head;
//        这里slow指针要指向head前一个节点，自己创建一个
        s=new ListNode(0,head);
        ListNode *head2=s;
        for (int i=0; i<n; i++) f=f->next;
        while (f != nullptr)
        {
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return head2->next;
    }
};