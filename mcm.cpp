#include<bits/stdc++.h>
using namespace std;
int mcm(int p[],int n)
{
    int m[n+1][n+1];
    for(int i=0;i<=n;i++)
        m[i][i]=0;
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<m[i][j])
                   {
                       m[i][j]=q;
                   }

            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<m[i][j]<<" ";
        cout<<"\n";
    }
    return m[1][n];
}
int main()
{
    int n,f;

    cin>>n;
    int p[n+2];
    for(int i=0;i<=n;i++)
        cin>>p[i];
    f=mcm(p,n);
    cout<<f;
}
