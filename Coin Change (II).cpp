/**
https://lightoj.com/problem/coin-change-ii
**/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, cs = 1;
    scanf("%d", &T);
    while(T--)
    {
        int n, K;
        scanf("%d %d", &n, &K);

        vector<int> coin(n, 0);

        for (int i = 0; i < n; i++)
            scanf("%d", &coin[i]);

        vector<int> dp(K + 1, 0);

        dp[0] = 1;

        ///3 5
        ///coin = [1 2 5] dp[1]
        for (int i = 0; i < n; i++)
        {
            for (int j = coin[i]; j <= K; j++)
            {
                cout<<"i: "<<i<<" j: "<<j<<" dp[j]: "<<dp[j]<<endl;
                dp[j] += dp[j - coin[i]];

                if (dp[j] >= 100000007)
                    dp[j] %= 100000007;
            }
        }
        printf("Case %d: %d\n", cs++, dp[K]);
    }
    return 0;
}
