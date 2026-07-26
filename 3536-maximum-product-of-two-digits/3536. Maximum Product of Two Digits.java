class Solution {
    public int maxProduct(int n) {

        Integer ans = Integer.valueOf(n);
        String str = ans.toString();

        char[] arr = str.toCharArray();
        Arrays.sort(arr);

        return ((arr[arr.length-1]-'0') * (arr[arr.length-2]-'0'));
        
    }
}