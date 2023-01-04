#include <iostream>
using namespace std;
// 1st Method
// void ReverseArray(int arr[5], int arr2[5])
// {
//     int j = 0;
//     for (int i = 4; i >= 0; i--)
//     {
//         // cout<<arr[i]<<endl;
//         arr2[j] = arr[i];
//         j++;
//     }
// }
// int main()
// {
//     int arr[5] = {1, 2, 3, 4, 5};
//     int arr2[5];
//     ReverseArray(arr, arr2);
//     for (int i = 0; i < 5; i++)
//     {
//         cout << arr2[i];
//     }
// }


// 2nd Method 
int * ReverseArray(int arr[],int size){
    int temp,n;
    n=size-1;
    for(int i=0;i<n;i++,n--){
        temp=arr[i];
        arr[i]=arr[n];
        arr[n]=temp;
    }
    return arr;
}
int main(){
    int size,*ptr;
    cout<<"Enter size of Array";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter element of Array for index "<<i<<endl;
        cin>>arr[i];
    }
    ptr=ReverseArray(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i];
    }
}