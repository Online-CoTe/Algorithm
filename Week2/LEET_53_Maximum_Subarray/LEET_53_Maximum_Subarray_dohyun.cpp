class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }
private:
    int maxSubArrayHelper(vector<int>& nums, int i, int j) {
        if (i==j) return nums[i];
        int mid = (i+j)/2;
        int a = maxSubArrayHelper(nums, i, mid);
        int b = maxSubArrayHelper(nums, mid+1, j);
        int aa = -1e6, sum = 0;
        for (int k=mid+1; k<=j; k++) {
            sum += nums[k];
            aa = max(sum, aa);
        }
        int bb = -1e6;
        sum = 0;
        for (int k=mid; k>=i; k--) {
            sum += nums[k];
            bb = max(sum, bb);
        }
        int result = max(max(a, b), aa+bb);
        return result;
    }
};