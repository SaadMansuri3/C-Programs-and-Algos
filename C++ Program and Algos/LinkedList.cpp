#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void PrintTheLL(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}  

void InsertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

bool SearchTheLL(node* &head, int val){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DeleteAtHead(node* &head){
    node* toDelete  = head;
    head = head->next;
    delete toDelete;
}

void DeleteTheNode(node* &head, int val){

    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        DeleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}



int main(){

    node* head= NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtHead(head,5);
    PrintTheLL(head);

    DeleteAtHead(head);
    DeleteTheNode(head,3);
    PrintTheLL(head);

    return 0;
}