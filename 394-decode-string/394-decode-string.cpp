class Solution
{
public:
    int number(string s, int &i)
    {
        int num = 0;
        // int count = 1;

        while (s[i] >= 48 && s[i] <= 57)
        {
            // cout<<"yes"<<endl;
            num = num*10 + (s[i] - '0');
            // count *= 10;
            i++;
        }

        // i++;
        // cout<<num<<endl;
        return num;
    }

    void recover(string s, int &i, int num, string &ans)
    {
        if (s[i] == ']')
        {
            // cout<<ans<<endl;
            string temp = ans;

            for (int i = 1; i < num; i++)
            {
                ans += temp;
            }

            // cout << ans << " 2" << endl;
            return;
        }

        
        else if (s[i] >= 48 && s[i] <= 57)
        {
            int numm = number(s, i);

            if (s[i] == '[')
            {
                string neww = "";
                i++;
                recover(s, i, numm, neww);
                ans += neww;
            }
            
        }
        
        
        else
        ans += s[i];
        
        i++;
        recover(s, i, num, ans);
    }

    
    string decodeString(string s)
    {
        string ans = "";

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int num = 0;

            if (s[i] >= 48 && s[i] <= 57)
            {
                num = number(s, i);
            }

            if (s[i] == '[')
            {
                // cout << num << endl;

                string curr = "";
                i++;
                recover(s, i, num, curr);

                ans += curr;
            }

            else if (s[i] >= 65 && s[i] <= 122)
                ans.push_back(s[i]);
        }

        return ans;
    }
    
};