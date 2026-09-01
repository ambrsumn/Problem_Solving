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
    ListNode temp;

    public ListNode recur(ListNode head) {
        if (head == null)
            return null;
        if (head.next == null)
        {
            if(temp == null)temp = head;
            IO.println(temp.val);
            return head;
        }

        ListNode parent = recur(head.next);
        parent.next = head;
        head.next = null;

        return head;
    }

    public ListNode reverseList(ListNode head) {

        recur(head);

        return temp;
    }
}