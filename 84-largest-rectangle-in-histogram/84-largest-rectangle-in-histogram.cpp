class Solution {
public:
    
    vector<int> leftMin(vector<int> arr)
    {
        int n = arr.size();
        stack<int> st;
        
        vector<int> vec;
        
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
    
    vector<int> rightMin(vector<int> arr)
    {
        int n = arr.size();
        stack<int> st;
        
        vector<int> vec;
        
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
    
    
    int largestRectangleArea(vector<int>& heights) 
    {
        vector<int> left = leftMin(heights);
        vector<int> right = rightMin(heights);
        
        int maxi = -1;
        
        for(int i=0; i<heights.size(); i++)
        {
            int curr = 0;
            curr = ((right[i]-1)-(left[i]+1)+1)*heights[i];
            
            // cout<<right[i]<<" "<<left[i]<<endl;
                
            if(curr > maxi)
                maxi = curr;
        }
        
        return maxi;
    }
};