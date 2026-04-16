class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) 
    {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if ((words[(startIndex+i)%n]==target) ||
                (words[(startIndex-i+n)%n]==target))
            {
                return i;
            }
        }
        return -1;
    }
};