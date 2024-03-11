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
    bool hasCycle(ListNode *head) {
//    	简单哈希表遍历判定
        unordered_set<ListNode*> hash;
        while (head != nullptr)
        {
            if (hash.count(head)) return 1;
            hash.insert(head);
            head=head->next;
        }
        return 0;
    }
};