class Solution {
public:
    unordered_map<int, string> mp;
    vector<string> ans;
    void solve(string digits ,int i, string &output){
        if(i>=digits.size()) {
            ans.push_back(output);
            return;
        }

        int digit = digits[i] - '0';
        for(auto letter:mp[digit]){
            output.push_back(letter);
            solve(digits,i+1,output);
            output.pop_back();
        }
        return;
        
    }
    vector<string> letterCombinations(string digits) {
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        if(digits.size() == 0){
            return ans;
        }
        string output;
        solve(digits,0,output);
        return ans;
    }
};