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
    ListNode* merge(ListNode *head1,ListNode *head2)
    {
        ListNode *chead=new ListNode(0);
        ListNode *now=chead;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                now->next=head1;
                head1=head1->next;
            }
            else
            {
                now->next=head2;
                head2=head2->next;
            }
            now=now->next;
        }
        if (head1 != nullptr) now->next=head1;
        else now->next=head2;
        return chead->next;
    }

//	遍历合并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans=new ListNode(-1e5);
        for (int i=0; i<lists.size(); i++)
        {
            ans=merge(lists[i],ans);
        }
        return ans->next;
    }
};