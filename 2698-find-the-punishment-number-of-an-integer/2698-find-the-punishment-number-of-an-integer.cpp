class Solution {
public:
    
    int chk=0;
    bool flag = false;
    
void recur(int i,const string &t, int sum)
{
	if (i >= t.size())
	{
		if(sum == chk)flag=true;
		return;
	}

	for (int j = 1; j <= t.length() - i; j++)
	{
		int d = stoi(t.substr(i, j));

		recur(i + j, t, sum + d);
	}

	return;
}
    
    int punishmentNumber(int n) 
    {
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            int temp = pow(i,2);
            string t = to_string(temp);
            
            chk = i;
            flag=false;
            recur(0, t, 0);
            
            if(flag)ans += temp;
        }
        
        return ans;
    }
};