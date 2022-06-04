// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    vector<long long> leftMin(long long arr[], int n)
    {
        stack<long long> st;
        
        vector<long long> vec;
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
            
            if(st.empty())
                vec.push_back(-1);
            else
                vec.push_back(st.top());
            
            st.push(i);
        }
        
        return vec;
    }
    
    vector<long long> rightMin(long long arr[], int n)
    {
        stack<long long> st;
        
        vector<long long> vec;
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[i] <= arr[st.top()])
            st.pop();
            
            if(st.empty())
                vec.push_back(n);
            else
                vec.push_back(st.top());
            
            st.push(i);
        }
        
        reverse(vec.begin(), vec.end());
        return vec;
    }
    
    long long getMaxArea(long long heights[], int n)
    {
        vector<long long> left = leftMin(heights, n);
        vector<long long> right = rightMin(heights, n);
        
        long long maxi = -1;
        
        for(int i=0; i<n; i++)
        {
            long long curr = 0;
            curr = ((right[i]-1)-(left[i]+1)+1)*heights[i];
            
            // cout<<right[i]<<" "<<left[i]<<endl;
                
            if(curr > maxi)
                maxi = curr;
        }
        
        return maxi;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends