class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int,int>> st;
        int i=nums.size()-1;
        
        while(i>=0){
            int temp = nums[i] - k;
            int j = i-1;
            while (j>=0){
                if(nums[j] == temp){
                    st.insert({nums[j],temp+2});
                    break;
                }
                j--;
            }
            i--;
        }
        return st.size();
    }
};