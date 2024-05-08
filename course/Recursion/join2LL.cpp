#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }

    Node* head;
    if (l1->data < l2->data) {
        head = l1;
        head->next = mergeSortedLists(l1->next, l2);
    } else {
        head = l2;
        head->next = mergeSortedLists(l1, l2->next);
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    Node* mergedList = mergeSortedLists(l1, l2);

    std::cout << "Merged sorted list: ";
    printList(mergedList);

    // Clean up memory
    Node* curr = mergedList;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
