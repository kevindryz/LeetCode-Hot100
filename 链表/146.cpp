struct Node{
    int key,val;
    Node *pre,*nxt;
//    在结构体里定义无初值初始化和赋值初始化 双向链表
    Node(): key(0),val(0),pre(nullptr),nxt(nullptr){};
    Node(int k,int v): key(k),val(v),pre(nullptr),nxt(nullptr){};
};

class LRUCache {
private:
    int cap=0,sum=0;
    unordered_map<int,Node*> cache;
    Node *head,*tail;


public:
    LRUCache(int capacity) {
        head=new Node();
        tail=new Node;
        head->nxt=tail;
        tail->pre=head;
        cap=capacity;

    }
    
    int get(int key) {
        if (!cache[key]) return -1;
        Node *tem=cache[key];
        moveToHead(tem);
        return tem->val;
    }

    void moveToHead(Node *node)
    {
        removeNode(node);
        addNode(node);
    }

    void removeNode(Node *node)
    {
        node->pre->nxt=node->nxt;
        node->nxt->pre=node->pre;
    }

    void addNode(Node *node)
    {
        node->pre=head;
        node->nxt=head->nxt;
        head->nxt->pre=node;
        head->nxt=node;
    }

    Node* removeTail()
    {
        Node* tem=tail->pre;
        tail->pre=tem->pre;
        tem->pre->nxt=tail;
        return tem;
    }
    
    void put(int key, int value) {
        if (!cache[key])
        {
            Node *newNode=new Node(key,value);
            cache[key]=newNode;
            addNode(newNode);
            sum++;
            if (sum > cap)
            {
                Node *tailNode=removeTail();
                cache.erase(tailNode->key);
                delete tailNode;
                sum--;
            }
        }
        else
        {
            Node* node=cache[key];
            node->val=value;
            moveToHead(node);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */