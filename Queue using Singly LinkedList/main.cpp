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
class Queue{
        private:
        LinkedList l1;
        public:
        bool isEmpty(){
            return l1.isEmpty();
        }
        bool enQueue(int value){
            l1.insetAtLast(value);
            return true;
        }
        bool deQueue(){
            if(isEmpty()){
                return false;
            }
            else{
                l1.removeFromBeg();
                return true;
            }
        }
        int peek(){
            if(isEmpty()){
                return -1;
            }
            else{
                l1.getFirstElement()->getData();
            }
        }
        void print(){
            l1.print();
        }
};
int main(){
    Queue obj1;
    obj1.enQueue(50);
    obj1.enQueue(40);
    obj1.enQueue(30);
    obj1.print();
    cout<<endl<<obj1.peek()<<endl;
    obj1.deQueue();
    cout<<"After Dequeue"<<endl;
    obj1.print();
    cout<<endl<<obj1.peek();
}