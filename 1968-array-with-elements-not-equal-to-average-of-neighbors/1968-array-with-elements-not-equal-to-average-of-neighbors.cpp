class Solution {
public:
    vector<int> rearrangeArray(vector<int>& vec) 
    {
        sort(vec.begin(), vec.end());
        int n=vec.size();
        vector<int> arr(n,0);
        
        for(int i=1; i<n; i+=2)
        {
            arr[i] = vec.back();
            vec.pop_back();
        }
        
        for(int i=0; i<n; i+=2)
        {
            arr[i] = vec.back();
            vec.pop_back();
        }
        
        return arr;
    }
};