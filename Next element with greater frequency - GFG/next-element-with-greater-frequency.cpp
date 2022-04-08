// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        unordered_map<int, int> mpp;
        
        for(int i=0; i<n; i++)
        {
            mpp[arr[i]]++;
        }
        
        vector<int> ans;
        vector<int> temp;
        ans.push_back(-1);
        
        temp.push_back(arr[n-1]);
        
        int max = mpp[temp[0]];
        // cout<<max<<" mx "<<endl;
        
        for(int i=(n-2); i>=0; i--)
        {
            if(mpp[arr[i]] < max)
            {
                // cout<<" yes "<<endl;
                int f = temp.size();
                
                for(int j=(f-1); j>=0; j--)
                {
                    // cout<<" l2 "<<mpp[temp[j]]<<endl;
                    
                    if(mpp[arr[i]] < mpp[temp[j]])
                    {
                        // cout<<" y1 "<<endl;
                        ans.push_back(temp[j]);
                        temp.push_back(arr[i]);
                    
                    
                    if(mpp[arr[i]] > max)
                        max = mpp[arr[i]];
                    
                        break;
                    
                    }
                }
            }
            
            else
            {
                // cout<<" no "<<endl;
                ans.push_back(-1);
                temp.push_back(arr[i]);
                
                    if(mpp[arr[i]] > max)
                        max = mpp[arr[i]];                
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends