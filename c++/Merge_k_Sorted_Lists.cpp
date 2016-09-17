/*Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       ListNode *dummy = new ListNode(0), *tail = dummy;
       unordered_map<int, vector<ListNode*>> mp;
       vector<int> keys;
       for(int i = 0; i < lists.size(); i++){
           while(lists[i]){
               int key = lists[i]->val;
               if(mp.find(key) != mp.end()){
                   mp[key].push_back(lists[i]);
                   lists[i] = lists[i]->next;
               }
               else{
                   mp[key] = {lists[i]};
                   keys.push_back(key);
                   lists[i] = lists[i]->next;
               }
           }
       }
       sort(keys.begin(),keys.end());
       for(int i = 0; i < keys.size(); i++){
           for(int j = 0; j < mp[keys[i]].size(); j++){
               tail->next = mp[keys[i]][j];
               tail = tail->next;
           }
       }
       return dummy->next;
    }
};


class Solution {
public:
        struct compNode {
        bool operator()(ListNode *p, ListNode *q) const {
            return p->val>q->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
       ListNode *dummy = new ListNode(0), *tail = dummy;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()){
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if(tail->next) pq.push(tail->next);
        }
            return dummy->next;
    }
};
