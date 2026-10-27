class RangeFreqQuery {

    Map<Integer, List<Integer>> freq = new HashMap<>();

    public int lowerBound(List<Integer> arr, int target)
    {
        int low=0;
        int high = arr.size()-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(arr.get(mid) >= target)
            {
                ans = mid;
                high = mid-1;
            }
            else 
            {
                low = mid+1;
            }
        }

        return ans;
    }

    public int upperBound(List<Integer> arr, int target)
    {
        int low=0;
        int high = arr.size()-1;
        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(arr.get(mid) <= target)
            {
                ans = mid;
                low = mid+1;
            }
            else 
            {
                high = mid-1;
            }
        }

        return ans;
    }

    public RangeFreqQuery(int[] arr) {

        for(int i=0; i<arr.length; i++)
        {
            freq.computeIfAbsent(arr[i], k->new ArrayList<>()).add(i);
        }

    }
    
    public int query(int left, int right, int value) {

        if(!freq.containsKey(value))return 0;

        int leftSide = lowerBound(freq.get(value), left);
        // IO.println(value + " " + leftSide);

        if(leftSide == -1)return 0;

        int rightSide = upperBound(freq.get(value), right);
        // IO.println(rightSide);


        return rightSide-leftSide+1;
    }
}