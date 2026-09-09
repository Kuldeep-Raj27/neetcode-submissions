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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tempPtr = nullptr;
        ListNode* prevPtr = nullptr;

        while(head!=nullptr){
            tempPtr = head;
            head = tempPtr->next;
            tempPtr->next = prevPtr;
            prevPtr = tempPtr;
        }
        return tempPtr;
    }
};
