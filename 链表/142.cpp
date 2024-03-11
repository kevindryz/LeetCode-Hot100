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
    ListNode *detectCycle(ListNode *head) {
//    	快慢指针的方法
        ListNode *s,*f;
        s=head;f=head;
        while (1)
        {
            if (f == nullptr || f->next == nullptr) return nullptr;
            f=f->next->next;
            s=s->next;
//            假设slow走了s步,相遇时fast走了s+nb步(b是环的长度),所以s=nb,slow指针再走a步才能到环的开始节点
//            head和slow指针当前位置一起走，总会碰到，碰到的点就是环开始节点
            if (f == s)
            {
                ListNode* ptr=head;
                while (ptr != s)
                {
                    ptr=ptr->next;
                    s=s->next;
                }
                return s;
            }
        }
        
    }
};