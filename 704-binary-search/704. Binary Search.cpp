class Solution {
public:
    int search(vector<int>& vec, int target) {
        sort(vec.begin(), vec.end());
        int n = vec.size();
        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] == target)return mid;

            if (vec[mid] > target)high = mid-1;

            else low = mid+1;
        }

        return -1;
    }
};