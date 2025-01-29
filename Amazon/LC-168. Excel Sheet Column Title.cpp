class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber){
            char c = 'A' + (columnNumber - 1)%26;
            ans = c + ans;
            columnNumber = (columnNumber-1)/26;
        }
        return ans;
        
    }
};