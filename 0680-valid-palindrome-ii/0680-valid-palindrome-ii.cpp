class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        int count1 = 0;
        while(i < j)
        {
            if(s[i] != s[j]) 
            {
                j--;
                count1++;
            }
            else
            {
                i++;
                j--;
            }
        }
        int count2 = 0;
        i = 0;
        j = s.size()-1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                i++;
                count2++;
            }else
            {
                i++;
                j--;
            }
        }
        return min(count1,count2) <= 1;
    }
};