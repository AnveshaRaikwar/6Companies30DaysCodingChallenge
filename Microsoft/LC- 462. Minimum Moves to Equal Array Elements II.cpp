class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[n/2];

        int ans=0;
        for(int i=0; i<n; i++){
            //no need to skip median bocz whle subtracting it becomes 0
            ans+=abs(nums[i]-median);
        }
        return ans;
    }
};