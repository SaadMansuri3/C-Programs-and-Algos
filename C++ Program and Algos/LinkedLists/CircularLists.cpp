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
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp!=head);
    cout<<endl;
}

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        n->next=n;
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head= n;
}
void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==NULL){
        InsertAtHead(head,val);
        return;
    }
    node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}  

void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp = temp->next;
    }

    node* todelete = head;
    temp ->next = head->next;
    head = head->next;

    delete todelete;

}

void deleteNode(node* &head, int pos){
    
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    int count = 1;
    while(count!=pos-1){
        temp = temp->next;
        count ++;   
    }
    node* todelete = temp->next;
    temp->next = temp ->next->next;

    delete todelete;
}


int main(){

    node* head= NULL;
    
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);

    PrintTheLL(head);

    deleteNode(head, 1);
 
    PrintTheLL(head);
    return 0;
}