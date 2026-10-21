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

    private StringBuilder getNumber(ListNode l1)
    {
        StringBuilder str = new StringBuilder("");

        while(l1 != null)
        {
            str.append((char)(l1.val+48));
            l1 = l1.next;
        }

        return str;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if(l1 == null)return l2;
        if(l2 == null)return l1;

        StringBuilder s1 = getNumber(l2); 
        StringBuilder s2 = getNumber(l1);

        s1.reverse();
        s2.reverse();
        
        ListNode ans = null;

        int i=0;
        int carry = 0;
        while(i < Math.max(s1.length(), s2.length()) || carry > 0)
        {
            int curr = carry;
            if(i < s1.length())
            {
                curr += (int)(s1.charAt(i) - 48);
            }

            if(i < s2.length())
            {
                curr += (int)(s2.charAt(i) - 48);
            }

            carry = curr/10;

            ListNode temp = new ListNode(curr%10); 

            if(ans == null)
            {
                ans = temp;
            }
            else 
            {
                temp.next = ans;
                ans = temp;
            }

            i++;
        }

        return ans;
    }
}