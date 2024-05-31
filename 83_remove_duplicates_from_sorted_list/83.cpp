#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Create a linked list from a vector of integers
 *
 * @param values vector of integers representing the values of the linked list
 * @return pointer to the head of the linked list
 */
ListNode* createLinkedList(const vector<int>& values) {
    // If the vector is empty, return nullptr
    if (values.empty()) return nullptr;

    // Create the head of the linked list with the first value
    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;

    // Iterate through the vector and create nodes for each value
    for (int i = 0; i < values.size(); i++) {
        // Create a new node with the current value
        curr->next = new ListNode(values[i]);

        // Move the current node to the next node
        curr = curr->next;
    }

    // Return the head of the linked list
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
}

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* current = head;
        while (current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;
            }
            else {
                current = current->next;
            }
        }

        return head;
    }
};

int main() {
    vector<int> values = { 1,1,2,3,3 };
    ListNode* head = createLinkedList(values);

    Solution solution;
    ListNode* newNode = solution.deleteDuplicates(head);
    printLinkedList(newNode);

    return 0;
}