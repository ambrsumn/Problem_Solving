class Solution {
public:

    bool isValidCoupan(string s)
    {
        if(s == "")return false;

        for(auto it : s)
        {
            if(it == '_' || 
            it >= 65 && it<= 90 ||
            it >= 97 && it<= 122 || 
            it >= 48 && it<= 57)continue;
            else return false;
        }

        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& bl, vector<bool>& isActive) {

        vector<pair<string, string>> ans;
        for(int i=0; i<code.size(); i++)
        {
            if(isValidCoupan(code[i]) && 
            (bl[i]=="electronics" || bl[i]=="grocery" || bl[i]=="pharmacy" || bl[i]=="electronics" || bl[i]=="restaurant") && 
            isActive[i] == true)ans.push_back({bl[i], code[i]});
        }
        sort(ans.begin(), ans.end());
        vector<string> temp;

        for(auto it : ans)temp.push_back(it.second);
        return temp;
        
    }
};