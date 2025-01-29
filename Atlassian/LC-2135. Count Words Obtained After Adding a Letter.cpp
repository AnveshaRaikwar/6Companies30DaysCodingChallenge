class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;

        for(int i=0;i<startWords.size(); i++){
            sort(startWords[i].begin(), startWords[i].end());
            s.insert(startWords[i]);
        }

        int ans = 0;

        for(int i=0; i<targetWords.size(); i++){
            string trial = targetWords[i];
            sort(trial.begin(),trial.end());
            bool flag = false;

            for(int j=0; j<trial.size(); j++){
                string search = trial.substr(0,j) + trial.substr(j+1);
                if(s.find(search)!=s.end()){
                    flag = true;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};