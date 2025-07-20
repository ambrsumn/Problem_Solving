class Solution {
public:
    bool checkDivisibility(int n) {

        int temp = n, sum = 0, pro = 1;

        while(temp != 0)
            {
                int curr = temp%10;
                sum += curr;
                pro *= curr;

                temp /= 10;
            }

        if(n%(sum+pro) == 0)return true;
        return false;
        
    }
};