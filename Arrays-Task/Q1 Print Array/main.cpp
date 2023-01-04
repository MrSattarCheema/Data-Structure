#include <iostream>
using namespace std;
void printArray(int arr[5]){
    for (int i = 0; i < 5; i++)
    {
        cout<<endl<<arr[i];
    }
    
}
int main(){
    int arr[5]={1,22,31,4,55};
    printArray(arr);
}