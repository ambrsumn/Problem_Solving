class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        string temp = "";
        int one = 0;

        for(auto it : s)
        {
            if(it == '1')one++;
            if(it == '1' && temp.length() > 0 && temp.back() != '1')temp += '1';
            if(it == '0') temp += it;
        }
        vector<int> ones;

        for(int i=0; i<temp.length(); i++)if(temp[i] == '1')ones.push_back(i);

        int maxConvert = 0;
        // cout<<temp<<endl;

        for(int i=0; i<ones.size(); i++)
        {
            int left = 0, right = 0;

            if(i == 0)left = ones[i];
            else left = ones[i]-ones[i-1]-1;

            if(i == ones.size()-1)right = temp.size()-ones[i]-1;
            else right = ones[i+1]-ones[i]-1;

            if(left != 0 && right != 0)maxConvert = max(maxConvert, (left+right));
        }
        // cout<<maxConvert<<endl;

        return one+maxConvert;
    }
};