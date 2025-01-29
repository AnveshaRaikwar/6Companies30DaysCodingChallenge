class Solution {
public:

    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum = 0;
        long long maxi =0;

        unordered_set<int> st;

        int i=0, j=0;
        while(j<n){

            while(st.count(nums[j])){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            st.insert(nums[j]);

            if(j-i+1==k){
                maxi = max(maxi,sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return maxi;
        
    }
};