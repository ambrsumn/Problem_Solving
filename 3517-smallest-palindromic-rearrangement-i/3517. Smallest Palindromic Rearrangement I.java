class Solution {
    public String smallestPalindrome(String s) {

        TreeMap<Character, Integer> mpp = new TreeMap<>();
        List<Character> temp = new ArrayList<>();
        String middle = "";
        int count = 0;

        for (char it : s.toCharArray()) {
            temp.add('0');

            if (mpp.containsKey(it))
                mpp.put(it, mpp.get(it) + 1);
            else
                mpp.put(it, 1);
        }

        for (char it : mpp.keySet()) {
            int val = mpp.get(it);

            if (val % 2 != 0) {
                middle += it;
                val--;
            }

            if (val > 0) {
                temp.set(count - 1 + val / 2, it);
                count = count + val / 2;
            }
        }

        // for (char it : temp)
        //     IO.print(it);
        // IO.println();

        while (temp.size() > 0 && temp.get(temp.size() - 1) == '0')
            temp.remove(temp.size() - 1);

        for (int i = temp.size() - 2; i >= 0; i--) {
            if (temp.get(i) == '0')
                temp.set(i, temp.get(i + 1));
        }

        // for (char it : temp)
        //     IO.print(it);
        // IO.println("\n" + middle);

        StringBuilder front = new StringBuilder();
        for (char c : temp)
            front.append(c);

        String rev = new StringBuilder(front).reverse().toString();

        return front + middle + rev;
    }

}