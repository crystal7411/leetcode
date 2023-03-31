class Solution {
	int max = INT_MIN;
public:
	long long calculate(vector<int>& time, int target, long long mid) {
		long long sum = 0;
		for (int t : time) {
			sum += mid / t;
		}
		if (sum >= target) {
			return mid;
		}
		return -1;
	}

	long long minimumTime(vector<int>& time, int totalTrips) {
		int n = time.size();
		long long max = *max_element(time.begin(), time.end());
		long long start = 0, end = max * totalTrips;
		long long result = end;

		while (start <= end) {
			long long mid = (start + end) / 2;
			long long ret = calculate(time, totalTrips, mid);
			if (ret != -1) {
				result = min(result, ret);
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		return result;
	}
};
