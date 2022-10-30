#include<bits/stdc++.h>
using namespace std;

string s , p;
int dp[1020][1020];

int findLCS(int p1 , int p2)
{
    if(p1 >= s.size() || p2 >= p.size()) return 0;

    if(dp[p1][p2] != -1) return dp[p1][p2];

    int include = 0 , exclude = 0;

    if(s[p1] == p[p2])
        include = 1 + findLCS(p1 + 1 , p2 + 1);

    exclude = max(findLCS(p1 , p2 + 1) , findLCS(p1 + 1 , p2));
    return dp[p1][p2] = max(include , exclude);
}

int main()
{
    cin>>s>>p;
    memset(dp , -1 , sizeof dp);
    cout<<findLCS(0 , 0)<<endl;
    return 0;
}
