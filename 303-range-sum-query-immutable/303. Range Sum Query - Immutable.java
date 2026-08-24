class NumArray {
    ArrayList<Integer> pre = new ArrayList();

    public NumArray(int[] nums) {
        int curr = 0;
        for(int it : nums)
        {
            curr += it;
            pre.add(curr);
        }
    }
    
    public int sumRange(int left, int right) {

        int rangeSum = pre.get(right);

        if(left > 0)rangeSum -= pre.get(left-1);

        return rangeSum;

    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */