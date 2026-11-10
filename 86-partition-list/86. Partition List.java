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
    public ListNode partition(ListNode head, int x) {

        List<Pair<Integer, Integer>> list = new ArrayList<>();

        ListNode temp = head;
        int i=0;

        while(head != null)
        {
            list.add(new Pair<>(head.val, i));
            head = head.next;
            i++;
        }

        // IO.println(list);

        list.sort((a, b)->
        {
            if((a.getKey() < x && b.getKey() < x) || (a.getKey() >= x && b.getKey() >= x))
                return a.getValue() - b.getValue();
            return a.getKey() - b.getKey();
        });

        // IO.println(list);

        head = temp;

        i=0;
        while(head != null)
        {
            head.val = list.get(i).getKey();
            head = head.next;
            i++;
        }
        return temp;
    }
}