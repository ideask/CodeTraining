class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool chk(char c) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
			return true;
		}
		return false;
	}

    bool isPalindrome(string &s) {
        // write your code here
            int n = s.size();
        if (n == 1) return true;
        int i = 0, j = n - 1;
        while (i <= j) { // two pointers not met yet
            // ignore other characters from beginning
            while ((i <= j) && (!chk(s[i]))) i ++;              
            // ignore other characters from end             
            while ((j >= i) && (!chk(s[j]))) j --; 
            // not equal return invalid
            if ((i < j) && (s[i] != s[j]) && (s[i] != toupper(s[j])) && (s[j] != toupper(s[i]))) return false;
            i ++;
            j --;
        }
        return true;
    }
};
