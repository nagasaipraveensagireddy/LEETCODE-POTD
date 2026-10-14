#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        while(sum && res.size() < num){
            if(sum > 9){
                res += "9";
                sum -= 9;
            }
            else{
                res += to_string(sum);
                sum = 0;
            }
        }
        if(sum) return "";
        while(res.size() < num){
            res += "0";
        }
        return res;
    }
};