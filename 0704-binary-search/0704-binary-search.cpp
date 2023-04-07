class Solution {
public:
	int search(vector<int>& nums, int target) {

		int start = 0;
		int end = nums.size() - 1; // 5

		while (start <= end)
		{
			int mid = (start + end) / 2;
			printf("%d, %d, %d\n", start, end, mid);

			if (target < nums[mid]) // 중간 값보다 target이 작으면, 작은쪽으로 탐색
				end = mid - 1;
			else if (target > nums[mid])
				start = mid + 1;
			else if (target == nums[mid])
			{
				//printf("find %d\n", mid);
				return mid;
			}
		}

		return -1; // 못찾은 경우
	}
};