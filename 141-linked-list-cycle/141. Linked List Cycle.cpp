/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//  HEIR TORTOISE ALGORITHM -> TO DETECT CYCLE IN A LINKED LIST
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == NULL)return false;

        ListNode* kanika = head;
        ListNode* vanshika = head;

        // [1,2,3,4]

        while(vanshika != NULL && vanshika->next != NULL)
        {
            kanika = kanika->next;
            vanshika = vanshika->next->next;

            if(kanika == vanshika)return true;
        }

        return false;
    }
};