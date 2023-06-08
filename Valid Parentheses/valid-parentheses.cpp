class Solution {
public:
    bool isValid(string s) {
        
        stack <char> check; 

        if (s.length() <= 1) {
            return false;
        }

        for(int i =0; i < s.length(); i++) {
            char ch = s[i]; 

            //for opening brackets, we push elements into the stack 
            //for closing brackets, we pop element from the stack 

            if(ch == '(' || ch == '{' || ch == '[') {
                check.push(ch); 
            }

            else {
                if(!check.empty()) {
                    char top = check.top();
                
                    if ((ch == ')' && top == '(') || 
                    (ch == ']' && top == '[') || 
                    (ch == '}' && top == '{')) {
                        check.pop();
                    }

                    else {
                        return false; 
                    }
                }
                else if (check.empty()) {
                    return false;
                }
            }
        }

        if(check.empty()) {
            return true;
        }
        else{
            return false;
        }
    }
};