
#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

     int dp[30][30]; //creating a 2d dp array

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= m; j++) {
            if (s1[i- 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match, increment LCS length
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}

int main() {
   string s1,s2;
   cout<<"Enter S1: ";
   cin>>s1;
   cout<<"Enter S2: ";
   cin>>s2;
     if (s1.size() > 29 || s2.size() > 29) {
        cout << "Error: Strings cannot exceed 29 characters." << endl;
        return 1; 
    }

    // Call the function to find and output the length of the Longest Common Subsequence
    cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}

