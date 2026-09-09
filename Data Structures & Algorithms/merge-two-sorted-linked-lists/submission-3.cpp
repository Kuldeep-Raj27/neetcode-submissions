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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* main = nullptr;
        ListNode* anod = nullptr;

        // handling nullptr list
        if(list1==nullptr || list2==nullptr){
            if(list1!=nullptr){
                return list1;
            }
            return list2;
        }

// approach - in place merge
        if(list1->val > list2->val){
            main = list2;
            anod = list1;
        }
        else{
            main = list1;
            anod = list2;
        }

        ListNode* curr = main;
        ListNode* save = nullptr;
        while(true){
            if(curr->next ==nullptr){
                curr->next = anod;
                break;
            }
            if(anod->val < curr->next->val){
                 save = curr->next;
                 curr->next = anod;
                 curr = curr->next;   
                 anod = save;              
            }
            else{
                curr= curr->next;
            }

        }

        return main;
    }
};
