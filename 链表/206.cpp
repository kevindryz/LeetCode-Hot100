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
    ListNode* reverseList(ListNode* head) {
        ListNode* headb=nullptr;
        while (head != nullptr)
        {
            ListNode* nxt=head->next;
            head->next=headb;
            headb=head;
            head=nxt;
        }
//        因为这里head指的已经是nullptr了
        return headb;

    }
};