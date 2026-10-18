class Solution {
public:
    long long power(long long base, long long exp, long long MOD){
        long long res = 1;
        base = base % MOD;
        while(exp){
            if(exp & 1){
                res = (res * base) % MOD;
            }
            exp /= 2;
            base = (base * base) % MOD;
        }
        return res;
    }
    int numOfWays(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        long long fact = 1, sizes = 1;
        vector<int> insertionTime(n + 2, -1);
        for(int i = 0; i < n; i++) insertionTime[nums[i]] = i;
        for(int i = 2; i <= n; i++) fact = (fact * i) % MOD; //constraint 2
        vector<int> stack = {0};
        for(int v = 1; v <= n + 1; v++){
            while(insertionTime[stack.back()] > insertionTime[v]){
                stack.pop_back();
                sizes = sizes * (v - stack.back() - 1) % MOD;
            }
            stack.push_back(v);
        }
        return (fact * power(sizes, MOD - 2, MOD) - 1 + MOD) % MOD;
    }
}; 