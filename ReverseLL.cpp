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

Node* reverseLL(Node* head)
{
    Node *curr = head, *prev = NULL;

    while(curr != NULL)
    {
        Node *temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main()
{
    Node *head = insertNode();

    head = reverseLL(head);
    print(head);
    return 0;
}
