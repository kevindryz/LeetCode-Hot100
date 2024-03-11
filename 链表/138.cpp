/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* now=head;
        unordered_map<Node*,Node*> hash;
//        哈希存储，遍历深拷贝
        while (now != nullptr)
        {
            hash[now]=new Node(now->val);
            now=now->next;
        }
        now=head;
        while (now != nullptr)
        {
            hash[now]->next=hash[now->next];
            hash[now]->random=hash[now->random];
            now=now->next;
        }
        return hash[head];
         
    }
};