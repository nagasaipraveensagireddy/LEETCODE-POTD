#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

int main(){
    ifstream file("test_cases.txt");

    if(!file.is_open()){
        cout<<"Can't open file test_cases.txt";
        return 1;
    }
    Solution obj;
    int n;
    long long expected;
    int testCase = 1;
    while (file >> n){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            if(!(file >> nums[i])){
                cout<<"Inavlid array input for testCase: "<<testCase;
                return 1;
            }
        }
        if(!(file >> expected)){
            cout<<"Inavlid expected data in test Case : "<<testCase;
            return 1;
        }
        long long res = obj.maxAlternatingSum(nums);
        if(res == expected){
            cout<<"Test Case: "<<testCase<<endl;
            cout<<"Status: Pass\n";
            cout<<"Expected result: "<<expected<<endl;
            cout<<"Obtained result: "<<res<<endl;
        }
        else{
            cout<<"Test Case: "<<testCase<<endl;
            cout<<"Status: Fail\n";
            cout<<"Expected result: "<<expected<<endl;
            cout<<"Obtained result: "<<res<<endl;
        }
        testCase++;
    }
    file.close();
    return 0;
}