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

node* reverseLL(node* head){
    //Iterative Way
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while (currptr!=NULL){
        
        nextptr = currptr -> next;
        currptr -> next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
    
}

node* reverseLL2(node* head){
    //Recursive way 

    if(head==NULL || head->next == NULL){
        return head;
    }

    node* newhead = reverseLL2(head->next);
    
    head ->next->next = head;
    head->next = NULL;

    return newhead;

}

node* ReverseK(node* head, int k){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    
    int count = 0;
    while(currptr!=NULL && count <k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if(nextptr!= NULL)
        head->next = ReverseK(nextptr,k);
    
    return prevptr;
}

int LLLength(node* head){
    int l = 0;
    node* temp = head;
    while(temp!= NULL){
        temp = temp -> next;
        l++;
    }
    return l;
}

void MakeIntersect(node* &head1, node* &head2,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int DetectIntersection(node* &head1, node* &head2){
    int l = 0;
    int l1= LLLength(head1);
    int l2= LLLength(head2);

    int d = 0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!= NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

node* MergeTwoLL(node* &head1,node* &head2){
    //Merges sorted lists

    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode; 
    while(p1 != NULL && p2 != NULL){
        if(p1->data<p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while(p1!=NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummyNode->next;
}

int main(){

    node* head= NULL;
    node* head2= NULL;
    
    InsertAtTail(head,1);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,7);

    InsertAtTail(head2,2);
    InsertAtTail(head2,3);
    InsertAtTail(head2,6);

    PrintTheLL(head);
    PrintTheLL(head2);

    node* newhead = MergeTwoLL(head,head2);
    PrintTheLL(newhead);


    return 0;
}