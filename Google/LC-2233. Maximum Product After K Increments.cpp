#define MOD 1000000007
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(int i=0; i<nums.size(); i++){
            minHeap.push(nums[i]);
        }
        int cnt=0;
        while(k){
            int temp = minHeap.top();
            minHeap.pop();
            temp += 1;
            minHeap.push(temp);
            cnt++;
            k--;
        }
        
        long long product = 1;
        while(!minHeap.empty()){
            product = ((product%MOD) * minHeap.top())%MOD;
            minHeap.pop();
        }
        return product%MOD;
    }
};