class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        int n = arr2.size();
        map<int, int> order;

        for (int i = 0; i < arr2.size(); i++) {
            order[arr2[i]] = n - i;
        }

        for(auto it : order)cout<<it.first<<" "<<it.second<<endl;

        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            // both present in arr2
            if (order.find(a) != order.end() && order.find(b) != order.end()) {
                return order[a] > order[b];
            }

            // a present in arr2
            if (order.find(a) != order.end())
                return true;

            // b present in arr2
            if (order.find(b) != order.end())
                return false;

            // none present so compare and put
            return a < b;
        });

        return arr1;
    }
};