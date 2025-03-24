class Solution {
    public boolean ifPossible(long[] time, int[] mana, long val, int[] skill, int por){
        for(int j=0;j<time.length;j++){
            if(time[j] > val) return false;
            val+=mana[por]*skill[j];
        }
        return true;
    }
    public long getStart(long[] time, int[] mana, int[] skill, int por){
        int n = time.length;
        long start = time[0];
        long end = time[n-1];
        long ans = -1;


        while(start <= end){
            long mid = (start+end)/2;
            if(ifPossible(time, mana, mid, skill, por)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
    public long minTime(int[] skill, int[] mana) {
        int n = skill.length;
        int m = mana.length;
        long min = -1;
        long max = Long.MAX_VALUE;
        long[] time = new long[n];
        for(int i=0;i<m;i++){
            if(i == 0){
                long timeElapsed = 0;
                for(int j=0;j<n;j++){
                    timeElapsed+=mana[i]*skill[j];
                    time[j] = timeElapsed;
                }
            }else{
                long timeElapsed = getStart(time, mana, skill, i);
                for(int j=0;j<n;j++){
                    timeElapsed+=mana[i]*skill[j];
                    time[j] = timeElapsed;
                }
            }
        }
        return time[n-1];
    }
}