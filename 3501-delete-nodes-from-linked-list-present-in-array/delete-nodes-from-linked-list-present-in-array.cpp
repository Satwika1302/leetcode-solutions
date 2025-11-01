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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(int k:nums){
            mp[k]++;
        }      
        while(head!=NULL && mp[head->val]>0){
            head=head->next;
        }
        if(head==NULL)return NULL;
        ListNode* curr=head;
        while(curr->next!=NULL){
            if(mp[curr->next->val]>0){
                curr->next=curr->next->next;
            }else{
                curr=curr->next;
            }
        }
        return head;
    }
};