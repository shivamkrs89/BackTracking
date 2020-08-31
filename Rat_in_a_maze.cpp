/*
Rat in a Maze Problem - I

Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

Example 1:

Input: N = 4, m[][] = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the 
destination at (3, 3) from (0, 0) by two 
paths ie DRDDRR and DDRDRR when printed 
in sorted order we get DDRDRR DRDDRR.

Example 2:

Input: N = 2, m[][] = {{1, 0},
                       {1, 0}}
Output: -1
Explanation: No path exits


Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2d array m[][] as input parameters and returns a list of paths.
 
Note:  In case of no path, return an empty list. The driver will output -1 automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/
//code goes here
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
void  backtrack(int m[MAX][MAX],vector<vector<bool>> vis,string s,int i,int j,int n,vector<string> & stream)
{
vis[i][j]=1;
    if(j==n-1 && i==n-1){
   stream.push_back(s);
    return ;
    }
    
   
    if(i+1<n && !vis[i+1][j] && m[i+1][j]==1)
   {
       
       backtrack(m,vis,s+'D',i+1,j,n,stream);
   }
    if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1)
   {
       
       backtrack(m,vis,s+'L',i,j-1,n,stream);
       
   }

if(j+1<n && !vis[i][j+1] && m[i][j+1]==1)
{
       
       
       backtrack(m,vis,s+'R',i,j+1,n,stream);
}
    if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1)
   {

       
       backtrack(m,vis,s+'U',i-1,j,n,stream);
   }
 
}
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
   vector<vector<bool> > vis( n , vector<bool> (n, 0));
    int i,j,k,l;vector<string> stream;
  if(m[0][0]==0)
  return stream;
  
  vis[0][0]=1;
  string s="";
  backtrack(m,vis,s,0,0,n,stream);
  cout<<stream.size()<<'\n';
   return stream;  
    
}

