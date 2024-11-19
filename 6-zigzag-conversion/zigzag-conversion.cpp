class Solution {
public:
    string convert(const string& s, int numRows) {
        if(s.empty()) return "";
        if(s.size() == 1) return s;
        if(numRows == 1) return s;

        string converted;

        vector<string> rows(min(numRows, int(s.length())));
        int currRow = 0;
        bool goDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if(currRow == 0 || currRow == numRows - 1) {
                goDown = !goDown;
            }
            currRow += goDown ? 1 : -1;
        }

        for(const string& row : rows) {
            converted += row;
        }

        return converted;
    }
};