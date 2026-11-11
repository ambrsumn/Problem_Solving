class Solution {

    Map<Pair<Integer, Integer>, Integer> dp = new HashMap<>();

    public int recur(int i, int j, int m, int n, int[][] grid)
    {
        if(i == m-1 && j == n-1)return grid[m-1][n-1];
        if(i>=m || j >= n)return Integer.MAX_VALUE;

        if(dp.containsKey(new Pair<>(i, j)))return dp.get(new Pair<>(i, j));

        dp.put(new Pair<>(i, j), grid[i][j] + Math.min(recur(i+1, j, m, n, grid), recur(i, j+1, m, n, grid)));
        return dp.get(new Pair<>(i, j));
    }
    public int minPathSum(int[][] grid) {

        return recur(0, 0, grid.length, grid[0].length, grid);
    }
}