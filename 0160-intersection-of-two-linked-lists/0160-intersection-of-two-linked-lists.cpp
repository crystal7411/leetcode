class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* nodeA = headA;
		ListNode* nodeB = headB;

		while (nodeA && nodeB) {
			if (nodeA == nodeB) 
				return nodeA;
			
			nodeA = nodeA->next;
			nodeB = nodeB->next;

			if (!nodeA && !nodeB) 
				return NULL;
			if (nodeA == NULL) 
				nodeA = headB;
			if (nodeB == NULL) 
				nodeB = headA;
		}
		return NULL;
	}
};
