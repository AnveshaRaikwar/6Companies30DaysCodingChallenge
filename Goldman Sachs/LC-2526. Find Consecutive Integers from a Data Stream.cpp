class DataStream {
public:
    int value;
    int k;
    unordered_map<int,int> mp;
    queue<int> q;

    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        q.push(num);
        mp[num]++;

        if(q.size()>k){
            int front = q.front();
            q.pop();
            mp[front]--;
            if(mp[front]==0){
                mp.erase(front);
            }
        }
         
        return (q.size()==k && mp[value]==k);
    }
};
