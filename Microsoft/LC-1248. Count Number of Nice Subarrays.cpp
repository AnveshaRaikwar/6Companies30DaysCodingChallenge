class Solution {
public:

    // //METHOD 1
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     // method 1 =(all methods by striver) taking all subarray by using prefixSum 
    //     // take modulus for odd and even.
    //     // converting to question count subarray sum equals k
    //     int n=nums.size();
    //     unordered_map<int,int> map;
    //     map[0]=1;
    //     int presum=0;
    //     int cnt=0;
    //     for(int i=0; i<n; i++){
    //         presum += nums[i]%2;
    //         int subarrayInPresum = presum-k;
    //         cnt += map[subarrayInPresum];
    //         map[presum] += 1;
    //     }
    //     return cnt;
    // }

    //METHOD 2

    int solveGoal(vector<int>& nums, int goal){
        if(goal<0) return 0;

        int l=0, r=0, n=nums.size(), sum=0, cnt=0;
        while(r < n){
            sum = sum + (nums[r] % 2);
            while(sum > goal){
                sum = sum - (nums[l] % 2);
                l=l+1;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k){
        return solveGoal(nums,k) - solveGoal(nums,k-1);
    }
};