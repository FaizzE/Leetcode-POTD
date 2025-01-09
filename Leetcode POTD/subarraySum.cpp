vector<int> subarraySum(vector<int> &arr, int target) {
         unordered_map<int,int>mp;
        int n=arr.size();
        int sum=0;
        mp[0]=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum-target)!=mp.end()){
                return {mp[sum-target]+1,i+1};
            }
            if(mp.find(sum)==mp.end())
            mp[sum]=i+1;
        }
        return {-1};
    }
