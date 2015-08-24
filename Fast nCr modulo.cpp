#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<list>
using namespace std;


typedef int elem_t;
long long C(long long n, long long r, long long MOD)
{
    vector< vector<long long> > C(n+1,vector<long long> (r+1,0));

    for (long long i=0; i<=n; i++)
    {
        for (long long k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
    }
    return C[n][r];
}
int main()
{
    int n,r,m;
    m=10000007;
    while (scanf("%d%d",&n,&r))
    {
        if(n>=r)
        printf("%lld\n",C(n, r, m));
        else printf("-1");
    }
}
