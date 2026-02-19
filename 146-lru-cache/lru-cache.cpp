class LRUCache {
public:
    class Node{
        public :
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
     int cap;
    unordered_map<int, Node*> mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
       if(mpp.find(key)==mpp.end()) return -1;
       Node *node=mpp[key];
       deleteNode(node);
       insertAfterHead(node);
       int ans=node->val;
       return ans;
    }
     void insertAfterHead(Node *newnode){
         Node* temp = head -> next;
          newnode -> next = temp;
        newnode -> prev = head;
           head -> next = newnode;
        temp -> prev = newnode;
    }
     void deleteNode(Node* delnode){
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(mpp.size()==cap){
                Node* node=tail->prev;
                mpp.erase(node->key);
                 deleteNode(node);
            }
            Node *node=new Node(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */