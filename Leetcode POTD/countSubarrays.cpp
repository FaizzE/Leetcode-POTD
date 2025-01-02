int countSubarrays(vector<int> &arr, int k) {
        // code hereint 
        unordered_map<int, int> prefixSumCount;
        int currentSum = 0, kSumCnt = 0;
    
        for (int num : arr) {
            currentSum += num;
    
            // Check if the current sum equals k
            if (currentSum == k) {
                kSumCnt++;
            }
    
            // Check if (currentSum - k) exists in the map
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                kSumCnt += prefixSumCount[currentSum - k];
            }
    
            // Update the prefix sum count
            prefixSumCount[currentSum]++;
        }
    
        return kSumCnt;
    }
