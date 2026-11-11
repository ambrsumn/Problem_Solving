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

        List<Integer> list = new ArrayList<>();

        ListNode temp = head;

        while(temp != null)
        {
            list.add(temp.val);
            temp = temp.next;
        }

        List<Integer> rotatedList = new ArrayList<>(list);

        for(int i=0; i<list.size(); i++)rotatedList.set((i+k)%list.size(), list.get(i));

        temp = head;
        int i=0;

        while(temp != null)
        {
            temp.val = rotatedList.get(i);
            i++;
            temp = temp.next;
        }
        
        return head;
    }
}