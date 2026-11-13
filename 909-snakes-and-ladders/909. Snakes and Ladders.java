class Solution {
    public int snakesAndLadders(int[][] board) {

        Map<Integer, Integer> transporters = new HashMap<>();
        int n = board.length;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != -1) {
                    int rowFromBottom = n - i - 1;
                    int st = 0;

                    if (rowFromBottom % 2 == 0)
                        st = rowFromBottom * n + j + 1;
                    else
                        st = rowFromBottom * n + n - j;

                    // IO.println(st + " -> " + i + " " + j);

                    transporters.put(st, board[i][j]);
                }
            }
        }
        // IO.println(transporters);

        int[] visited = new int[n * n + 1];
        Deque<Integer> q = new ArrayDeque<>();

        q.addFirst(1);
        visited[1] = 1;
        int ans = 0;

        while (!q.isEmpty()) {
            int currSize = q.size();
            ans++;
            while (currSize > 0) {
                int top = q.removeFirst();

                for (int j = top + 1; j <= Math.min(top + 6, n * n); j++) {
                    int pos = transporters.containsKey(j) ? transporters.get(j) : j;

                    // IO.println(top + " " + j + " " + pos);
                    if (pos == n * n || j == n * n)
                        return ans;
                    if (visited[pos] == 0) {
                        visited[pos] = 1;
                        q.addLast(pos);
                    }
                }

                currSize--;
            }
        }

        return -1;
    }
}