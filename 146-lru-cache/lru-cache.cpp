class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key,int value){
            this->value = value;
            this->key = key;
        }
    };

     Node* head = new Node(-1,-1);
     Node* tail = new Node(-1,-1);
     int cap;
     unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    void deletenode(Node* node){
        Node* nextt = node->next;
        Node* prevv = node->prev;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* res = m[key];         //find the address of the key using map
            int ans = res->value;       //find the value of the key using DLL                 
            m.erase(key);               //remove the key from map
            deletenode(res);            //delete the node in order to place the node at head->next
            addnode(res);
            m[key] = head->next;        //add the key back into the map with the new address
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){              //check if key is already present in the map or not
            Node* resnode = m[key];            //if it is present then we have to remove it from the map 
            m.erase(key);                      //insert fresh value
            deletenode(resnode);
        }     
        if(m.size()==cap){                      //check for the size 
            m.erase(tail->prev->key);           //if the size is equal for cap thenn erase the node behind the tail
            deletenode(tail->prev);             
        } 
        addnode(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */