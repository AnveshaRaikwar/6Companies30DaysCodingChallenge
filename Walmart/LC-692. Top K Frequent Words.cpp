class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int,string>> v;
        unordered_map<string,int> mp;

        for(string &word:words){
            mp[word]++;
        }
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }

        auto lambda=[](pair<int,string> &p1,pair<int,string> &p2){
            if(p1.first == p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        };

        sort(begin(v),end(v),lambda);

        int i=0;
        vector<string> result(k);
        while(i<k){
            result[i] = v[i].second;
            i++;
        }
        return result;
    }
};