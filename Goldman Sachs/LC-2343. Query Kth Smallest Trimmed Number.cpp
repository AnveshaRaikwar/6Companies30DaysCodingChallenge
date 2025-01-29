class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto i:queries){
            vector<pair<string,int>> v;
            for(int j=0; j<nums.size() ;j++){
                string sub = nums[j].substr(nums[j].size()-i[1]);
                v.push_back({sub,j});
            }
            sort(v.begin(), v.end());
            int k = i[0]-1;
            ans.push_back(v[k].second);
        }
        return ans;
    }
};