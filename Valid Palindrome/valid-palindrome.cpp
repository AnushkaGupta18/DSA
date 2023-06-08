class Solution {
private: 
    bool isValid(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return 1;
        }
        return 0;
    }

    char toLowercase(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            return ch;
        }
        else {
            return (ch - 'A' + 'a');
        }
    }

    bool palindrome(string a) {
        int i = 0;
        int j = a.length() - 1;

        while (i <= j) {
            if (a[i] != a[j]) {
                return 0;
            }
            else {
                i++;
                j--;
            }
        }
        return 1;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i < s.length(); i++) {
            //we'll add the characters which are alphanumeric to the temporary string
            if(isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }

        //now we'll convert all the characters to lowercase
        for(int i = 0; i < temp.length(); i++) {
            temp[i] = toLowercase(temp[i]);
        }
        
        //now, we'll check for palindrome
        return (palindrome(temp));
    }
};