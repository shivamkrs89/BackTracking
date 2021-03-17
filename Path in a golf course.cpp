/*
You will be given a 2-D array a[ ][ ] of size n * n which represents positions in a golf course. A golfer wants to start from the top left corner and reach the bottom right corner of the golf course with any number of shots. Your task is to analyse the 2-D array and determine whether it is possible or not.

The 2-D array has a whole number in each cell. The number represents the maximum distance, a shot taken from that cell can reach. Shots can be taken in any of the 4 directions - UP, RIGHT, DOWN and LEFT. For example if a[i][j] hold a value 'x', then the golfer can go to any cell between a[i-x][j] and a[i+x][j] or between a[i][j-x] and a[i][j+x] from that cell. If a cell holds the value 0, that cell is a dead end. The golfer cannot go anywhere if he reaches there.

Input: First line of input contains number of test cases T. Then T test cases follow. In each test case, first line contains the value n. Second line of each test case contains n*n space separated integers that form the 2-D array A[ ][ ]. Input will be read by driver code.

Output: If it is possible to reach the bottom right celll starting from the top left, 1 is printed, else, 0 is printed.

Your task: Your task is to complete the function is_possible(). This function gets the 2-D array a[ ][ ] and its number of rows n as argument. Return 1 if it is possible to start from top left and reach bottom right, else return 0. Returned value will be printed  y driver code.

Constraints: T <= 200 ; 2 <= n <= 150 ; 0 <= a[i][j] <= 10

Example:
Input:
2
4
3 0 0 2 0 2 1 1 1 0 0 0 0 4 0 0
3
1 2 0 0 0 2 3 0 1

Output:
1
0

Explanation:
Testcase 1:
3 0 0 2
0 2 1 1
1 0 0 0
0 4 0 0
We can see the path a[0][0] -> a[0][3] -> a[1][3] -> a[1][2] -> a[1][1] -> a[3][1] -> a[3][3], hence output is 1

Testcase 2:
1 2 0
0 0 2
3 0 1
​There is no possible path to reach the bottom right cell, hence output is 0.
*/

//code begins here
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool is_possible(int** a, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int** a = new int*[n];
        for(int i=0 ; i<n ; i++)
        {
            a[i] = new int[n];
            for(int j=0 ; j<n ; j++)
                cin>> a[i][j];
        }
        
        cout<< is_possible(a,n) << endl;
    }
    return 1;
}
// } Driver Code Ends


//User function Template for C++

// Do not take input
// Do not print anything, just return 0 or 1

bool ispossible(int i,int j,int n)
{
    if(i<0 || i>=n || j<0 || j>=n)
    return 0;
    
    return 1;
}

bool f1(int **a,int i,int j,int n,vector<vector<bool>> &vis)
{
   // cout<<i<<' '<<j<<'\n';
    vis[i][j]=1;
    
    if(i==n-1 && j==n-1)
    return 1;
    
    if(a[i][j]==0)
    return 0;
    int x1=a[i][j],x;
    bool a1=0,a2=0,a3=0,a4=0;
    for(x=1;x<=x1;x++){
        if(ispossible(i+x,j,n) && vis[i+x][j])
          continue;
    if(ispossible(i+x,j,n))
    a1|=f1(a,i+x,j,n,vis);
    if(a1==1)
    return 1;
    }
    for(x=1;x<=x1;x++){
        if(ispossible(i-x,j,n) && vis[i-x][j])
          continue;
    if(ispossible(i-x,j,n))
    a2|=f1(a,i-x,j,n,vis);
    if(a2==1)
    return 1;
    }
    for(x=1;x<=x1;x++){
        if(ispossible(i,j+x,n) && vis[i][j+x])
          continue;
    if(ispossible(i,j+x,n))
    a3|=f1(a,i,j+x,n,vis);
    if(a3==1)
    return 1;
    }
    for(x=1;x<=x1;x++){
        if(ispossible(i,j-x,n) && vis[i][j-x])
          continue;
    if(ispossible(i,j-x,n))
    a4|=f1(a,i,j-x,n,vis);
    if(a4==1)
    return 1;
    }
    
    return a1 || a2 || a3 || a4;
}

bool is_possible(int** a, int n)
{
    if(!a[0][0])
    return 0;
    
    int i,j;
    vector<vector<bool>> vis(n);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        vis[i].push_back(0);
    }

     return f1(a,0,0,n,vis);
    
    
}


