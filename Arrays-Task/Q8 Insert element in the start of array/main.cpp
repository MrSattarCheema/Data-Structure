#include <iostream>
using namespace std;
void insertAtStart(int arr[],int size,int value){
    for(int i=(size-1);i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=value;
}
int main(){
    int size,index,value;
    cout << "Enter size of Array";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element of Array for index " << i << endl;
        cin >> arr[i];
    }
    cout<<"Enter the value that you want to insert";
    cin>>value;
    insertAtStart(arr,size,value);
    cout<<"The Element of Array are now";
    size++;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
}