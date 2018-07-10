//============================================================================
// Name        : codeforces.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Space optimized CPP implementation to print
// longest common substring.
#include <bits/stdc++.h>
#include<iostream>

#include<string>
#include <cstdlib>
using namespace std;
 
// Function to find longest common substring.
string LCSubStr(string X, string Y)
{
    // Find length of both the strings.
    int m = X.length();
    int n = Y.length();
 
    // Variable to store length of longest
    // common substring.
    int result = 0;
 
    // Variable to store ending point of
    // longest common substring in X.
    int end;
 
    // Matrix to store result of two
    // consecutive rows at a time.
    int len[2][n];
 
    // Variable to represent which row of
    // matrix is current row.
    int currRow = 0;
 
    // For a particular value of i and j,
    // len[currRow][j] stores length of longest
    // common substring in string X[0..i] and Y[0..j].
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result) {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else {
                len[currRow][j] = 0;
            }
        }
 
        // Make current row as previous row and
        // previous row as new current row.
        currRow = 1 - currRow;
    }
 
    // If there is no common substring, print -1.
    if (result == 0) {
        return "-1";
    }
 
    // Longest common substring is from index
    // end - result + 1 to index end in X.
    return X.substr(end - result + 1, result);
}
// Driver Code
int main()
{
	int sl,tl,pl,ans;
    string s;
    string t;
    string c;
    // function call

    
    getline (cin, s);
    sl=s.length();
    getline (cin, t);
    char ch = *s.rbegin();
    char ch1= *t.rbegin();
    
    tl=t.length();
    cout << LCSubStr(s, t)<<endl;
    c=LCSubStr(s, t);
    pl=c.length();
    if(ch!=ch1){
    	cout<<sl+tl;
    }
    else{
    ans=abs(sl-pl)+abs(tl-pl);
    cout<<ans;
    }
    return 0;
}

