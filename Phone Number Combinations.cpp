Given a string digits containing 2 to 9 inclusive, return in sorted lexicographic order all possible strings it could represent when mapping to letters on a phone dialpad.

These are the mappings on a phone dialpad:

| 2 | abc  |
| 3 | def  |
| 4 | ghi  |
| 5 | jkl  |
| 6 | mno  |
| 7 | pqrs |
| 8 | tuv  |
| 9 | wxyz |

Example 1
Input

digits = "23"

Output

["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

//code
void getkeys(vector<string> &keypad, string &digits, int index, string snew) {
    if (index >= digits.size()) {
        keypad.push_back(snew);
        return;
    }

    string k = keypad[(digits[index] - '0') - 2];
    for (int i = 0; i < int(k.size()); i++) {
        string scurr = snew + k[i];
        getkeys(keypad, digits, index + 1, scurr);
    }
}

vector<string> solve(string digits) {
    vector<string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string s = "";
    getkeys(keypad, digits, 0, s);
    vector<string> retvec;
    for (int i = 8; i < int(keypad.size()); i++) {
        if (keypad[i] != "") retvec.push_back(keypad[i]);
    }

    return retvec;
}
