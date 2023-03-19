//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) 
    {
        vector<int> left, right;
        
        map<int, int> mpp;
        
        for(auto it : A)
        {
            left.push_back(mpp.size());
            mpp[it]++;
        }
        mpp.clear();
        
        for(int i=N-1; i>=0; i--)
        {
            // cout<<mpp.size()<<endl;
            right.push_back(mpp.size());
            mpp[A[i]]++;
        }
        reverse(right.begin(), right.end());
        
        // for(auto it : left)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        // for(auto it : right)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        for(int i=0; i<N; i++)
        {
            left[i] -= right[i];
        }
        
        return left;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends