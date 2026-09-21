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

    public ListNode recur(ListNode head1, ListNode head2, int carry) {
        if (head1 == null && head2 == null) {
            if (carry == 0)
                return null;
            return new ListNode(carry);
        }

        if (head2 == null) {
            ListNode h = null;
            ListNode temp = null;

            while (head1 != null) {
                int val = head1.val + carry;
                carry = 0;
                int actual = val;
                if (val >= 10) {
                    actual = val % 10;
                    carry = val / 10;
                }

                if (h == null) {
                    h = new ListNode(actual);
                    temp = h;
                } else {
                    ListNode newNode = new ListNode(actual);
                    temp.next = newNode;
                    temp = newNode;
                }

                head1 = head1.next;
            }
            if(carry>0)temp.next = new ListNode(carry);

            return h;
        }

        if (head1 == null) {
            ListNode h = null;
            ListNode temp = null;

            while (head2 != null) {
                int val = head2.val + carry;
                carry = 0;
                int actual = val;
                if (val >= 10) {
                    actual = val % 10;
                    carry = val / 10;
                }

                if (h == null) {
                    h = new ListNode(actual);
                    temp = h;
                } else {
                    ListNode newNode = new ListNode(actual);
                    temp.next = newNode;
                    temp = newNode;
                }

                head2 = head2.next;
            }
            if(carry>0)temp.next = new ListNode(carry);

            return h;
        }

        int val = head2.val + head1.val + carry;
        carry = 0;
        int actual = val;
        if (val >= 10) {
            actual = val % 10;
            carry = val / 10;
        }
        // IO.println(val + " " + carry);

        ListNode newNode = new ListNode(actual);
        newNode.next = recur(head1.next, head2.next, carry);
        return newNode;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode newNode = recur(l1, l2, 0);
        return newNode;

    }
}