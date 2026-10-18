class Solution {
    public int[] lastVisitedCell(char[][] grid) {

        int n = grid.length;
        int m = grid[0].length;
        int[][] visited = new int[n][m];

        int[] curr = { 0, 0 };
        while (true) {
            int i = curr[0];
            int j = curr[1];
            visited[i][j] = 1;

            char dir = grid[i][j];
            // IO.println(i + " " + j + " " + dir);

            if (dir == 'U') {
                if (i - 1 < 0 || visited[i - 1][j] == 1)
                    return curr;
                curr[0] = i - 1;
                continue;
            }

            if (dir == 'D') {
                if (i + 1 >= n || visited[i + 1][j] == 1)
                    return curr;
                curr[0] = i + 1;

                continue;
            }

            if (dir == 'L') {
                if (j - 1 < 0 || visited[i][j - 1] == 1)
                    return curr;
                curr[1] = j - 1;

                continue;
            }

            if (dir == 'R') {
                if (j + 1 >= m || visited[i][j + 1] == 1)
                    return curr;
                curr[1] = j + 1;

                continue;
            }
        }
    }
}