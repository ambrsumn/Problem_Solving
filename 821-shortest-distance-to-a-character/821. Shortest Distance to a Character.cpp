class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> vec;
        for(int i=0;i<s.length();i++){
            int n=s.length();
            for(int j=0;j<s.length();j++) {
                if(s[j]==c){
                    if(abs(i-j)<n){
                        n=abs(i-j);
                    }
                }
            }
            vec.push_back(n);
        }
        return vec;
    }
};
