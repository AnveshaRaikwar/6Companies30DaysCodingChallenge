class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (auto x : nums) {
            minHeap.push(x);
            if (minHeap.size() > k) {
                minHeap.pop(); // Keep only the k largest elements
            }
        }
        // int i =0;
        // for(; i<k; i++){
        //     minHeap.push(nums[i]);
        // }

        // while(i<nums.size()){
        //     if(minHeap.top()<nums[i]){
        //         minHeap.pop();
        //     }
        //     else{
        //         minHeap.push(nums[i]);
        //     }
        // }
        
    }
    
    int add(int val) {
        minHeap.push(val);

        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};