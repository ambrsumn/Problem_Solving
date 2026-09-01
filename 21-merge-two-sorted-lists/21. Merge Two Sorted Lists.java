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

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        if (list1 == null && list2 == null)
            return null;
        if (list1 == null)
            return list2;
        if (list2 == null)
            return list1;

        ListNode temp;

        if (list1.val <= list2.val) {
            temp = new ListNode(list1.val);
            list1 = list1.next;
        } else {
            temp = new ListNode(list2.val);
            list2 = list2.next;
        }

        temp.next = mergeTwoLists(list1, list2);
        return temp;
    }
}