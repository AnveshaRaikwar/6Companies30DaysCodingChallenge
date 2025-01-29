class Solution {
public:

    int solve(vector<int>& nums, int n, int prevSum, int totalSum, int maxi, int i){
        if(i>=n){
            return maxi;
        }

        int currsum = prevSum + totalSum - n * nums[n-i];

        maxi = max(maxi,currsum);

        return solve(nums, n, currsum, totalSum, maxi, i+1);
    }

    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum1=0,sum2=0;

        for(int i=0; i<n; i++){
            sum1+=nums[i];
            sum2 = sum2 + nums[i]*i;
        }

        return solve(nums,n, sum2, sum1, sum2,1);
    }
};