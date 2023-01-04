#include <iostream>
using namespace std;
void reverseArray(int arr[5],int arr2[5]){
    for(int i=0;i<5;i++){
        arr2[i]=arr[i];
    }
}
int main(){
    int arr[5]={1,2,3,4,5};
    int arr2[5];
    reverseArray(arr,arr2);
    for(int i=0;i<5;i++){
        cout<<arr2[i]<<endl;
    }
}