class Solution {
public:
    /**
     * @param s: input string
     * @return: the longest palindromic substring
     */
    string preProcess(string s)
    {
        int n = s.length();
        if (n == 0) return "^$";
        string ret = "^";
        for (int i = 0; i < n; ++i)
        ret += "#" + s.substr(i, 1);
        ret += "#$";
        return ret;
    }
    string longestPalindrome(string &s) {
        // write your code here
          string T = preProcess(s);
          int n = T.length();
          vector<int> p(n, 0);
          int C = 0, R = 0;
          for (int i = 1; i < n-1; ++i){
            int i_mirror = 2*C-i;
         
            p[i] = (i < R) ? min(R-i, p[i_mirror]) : 0; 
         
            // attempt to expand palindrome centered at i
            while(T[i + 1 + p[i]] == T[i - 1 - p[i]])
              ++ p[i];
         
            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome,
            if(p[i] + i > R){
              C = i;
              R = i + p[i];
            }
          }
         
          // Find the maximum element in p
          int maxLen = 0;
          int centerIndex = 0;
          for (int i = 1; i < n-1; ++i){
            if(p[i] > maxLen){
              maxLen = p[i];
              centerIndex = i;
            }
          }
          return s.substr((centerIndex - 1 - maxLen)/2 , maxLen);
    }
};
