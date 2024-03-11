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
//	这里是自己定义的一个Reverse函数
    pair<ListNode*,ListNode*> Reverse(ListNode* head,ListNode* tail)
    {
        ListNode* nxt=tail->next;
        ListNode* now=head;
//        如果后面一个已经到tail了，就可以直接返回，不然又会回去
        while (nxt != tail)
        {
            ListNode* tem=now->next;
            now->next=nxt;
            nxt=now;
            now=tem;
        }
        return {tail,head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dhead=new ListNode(0,head);
        ListNode *pre=dhead;
        while (pre != nullptr)
        {
            ListNode *tail=pre;
            for (int i=0; i<k; i++)
            {
                tail=tail->next;
                if (tail == nullptr) return dhead->next;
            }
            ListNode *tem=tail->next;
//            用pair存储头和尾结点
            pair<ListNode*,ListNode*> p=Reverse(head,tail);
            pre->next=p.first;
            p.second->next=tem;
            head=p.second->next;
            pre=p.second;
        }
        return dhead->next;

    }
};