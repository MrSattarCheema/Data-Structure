#include <iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int length=sizeof(arr)/sizeof(arr[0]);
    cout<<length;
}