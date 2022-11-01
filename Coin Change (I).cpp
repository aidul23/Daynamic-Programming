/**
https://lightoj.com/problem/coin-change-i
**/

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
const int MOD = 100000007;

int coins[MAX + 5];
int freq[MAX + 5];
int dp[52][1020];

int n, k;

int f(int pos, int rem)
{
    if(pos == n) return (rem == 0);
    if(rem < 0) return 0;
    if(dp[pos][rem] != -1)
    {
        return dp[pos][rem];
    }
    int total = 0;

    for(int i = 0 ; i <= freq[pos] ; i++)
    {
        total = (total + f(pos + 1, rem - (i * coins[pos]))) % MOD;
    }
    dp[pos][rem] = total;
    return total;
}

int main()
{
    int t, cs = 1;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp, - 1, sizeof(dp));
        scanf("%d %d",&n,&k);

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&coins[i]);
        }

        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&freq[i]);
        }

        printf("Case %d: %d\n",cs++,f(0,k));
    }
    return 0;
}
