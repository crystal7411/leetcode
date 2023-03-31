class Solution {
	queue<pair<TreeNode*, int>> treeq;
	bool is_exist = 0;
public:
	void traverse(TreeNode *root, int val, int target)
	{
		if (root == 0)
			return;

		treeq.push({ root, root->val });

		while (!treeq.empty())
		{
			TreeNode *cur = treeq.front().first;
			int curval = treeq.front().second;

			treeq.pop();

			if (cur->left == 0 && cur->right == 0) // leaf node
				if (curval == target)
					is_exist = 1;

			if (cur->left != 0)
				treeq.push({ cur->left, curval + cur->left->val });

			if (cur->right != 0)
				treeq.push({ cur->right, curval + cur->right->val });
		}
	}

	bool hasPathSum(TreeNode* root, int targetSum) {
		traverse(root, 0, targetSum);

		return is_exist;
	}
};