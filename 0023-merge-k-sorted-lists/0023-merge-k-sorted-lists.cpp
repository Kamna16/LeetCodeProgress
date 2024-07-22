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
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* result;
        if(list1->val <= list2->val)
        {
            result = list1;
            result->next = mergeTwoLists(list1->next,list2);
        }else{
            result = list2;
            result->next = mergeTwoLists(list1,list2->next);
        }
        return result;
    }
    ListNode* partitionMerge(int s, int e,vector<ListNode*>& lists){
        if(s>e) return NULL;
        if(s == e) return lists[s];
        int mid = s+(e-s)/2;
        ListNode* l1 = partitionMerge(s,mid,lists);
        ListNode* l2 = partitionMerge(mid+1,e,lists);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int  k = lists.size();
        if(k ==0) return NULL;
        return partitionMerge(0,k-1,lists);
    }
};