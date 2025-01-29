class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto i:mp){
            pq.push({i.second,i.first});
        }

        string ans= "";

        while(!pq.empty()){
            int n = pq.top().first;
            while(n--){
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};