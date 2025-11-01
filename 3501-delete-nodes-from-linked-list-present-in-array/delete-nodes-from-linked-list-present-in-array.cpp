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
// 1.Initialize a set valuesToRemove and populate it with the values of the nums array.
// 2.While the head of the linked list is not null and the head's value is present in valuesToRemove:
// 3.Move head to head.next.
// 4.If the head is null, return null since all nodes have been removed.
// 5.Start iterating from the head of the modified list:
// 6.For each node current, check if the value of the next node (current.next) is in the valuesToRemove set.
// 7.If it is, skip the next node by updating current.next to current.next.next
// 8.If it is not, move the current pointer to the next node in the list.
// Return the updated head of the list.

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