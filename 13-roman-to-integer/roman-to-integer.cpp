class Solution {
public:
    int check(char i){
        if(i=='I'){
            return 1;
        }
        else if(i=='V'){
            return 5;
        }
        else if(i=='X'){
            return 10;
        }
        else if(i=='L'){
            return 50;
        }
        else if(i=='C'){
            return 100;
        }
        else if(i=='D'){
            return 500;
        }
        else if(i=='M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0; i<s.size()-1; i++){
             if(check(s[i])>=check(s[i+1])){
                ans = ans + check(s[i]);
             }
             else {
                ans = ans - check(s[i]);
             }
        }
        ans = ans+ check(s[s.size()-1]);
        return ans ;
    }
};