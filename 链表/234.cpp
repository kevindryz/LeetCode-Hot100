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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* now=head;
//        简单遍历的方法，这里用了emplace_back
        while (now != nullptr)
        {
            v.emplace_back(now->val);
            now=now->next;
        }
        for (int i=0; i<v.size(); i++)
        {
            if (v[i] == v[v.size()-1-i]) continue;
            else return 0;
        }
        return 1;
    }
};