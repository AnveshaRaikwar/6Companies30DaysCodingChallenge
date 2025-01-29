class Solution {
public:
    // void wiggleSort(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());

    //     int mid=(nums.size()/2)-1;
    //     int last=nums.size()-1;

    //     vector<int> temp;
    //     int index=mid;
    //     for(int i=0 ; i<nums.size() ; i++){
    //         if(index >= 0 && last > mid){
    //             temp.push_back(nums[index--]);
    //             temp.push_back(nums[last--]);
    //         }
    //         if(index >= 0){
    //             temp.push_back(nums[index--]);
    //         }
    //         if(last > mid){
    //             temp.push_back(nums[last--]);
    //         }

    //     }
    //     for(int i=0; i<nums.size(); i++){
    //         nums[i]=temp[i];
    //     }

    // }
    void wiggleSort(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp(n);

        int i=1,j=n-1;

        while(i<n){
            temp[i]=nums[j];
            i=i+2;
            j--;
        }
        i=0;
        while(i<n){
            temp[i]=nums[j];
            i=i+2;
            j--;
        }
        for(int k=0; k<n; k++){
            nums[k]=temp[k];
        }
    }
};