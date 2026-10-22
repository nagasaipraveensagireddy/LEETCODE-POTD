class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc = 1, desc = 1;
        for(int i = 1; i < n; i++){
            //using %n for 0, n - 1 pair here, take an exmp and try
            asc += nums[i] == (nums[i - 1] + 1) % n;
            //%n for n - 1, 0 case
            desc += nums[i - 1] == (nums[i] + 1) % n;
        }
        if(asc == n){
            return nums[0] ? min(n - nums[0], nums[0] + 2) : 0;
        }

        if(desc == n){
            return min(n - nums[n - 1], nums[n - 1]) + 1;
        }
        return -1;
    }
};