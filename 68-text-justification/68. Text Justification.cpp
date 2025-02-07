class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {
            string currLine = "";
            int currLen = 0;
            vector<string> curr;
            vector<int> spaces;
            int totalWords = 0;

            while (currLen <= maxWidth && i < words.size()) {
                if (words[i].length() + currLen + curr.size() - 1 < maxWidth) {
                    curr.push_back(words[i]);
                    currLen += words[i].length();
                    i++;
                } else {
                    break;
                }
            }
            i--;
            int totalSpace = maxWidth - currLen;
            int divisors = curr.size() - 1;

            if (i != words.size()-1) {
                if (curr.size() == 1) {
                    int giveSpace = maxWidth - curr[0].length();
                    currLine += curr[0];
                    while (giveSpace--)
                        currLine += ' ';
                }

                else {
                    int k = 0;
                    while (divisors > 0) {
                        int giveSpace =
                            ceil((float)totalSpace / (float)divisors);
                        totalSpace -= giveSpace;
                        divisors--;

                        currLine += curr[k];
                        while (giveSpace--)
                            currLine += ' ';
                        k++;
                    }
                    currLine += curr[k];
                }
            }

            else {
                for (int i = 0; i < curr.size(); i++) {
                    currLine += curr[i];
                    if (i != curr.size() - 1)
                        currLine += ' ';
                }

                int pending = maxWidth - currLine.length();
                while(pending--)currLine += ' '; 
            }
            ans.push_back(currLine);
        }

        return ans;
    }
};