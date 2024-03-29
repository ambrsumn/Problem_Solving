// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
static bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[0] < v2[0];
}

    int find(int a, int b)
    {
       int c = min(a ,b);
       
       for(int i=c; i>=2; i--)
       {
           if(a%i == 0 && b%i == 0)
           return i;
       }
       
       return 1;
    }
    
    
    int maxBinTreeGCD(vector<vector<int>> arr, int N) 
    {
        if(N == 1 || arr.size() < 2)
        return 0;
        
        sort(arr.begin(), arr.end(), sortcol);
        
        vector<int> gcds;
        
        for(int i=0; i<(arr.size()-1); i++)
        {
            if(arr[i][0] == arr[i+1][0])
            {
                gcds.push_back(find(arr[i][1], arr[i+1][1]));
                i++;
            }
            
            else
            {
                gcds.push_back(0);
            }
        }
        
        sort(gcds.begin(), gcds.end());
        
        return gcds[(gcds.size()-1)];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends