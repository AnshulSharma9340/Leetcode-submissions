class Solution {
public:
    void generateParenthesesHelper(int open, int close, string current, vector<string> &result){
        if (open == 0 && close == 0) {
        result.push_back(current);
        return;
        }
        if (open > 0) {
        generateParenthesesHelper(open - 1, close, current + "(", result);
        }
        if (close > open) {
            generateParenthesesHelper(open, close - 1, current + ")", result);
        }
    
}
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n <= 0) return result;
        generateParenthesesHelper(n, n, "", result);
        return result;
    }
};