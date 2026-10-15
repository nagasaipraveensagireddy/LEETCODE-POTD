#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> st;
            for(int j = i; j < nums.size(); j++){
                st.insert(nums[j]);
                int add = st.size();
                add *= add;
                res += add;
            }
        }
        return res;
    }
};