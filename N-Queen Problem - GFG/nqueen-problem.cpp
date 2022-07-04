// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void put_ans(vector<vector<int>> &temp, vector<vector<int>> &ans, int n)
    {
        // cout<<"YES"<<endl;
        vector<int> tempu;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(temp[j][i] == 1)
                tempu.push_back(j+1);
            }
        }
        
        ans.push_back(tempu);
        return;
    }
    
    bool isSafe(int col, int row, int n, vector<vector<int>> &temp)
    {
       for(int i=col; i>=0; i--)
       {
            if(temp[row][i] == 1)
            return false;
       }
       
       int i=row, j=col;
       
       while(i>=0 && j>=0)
       {
           if(temp[i][j] == 1)
           return false;
           
           i--;
           j--;
       }
       
       i = row, j=col;
       
       while(i<n && j>=0)
       {
           if(temp[i][j] == 1)
           return false;
           
           i++;
           j--;
       }
       
       return true;
    }
    
    void queen(int col, vector<vector<int>> &temp, vector<vector<int>> &ans, int n)
    {
        if(col == n)
        {
            put_ans(temp, ans, n);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            if(isSafe(col, i, n, temp))
            {
                temp[i][col] = 1;
                queen(col+1, temp, ans, n);
                temp[i][col] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>> ans;
        vector<vector<int>> temp (n, vector<int>(n,0));
        
        queen(0, temp, ans, n);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends