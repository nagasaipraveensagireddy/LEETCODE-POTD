#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(30, 0);
        long long res = 0;
        int MOD = 1e9 + 7;
        for(auto& it : nums){
            for(int i = 0; i < 30; i++){
                if(it & (1 << i)) bitCount[i]++;
            }
        }
        for(int cnt = 0; cnt < k; cnt++){
            long long n = 0;
            for(int i = 0; i < 30; i++){
                if(bitCount[i]){
                    n |= (1LL << i);
                    bitCount[i]--;
                }
            }
            res = (res + n * n) % MOD;
        }
        return (int)res;
    }
};