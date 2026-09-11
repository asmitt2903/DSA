class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        int count = 0;
        for(int digit: digits)
        {
            freq[digit]++;
        }

        for(int ones:{0,2,4,6,8})
        {
            if(freq[ones] <= 0) continue;
            freq[ones]--;
            for(int h = 1;h < 10;h++)
            {
                if(freq[h] <= 0) continue;
                freq[h]--;
                for(int i = 0;i < 10;i++)
                {
                    if(freq[i] > 0) count++;
                }
                freq[h]++;
            }
            freq[ones]++;
        }
        return count;
    }
};