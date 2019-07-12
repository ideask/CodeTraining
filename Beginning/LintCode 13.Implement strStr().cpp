class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        int slen = source.length();
        int tlen = target.length();
        int i = 0, j = 0;
        if(tlen == 0)
        {
            return 0;
        }
        if(tlen != 0 && slen == 0)
        {
            return -1;
        }
        while(i < slen && j < tlen)
        {
            if(source[i] == target[j])
            {
                i ++;
                j ++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
            if(j == tlen)
            {
                return i - j;
            }
        }
        return -1;
    }
};
