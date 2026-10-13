class Solution {

    public int calculateMinLen(int rem, int k)
    {
        int i = 1;

        while((rem*i)%k != 0)i++;

        return i+1;
    }
    public int resilientSubarray(int[] nums, int k) {

        int n = nums.length;
        int[] pre = new int[n];
        int ans = 1;

        for (int i = 0; i < n; i++) {

            pre[i] = nums[i]%k;

            IO.print(pre[i] + " ");
        }
        IO.println();

        int i = 0;
        int j = 0, count = 0, len = 0, minRequiredLength = 0;

        while (i < n) {
            j = i;
            IO.println("starting " + j);

            while (j < n-1 && pre[j] == pre[j + 1])
            {
                IO.println(pre[j] + " ---- " + pre[j+1]);
                j++;
            }

            count = j - i + 1;

            IO.println(i + " " + j + " " + count);

            if (pre[i] == 0)
                ans = Math.max(ans, count);
            else {
                minRequiredLength = calculateMinLen(pre[i], k);
                IO.println("required len = " + minRequiredLength);

                if (count >= minRequiredLength) {
                    len = minRequiredLength;
                    count -= len;

                    while(count - (minRequiredLength - 1) >= 0)
                    {
                        len += minRequiredLength-1;
                        count -= (minRequiredLength - 1);
                    }

                    ans = Math.max(ans, len);
                    IO.println("AaaaaaaNNNNNNNNNNNSSSSSS " + ans);
                }
            }
            i = j + 1;
            IO.println("ending " + i);
        }

        // count = j - i + 1;
        // if (pre[i] == 0)
        //     ans = Math.max(ans, count);
        // else {
        //     minRequiredLength = k + 1;

        //     if (count >= minRequiredLength) {
        //         len = minRequiredLength + (count - minRequiredLength) / (k + 1);
        //         ans = Math.max(ans, len);
        //     }
        // }

        return ans;
    }
}