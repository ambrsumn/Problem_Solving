class Solution {
public:
    
vector<int> lastGreater(vector<int> arr, int n)
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
    
    
vector<int> firstGreater(vector<int> arr, int n)
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
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> last = lastGreater(arr, n);
        vector<int> first = firstGreater(arr, n);
        
        int ans = 0;
        
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