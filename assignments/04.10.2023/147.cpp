/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = head;

        while (curr)
        {
            ListNode *next = curr->next;
            ListNode *temp = dummy;

            while (temp->next && temp->next->val < curr->val)
            {
                temp = temp->next;
            }

            curr->next = temp->next;
            temp->next = curr;

            curr = next;
        }

        ListNode *result = dummy->next;
        // delete dummy;
        return result;
    }
};
