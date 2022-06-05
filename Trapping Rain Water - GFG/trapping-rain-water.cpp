// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    
vector<int> lastGreater(int arr[], int n)
{
    vector<int> vec;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
            while (!st.empty() && arr[i] > st.top())
                st.pop();

            if (st.empty())
                vec.push_back(-1);
            else
                vec.push_back(st.top());

            if(st.empty())
                st.push(arr[i]);
    }
    
    reverse(vec.begin(), vec.end());
    
    return vec;
}
    
    
vector<int> firstGreater(int arr[], int n)
{
    vector<int> vec;
    stack<int> st;

    for (int i=0; i<n; i++)
    {
            while (!st.empty() && arr[i] > st.top())
                st.pop();

            if (st.empty())
                vec.push_back(-1);
            else
                vec.push_back(st.top());

            if(st.empty())
                st.push(arr[i]);
    }
    
    return vec;
}    
    long long trappingWater(int arr[], int n)
    {
        vector<int> last = lastGreater(arr, n);
        vector<int> first = firstGreater(arr, n);
        
        long long ans = 0;
        
        // for(int i=0; i<n; i++)
        // {
        //     cout<<last[i]<<" "<<first[i]<<endl;
        // }
        
        for(int i=0; i<n; i++)
        {
            int mini = min(last[i], first[i]);
            
            if(mini > arr[i])
                ans += mini-arr[i];
        }
        
        return ans;
        
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends