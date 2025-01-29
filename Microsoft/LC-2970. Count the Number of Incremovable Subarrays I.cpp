class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
    int m = nums.size();
    int ans = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            bool flag = true;
            int last = -1;
            for (int k = 0; k < m ; k++) {
                // Skip indices within [i, j]
                if (k >= i && k <= j) continue;
                if(last >= nums[k]){
                    flag = false;
                    break;
                }
                last = nums[k];
            }

            if (flag) ans++;
        }
    }

    return ans;
    }
};