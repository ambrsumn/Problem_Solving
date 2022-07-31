class NumArray {
public:
    
    vector<int> vec;
    int sum=0;
    NumArray(vector<int>& nums) 
    {
        for(auto it : nums)
        {
            vec.push_back(it);
            sum += it;
        }
        // cout<<sum<<endl;
    }
    
    void update(int index, int val) 
    {
        sum -= vec[index];
        vec[index] = val;
        sum += val;
        // cout<<" chng : "<<sum<<endl;
    }
    
    int sumRange(int left, int right) 
    {
        int temp = sum;
        
        for(int i=0; i<left; i++)
            {temp -= vec[i];}
        
        for(int j=right+1; j<vec.size(); j++)
            {temp -= vec[j];}
        
        return temp;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */