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
    ListNode newHead = null;

    public void recur(ListNode head, ListNode prev) {
        if (head == null)
            return;

        if (head.next != null) {

            ListNode temp = head.next;
            if(prev != null)prev.next = temp;
            ListNode nn = null;
            if(temp.next != null)nn = temp.next;
            head.next = nn;
            temp.next = head;

            if(newHead == null)newHead = temp;

        }

        // IO.println(head.val + " " +head.next.val + " " + newHead.val);
        recur(head.next, head);
    }

    public ListNode swapPairs(ListNode head) {

        if(head == null || head.next == null)return head;
        recur(head, null);

        return newHead;

    }
}