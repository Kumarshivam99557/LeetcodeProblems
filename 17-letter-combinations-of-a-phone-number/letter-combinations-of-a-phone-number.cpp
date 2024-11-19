class Solution {
public:
    void generate(int i,string &comb,string &digits,string &s,vector<string>&sol){
        if(i==digits.length()){
            if(comb.length())
            sol.push_back(comb);
            return;
        }
        int ind;
        switch(digits[i]){
            case '2':ind=1;
            break;
            case '3':ind=4;
            break;
            case '4':ind=7;
            break;
            case '5':ind=10;
            break;
            case '6':ind=13;
            break;
            case '7':ind=16;
            break;
            case '8':ind=20;
            break;
            case '9':ind=23;
            break;
        }
        int k=3;
        if(digits[i]=='9' || digits[i]=='7')
        k=4;
        for(int z=ind;(z-ind)<k;z++){
            comb+=s[z];
            generate(i+1,comb,digits,s,sol);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string s="1abcdefghijklmnopqrstuvwxyz";
        vector<string>sol;
        string comb="";
        generate(0,comb,digits,s,sol);
        return sol;
    }
};