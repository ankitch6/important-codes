/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void FrontBackSplit(ListNode* head, ListNode** a, ListNode** b)
    {
        ListNode *fast = head, *slow = head;
        fast = fast->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        *a = head;
        *b = slow->next;
        slow->next = NULL;
        //next of last node of the first list should point to NULL
    }

    ListNode* SortedMerge(ListNode* a, ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;

        ListNode* result = NULL;

        if(a->val < b->val)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return result;
    }

    void MergeSort(ListNode** headref)
    {
        ListNode* head = *headref;

        if(!head || !(head->next))
            return;

        //now we divide the list into two halves
        ListNode *a = NULL, *b = NULL;
        FrontBackSplit(head, &a, &b);
        //sort both the halves
        MergeSort(&a);
        MergeSort(&b);

        *headref = SortedMerge(a,b);
    }
    ListNode* sortList(ListNode* head) {

        //call mergesort using this function
        MergeSort(&head);
        return head;
    }
};
