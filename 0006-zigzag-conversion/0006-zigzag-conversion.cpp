class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1)return s;

        if(numRows == 2)
        {
            string ans = "";

            for(int i=0; i<s.length(); i+=2)
            {
                ans += s[i];
            }
            for(int i=1; i<s.length(); i+=2)
            {
                ans += s[i];
            }

            return ans;

        }


        int i = 0, j = 0;
        int zigLen = numRows - 2;
        int curr = 0;

        vector<vector<char>> vec(numRows,
                                 vector<char>(1000, '1'));



        for (int k=0; k<s.length(); k++) {
            if (i < numRows) {
                // cout << "capacity: " << numRows << " " << vec[0].size() <<
                // endl; cout << i << " " << j << " " << it << endl;

                if (i < numRows && j < vec[0].size() && k<s.length()) {

                    vec[i][j] = s[k];
                    // cout << "stored " << i << " " << j << " " << s[k] << " "
                    //      << vec[i][j] << endl;
                }
                i++;
            } else {
                i--;
                curr = 0;

                // cout << i << " " << j << " " << it << " " << curr << endl;

                while (curr < zigLen) {
                    i--;
                    j++;
                    curr++;

                    if (i < numRows && j < vec[0].size() && k<s.length()) {
                        vec[i][j] = s[k];
                        // cout << "stored Z " << i << " " << j << " "<<k<<" "<< s[k] << " "
                        //      << vec[i][j] << endl;
                    }

                    if(curr < zigLen)k++;
                }
                i--;
                j++;
            }
        }

        string ans = "";
        for (auto it : vec) {
            for (auto itt : it) {
                // cout<<itt<<" ";
                if((itt >= 65 && itt<=90) || (itt >= 97 && itt<=122) || itt == ',' || itt == '.')ans += itt;
            }
            // cout << endl;
        }
        return ans;
    }
};