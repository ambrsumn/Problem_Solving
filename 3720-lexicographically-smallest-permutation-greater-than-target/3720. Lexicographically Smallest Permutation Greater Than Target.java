class Solution {

public Pair<Integer, Integer> bs(ArrayList<Character> vec, char target) {
    int i = 0, j = vec.size() - 1;
    int idx2 = -1;

    // Find first element >= target
    while (i <= j) {
        int mid = i + (j - i) / 2;

        if (vec.get(mid) >= target) {
            idx2 = mid;
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }

    if (idx2 == -1)
        return new Pair<>(-1, -1);

    // If first >= target is target,
    // find first occurrence by moving backward.
    int idx = idx2;

    if (vec.get(idx) == target) {
        while (idx - 1 >= 0 && vec.get(idx - 1) == target)
            idx--;
    } else {
        // No exact target exists.
        idx = -1;
    }

    // idx2 currently means first >= target.
    // For recursion, we need first > target.
    if (vec.get(idx2) == target) {
        while (idx2 < vec.size() && vec.get(idx2) == target)
            idx2++;
    }

    if (idx2 == vec.size())
        idx2 = -1;

    return new Pair<>(idx, idx2);
}

    public String recur(int i, StringBuilder curr, String target, ArrayList<Character> vec, int n) {
        if (curr.length() == n) {
            if (curr.toString().compareTo(target) > 0)
                return curr.toString();

            return "{";
        }

        Pair<Integer, Integer> pr = bs(vec, target.charAt(i));
        // IO.println(curr + " " + pr.getKey() + " " + pr.getValue() + " " + target.charAt(i));
        // IO.println(vec);


        StringBuilder same = new StringBuilder("{");
        StringBuilder next = new StringBuilder("{");

        if (pr.getKey() != -1) {
            ArrayList<Character> n1 = new ArrayList<>(vec);
            StringBuilder curr1 = new StringBuilder(curr);
            curr1.append(n1.get(pr.getKey()));
            // IO.println("original " + n1);
            n1.remove(pr.getKey().intValue());
            // IO.println("modified ---- " + n1);

            same = new StringBuilder(recur(i + 1, curr1, target, n1, n));
        }

        if (pr.getValue() != -1) {
            ArrayList<Character> n1 = new ArrayList<>(vec);
            StringBuilder curr1 = new StringBuilder(curr);
            curr1.append(n1.get(pr.getValue()));
            
            n1.remove(pr.getValue().intValue());

            StringBuilder sb = new StringBuilder();

            for (char c : n1) {
                sb.append(c);
            }

            curr1.append(sb);
            next = curr1;

            // IO.println("next str ---- " + next);
        }

        // IO.println(curr + " " + same + " " + next);

        return same.toString().compareTo(next.toString()) < 0 ? same.toString() : next.toString();
    }

    public String lexGreaterPermutation(String s, String target) {

        // char[] arr = new char[s.length()];
        ArrayList<Character> vec = new ArrayList<>();
        int n = s.length();

        for (int i = 0; i < n; i++)
            vec.add(s.charAt(i));
        vec.sort(null);

        StringBuilder st = new StringBuilder("");
        String ans = recur(0, st, target, vec, target.length());
        return ans.equals("{") ? "" : ans;
    }
}