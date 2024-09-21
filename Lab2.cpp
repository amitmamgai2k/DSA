#include <iostream>;
using namespace std;
int main(){
    int rows,cols;
    // Enter rows number
    cout<<"Enter the number of rows:";
    cin>>rows;
    // Enter cols Number;
    cout<<"Enter the number of cols";
    cin>>cols;
    int arr1[rows][cols], arr2[rows][cols], result[rows][cols];

    // First array input from user;
    cout<<"Enter first array elements:\n";
    for (int i = 0; i<rows;i++){
        for (int j = 0;j<cols;j++){
            cin>>arr1[i][j];
        }
    }
    // second array input from user;
    cout <<"Enter second array element:\n";
    for(int i= 0;i<rows;i++){
        for(int j =0;j<cols;j++){
            cin>>arr2[i][j];
        }
    }
    // Addition of two array;
    cout<<"Final array after addition:\n";
    for(int i = 0;i<rows;i++){
        for(int j= 0;j<cols;j++){
            result[i][j] = arr1[i][j]+arr2[i][j];
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;



}