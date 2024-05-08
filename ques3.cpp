#include <iostream>
#include <unordered_map>

using namespace std;

// Node class for the doubly linked list
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    time_t timestamp; // Timestamp for cache expiration

    // Constructor to initialize key, value, and timestamp
    Node(int kkey, int vval) {
        key = kkey;
        val = vval;
        timestamp = time(nullptr); // Initialize timestamp with current time
    }
};

// Function to insert a new node after the head
void insert(Node* newnode, Node* head, Node* tail) {
    Node* dummy = head->next;
    newnode->next = dummy;
    newnode->prev = head;
    head->next = newnode;
    // If dummy is not NULL, set its prev to newnode; Otherwise, set tail's prev to newnode
    if (dummy != NULL) {
        dummy->prev = newnode;
    } else {
        tail->prev = newnode;
        newnode->next = tail;
    }
}

// Function to delete a node from the doubly linked list
void deleteNode(Node* delnode) {
    Node* prevv = delnode->prev;
    Node* nextt = delnode->next;
    prevv->next = nextt;
    nextt->prev = prevv;
}

// Function to check expiration of nodes in the cache
void checkExpiry(unordered_map<int, Node*>& map, int expirationTime) {
    // Get the current time
    time_t currentTime = time(nullptr);
    // Iterate over every cache node present and if current time minus the 
    // time when cache was created is greater than expiration time then delete the cache
    for (auto it : map) {
        Node* n = it.second;
        if (currentTime - n->timestamp > expirationTime) {
            map.erase(n->key);
            deleteNode(n);
        }
    }
}

// Function to get the value corresponding to a key from the cache
int get(int key, unordered_map<int, Node*>& map, Node* head, int exp) {
    // Check for expired nodes and remove them
    checkExpiry(map, exp);
    // If key exists, move the corresponding node to the front of the cache and return its value
    if (map.find(key) != map.end()) {
        Node* resNode = map[key];
        int ans = resNode->val;
        map.erase(key);
        deleteNode(resNode);
        insert(resNode, head, NULL); // The tail pointer is not used here
        map[key] = head->next;
        return ans;
    }
    // Return -1 if key doesn't exist in the cache
    return -1;
}

// Function to insert or update a key-value pair in the cache
void put(int key, int value, unordered_map<int, Node*>& map, Node* head, Node* tail, int cap, int exp) {
    // Check for expired nodes and remove them
    checkExpiry(map, exp);
    // If key already exists, delete the corresponding node
    if (map.find(key) != map.end()) {
        Node* curr = map[key];
        map.erase(key);
        deleteNode(curr);
    }
    // If cache is full, remove the least recently used node
    if (map.size() == cap) {
        map.erase(tail->prev->key);
        deleteNode(tail->prev);
    }
    // Insert the new node at the front of the cache and update the map
    insert(new Node(key, value), head, tail);
    map[key] = head->next;
}

// Function to print the contents of the cache
void print(unordered_map<int, Node*>& map, int exp) {
    // Check for expired nodes and remove them
    checkExpiry(map, exp);
    // Iterate over the cache and print key-value pairs
    for (auto it : map) {
        cout << it.first << " " << it.second->val << "\n";
    }
}

int main() {
    int cap;
    unordered_map<int, Node*> map;
    Node* head = new Node(-1, -1); // Dummy head node
    Node* tail = new Node(-1, -1); // Dummy tail node
    cout << "Enter the capacity\n";
    cin >> cap;
    int exp;
    cout << "Enter expiration time in sec for the cache\n";
    cin >> exp;
    // Continuous loop for cache operations
    while (true) {
        int option;
        cout << "Enter 1 to push, 2 to get, 3 to print and 4 to exit\n";
        cin >> option;

        int key, value;
        int getKey;

        if (option == 1) {
            cout << "Enter key\n";
            cin >> key;
            cout << "Enter value\n";
            cin >> value;
        }

        if (option == 2) {
            cout << "Enter the key to get value\n";
            cin >> getKey;
        }

        switch (option) {
            case 1:
                put(key, value, map, head, tail, cap, exp);
                break;
            case 2:
                int v;
                v = get(getKey, map, head, exp);
                cout << v << "\n";
                break;
            case 3:
                print(map, exp);
                break;
            case 4:
                return 0;
            default:
                cout << "invalid option";
        }
    }
    return 0;
}
