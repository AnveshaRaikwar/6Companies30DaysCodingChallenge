class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int collitions = 0;

        int i=0;
        while(i<n && directions[i] == 'L'){
            i++;
        }

        int j=n-1;
        while(j>=0 && directions[j] == 'R'){
            j--;
        }

        for(int x=i; x<=j; x++){
            if(directions[x]!='S'){
                collitions++;
            }
        }

        return collitions;
    }
};