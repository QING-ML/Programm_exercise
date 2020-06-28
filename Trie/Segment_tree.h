#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

class NumArray {
public:
	NumArray(vector<int>& nums) {
		if (nums.size() == 0) {
			return;
		}
		int n = log2(nums.size()) + 2;
		int size_v = 0;
		for (int i = 0; i <= n; i++) {
			size_v += pow(2, i);
		}
		for (int i = 0; i < size_v; i++) {
			_value.push_back(0);
		}
		build_segment_tree(_value, nums, 0, 0, nums.size() - 1);
		_right_end = nums.size() - 1;
	}

	void update(int i, int val) {
		update_segment_tree(_value, 0, 0, _right_end, i, val);
	}

	int sumRange(int i, int j) {
		return sum_range_segment_tree(_value, 0, 0, _right_end, i, j);
	}

	void build_segment_tree(vector<int> &value, vector<int> &nums, int pos, int left, int right) {
		//pos: index of _value
		//left: left boundry of nums index
		//right: right boundry of nums index

		if (left == right) {
			value[pos] = nums[left];
			return;
		}
		int mid = (left + right) / 2;
		build_segment_tree(value, nums, pos * 2 + 1, left, mid);
		build_segment_tree(value, nums, pos * 2 + 2, mid + 1, right);

		value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];

	}

	int sum_range_segment_tree(vector<int> &value, int pos, int left, int right,
		int qleft, int qright) {
		if (qleft > right || qright < left) {
			return 0;
		}
		if (qleft <= left && qright >= right) {
			return value[pos];
		}
		int mid = (left + right) / 2;
		return sum_range_segment_tree(value, pos * 2 + 1, left,
			mid, qleft, qright) +
			sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
	}

	void update_segment_tree(vector<int> &value, int pos, int left,
		int right, int index, int new_value) {
		//index: index of nums
		if (left == right && left == index) {
			value[pos] = new_value;
			return;
		}
		int mid = (left + right) / 2;
		if (index <= mid) {
			update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
		}
		else {
			update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
		}
		value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
	}
private:
	vector<int> _value;
	int _right_end;
};

int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	NumArray num_array(nums);
	printf("%d\n", num_array.sumRange(0, 2));
	num_array.update(1, 2);
	printf("%d\n", num_array.sumRange(0, 2));
	return 0;
}