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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ans = head;
        ListNode* temp = head;//移除點
        ListNode* next_insert = head;//插入點
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;
        for(int i = 1; i < n; i = i + 2){
            cout << i;
            ListNode* last = temp->next;
            temp = temp->next->next;
            if(!temp){
                break;
            }
            else{
                last->next = temp->next;
                ListNode* tmp = next_insert->next;
                next_insert->next = temp;
                temp->next = tmp;
            
            
                temp = last;
                cout << temp->val << endl;
                next_insert = next_insert->next;
            }
        }
        return ans;
    }
};
