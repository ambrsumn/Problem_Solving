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
    ListNode first = null;
    ListNode prev = null;
    ListNode temp = null;
    int count=0;
    int len = 0;

    public void recur(ListNode head)
    {
        if(head == null)return;

        recur(head.next);

        if(count >= len/2)return;

        if(prev != null)prev.next = first;
        temp = first;
        first = first.next;
        temp.next = head;
        head.next = null;

        prev = head;
        count++;
    }
    public void reorderList(ListNode head) {

        if(head.next == null)return;

        first = head;
        newHead = head;

        while(head != null)
        {
            head = head.next;
            len++;
        }

        head = first;
        recur(head);

        if(len%2 != 0)
        {
            prev.next = first;
            first.next = null;
        }
        return;
    }
}