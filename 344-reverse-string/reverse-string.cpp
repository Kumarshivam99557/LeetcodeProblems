class Solution {
public:
    void reverseString(vector<char>& toy) {
        int h = toy.size();
        for (int i = 0; i < toy.size() / 2; i++) {

            int temp = toy[i];
            toy[i] = toy[h - i - 1];
            toy[h - i - 1] = temp;
        }
    }
};