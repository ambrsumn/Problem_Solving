/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {

        Node temp = head;
        Node newHead = null;

        Map<Node, Node> mpp = new HashMap<>();

        while(temp != null)
        {
            if(!mpp.containsKey(temp))
            {
                Node newNode = new Node(temp.val);
                mpp.put(temp, newNode);

                if(newHead == null)newHead = newNode;
            }

            Node currentNode = mpp.get(temp);

            Node next = temp.next;
            Node random = temp.random;

            if(next != null && !mpp.containsKey(next))
            {
                Node nextNode = new Node(next.val);
                mpp.put(next, nextNode);
            }
            if(random != null && !mpp.containsKey(random))
            {
                Node randomNode = new Node(random.val);
                mpp.put(random, randomNode);
            }

            currentNode.next = mpp.get(next);
            currentNode.random = mpp.get(random);

            temp = temp.next;
        }

        return newHead;
    }
}