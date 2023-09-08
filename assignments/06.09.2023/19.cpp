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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        curr = head;

        while (count > n)
        {
            prev = curr;
            curr = curr->next;
            count--;
        }

        if (prev == NULL)
        {
            head = curr->next;
            delete curr;
        }
        else
        {
            prev->next = curr->next;
            delete curr;
        }

        return head;
    }
};
