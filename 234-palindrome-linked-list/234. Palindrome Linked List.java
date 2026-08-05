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

    public void recur(ListNode head, ArrayList<Integer> arr)
    {
        if(head == null)return;

        recur(head.next, arr);
        arr.add(head.val);
    }

    public boolean isPalindrome(ListNode head) {

        ArrayList<Integer> arr = new ArrayList<Integer>();
        ListNode temp = head;

        recur(temp, arr);
        int i=0;
        while(head != null)
        {
            if(head.val != arr.get(i))return false;
            head = head.next;
            i++;
        }

        return true;
    }
}