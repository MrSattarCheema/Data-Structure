#include <iostream>
using namespace std;
class Node{
    private:
    int data;
    Node* next;
    public:
    Node(){
        data=-1;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        next=NULL;
    }
    Node(Node* next){
        this->next=next;
        data=-1;
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
    Node* FirstElement(){
        return head;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void insertAtStart(int value){
        Node* newNode=new Node(value);
        if(isEmpty()){
            head=newNode;
        }
        else{
            newNode->setNext(head);
            head=newNode;
        }
    }
    void insertAtLast(int value){
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
    int getLength(){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->getNext();
        }
        return count;
    }
    void insertAtNth(int value,int position){   
        int len=getLength();
        cout<<"\nlength "<<len;
        Node *temp=head;
        Node *newNode=new Node(value);
        if(len+1>=position && position>=1){
            if(position==1){
                newNode->setNext(head);
                head=newNode;
                return;
            }
            for(int i=0;i<position-2;i++){
                temp=temp->getNext();
                
            }
            
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
        else{
            cout<<"Index postion is out of range";
        }
    }
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<endl<<temp->getData();
            temp=temp->getNext();
        }
    }
    bool deleteFromStart(){
        if(isEmpty()){
            return false;
        }
        else if(getLength()==1){
            delete head;
            head=NULL;
        }
        else{
            Node* temp=head;
            head=temp->getNext();
            delete temp;
        }
    }
    bool deleteFromEnd(){
        if(isEmpty()){
            return false;
        }
        else{
            Node* temp=head;
            Node* previous;
            while(temp->getNext()!=NULL){
                previous=temp;
                temp=temp->getNext();
            }
            delete temp;
            previous->setNext(NULL);
        }
    }
    bool deleteFrom_NthPos(int position){
        if(isEmpty()){
            return false;
        }
        else if(getLength()>=position && position>=1){
            if(position==1){
                deleteFromStart();
                return true;
            }
            Node* temp=head;
            Node* temp2;
            for(int i=0;i<position-2;i++){
                temp=temp->getNext();
            }
            temp2=temp->getNext();
            temp->setNext(temp2->getNext());
            delete temp2;
        }
    }
    void reverse(){
        Node* current,* next,* prev;
        current=head;
        prev=NULL;
        while(current!=NULL){
            next=current->getNext();
            current->setNext(prev);
            prev=current;
            current=next;
        }
        head=prev;
    }
    void printReverse(Node* head){        //Using Recursion Reveres Print
        if(head==NULL) return;
        printReverse(head->getNext());
        cout<<"\n"<<head->getData();
    }
    void reverseRec(Node* h){
        if(h==NULL){
            return;
        }
        reverseRec(h->getNext());
        // cout<<"\n"<<h->getData();
        if(h->getNext()==NULL){
            head=h;
            return;
        }
        Node* temp=h->getNext();
        temp->setNext(h);
        h->setNext(NULL);
        
    }
};
int main(){
    LinkedList l;
    cout<<l.isEmpty();
    l.insertAtStart(20);
    l.insertAtStart(10);
    l.insertAtLast(30);
    l.insertAtLast(40);
    l.insertAtLast(60);
    l.insertAtNth(5,1);
    l.insertAtLast(70);
    l.print();
    cout<<"\nAfter Delete\n";
    l.deleteFromStart();
    l.deleteFromEnd();
    l.deleteFrom_NthPos(1);
    l.print();
    cout<<"\nAfter Reversing LinkedList";
    l.reverse();
    l.print();
    cout<<"\nReverse Print";
    Node *head=l.FirstElement();
    l.printReverse(head);
    cout<<"\nReverse LinkedList using recursion";
    l.reverseRec(head);
    l.print();
}