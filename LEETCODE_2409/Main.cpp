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
    string aliceArrive, aliceLeave, bobArrive, bobLeave;
    int expected;
    int testCase = 1;

    while(file >> aliceArrive >> aliceLeave >> bobArrive >> bobLeave){
        if(!(file >> expected)){
            cout<<"Invalid expected data in test case :"<<testCase;
            return 1;
        }
        int res = obj.countDaysTogether(aliceArrive, aliceLeave, bobArrive, bobLeave);
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