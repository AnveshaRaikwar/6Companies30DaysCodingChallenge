#define ll long long
#define MOD 1000000007

class Solution {
public:

    int peopleAwareOfSecret(int n, int delay, int forget) {
        ll day =2;
        vector<array<ll,3>> persons = {{delay+1,forget+1,1}};
        while(day<=n){
            // remove those who forget
            while(!persons.empty() && persons[0][1] == day){
                persons.erase(persons.begin());
            }

            //no. of person tht can spread secret
            ll cnt = 0;
            for(auto x:persons){
                if(x[0]<=day){
                    cnt = (cnt + x[2])%MOD;
                }
                cnt %= MOD;
            }
            persons.push_back({day+delay,day+forget,cnt});
            day++;
        }
        ll ans = 0;

        for(auto &x:persons){
             ans = (ans + x[2]) % MOD;
        }
        return ans;
    }
};