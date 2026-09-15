class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int prevCount = 0;
        // for(int i = 0;i < s.size();i++)
        // {
        //     if(count == 0 && s[i] != ' ')
        //     {
        //         prevCount = 1;
        //         count++;
        //     }

        //     else if(s[i] != (' '))
        //     {
        //         count++;
        //         prevCount++;
        //     }
        //     else if(s[i] == ' ')
        //     {
        //         count = 0;
        //     }
        // }
        int j = s.size()-1;
        while(j >= 0)
        {
            if(count == 0 && s[j] == ' ')
            {
                j--;
                continue;
            }
            else if(s[j] == ' ')
            {
                return prevCount;
            }
            else
            {
                count++;
                prevCount++;
            }
            j--;
        }
        return prevCount;
        
    }
};