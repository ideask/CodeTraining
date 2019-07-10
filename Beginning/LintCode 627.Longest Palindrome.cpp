class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        int hashtable[1010];
        memset(&hashtable, 0, sizeof(hashtable));
        for(char ch:s)
        {
            hashtable[ch] +=1;
        }
        int result = 0;
        bool hasodd = false;
        for(int i:hashtable)
        {
            if(i % 2 == 0)
            {
                result += i;
            }
            else
            {
                result += i - 1;
                hasodd = true;
            }
        }
        return hasodd ? result + 1 : result;
    }
};