class Solution {
public:
    string customSortString(string order, string s) {

        map<char, int> mpp;

        for (int i = 0; i < order.size(); i++) {
            mpp[order[i]] = i + 1;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            if (mpp[a] < mpp[b])
                return true;

            return false;
        });

        return s;
    }
};