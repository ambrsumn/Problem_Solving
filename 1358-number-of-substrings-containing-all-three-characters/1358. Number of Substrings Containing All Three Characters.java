class Solution {
    public int numberOfSubstrings(String s) {

        int i=0, j=0;
        int a=0, b=0, c=0;

        int ans = 0;

        // System.out.println("Start ");


        while(j<s.length())
        {
                // System.out.println(s.charAt(j));

            if(s.charAt(j) == 'a')a++;
            else if(s.charAt(j) == 'b')b++;
            else if(s.charAt(j) == 'c')c++;

            // System.out.println("Values ");
            // System.out.print(a + " ");
            // System.out.print(b + " ");
            // System.out.println(c + " ");
            


            if(a>0 && b>0 && c>0)
            {
                ans += (s.length() - j);
                // System.out.println(ans + " ");
            }

            while(i<=j && (a>0 && b>0 && c>0))
            {
                // System.out.println("INSIDE ");


                if(s.charAt(i) == 'a')a--;
                else if(s.charAt(i) == 'b')b--;
                else if(s.charAt(i) == 'c')c--;

                // System.out.println("Values ");
                // System.out.print(a + " ");
                // System.out.print(b + " ");
                // System.out.println(c + " ");

                if(a>0 && b>0 && c>0)
                {
                    ans += (s.length() - j);
                    // System.out.println(ans + " ");

                }

                i++;
            }

                // System.out.println("OUTSIDE ");


            j++;
        }

        // System.out.println(ans);

        return ans;
        
    }
}