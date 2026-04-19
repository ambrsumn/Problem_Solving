class Solution {
public:
    int closestTarget(vector<string>& words, string target, int st) {

        auto it = find(words.begin(), words.end(), target);
        if(it == words.end())return -1;

        int ans = INT_MAX;
        int n = words.size();

        int count = 0;
        int i = st;
        while(words[i] != target) 
        {
            if (words[i] == target)
                break;
            count++;
            i = (i + 1) % n;
        }

        ans = min(ans, count);

        i = st;
        count=0;

        while(words[i] != target) 
        {
            if (words[i] == target)
                break;
            count++;
            i = (i - 1 + n) % n;
        }

        ans = min(ans, count);

        return ans;
    }
};