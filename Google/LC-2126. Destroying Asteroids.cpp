class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long planetmass = mass;
        if(asteroids.size() == 1 && asteroids[0] <= mass){
            return true;
        }
        sort(asteroids.begin(),asteroids.end());

        for(int i=0;i<asteroids.size(); i++){
            if(  asteroids[i] > planetmass ){
                return false;
            }
            planetmass += asteroids[i];
        }

        return true;
    }
};