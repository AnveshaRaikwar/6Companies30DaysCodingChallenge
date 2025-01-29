class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<k; i++){
            while(!dq.empty() && dq.back()<arr[i]){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
        }
        
        ans.push_back(dq.front());
        
        for(int i=k; i<arr.size(); i++){
            if(dq.front() == arr[i-k]){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back()<arr[i]){
                dq.pop_back();
            }
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};