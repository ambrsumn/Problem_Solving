/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {

        ListNode temp = head;
        List<Integer> list = new ArrayList<>();

        while (temp != null) {
            list.add(-1);
            temp = temp.next;
        }

        int i=0;
        temp = head;

        while (temp != null) {

            int newPos = (i+k)%list.size();
            list.set(newPos, temp.val);
            temp = temp.next;
            i++;
        }

        temp = head;
        i=0;
        while (temp != null) {
            temp.val = list.get(i);
            i++;
            temp = temp.next;
        }

        return head;
    }
}