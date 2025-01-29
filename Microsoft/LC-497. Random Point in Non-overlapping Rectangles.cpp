class Solution {
public:
    vector<vector<int>> rects;
    vector<long> sum;
    long total;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        total=0;
        for(auto rect:rects){
            total +=(long)(rect[2]-rect[0]+1) * (rect[3]-rect[1]+1);
            sum.push_back(total);
        }
        srand(time(0)); //seed the random number generator
        
    }
    
    vector<int> pick() {
        int target = rand() % total; // to ensure that random no. taken is in range(less then total no.)
        // target tells that from total n points we want ith point

        int i=0, j=sum.size()-1;

        while(i<j){
            int mid = i+(j-i)/2;

            if(sum[mid]>target){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }

        const auto& rec = rects[i];
        int x1 = rec[0] , x2 = rec[2] , y1 = rec[1] , y2 = rec[3];

        int x = rand() % (x2 - x1 + 1);
        int y = rand() % (y2 - y1 + 1);

        return {x1+x , y1+y};
    }
};
