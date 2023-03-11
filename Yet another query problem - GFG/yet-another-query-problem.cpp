//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &a, vector<vector<int>> &q) 
    {
        map<int, int> mpp;
        vector<int> ans;
        
        for(auto it : a)mpp[it]++;
        vector<int> total;
        
        for(int i=0; i<N; i++)
        {
            int temp = a[i];
            total.push_back(mpp[temp]);
            mpp[temp]--;
        }
        
        for(int i=0; i<num; i++)
        {
            int f = q[i][0];
            int l = q[i][1];
            int freq = q[i][2];
            int count=0;
            
            for(int i=f; i<=l; i++)
            {
                int temp = total[i];
                if(temp == freq)count++;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends