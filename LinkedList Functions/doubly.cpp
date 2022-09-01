#include <iostream>
using namespace std;
class Node{
    private:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(){
        data=-1;
        next=NULL;
        prev=NULL;
    }
    Node(int data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
    Node(Node* next){
        this->next=next;
        data=-1;
        prev=NULL;
    }
    // Node(Node* prev){
    //     this->prev=prev;
    //     data=-1;
    //     next=NULL;
    // }
    Node(int data,Node* next,Node* prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
    void setData(int data){
        this->data=data;
    }
    void setNext(Node* next){
        this->next=next;
    }
    void setPrev(Node* prev){
        this->prev=prev;
    }
    int getData(){
        return data;
    }
    Node* getNext(){
        return next;
    }
    Node* getPrev(){
        return prev;
    }
};
class DoublyLinkedList{
    Node* head;
    public:
    DoublyLinkedList(){
        head=NULL;
    }
    bool isEmpty(){
        return (head==NULL);
    }
    void insertAtHead(int value){
        Node* newNode=new Node(value);
        if(isEmpty()){
            head=newNode;
        }
        else{
            head->setPrev(newNode);
            newNode->setNext(head);
            head=newNode;
        }
    }
    void insertAtTail(int value){
        Node* newNode=new Node(value);
        if(isEmpty()){
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->getNext()!=NULL){
                temp=temp->getNext();
            }
            temp->setNext(newNode);
            newNode->setPrev(temp);
        }
    }
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<"\n"<<temp->getData();
            temp=temp->getNext();
        }
    }
    void reversePrint(){
        Node* temp=head;
        if(head==NULL) return;
        while(temp->getNext()!=NULL){
            temp=temp->getNext();
        }
        while(temp!=NULL){
            cout<<"\n"<<temp->getData();
            temp=temp->getPrev();
        }
    }
};
int main(){
    DoublyLinkedList l;
    l.insertAtHead(20);
    l.insertAtTail(30);
    l.insertAtTail(40);
    l.insertAtHead(10);
    l.insertAtTail(50);
    l.print();
    cout<<"\nReverse Print";
    l.reversePrint();
}