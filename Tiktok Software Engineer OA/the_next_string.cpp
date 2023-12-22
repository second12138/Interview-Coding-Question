class Solution {
public:
    string suggestedProducts(string s, int k) {
        unordered_set<char> alphabet(s.begin(), s.end());
        vector<char> sorted_letters(alphabet.begin(), alphabet.end());
        sort(sorted_letters.begin(), sorted_letters.end());
        if(k>s.size()){
            return s+sorted_letters[0];
        }
        string ans=s.substr(0,k);
        int n=sorted_letters.size();
        for(int i=ans.size()-1; i>=0; i++){
            if(ans[i]==sorted_letters[n-1]){
                ans[i]=sorted_letters[0];
            }else{
                auto it = find(sorted_letters.begin(), sorted_letters.end(), ans[i]); 
                ans[i]=sorted_letters[(it-sorted_letters.begin())+1];
            }
        }
        return ans;
    }
};