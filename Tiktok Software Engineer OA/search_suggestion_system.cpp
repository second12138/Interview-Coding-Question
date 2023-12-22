class Solution {
public:
    /*vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n=products.size();
        sort(products.begin(), products.end());
        string curr="";
        for(auto c:searchWord){
            curr+=c;
            temp.clear();
            for(int i=0; i<n; i++){
                if(products[i].substr(0, curr.length())==curr){
                    temp.push_back(products[i]);
                }
                if(temp.size()==3) break;
            }
            ans.push_back(temp);
        }
        return ans;
    }*/
    //time complexity(O(nlogn+nm))
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        int l=0, r=products.size()-1;
        for(int i=0; i<searchWord.size(); i++){
            while(l<=r&&(products[l][i]!=searchWord[i]||products[l].size()<i)){
                l++;
            }
            while(l<=r&&(products[r][i]!=searchWord[i]||products[r].size()<i)){
                r--;
            }
            vector<string> temp;
            int length=min(3,r-l+1);
            for(int j=0; j<length; j++){
                temp.push_back(products[l+j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};