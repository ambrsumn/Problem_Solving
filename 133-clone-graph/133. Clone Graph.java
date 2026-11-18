/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {

    public Node ans = null;
    Set<Node> visited;
    Map<Node, Node> mapper;

    public void recur(Node node) {
        if (node == null)
            return;
        if (visited.contains(node))
            return;

        visited.add(node);

        if (!mapper.containsKey(node)) {
            Node newNode = new Node(node.val);
            mapper.put(node, newNode);
            ans = newNode;
        }

        Node clone = mapper.get(node);

        for (Node n : node.neighbors) {
            Node childClone = null;
            if(mapper.containsKey(n))childClone = mapper.get(n);
            else 
            {
                childClone = new Node(n.val);
                mapper.put(n, childClone);
            }

            clone.neighbors.add(childClone);
        }

        for (Node n : node.neighbors) {
            if(!visited.contains(n))recur(n);
        }

        return;
    }

    public Node cloneGraph(Node node) {
        visited = new HashSet<>();
        mapper = new HashMap<>();

        recur(node);

        return ans;
    }
}