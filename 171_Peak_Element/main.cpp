class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return recur(nums, 0, n - 1);
    }

    int recur(const vector<int> &nums, int begin, int end) {
        if (begin > end) {
            return -1;
        }

        int mid = (end - begin) / 2 + begin;
        if ((mid == nums.size() - 1|| nums[mid] > nums[mid + 1]) && (mid == 0 || nums[mid] > nums[mid - 1])) {
            return mid;
        }
        else {
            int ans;
            return (ans = recur(nums, begin, mid - 1)) != -1 ? ans : recur(nums, mid + 1, end);
        }
    }
};


