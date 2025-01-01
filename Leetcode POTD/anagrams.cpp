vector<vector<string>> anagrams(vector<string>& arr) {
        map<string,vector<string>> anagram;
        
        for(auto str:arr){
            string sortedString = str;
            sort(sortedString.begin(),sortedString.end());
            anagram[sortedString].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto i :anagram){
        
            ans.push_back(i.second);
        }
        return ans;
    }
