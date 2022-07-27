#include <iostream> 

 using namespace std; 

class Node{

    int data;

    Node* next;

    public:

    Node(int data=0,Node* next=NULL){

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

int main(){

    Node *head=new Node(2);

    Node *n1=new Node(3);

    cout<<head->getData();

    Node *ptr=head;

    head->setNext(n1);

    cout<<head->getData();

}
