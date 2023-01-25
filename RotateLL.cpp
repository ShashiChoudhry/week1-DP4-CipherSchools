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

int lenLL(Node* head)
{
    if(head == NULL)
        return 0;

    return 1 +lenLL(head -> next);
}

Node* rotateLL(Node *head, int k) {

    if(head == NULL ) return NULL;

    int len = lenLL(head);
    k = k % len;

    if(k == 0 || k == len) return head;


    Node *ptr = head, *prevHead, *prev = NULL;

    int i = 0;
    Node* newHead = NULL;

    while(ptr != NULL) {

        if(i < (len - k)) {
            newHead = ptr;
        }
        prev = ptr;
        ptr = ptr -> next;
        i++;
    }

    Node* temp = newHead -> next;
    Node* tail = newHead;
//    tail -> next = NULL;
    prev -> next = head;
    tail -> next = NULL;

    cout<< newHead -> data << ' ' << prev -> data << endl;
    return temp;
}

int main()
{
    Node *head = insertNode();
    print(head);

    cout<< endl;

    int k; cin>> k;
    head = rotateLL(head, k);
    print(head);
    return 0;
}

