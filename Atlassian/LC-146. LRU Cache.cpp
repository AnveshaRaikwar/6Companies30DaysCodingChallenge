class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
    
};
void insertAtHead(Node* &head, Node* &tail,  int key, int value){
    if(head == NULL){
        Node* newnode = new Node(key, value);
        head = newnode;
        tail = newnode;
        return;
    }
    Node* newnode = new Node(key, value);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

int getlength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

void deleteNode(Node*& head, Node*& tail, Node* node) {
    if (node == head && node == tail) {
        // Single node in the list
        head = NULL;
        tail = NULL;
    } else if (node == head) {
        // Remove the head
        head = head->next;
        head->prev = NULL;
    } else if (node == tail) {
        // Remove the tail
        tail = tail->prev;
        tail->next = NULL;
    } else {
        // Remove from the middle
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    delete node;
}


class LRUCache {
public:

    map<int, Node*> mp;
    Node* head =NULL;
    Node* tail = NULL;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)== mp.end()) return -1;
        
        Node* node = mp[key];
        int value = node->value;
        deleteNode(head,tail,node);
        insertAtHead(head,tail,key,value);

        mp[key] = head;
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            deleteNode(head, tail, node);
            insertAtHead(head, tail, key, value);

            mp[key] = head;

        }
        else{
            if(mp.size() >= capacity){
                
                mp.erase(tail->key);
                deleteNode(head, tail, tail);
            }
            insertAtHead(head, tail, key, value);
            mp[key] = head; // Add to the map
        }
    }
};
