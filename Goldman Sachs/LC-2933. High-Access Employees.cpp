class Solution {
public:
    int toMinutes(string s){
        int hr = (s[0]-'0' )*10 + s[1] - '0';
        int min = (s[2]-'0')*10 + s[3] - '0';

        int total_min = hr*60 + min;
        return total_min;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(),access_times.end());
        
        unordered_map<string,list<int>> mp;
        for(auto t:access_times){
            mp[t[0]].push_back(toMinutes(t[1]));
        }

        vector<string> ans;
        
        for(auto i:mp){
            auto times = i.second;
            int cnt=0;
            times.sort();

            auto start = times.begin();
            for(auto it=times.begin(); it!=times.end(); it++){
                while(*it - *start >= 60) {
                    ++start;
                }
                cnt = distance(start, it) + 1; // Count elements in the 60-minute window
                if (cnt >= 3) {
                    ans.push_back(i.first); // Add employee to the result
                    break; // No need to process further for this employee
                }
            }
        }
        return ans;
    }
};