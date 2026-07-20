class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        
        string currentString = "";
        int k = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } 
            // num = 3, curr""
            else if (isalpha(c)) {
                currentString += c;
            } 
            // stnums = 3, nums = 0, curr =""
            else if (c == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                k = 0;
                currentString = "";
            } 
            else if (c == ']') {
                // We've reached the end of an inner string, time to decode it
                string decodedString = stringStack.top();
                stringStack.pop();
                
                int repeatTimes = countStack.top();
                countStack.pop();
                
                // Multiply the current string and append it to the previous state
                for (int i = 0; i < repeatTimes; i++) {
                    decodedString += currentString;
                }
                
                // The newly formed string becomes our new current state
                currentString = decodedString;
            }
        }
        
        return currentString;
    }
};