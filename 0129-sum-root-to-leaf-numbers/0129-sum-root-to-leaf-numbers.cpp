class Solution {
	int sum = 0;
public:
	void traverse(TreeNode* node, int prev)
	{
		if (node == 0)
			return;

		int newval = (prev * 10) + (node->val); // 10배씩 증가시키면서 자식노드까지 전달

		if (node->left == 0 && node->right == 0) // 리프노드 도달
		{
			sum += newval;
			return;
		}

		traverse(node->left, newval);
		traverse(node->right, newval);
	}

	int sumNumbers(TreeNode* root) {
		traverse(root, 0);
		printf("sum : %d\n", sum);
		return sum;
	}
};