class Solution {
	bool is_exist = 0;
public:
	void traverse(TreeNode *root, int val, int target)
	{
		if (root == 0)
			return;

		val = root->val + val;

		if (root->left == 0 && root->right == 0) // leaf node
		{
			if (val == target)
				is_exist = 1;
		}

		traverse(root->left, val, target);
		traverse(root->right, val, target);
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		traverse(root, 0, targetSum);

		return is_exist;
	}
};
