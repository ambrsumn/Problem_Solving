class Solution {

    HashSet<List<String>> ans;

    public boolean isInvalid(List<String> currList) {
        int n = currList.size();
        if (n == 0)
            return false;
        int m = currList.get(0).length();

        int[][] board = new int[n][m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (currList.get(i).charAt(j) == 'Q' && board[i][j] == 1)
                    return true;

                if (currList.get(i).charAt(j) == 'Q') {
                    for (int k = 0; k < n; k++)
                        board[k][j] = 1;
                    for (int k = 0; k < n; k++)
                        board[i][k] = 1;

                    int step = 1;

                    while (i + step < n && j + step < m) {
                        board[i + step][j + step] = 1;
                        step++;
                    }
                    step = 1;
                    while (i - step >= 0 && j - step >= 0) {
                        board[i - step][j - step] = 1;
                        step++;
                    }
                    step = 1;

                    while (i + step < n && j - step >= 0) {

                        board[i + step][j - step] = 1;

                        step++;

                    }

                    step = 1;

                    while (i - step >= 0 && j + step < m) {

                        board[i - step][j + step] = 1;

                        step++;

                    }
                }
            }
        }

        return false;
    }

    public void recur(int i, int n, StringBuilder curr, List<String> currList) {
        if (isInvalid(currList))
            return;

        if (i >= n) {
            ans.add(new ArrayList<>(currList));
            return;
        }

        StringBuilder thisRow = new StringBuilder("");
        for (int k = 0; k < n; k++)
            thisRow.append('.');

        for (int k = 0; k < n; k++) {
            thisRow.setCharAt(k, 'Q');
            currList.add(thisRow.toString());
            StringBuilder nextRow = new StringBuilder("");

            recur(i + 1, n, nextRow, currList);

            thisRow.setCharAt(k, '.');
            currList.remove(currList.size() - 1);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        ans = new HashSet<>();
        List<String> currList = new ArrayList<>();
        StringBuilder thisRow = new StringBuilder("");

        recur(0, n, thisRow, currList);
        return new ArrayList<>(ans);
    }
}