class Solution {
public:
    int minimumLength(string s) {
        vector<int> aksharGinti(26, 0);
        int kulLambai = 0;

        for (char vartamanAkshar : s) {
            aksharGinti[vartamanAkshar - 'a']++;
        }
        for (int ginti : aksharGinti) {
            if (ginti == 0) continue;
            if (ginti % 2 == 0) {
                kulLambai += 2;
            } else {
                kulLambai += 1;
            }
        }
        return kulLambai;
    }
};
