#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Common Subsequence (LCS)
int lcs(string s1, string s2, string &ans) {
    int n = s1.size();
    int m = s2.size();
    int dp[n+1][m+1]; // Creating a 2D dp array

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
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match, increment LCS length
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Characters don't match, take the maximum
            }
        }
    }

    // Trace back to find the LCS string
    int len = dp[n][m];
    ans = string(len, '$'); // Initialize the result string with length 'len'
    int index = len - 1;
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans[index] = s1[i - 1]; // If characters match, add to the result
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up if the previous cell has a larger value
        } else {
            j--; // Move left if the top cell has a larger value
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}

int main() {
    string s1, s2;
    cout << "Enter S1: ";
    cin >> s1;
    cout << "Enter S2: ";
    cin >> s2;

    string ans;

    // Call the function to find and output the length of the Longest Common Subsequence
    int length = lcs(s1, s2, ans);

    cout << "The Length of Longest Common Subsequence is " << length << endl;
    cout << "The Longest Common Subsequence is: " << ans << endl;

    return 0; // Return 0 to indicate successful program execution
}
