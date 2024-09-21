#include <iostream>
#include <vector>

using namespace std;

// Function to convert a dense matrix to a sparse matrix representation
void convertToSparse(int m, int n, int A[][10]) {
    int counter = 0;
    //count non zero elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                counter++;
            }
        }
    }

    if (counter >= 0.25 * (m * n)) {
        // Not a sparse matrix
          cout<<"Number of Non-Zero elements in given Matrix in Greater than 1/4(TotalElements). Hence Sparse Matrix Not Created.\n";
    }

    int sparseMatrix[counter + 1][3] ;
    sparseMatrix[0][0] = m;
    sparseMatrix[0][1] = n;
    sparseMatrix[0][2] = counter;
    int row = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                sparseMatrix[row][0] = i;
                sparseMatrix[row][1] = j;
                sparseMatrix[row][2] = A[i][j];
                row++;
            }
        }
    }

   
}

int main() {
    int m, n;
    cout << "Enter Number of Rows and Columns: " << endl;
    cin >> m >> n;

    int A[m][n];

    cout << "Enter elements of matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Input Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int sparseMatrix = convertToSparse(m, n, A);

    if (sparseMatrix.empty()) {
        cout << "Number of Non-Zero elements in given Matrix is greater than 1/4(TotalElements). Hence Sparse Matrix Not Created.\n";
    } else {
        cout << "Sparse Matrix :" << endl;
        for (int i = 0; i < sparseMatrix.size(); i++) {
            for (int j = 0; j < 3; j++) {
                cout << sparseMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}