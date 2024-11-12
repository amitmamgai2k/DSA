#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* CreateLinkedList(int n) {
    if (n <= 0) return nullptr;

    Node* head = (Node*)malloc(sizeof(Node));
    cout << "Enter element 1: ";
    cin >> head->data;
    head->next = nullptr;
    Node* mover = head;

    for (int i = 1; i < n; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        cout << "Enter element " << i + 1 << ": ";
        cin >> temp->data;
        temp->next = nullptr;
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node* MergeLinkedList(Node* head1, Node* head2) {
    Node* dummyNode = (Node*)malloc(sizeof(Node));
    Node* temp = dummyNode;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        }
        else if (head1->data > head2->data) {
            temp->next = head2;
            head2 = head2->next;
        }
        else {
            temp->next = head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    // the remaining nodes
    if (head1 != nullptr) temp->next = head1;
    if (head2 != nullptr) temp->next = head2;

    return dummyNode->next; // Return merged list
}
void Display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    int n, m;
    cout << "Enter the number of elements in the Linked List 1: ";
    cin >> n;
    if (n >= 30 || n < 0) {
        cout << "Linked List Size should be less than 30 and greater than or equal to one.";
        return 1;
    }
    Node* head1 = CreateLinkedList(n);
    cout << "LinkedList 1: " << endl;
    Display(head1);

    cout << "Enter the number of elements in the Linked List 2: ";
    cin >> m;
    if (m >= 30 || m < 0) {
        cout << "Linked List Size should be less than 30 and greater than or equal to one.";
        return 1;
    }
    Node* head2 = CreateLinkedList(m);
    cout << "LinkedList 2: " << endl;
    Display(head2);
    Node* head = MergeLinkedList(head1, head2);
    cout << "Merged Linked List: " << endl;
    Display(head);

    return 0;
}
