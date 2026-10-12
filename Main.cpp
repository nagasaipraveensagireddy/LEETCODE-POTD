#include<bits/stdc++.h>
using namespace std;

#include "Solution.cpp"

int main(){
    ifstream file("test_cases.txt");

    if(!file.is_open()){
        cout<<"Can't open file test_cases.txt\n";
        return 1;
    }

    Solution obj;
    int n, k, expected;
    int testCase = 1;
    while(file >> n >> k){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            if(!(file >> nums[i])){
                cout<<"Invalid input in test case :"<<testCase;
                return 1;
            }
        }

        if(!(file >> expected)){
            cout<<"Invalid expected output in test case:"<<testCase;
            return 1;
        }

        int res = obj.maxSum(nums, k);

        if(res == expected){
            cout<<"Test Case :"<<testCase<<endl;
            cout<<"Status :PASS\n";
            cout<<"Expected Result: "<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl<<endl;
        }
        else{
            cout<<"Test Case :"<<testCase<<endl;
            cout<<"Status : FAIL\n";
            cout<<"Expected Result: "<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl<<endl;
        }

        testCase++;
    }

    file.close();
    return 0;
}