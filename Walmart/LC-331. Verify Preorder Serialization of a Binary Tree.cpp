class Solution {
public:
    bool solve(vector<int>& arr, int& index){

        if(index >= arr.size()){
            return false;
        }
        if(arr[index] == -1){
            index++;
            return true;
        }
        index++;
        if(!solve(arr, index)) {
            return false;
        }

        if(!solve(arr, index)){
            return false;
        }

        return true;
    }
    
    bool isValidSerialization(string preorder) {
        int n=preorder.size();
        vector<int> arr;
        
        for(int i=0; i<n;){
            string nums = "";
            while(i<n && preorder[i] != ','){
                nums += preorder[i++];
            }
            if(nums == "#"){
                arr.push_back(-1);
            }
            else{
                arr.push_back(stoi(nums));
            }
            i++;
        }

        int index = 0;
        if(!solve(arr, index)){
            return false;
        }
        return index == arr.size();
    }
};