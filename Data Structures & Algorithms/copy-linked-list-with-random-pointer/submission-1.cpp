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
        if (!head) return nullptr;

        unordered_map<Node*, Node*> map;

        // First pass: create all nodes
        for (Node* cur = head; cur; cur = cur->next)
            map[cur] = new Node(cur->val);
        
        // Second pass: wire next and random
        for (Node* cur = head; cur; cur = cur->next) {
            map[cur]->next = map[cur->next]; // nullptr maps to nullptr via [] default
            map[cur]->random = map[cur->random];
        }

        return map[head];
    }
};
