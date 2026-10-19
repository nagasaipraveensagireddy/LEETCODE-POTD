#include<bits/stdc++.h>
using namespace std;
#include "Solution.cpp"
int main(){
    ifstream file("test_cases.txt");
    if(!file.is_open()){
        cout << "Failed to open the file." << endl;
        return 1;
    }
    Solution obj;
    int n, target, expectedSize;
    int testCase = 1;
    while(file >> n >> target){
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            if(!(file >> nums[i])){
                cout<<"Inavlid array input in test case :"<<testCase;
                return 1;
            }
        }
        if(!(file >> expectedSize)){
            cout<<"Inavlid expectedSize in test case :"<<testCase;
                return 1;
        }
        vector<int> expected(expectedSize);
        for(int i = 0; i < expectedSize; i++){
            if(!(file >> expected[i])){
                cout<<"Inavlid expected data in test case :"<<testCase;
                return 1;
            }
        }
        vector<int> res = obj.targetIndices(nums, target);
        if(res == expected){
            cout<<"Test case: "<<testCase<<endl;
            cout<<"Status: PASS"<<endl;
            cout<<"Expected Result:"<<endl;
            for(auto& it : expected) cout<<it<<" ";
            cout<<endl;
            cout<<"Actual Result: "<<endl;
            for(auto& it : res) cout<<it<<" ";
            cout<<endl;
            cout<<"______________________________\n";
        }
        else{
            cout<<"Test case: "<<testCase<<endl;
            cout<<"Status: FAIL"<<endl;
            for(auto& it : expected) cout<<it<<" ";
            cout<<endl;
            cout<<"Actual Result: "<<endl;
            for(auto& it : res) cout<<it<<" ";
            cout<<endl;
            cout<<"______________________________\n";
        }
        testCase++;
    }
    file.close();
    return 0;
}