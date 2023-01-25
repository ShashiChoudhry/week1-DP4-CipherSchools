#include<bits/stdc++.h>
using namespace std;

class Node {
public:

    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* insertNode() {

    int n; cin>> n;
    Node *head = NULL, *ptr;

    for(int i = 1; i <= n; i++) {
        int x; cin>> x;

        Node* newNode = new Node(x);

        if(head == NULL) {
            head = newNode;
            ptr = head;
        } else {
            Node *temp = newNode;
            ptr -> next = temp;
            ptr = ptr -> next;
        }
    }

    return head;
}

void print(Node *head) {
    Node *ptr = head;

    while(ptr != NULL) {
        cout<< ptr -> data << ' ';
        ptr = ptr -> next;
    } cout<< endl;
}

Node* DeleteDuplicate(Node *head) {

    if(head == NULL)
        return head;

    Node *ptr = head, *dup, *temp;

    while(ptr != NULL && ptr -> next != NULL) {
        temp = ptr ;
        // Node *prev = ptr;
        while(temp -> next != NULL ) {

            if(ptr -> data == temp -> next -> data) {
                dup = temp -> next;

                temp -> next = temp -> next -> next;
                delete(dup);
            } else {
                temp = temp -> next;
            }
        } cout<< endl;
        ptr = ptr -> next;
    }

    return head;
}

int main()
{
    Node *head = insertNode();
    print(head);

    // cout<< endl;

    DeleteDuplicate(head);
    print(head);
    return 0;
}
