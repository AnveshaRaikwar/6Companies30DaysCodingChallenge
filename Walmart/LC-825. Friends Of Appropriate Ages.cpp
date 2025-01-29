class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int agecount[121] ;

        for( int age: ages){
            agecount[age]++;
        }

        int cnt=0;
        for(int i=1; i<121; i++){
            for(int j = i/2 + 8; j<=i; j++){
                cnt += agecount[i] * (agecount[j] - (i==j?1:0));
            }
        }
        return cnt;
    }
};