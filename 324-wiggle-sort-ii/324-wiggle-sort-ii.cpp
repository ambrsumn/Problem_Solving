class Solution {
public:
    void wiggleSort(vector<int>& vec) 
    {
        vector<int> arr = vec;
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<vec.size(); i+=2)
        {
            vec[i] = arr.back();
            arr.pop_back();
        }
        
        for(int i=0; i<vec.size(); i+=2)
        {
            vec[i] = arr.back();
            arr.pop_back();
        }
    }
};