#include <iostream>
using namespace std;
class BstNode{
    int data;
    BstNode* right;
    BstNode* left;
    public:
    BstNode(int data){
        this->data=data;
        right=NULL;
        left=NULL;
    }
    void setData(int data){
        this->data=data;
    }
    int getData(){
        return data;
    }
    void setRight(BstNode* right){
        this->right=right;
    }
    BstNode* getRight(){
        return right;
    }
    void setLeft(BstNode* left){
        this->left=left;
    }
    BstNode* getLeft(){
        return left;
    }
};
class BST{
    BstNode* root,* temp;
    int count;
    public:
    BST(){
        root=NULL;
        temp=NULL;
        count=0;
    }
    BstNode* getEdge(){
        return temp;
    }
    BstNode* getRoot(){
        return root;
    }
    BstNode* insert(BstNode* root,int value){
        if(root==NULL){
            root = new BstNode(value);
            if(count==0){
            this->root=root;
            }
            temp=root;
            return root;
        }
        else if(value<=root->getData()){
            count++;
            root->setLeft(insert(root->getLeft(),value));
        }
        else {
            count++;
            root->setRight(insert(root->getRight(),value));
        }
        return root;
    }
    bool search(BstNode* root,int value){
        if(root==NULL){
            return false;
        }
        else if(root->getData()==value){
            return true;
        }
        else if(value<=root->getData()){
            return search(root->getLeft(),value);
        }
        else{
            return search(root->getRight(),value);
        }
    }
    // void insert(int value){
    //     if (root==NULL){
    //         root = new BstNode(value);
    //     }
    //     else if(value<=root->getData()){
    //         root->setLeft(insert(value));
    //     }
    //     else {
    //         root->setRight(insert(value));
    //     }
    // }
    // void print2D(BstNode* root,int space){
    //     if(root==NULL) return;
    //     space +=10;
    //     print2D(root->getRight(),space);
    //     cout<<endl;
    //     for(int i=10;i<space;i++){
    //         cout<<" "<<root->getData()<<'\n';
    //     }
    //     print2D(root->getLeft(),space);
    // }
    // void print(){
    //     print2D(root,0);
    // }
};
int main(){
    BST T;
    T.insert(T.getEdge(),7);
    T.insert(T.getEdge(),2);
    T.insert(T.getEdge(),3);
    T.insert(T.getEdge(),10);
    T.insert(T.getEdge(),13);
    cout<<T.search(T.getRoot(),7);
    cout<<T.getEdge()->getData();
    cout<<T.getRoot()->getData();
}