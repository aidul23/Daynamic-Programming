#include<bits/stdc++.h>
using namespace std;

int findLIS(vector<int> &arr) /// Time Complexity O(nlog(n))
{
    vector<int> lis;

    for(auto &x : arr)
    {
        int pos = lower_bound(lis.begin() , lis.end() , x) - lis.begin();

        if(pos == lis.size())
            lis.push_back(x);
        else
            lis[pos] = x;
    }

    return lis.size();
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);

    printf("%d\n",findLIS(arr));
    return 0;
}

