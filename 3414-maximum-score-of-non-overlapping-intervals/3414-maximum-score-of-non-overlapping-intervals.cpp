class Solution {
public:
    using P = pair<long long, vector<int>>;

    bool better(const P& a, const P& b) {
        if (a.first != b.first)
            return a.first > b.first;

        return a.second < b.second;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            return x[1] < y[1];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int pos = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin();

            prev[i] = pos;
        }

        vector<vector<P>> dp(n + 1, vector<P>(5, {0, {}}));

        for (int i = 1; i <= n; i++) {

            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {

                P notTake = dp[i - 1][k];

                P take = dp[prev[idx]][k - 1];

                take.first += a[idx][2];
                take.second.push_back(a[idx][3]);

                sort(take.second.begin(), take.second.end());

                if (better(take, notTake))
                    dp[i][k] = take;
                else
                    dp[i][k] = notTake;
            }
        }

        return dp[n][4].second;
    }
};