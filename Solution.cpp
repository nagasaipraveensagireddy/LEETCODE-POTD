#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        long long res = 0;
        for(int i = 0; i < nums.size() / 2; i++){
            res -= 1LL * nums[i] * nums[i];
        }
        for(int i = nums.size() / 2; i < nums.size(); i++){
            res += 1LL * nums[i] * nums[i];
        }
        return res;
    }
};