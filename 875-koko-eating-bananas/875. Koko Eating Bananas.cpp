class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(begin(piles), end(piles));
        int si = 1;
        int ei = piles.back();
        int posi = ei;
        while (si <= ei) {
            int m = si + (ei - si) / 2;
            if (isPossible(piles, h, m)) {
                posi = m;
                ei = m - 1;
            } else {
                si = m + 1;
            }
        }
        return posi;
    }
private:
    bool isPossible(vector<int> &piles, int h, int curr) {
        long long cnt = 0;
        for (int i = 0;i < piles.size();i++) {
            int p = piles[i];
            if (p <= curr) {
                cnt++;
            } else {
                long long a = 0;
                while (p) {
                    a += (p/curr);
                    p = (p % curr);
                    if (p == 0) break;
                    if (p < curr) {
                        a++;
                        break;
                    }
                }
                cnt += a;
            }
        }
        return (cnt <= h);
    }
};