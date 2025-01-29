class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int k, int sum, vector<int> &output, vector<int> &nums){
        if(k==0 && sum==0){
            ans.push_back(output);
            return;
        }
        if(k == 0 || sum < 0 || i>=nums.size()){
            return;
        }

        //exclude
        solve(i+1,k,sum,output,nums);
        //include
        k--,sum = sum - nums[i];
        output.push_back(nums[i]);
        solve(i+1,k,sum,output,nums);
        output.pop_back();

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=0; i<9; i++){
            nums.push_back(i+1);
        }

        vector<int> output;
        
        solve(0,k,n,output,nums);

        return ans;
    }
};