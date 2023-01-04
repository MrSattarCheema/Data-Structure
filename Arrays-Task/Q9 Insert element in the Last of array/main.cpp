#include <iostream>
using namespace std;
int main(){
    int size,index,value,i;
    cout << "Enter size of Array";
    cin >> size;
    int arr[size];
    for (i = 0; i < size; i++)
    {
        cout << "Enter element of Array for index " << i << endl;
        cin >> arr[i];
    }
    cout<<"Enter the value that you want to insert";
    cin>>value;
    size++;
    arr[i]=value;
    cout<<"The Element of Array are now ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
}