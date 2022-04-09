class KthLargest {
public:
    int size = 0;
    multiset <int, greater<int>> a;
    KthLargest(int k, vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); ++i){
            a.insert(nums[i]);
        }
        
        size = k;
      
    }
    
    int add(int val) {
        
        
    a.insert(val);
        
        auto it = a.begin();
        
        std::advance(it,size-1);
        
        return *it;
    }
};