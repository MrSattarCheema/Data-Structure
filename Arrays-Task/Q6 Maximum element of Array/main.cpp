#include <iostream>
using namespace std;
int miniElement(int arr[],int size){
    int temp=arr[0];
    for(int i=0;i<size;i++){
        if(temp<arr[i]){
        	temp=arr[i];
        }
    }
    return temp;
}
int main()
{
    int size,value;
    cout << "Enter size of Array";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element of Array for index " << i << endl;
        cin >> arr[i];
    }
    value=miniElement(arr,size);
    cout<<"Maximum Element of Array is"<<value;
}