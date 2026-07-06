class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(vector<vector<string>> &result, vector<string> &partitions, string s) {
        if (s.length() == 0) {
            result.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            bool ans = isPalindrome(s, 0, i);
            if (ans == true) {
                partitions.push_back(s.substr(0, i + 1));
                solve(result, partitions, s.substr(i + 1));
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partitions;
        solve(result, partitions, s);
        return result;
    }
};