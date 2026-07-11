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
    ListNode* reverse(ListNode* head) {
        ListNode* prev= NULL;
        ListNode* temp= head;

        while (temp) {
            ListNode* next= temp->next; 
            temp->next= prev;           
            prev= temp;                 
            temp= next;                 
        }

        return prev; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;

        while(temp){
            ListNode* kthnode= temp;
            int count=1;

            while(count<k && kthnode){
                kthnode=kthnode->next;
                count++;
            }

            //less than k nodes left, don't reverse
            if(kthnode==NULL){
                if(prev){
                    prev->next=temp;
                }
                break;
            }

            ListNode* next= kthnode->next;
            kthnode->next=NULL;

            ListNode* newhead=reverse(temp);

            //connecting prev group to current reversed group
            if (temp==head) head=newhead;  //first group
            else prev->next = newhead;

            prev=temp;
            temp=next;
        }
        return head;
    }
};