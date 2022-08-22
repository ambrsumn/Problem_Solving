class Solution {
public:
    
  vector<int> vec;
  
  int recur(int i, int &k)
  {
      if(vec.size()==1)return vec[0];
      
      i = (i+k)%vec.size();
      vec.erase(vec.begin()+i);
      
      return recur(i,k);
  }
    
    int findTheWinner(int n, int k) 
    {
        for(int i=1; i<=n; i++)
            vec.push_back(i);
        
        k--;
        
    return recur(0,k);
    }
};