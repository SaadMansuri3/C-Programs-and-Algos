//Find cycle in linked lists
//Also known as Hare and tortoise algorithm
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

void MakeCycle(node* &head, int pos){
    node*temp = head;
    node*startNode;

    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

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

bool DetectCycle(node* &head ){

    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            return true;
        }
    }
    return false;
}

void RemoveCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow!=fast);

    fast = head; 
    while(slow->next!= fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}


int main(){

    node* head= NULL;

    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    MakeCycle(head,3);
    cout<<DetectCycle(head)<<endl;
    RemoveCycle(head);
    cout<<DetectCycle(head)<<endl;
    PrintTheLL(head);

    return 0;
}