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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp = head;
        ListNode* start = head;
        int count=0;
        while(temp!= nullptr){
            count++;
            s.push(temp);
            temp = temp->next;
        }
        if(count%2==0){

          for(int i=1; i<=(count/2);i++){
           
            ListNode* endNode = s.top();
            s.pop();
            ListNode* temp1 = start;
            start = start->next;
            temp1->next = endNode;
            endNode->next = start;
             if(i==count/2){
                endNode->next = nullptr;
                break;
            }
          }
        }
        else{

            for(int i=1; i<=(count/2 + 1);i++){
                if(i==(count+1)/2){
                    start->next = nullptr;
                    break;
                }
            ListNode* endNode = s.top();
            s.pop();
            ListNode* temp1 = start;
            start = start->next;
            temp1->next = endNode;
            endNode->next = start;
          }

        }
    }
};
