class Solution {
public:

    int solve(vector<int>& nums, int k, int p){
        set<vector<int>> st;

        for(int i=0; i<nums.size(); i++){
            vector<int> v;
            int cnt = 0;
            for(int j=i; j<nums.size(); j++){
                if(nums[j] % p == 0){
                    cnt++;
                }
                if(cnt>k){
                    break;
                }
                v.push_back(nums[j]);
                st.insert(v);
            }
        }
        return st.size();
    }

    int countDistinct(vector<int>& nums, int k, int p) {
        
        return solve(nums, k,p);
    }
};