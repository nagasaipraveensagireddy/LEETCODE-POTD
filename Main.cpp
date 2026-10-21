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
    string s;
    int expected;
    int testCase = 1;

    while(file >> s){
        if(!(file >> expected)){
            cout<<"Inavlid expected data in test case :"<<testCase;
            return 1;
        }
        int res = obj.minOperations(s);
        if(res == expected){
            cout<<"Test case: "<<testCase<<endl;
            cout<<"Status: PASS"<<endl;
            cout<<"Expected Result:"<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl;
            cout<<"______________________________\n";
        }
        else{
            cout<<"Test case: "<<testCase<<endl;
            cout<<"Status: FAIL"<<endl;
            cout<<"Expected Result:"<<expected<<endl;
            cout<<"Actual Result: "<<res<<endl;
            cout<<"______________________________\n";
        }
        testCase++;
    }
    file.close();
    return 0;
}