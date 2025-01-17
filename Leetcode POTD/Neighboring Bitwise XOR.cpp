class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int XORR = 0;
        for(int i=0; i<derived.size(); i++) {
            XORR = derived[i] ^ XORR;
        }
        return XORR == 0;
    }
};
