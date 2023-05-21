class Solution {
public:
    
    int getNum(int &i, string &f)
    {
        int curr = 0;
        
        while(f[i] >= '0' && f[i] <= '9')
        {
            curr = curr*10 + (int(f[i])-48);
            i++;
        }
        return curr;
    }
    
    map<string, int> recur(int &i, string &f)
    {
        string temp = "";
        map<string, int> mpp, rgh;
        
        int curr = 1;
        
        while(i<f.size())
        {
            // cout<<"char: "<<f[i]<<endl;
            
            if(f[i] == ')')
            {
                // cout<<"tmp "<<temp<<endl;
                if(!temp.empty())
                {
                    mpp[temp] += 1;
                    temp.clear();
                }
                
                break;
            }
            
            else if(f[i] != '(' && (f[i] >= 97 && f[i] <= 122 || temp.size() == 0))temp += f[i];
            
            else if(f[i] >= '0' && f[i] <= '9')
            {
                curr = getNum(i, f);
                i--;
                // cout<<temp<<" "<<curr<<endl;
                mpp[temp] += curr;
                curr = 1;
                temp = "";
            }
            
            else if(f[i] == '(')
            {
                if(!temp.empty())
                {
                    mpp[temp] += curr;
                    temp.clear();
                }
                
                i++;
                cout<<" call "<<endl;
                
                rgh = recur(i, f);
                
                cout<<" returned "<<rgh.size()<<endl;
                
                for(auto it : rgh)
                {
                    cout<<"r : "<<it.first<<" "<<it.second<<endl;
                }
        
                // cout<<"ccc "<<f[i]<endl;
                if(f[i+1] >= '0' && f[i+1] <= '9')
                {
                    i++;
                    curr = getNum(i, f);
                    cout<<"curr "<<curr<<" "<<f[i]<<endl;
                    i--;
                }
                else curr=1;
                
                for(auto it : rgh)
                {
                    cout<<" it.first "<<it.first<<" "<<curr<<endl;
                    int d = it.second*curr;
                    if(mpp.count(it.first))
                    {
                        mpp[it.first] += max(d,1);
                    }
                    else
                    {
                        mpp[it.first] = max(d,1);
                    }
                }
            }
            
            else if(!temp.empty() && f[i] >= 65 && f[i] <= 90)
            {
                mpp[temp] += 1;
                temp.clear();
                
                continue;
            }
            
            i++;
        }
        
        if(i >= f.size() && !temp.empty())
        {
            mpp[temp] = 1;
        }
        
        return mpp;
        
    }
    
    string countOfAtoms(string f) 
    {
        string ans = "";
        int i=0;
        
        map<string, int> mpp = recur(i, f);
        
        for(auto it : mpp)
        {
            ans += it.first;
            if(it.second != 1)
            ans += to_string(it.second);
        }
        
        return ans;
    }
};