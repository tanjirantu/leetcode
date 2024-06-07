#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Create a linked list from a vector of integers
 *
 * @param values vector of integers representing the values of the linked list
 * @return pointer to the head of the linked list
 */
ListNode *createLinkedList(const vector<int> &values) {
    // If the vector is empty, return nullptr
    if (values.empty()) return nullptr;

    // Create the head of the linked list with the first value
    ListNode *head = new ListNode(values[0]);
    ListNode *curr = head;

    // Iterate through the vector and create nodes for each value
    for (int i = 1; i < values.size(); i++) {
        // Create a new node with the current value
        curr->next = new ListNode(values[i]);

        // Move the current node to the next node
        curr = curr->next;
    }

    // Return the head of the linked list
    return head;
}

void printLinkedList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << "->";
        }
        current = current->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode();
        ListNode *current = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return head->next;
    }
};

int main() {
    vector<int> v1 = {1, 2, 4};
    vector<int> v2 = {1, 3, 4};
    ListNode *list1 = createLinkedList(v1);
    ListNode *list2 = createLinkedList(v2);

    Solution solution;
    ListNode *head = solution.mergeTwoLists(list1, list2);

    printLinkedList(head);

    return 0;
}