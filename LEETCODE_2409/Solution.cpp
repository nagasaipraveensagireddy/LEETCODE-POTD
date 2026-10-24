class Solution {
public:
    bool isOverlapping(int m, int d, int aliceAM, int aliceAD, int aliceLM, int aliceLD, 
                       int bobAM, int bobAD, int bobLM, int bobLD) {
         bool aliceStays = (m > aliceAM ||  (m == aliceAM && d >= aliceAD)) && 
                           (m < aliceLM || (m == aliceLM && d <= aliceLD));
         bool bobStays = (m > bobAM || (m == bobAM && d >= bobAD)) && 
                         (m < bobLM || (m == bobLM && d <= bobLD));
         return aliceStays && bobStays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 0;
        int aliceAM = stoi(arriveAlice.substr(0, 2));
        int aliceAD = stoi(arriveAlice.substr(3, 2));

        int aliceLM = stoi(leaveAlice.substr(0, 2));
        int aliceLD = stoi(leaveAlice.substr(3, 2));

        int bobAM = stoi(arriveBob.substr(0, 2));
        int bobAD = stoi(arriveBob.substr(3, 2));

        int bobLM = stoi(leaveBob.substr(0, 2));
        int bobLD = stoi(leaveBob.substr(3, 2));
        for(int i = 1; i <= 12; i++){
            for(int j = 1; j <= days[i]; j++){
                if(isOverlapping(i, j, aliceAM, aliceAD, aliceLM, aliceLD, 
                                 bobAM, bobAD, bobLM, bobLD)) res++;
            }
        }
        return res;
    }
};