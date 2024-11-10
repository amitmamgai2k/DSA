#include<iostream>
using namespace std;
//Merge function
void merge(int arr[],int left,int mid,int right){
    int temp[right-left+1];
    int  i = left; //left subarray starting index
    int j = mid+1; // rigth subarray starting index
    int k = 0;
    //Merge the two subarray into temp[]
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
       while(i<=mid){
            temp[k] = arr[i];
            k++;
            i++;
        }
        while(j<=right){
            temp[k] = arr[j];
            k++;
            j++;
        }
        for(int i  = left; i<=right;i++){
            arr[i] = temp[i-left];
        }
}
void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid = left +(right-left)/2;
        //Recursively divide th earray into two halves
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int size;
    cout<<"Enter the size of your array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" Elements: "<<endl;
    for (int i = 0;i<size;i++){
        cout<<"Element "<<i+1<<":";
        cin>>arr[i];
    }
    cout<<"\nUnsorted Array: ";
    for (int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,size-1);
    cout<<"Sorted Array: ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0 ;



}