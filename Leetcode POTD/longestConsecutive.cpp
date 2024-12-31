int longestConsecutive(vector<int>& arr) {
        if (arr.empty()) return 0;
    
        sort(arr.begin(), arr.end());
        int longest = 1, current = 1;
    
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                current++;  
            } else if (arr[i] != arr[i - 1]) {
                longest = max(longest, current); 
                current = 1;
            }
        }
        return max(longest, current);
    }   
