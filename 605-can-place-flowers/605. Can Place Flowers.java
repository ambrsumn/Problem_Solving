class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {

        if(n == 0)return true;
        if(flowerbed.length == 1)
        {
            return n == 1 && flowerbed[0] == 0;
        }

        for(int i=0; i<flowerbed.length; i++)
        {
            if(flowerbed[i] == 1)continue;

            if(i == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                n--;
                continue;
            }

            if(i == flowerbed.length-1 && flowerbed[i-1] == 0)
            {
                n--;
                flowerbed[i] = 1;
                continue;
            }


            if(i>0 && i<flowerbed.length-1 && Math.max(flowerbed[i+1], flowerbed[i-1]) == 0)
            {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n <= 0;
        
    }
}