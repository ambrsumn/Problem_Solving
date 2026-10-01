class Solution {

    HashSet<Character>[] rows = new HashSet[9];
    HashSet<Character>[] cols = new HashSet[9];
    HashSet<Character>[] boxes = new HashSet[9];

    boolean ansFound = false;

    public void recur(int i, int j, char[][] board) {

        if (i == 9) {
            ansFound = true;
            return;
        }


        if (j == 9) {
            recur(i + 1, 0, board);
            return;
        }


        if (board[i][j] != '.') {
            recur(i, j + 1, board);
            return;
        }

        int box = (i / 3) * 3 + (j / 3);

        for (char ch = '1'; ch <= '9'; ch++) {


            if (rows[i].contains(ch) ||
                cols[j].contains(ch) ||
                boxes[box].contains(ch)) {
                continue;
            }


            board[i][j] = ch;

            rows[i].add(ch);
            cols[j].add(ch);
            boxes[box].add(ch);

            recur(i, j + 1, board);


            if (ansFound)
                return;


            board[i][j] = '.';

            rows[i].remove(ch);
            cols[j].remove(ch);
            boxes[box].remove(ch);
        }
    }

    public void solveSudoku(char[][] board) {

        for (int i = 0; i < 9; i++) {
            rows[i] = new HashSet<>();
            cols[i] = new HashSet<>();
            boxes[i] = new HashSet<>();
        }

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.')
                    continue;

                char ch = board[i][j];

                rows[i].add(ch);
                cols[j].add(ch);

                int box = (i / 3) * 3 + (j / 3);
                boxes[box].add(ch);
            }
        }

        recur(0, 0, board);
    }
}