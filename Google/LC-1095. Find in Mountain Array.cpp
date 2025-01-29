class Solution {
public:
    int bs(int s, int e, MountainArray &mountainArr,int target ,bool isAsc){
        while(s<=e){
            int mid =(s+e)/2;

            if(mountainArr.get(mid) == target){
                return mid;
            }
            if(isAsc){
                if(mountainArr.get(mid) > target){
                e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(mountainArr.get(mid) > target){
                    s=mid+1;
                }
                else{
                    
                    e=mid-1;
                }
            }
            
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int e = mountainArr.length()-1;
        int s = 0;

        // find peak

        while(s<e){
            int mid = (s+e)/2;

            if(mid-1>=0 && mountainArr.get(mid) > mountainArr.get(mid-1)){
                s=mid+1;
            }
            else {
                e=mid;
            }
        }
        int peakindex = s;
        int ans1=-1,ans2=-1;
        
        ans1 = bs(0,peakindex, mountainArr,target, true);
        
        if (ans1 != -1) {
            return ans1;
        }
        
        ans2 = bs(peakindex,mountainArr.length()-1, mountainArr, target,false);

        return ans2;
    }
};