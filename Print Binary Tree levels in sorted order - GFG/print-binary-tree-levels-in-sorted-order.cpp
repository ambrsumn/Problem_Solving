// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        vector<vector<int>> ans;
        
        int total;
        int j=0;
        int i=0;
        
        while(i < n)
        {
            total = pow(2, j);
            int count = 0;
            vector<int> ansr;
            
            while(i<n && count < total)
            {
                ansr.push_back(arr[i]);
                i++;
                count++;
            }
            
            sort(ansr.begin(), ansr.end());
            ans.push_back(ansr);
            ansr.clear();
            j++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal  // } Driver Code Ends