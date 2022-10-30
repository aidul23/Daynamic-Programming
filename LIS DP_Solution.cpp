#include<bits/stdc++.h>
using namespace std;

int findLIS(vector<int> &arr) /// Time Complexity O(n^2)
{
    vector<int> dp(arr.size() , 1);

    for(int i = 0 ; i < arr.size() ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin() , dp.end());
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);

    printf("%d",findLIS(arr));
    return 0;
}
