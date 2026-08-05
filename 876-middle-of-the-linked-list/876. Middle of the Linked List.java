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

    public int recur(ListNode head)
    {
        int count = 0;

        while(head != null)
        {
            count++;
            head = head.next;
        }

        return (count/2 + 1);
    }

    public ListNode middleNode(ListNode head) 
    {
        ListNode temp = head;
        int mid = recur(temp);
        int curr = 1;

        while(curr != mid)
        {
            head = head.next;
            curr++;
        }

        return head;

    }
}