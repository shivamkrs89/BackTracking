/*
Subsets

Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.

Example 1:

Input: N = 3, arr[] = {1,2,2}
Output:(),(1),(1 2),(1 2 2),(2),(2 2)

Example 2:

Input: N = 4, arr[] = {1,2,3,3}
Output: (),(1),(1 2),(1 2 3)
(1 2 3 3),(1 3),(1 3 3),(2),(2 3)
(2 3 3),(3),(3 3)

Your Task:
Your task is to complete the function AllSubsets() which takes the array arr[] and N as input parameters and returns list of all possible unique subsets. 

Expected Time Complexity: O(2N).
Expected Auxiliary Space: O(2N * X), X = Length of each subset.

Constraints:
1 ≤ N ≤ 12
1 ≤ arr[i] ≤ 9
*/
//code goes here
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



void getsubsets(unordered_map<string,int> &s1,vector<vector<int>> &subsq,vector<int>& a,int s,bool take,vector<int>& v)
{
     if(take)
    {
        string x="";
        v.push_back(a[s]);
        for(int i=0;i<v.size();i++)
        x+='0'+v[i];
        
      
        if(s1[x]==0){
        subsq.push_back(v);
        s1[x]+=1;
        }
    }
    if(s>=a.size()-1)
    {
    return;
    }
 
      getsubsets(s1,subsq,a,s+1,1,v);
    v.pop_back();
    getsubsets(s1,subsq,a,s+1,0,v);
    
}

vector<vector<int> > AllSubsets(vector<int> A, int n)
{
    // code here
  vector<vector<int>> subsets,subsets2;
  vector<int> v;
  sort(A.begin(),A.end());
 
  
 subsets.push_back(v);
 unordered_map<string,int> s1;
  getsubsets(s1,subsets,A,0,1,v);
  v.pop_back();
  getsubsets(s1,subsets,A,0,0,v);
 
  
  return subsets;
}

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        
        vector<vector<int> > result = AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends
