#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};


//Declaring the global head and tail pointer
//Declaring the global head and tail pointer
struct Node *head=NULL,*tail=NULL;


//Inserting node at the end of the linked list
void insertAtEnd(int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(head==NULL){
        newNode->next=NULL;
        newNode->prev=NULL;
        head=newNode;
        tail=newNode;
    }
    else{
        newNode->next=tail->next;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}


//Inserting node at the front of the linked list
void insertAtFront(int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    newNode->prev=NULL;
    newNode->next=head;
    if(head==NULL)
        head=tail=newNode;
    else{
        head->prev=newNode;
        head=newNode;
    }
}


//Inserting a node after a given specific node
void insertAfterNode(struct Node *pos,int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    struct Node *temp=pos->next;
    pos->next=newNode;
    newNode->prev=pos;
    newNode->next=temp;
    temp->prev=newNode;
}


//Inserting a node before a given specific node
void insertBeforeNode(struct Node *pos,int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    struct Node *temp=pos->prev;
    pos->prev=newNode;
    newNode->next=pos;
    temp->next=newNode;
    newNode->prev=temp;
}


//Inserting new node at a given position
void insertAtPosition(int num,int pos){
    if(pos<1 || pos>getLength()+1){
        printf("Invalid Index");
        return;
    }
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(pos==1){
        newNode->prev=NULL;
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    else{
        int k=pos-2;
        struct Node *temp=head;
        while(k--)
            temp=temp->next;
        struct Node *t=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=t;
        if(t!=NULL)
            t->prev=newNode;
        if(pos==getLength())
            tail=newNode;
    }
}


//Deleting the given node
/*We will divide the deletion of the node from doubly linked list in three cases:-
i).When the node to be deleted is head node.
ii).When the node to be deleted is tail node i.e. the last node.
iii).When the node to be deleted is in between neither the first or last node.
*/
void deleteNode(struct Node *delNode){
    if(delNode==NULL){
        printf("Invalid Node!\n");
        return;
    }
    if(delNode==head){
        int x=delNode->data;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        else
            head=tail=NULL;
        free(delNode);
        printf("%d is deleted successfully\n", x);
    }
    else if(delNode==tail){
        int x=delNode->data;
        tail=tail->prev;
        if(tail!=NULL)
            tail->next=NULL;
        else
            head=tail=NULL;
        free(delNode);
        printf("%d is deleted successfully\n", x);
    }
    else{
        int x=delNode->data;
        struct Node *prevNode=delNode->prev;
        struct Node *nextNode=delNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        free(delNode);
        printf("%d is deleted successfully\n", x);
    }
}


//Deleting the node at a given position
void deleteNodeAt(int pos){
    struct Node *delNode;
    if(pos==1){
        delNode=head;
        int x=delNode->data;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        else
            head=tail=NULL;
        free(delNode);
        printf("%d is deleted successfully\n", x);
    }
    else if(pos==getLength()){
        delNode=tail;
        int x=delNode->data;
        tail=tail->prev;
        if(tail!=NULL)
            tail->next=NULL;
        else
            head=tail=NULL;
        free(delNode);
        printf("%d is deleted successfully\n", x);
    }
    else{
        pos--;
        delNode=head;
        while(pos--)
            delNode=delNode->next;
        int x=delNode->data;
        struct Node *prevNode=delNode->prev;
        struct Node *nextNode=delNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
        free(delNode);
        printf("%d is deleted successfully\n", x);
    }
}


//Reversing the doubly linked list
void reverse(){
    struct Node *first=head,*temp=NULL;
    while(first!=NULL){
        temp=first->next;
        first->next=first->prev;
        first->prev=temp;
        first=first->prev;
        if(first!=NULL && first->next!=NULL)
            head=first;
    }
}


//Displaying the list in forward direction
void displayForward(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}


//Displaying the list in backward direction
void displayBackward(){
    struct Node *temp=tail;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}


//Finding the length of the list
int getLength(){
    struct Node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}


int main(){
//insertAtFront(6);
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
insertAtFront(6);
//    insertAfterNode(head,6);
//    insertBeforeNode(tail,9);
//    insertAtPosition(10,7);
//    insertAtPosition(11,8);
//    insertAtPosition(12,10);
//    displayForward();
//    printf("The length of the list is:- %d\n", getLength());
//    deleteNodeAt(9);
    printf("The length of the list is:- %d\n", getLength());
    displayBackward();
    return 0;
}
