/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //reservoir sampling
private:
    ListNode* temp;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    
    Solution(ListNode* head) {
        temp = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int result = INT_MIN;
        ListNode* visit = temp;
        int k = 1;
        while(visit){
            int r = random() % k;
            if(r == 0){
                result = visit->val;    
            }
            ++ k;
            visit = visit->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
