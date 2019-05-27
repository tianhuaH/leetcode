#include<iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *q = NULL, *p = NULL, *cur = head, *tmp = head;
		int step = 0, size = 0;
		while (size < k && tmp) {
			tmp = tmp->next;
			size++;
		}
		if (size == k) {
			while (step < k) {
				p = cur->next;
				cur->next = q;
				q = cur;
				cur = p;
				step++;
			}
			if (p)
				head->next = reverseKGroup(p, k);
			return q;
		}
		else
			return head;
	}

};