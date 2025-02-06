class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack.length() < needle.length())return -1;
        if(haystack == needle)return 0;

        for(int i=0; i<haystack.length(); i++)
        {
            int j=0;
            int k = i;

            while(j<needle.length() && k<haystack.length() && needle[j] == haystack[k])
            {
                k++;
                j++;
            }
            if(j == needle.length())return i;
        }

        return -1;
        
    }
};