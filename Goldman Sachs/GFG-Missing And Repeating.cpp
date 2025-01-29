class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans;
        
        int n = arr.size();
        
        // for(int i=0; i<n; i++){
        //     while(arr[i]!=i+1){
        //         if(arr[arr[i]-1] == arr[i]-1){
        //             ans.push_back(arr[i]);
        //             ans.push_back(i+1);
        //             return ans;
        //         }
                
        //         swap(arr[i], arr[arr[i]-1]);
        //     }
        // }
        
        int i=0;
        while(i<n){
            int index = arr[i]-1;
            if(arr[i]!=arr[index]){
                swap(arr[i],arr[index]);
            }
            else{
                i++;
            }
        }
        
        for(int j=0; j<n;j++){
            if(arr[j]!=j+1){
                ans.push_back(arr[j]);
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};