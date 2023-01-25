#include<bits/stdc++.h>
using namespace std;

class ListNode{

public:
    int data;
    ListNode* next;

    ListNode(){}
        ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};


void print(ListNode *first){
    ListNode* ptr = first;

    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

ListNode* takeInput(){
    ListNode *head = NULL;

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int data;
        cin >> data;

        ListNode* newNode = new ListNode(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            ListNode *temp = head;

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;


    ListNode *head = NULL, *ptr;

    while(list1 != NULL && list2 != NULL) {

        if(head == NULL) {
            if(list1 -> data <= list2 -> data) {
                head = list1;
                ptr = head;
                list1 = list1 -> next;
            } else {
                head = list2;
                ptr = head;
                list2 = list2 -> next;
            }
        } else {
            if(list1 -> data <= list2 -> data) {
                ptr -> next = list1;
                ptr = ptr -> next;
                list1 = list1 -> next;
            } else {
                ptr -> next = list2;
                ptr = ptr -> next;
                list2 = list2 -> next;
            }
        }
    }

    if(list1 != NULL)
        ptr -> next = list1;

    if(list2 != NULL)
        ptr -> next = list2;

    return head;
}

int main(){

    ListNode* head1 = takeInput();
    ListNode* head2 = takeInput();

    ListNode* mergedHead = mergeTwoLists(head1, head2);

    cout<< endl;
    print(mergedHead);

    return 0;
}
