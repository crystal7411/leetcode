class Solution {
	int sum = 0;
public:
	int traverse(TreeNode* node, int val)
	{
		if (node == 0)
			return 0;

		if (node->left == 0 && node->right == 0)
			sum += (val * 10) + (node->val);

		val = (val * 10) + (node->val);
		traverse(node->left, val);
		traverse(node->right, val);

		return val;
	}

	int sumNumbers(TreeNode* root) {
		traverse(root, 0);
	//	printf("sum : %d\n", sum);
		return sum;
	}
};