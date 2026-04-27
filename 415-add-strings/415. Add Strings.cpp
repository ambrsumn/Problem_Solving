class Solution {
public:
    string addStrings(string num1, string num2) {

        string ans = "";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i = 0;
        int remaining = 0;

        while (i < min(num1.length(), num2.length())) {
            int a = num1[i] - '0';
            int b = num2[i] - '0';

            int currSum = a + b + remaining;

            ans += char((currSum % 10) + '0');
            remaining = currSum / 10;

            i++;
        }

        while (i < num1.length()) {
            int a = num1[i] - '0';

            int currSum = a + remaining;

            ans += char((currSum % 10) + '0');
            remaining = currSum / 10;

            i++;
        }

        while (i < num2.length()) {
            int b = num2[i] - '0';

            int currSum = b + remaining;

            ans += char((currSum % 10) + '0');
            remaining = currSum / 10;

            i++;
        }

        if (remaining > 0) {
            ans += char(remaining + '0');  // better than prefix
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};