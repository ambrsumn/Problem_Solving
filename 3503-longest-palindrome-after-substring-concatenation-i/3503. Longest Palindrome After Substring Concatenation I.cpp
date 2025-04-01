class Solution {
public:

    bool isPalindrome(int i, int j, string &s)
    {
        while(i<=j)
        {
            if(s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    int maxMatched(string s, string t)
    {
        reverse(t.begin(), t.end());
        int ans = 1;

        for(int i=0; i<s.length(); i++)
        {
            for(int j=0; j<t.length(); j++)
            {
                int matched = 0;
                int k=i;
                int l=j;

                while(k<s.length() && l<t.length() && s[k] == t[l])
                {
                    //cout<<"matched "<<k<<" "<<l<<endl;
                    matched++;
                    k++;
                    l++;
                }

                if(matched >= 1)
                {
                    // cout<<" matching ends "<<k<<" "<<l<<endl;
                    
                    matched *= 2;
                    if(k < s.length() || l < t.length())
                    {
                        int palOne = 0;
                        int palTwo = 0;
                        int fixed = 1;
                        // cout<<palOne<<" "<<palTwo<<endl;

                        if(k < s.length()-1)
                        {
                            // cout<<k<<" matching string 1 for palindrome "<<s.length()-1<<endl;
                            for(int i=s.length()-1; i>=k; i--)
                            {
                                if(isPalindrome(k, i, s))
                                {
                                    // cout<<k<<" "<<i<<" pal-one "<<s<<" "<<palOne<<endl;

                                    palOne = max(palOne, (i-k+1));
                                }
                                // cout<<"palone "<<palOne<<i<<" "<<j<<endl;
                            }
                            // cout<<"palOne "<<palOne<<endl;
                        }

                        if(l < t.length()-1)
                        {
                            // cout<<l<<" matching string 2 for palindrome "<<t.length()-1<<endl;
                            for(int i=t.length()-1; i>=l; i--)
                            {
                                // //cout<
                                if(isPalindrome(l, i, t))
                                {
                                    // cout<<l<<" "<<i<<" pal-two "<<t<<" "<<palTwo<<endl;
                                    palTwo = max(palTwo, (i-l+1));
                                }
                            }

                            // cout<<"palTwo "<<palTwo<<endl;
                        }

                        // cout<<k<<" palone "<<palOne<<endl;
                        // cout<<l<<" paltwo "<<palTwo<<endl;


                        matched += max({palTwo, palOne, fixed});
                    }
                }

                ans = max(ans, matched);
                // cout<<ans<<endl;
            }
        }

        return ans;
    }

    int longestPalindrome(string s, string t) 
    {

        int possibilityOne = maxMatched(s, t);
        int possibilityTwo = 0;
        int possibilityThree = 0;

        for(int i=0; i<s.length(); i++)
        {
            for(int j=s.length()-1; j>=i; j--)
            {
                if(isPalindrome(i, j, s))
                {
                    possibilityTwo = max(possibilityTwo, (j-i+1));
                }
            }
        }

        for(int i=0; i<t.length(); i++)
        {
            for(int j=t.length()-1; j>=i; j--)
            {
                if(isPalindrome(i, j, t))
                {
                    possibilityThree = max(possibilityThree, (j-i+1));
                }
            }
        }

        return max({possibilityOne, possibilityThree, possibilityTwo});
    }
};