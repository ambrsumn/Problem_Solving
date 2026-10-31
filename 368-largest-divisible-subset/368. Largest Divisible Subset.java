class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<List<Integer>> allowed = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        int[] indegree = new int[n];
        int ans = 0;
        int[] parent = new int[n];
        List<Integer> last = new ArrayList<>();
        List<Integer> before = new ArrayList<>();

        for (int i = 0; i < n; i++)
            parent[i] = -1;

        for (int i = 0; i < n; i++) {
            allowed.add(new ArrayList<>());
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    allowed.get(i).add(j);
                    indegree[j]++;
                }
            }
        }

        Deque<Integer> zeroDegrees = new ArrayDeque<>();
        last.clear();

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                zeroDegrees.addLast(i);
                last.add(i);
                indegree[i]--;
            }
        }

        while (!zeroDegrees.isEmpty()) {
            // //IO.println("itr " + last);
            before = new ArrayList<>(last);
            last.clear();
            ans++;
            int currSize = zeroDegrees.size();

            while (currSize > 0) {
                int p = zeroDegrees.removeFirst();
                currSize--;

                for (Integer it : allowed.get(p)) {
                    indegree[it]--;

                    if (indegree[it] == 0) {
                        parent[it] = p;
                        zeroDegrees.addLast(it);
                        last.add(it);
                    }
                }
            }
        }

        //IO.println(ans);
        //IO.println(before);
        // for (int i = 0; i < n; i++)
        //IO.println(i + " -> " + parent[i]);

        List<Integer> answer = new ArrayList<>();
        int start = before.get(0);

        while (start != -1) {
            answer.add(nums[start]);
            start = parent[start];
        }
        return answer;
    }
}