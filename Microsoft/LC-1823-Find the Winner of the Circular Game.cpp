class Solution {
public:
    int findTheWinner(int n, int k) {
        //METHOD 1: SIMULATION = do as it is given

        vector<int> arr;
        for(int i=0; i<n; i++){
            arr.push_back(i+1);
        }

        int index = 0;
        while(arr.size()>1){
            int win = (index+k-1) % arr.size();
            arr.erase(arr.begin() + win);
            index = win;
        }
        return arr[0];
    }
};