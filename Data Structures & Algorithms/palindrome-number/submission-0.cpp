class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        if (x<10) return true;
        int n = x;
        vector<int> nums;
        while (n!=0){
            nums.push_back(n%10);
            n = n/10;
        }
        int r = nums.size()-1;
        int l = 0;
        while (l<r){
            if (nums[l]!=nums[r]) return false;
        }
        return true;
    }
};