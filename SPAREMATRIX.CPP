#include <iostream>
using namespace std;

int main() {
    int m, n;
    
    cout << "Enter Number of  Rows and Columns :" << endl;
    cin >> m >> n;
    if(m>10 && n>10){
        cout<<"Rows and columns size should be less than 10\n";
        return 0;
    }
    //calculate total elements
   


   
    int totalElements = m*n;

    
    

    int A[m][n];
    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout<<"Input Matrix:\n "<<endl;
    for (int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    // Count non-zero elements
    int counter = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) counter++;
        }
    }
   
        
    if(counter < 0.25*(totalElements)){
    //  sparse matrix representation
    int sp[counter + 1][3];
    int row = 0;
    
    
    sp[row][0] = m;
    sp[row][1] = n;
    sp[row][2] = counter;
    row++;
    
    // Store non-zero elements in the sparse matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                sp[row][0] = i;
                sp[row][1] = j;
                sp[row][2] = A[i][j];
                row++;
            }
        }
    }

    // Output sparse matrix representation
    cout << "Sparse Matrix (including dimensions and count):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sp[i][j] << " ";
        }
        cout << endl;
    }
}
    else{
        cout<<"Number of Non-Zero elements in given Matrix in Greater than 1/4(TotalElements). Hence Sparse Matrix Not Created.\n";
    }


    return 0;
}
