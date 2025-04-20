class Solution {
public:
    int arr[201][201];
    int n = 0, m = 0;

    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        arr[i][j] = 1;
        board[i][j] = 'T';

        if (i - 1 >= 0 && arr[i - 1][j] == -1 && board[i - 1][j] == 'O')
            dfs(i - 1, j, board);
        if (j - 1 >= 0 && arr[i][j - 1] == -1 && board[i][j-1] == 'O')
            dfs(i, j - 1, board);
        if (i + 1 < n && arr[i + 1][j] == -1 && board[i + 1][j] == 'O')
            dfs(i + 1, j, board);
        if (j + 1 < m && arr[i][j + 1] == -1 && board[i][j+1] == 'O')
            dfs(i, j + 1, board);
    }

    void solve(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();
        memset(arr, -1, sizeof(arr));

        for (int i = 0; i < n; i++)
            if (board[i][0] == 'O' && arr[i][0] == -1) {
                dfs(i, 0, board);
            }
        for (int i = 0; i < n; i++)
            if (board[i][m - 1] == 'O' && arr[i][m - 1] == -1) {
                dfs(i, m - 1, board);
            }

        for (int i = 0; i < m; i++)
            if (board[0][i] == 'O' && arr[0][i] == -1) {
                dfs(0, i, board);
            }
        for (int i = 0; i < m; i++)
            if (board[n - 1][i] == 'O' && arr[n - 1][i] == -1) {
                dfs(n - 1, i, board);
            }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 'T')
                    board[i][j] = 'X';
                else
                    board[i][j] = 'O';
            }
        }

        return;
    }
};