class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nums[26] = {0};

        for (int i = 0; i != tasks.size(); i++) {
            nums[tasks[i] - 'A']++;
        }

        sort(nums, nums + 26);
        int i = 24;
        int times = 1;
        while (i >= 0 && nums[i] == nums[i + 1]) {
            times++;
            i--;
        }

        return max((n + 1) * (nums[25] - 1) + times, (int)tasks.size());
    }
};
