class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        
        vector<int> ans = code;
        
        if(k == 0)
        {
            for(int i=0; i<code.size(); i++)
                ans[i] = 0;
        }
        
        
        else if(k > 0)
        {
            for(int i=0; i<code.size(); i++)
            {
                int sum = 0, count = 0;
                int j = i+1;
                
                while(count < k)
                {
                    if(j == code.size())
                        j = 0;
                    
                    cout<<code[j]<<" ";
                    sum += code[j];
                    
                    j++;
                    count++;
                }
                
                ans[i] = sum;
                
                cout<<endl<<endl;
            }
        }
        
        else
        {
            cout<<"YES"<<endl;
                       
            for(int i=0; i<code.size(); i++)
            {
                cout<<i<<endl;
                
                int sum = 0, count = 0;
                int j = i-1;
                
                while(count > k)
                {
                    // cout<<"yes"<<endl;
                    
                    if(j == -1)
                        j = (code.size()-1);
                    
                    cout<<code[j]<<" ";
                    sum += code[j];
                    
                    j--;
                    count--;
                }
                
                ans[i] = sum;
                
                cout<<endl<<endl;
            }
        }
        
        return ans;
    }
};