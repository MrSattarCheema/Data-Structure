#include <iostream>
using namespace std;
class Node{
    private:
    int data;
    Node* next;
    public:
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    Node(Node* next){
        this->next=next;
        this->data=0;
    }
    Node(int data,Node* next){
        this->data=data;
        this->next=next;
    }
    void setData(int data){
        this->data=data;
    }
    void setNext(Node* next){
        this->next=next;
    }
    int getData(){
        return data;
    }
    Node* getNext(){
        return next;
    }
};
class LinkedList{
    private:
    Node* head;
    public:
    LinkedList(){
        head=NULL;
    }
    bool isEmpty(){
        return (head==NULL);
    }
    int getLength(){
        int count=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->getNext();
            count++;
        }
        return count;
    }
    void insetAtBeg(int value){
        Node* newNode=new Node(value);
        if(isEmpty()){
            head=newNode;
        }
        else{
            newNode->setNext(head);
            head=newNode;
        }
    }
    void insetAtLast(int value){
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
        }
    }
    bool removeFromBeg(){
        if(isEmpty()){
            return false;
        }
        else{
            Node* temp=head;
            if(getLength()==1){
                delete head;
                head=NULL;
            }
            else{
                head=temp->getNext();
                delete temp;
                return true;
            }
        }
    }
    bool removeFromLast(){
        if(isEmpty()){
            return false;
        }
        else{
            Node* temp,*previous;
            temp=head;
            while(temp->getNext()!=NULL){
                previous=temp;
                temp=temp->getNext();
            }
            delete temp;
            previous->setNext(NULL);
            return true;
        }
    }
    Node* getFirstElement(){
        return head;
    }
    Node* getLastElement(){
        Node* temp=head;
        while(temp->getNext()!=NULL){
            temp=temp->getNext();
        }
        return temp;
    }
    void print(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->getData()<<endl<<temp->getNext()<<endl;
            temp=temp->getNext();
        }
    }
};
int main(){
    // Node *head;
    // Node* n1=new Node(1);
    // head=n1;
    // cout<<head->getData();
    // Node* n2=new Node(2);
    // n1->setNext(n2);
    // cout<<n1->getNext()->getData();
    LinkedList l1;
    cout<<l1.isEmpty()<<endl;
    l1.insetAtBeg(5);
    l1.insetAtLast(2);
    l1.insetAtBeg(3);
    l1.insetAtLast(4);
    cout<<l1.getFirstElement()->getData()<<endl;
    cout<<l1.getLastElement()->getData()<<endl;
    cout<<"Get Length"<<endl;
    cout<<l1.getLength()<<endl;
    cout<<"Print All"<<endl;
    l1.print();
    cout<<endl<<"After Removing"<<endl;
    l1.removeFromBeg();
    l1.removeFromLast();
    l1.print();
}