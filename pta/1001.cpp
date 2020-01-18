#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int num[10];
int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(0);
    int i=0;
    ll a=0;
    ll b=0;
    ll sum=0;
    cin>>a>>b;
    sum=a+b;
    if(sum<0)
    {
        sum=-sum;
        cout<<"-";
    }
    if(sum==0)
    {
        
        cout<<"0"<<endl;
        #ifdef LOCAL
        system("pause");
        #endif
        return 0;
    }
    while(sum!=0)
    {
        num[i]=sum%10;
        sum/=10;
        i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        
        cout<<num[j];
        if(j==6||j==3)
            cout<<",";
    }
    cout<<endl;
    #ifdef LOCAL
    system("pause");
    #endif
    return 0;
}