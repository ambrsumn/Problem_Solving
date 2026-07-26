class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int rows = grid.length;
        int cols = grid[0].length;

        List<List<Integer>> ans = new ArrayList<>();
        List<List<Integer>> temp = new ArrayList<>();

        for (int i = 0; i < rows; i++) {
            ans.add(new ArrayList<>());
            temp.add(new ArrayList<>());
            for (int j = 0; j < cols; j++) {
                ans.get(i).add(grid[i][j]);
                temp.get(i).add(grid[i][j]);
            }
        }

        while (k > 0) {
            for (int i = 0; i < rows; i++) {

                for (int j = 0; j < cols; j++) {

                    // IO.println(grid[j][i]);

                    if (i == rows - 1 && j == cols - 1) {
                        ans.get(0).set(0, temp.get(i).get(j));
                    }

                    else if (j == cols - 1) {
                        ans.get(i + 1).set(0, temp.get(i).get(j));
                    } else {
                        ans.get(i).set(j + 1, temp.get(i).get(j));
                    }
                }
            }

            temp = new ArrayList<>();
            for (int i = 0; i < rows; i++)
                temp.add(new ArrayList<>(ans.get(i)));
            k--;
        }

        return ans;
    }
}