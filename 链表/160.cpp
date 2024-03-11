/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *stA=headA,*stB=headB;
        unordered_set<ListNode *> hash;
//        空指针用nullptr
        while (stA != nullptr)
        {
            hash.insert(stA);
            stA=stA->next;
        }
        while (stB != nullptr)
        {
            if (hash.count(stB)) return stB;
            stB=stB->next;
        }
        return nullptr;
    }
};