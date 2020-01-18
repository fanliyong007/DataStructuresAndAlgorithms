#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef struct 
{
    double n=0;
    bool flag=false;
}NUM;

int main()
{
    NUM num[1008];
    int all=0;
    int k=0;int ni=0;double ki=0;
    for(int j=2;j>0;j--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            
            cin>>ni>>ki;
            #ifdef LOCAL
           // cout<<"num["<<ni<<"]="<<num[ni].n<<"num["<<ni<<"]=.flag="<<num[ni].flag<<endl;
            #endif
            num[ni].n+=ki;
            num[ni].flag=true;

        }
    }
    for(int i=1001;i>=0;i--)
    {
        if(num[i].flag&&num[i].n!=0)
        {
            all++;
        }
    }
    cout<<all;
    for(int i=1001;i>=0;i--)
    {
        if(num[i].flag&&num[i].n!=0)
        {
            printf(" %d %.1f",i,num[i].n);
        }
    }
    printf("\n");
    #ifdef LOCAL
    system("pause");
    #endif
    return 0;
}
// bool flag[1008];
// double num[1008];               
// int main()
// {
//     int count=0;
//     while(cin>>count)
//     {
//         int x;
//         double y;
//         memset(flag,false,sizeof(flag));
//         memset(num,0,sizeof(num));
//         for(int i=1;i<=count;i++)
//         {
//             cin>>x>>y;
//             num[x]+=y;
//             flag[x]=true;
//         }
//         x=0;y=0;
//         int count=0;
//         cin>>count;
//         for(int i=1;i<=count;i++)
//         {
//             cin>>x>>y;
//             num[x]+=y;
//             flag[x]=true;
//         }
//         int g=0;
//         for(int i=1002;i>=0;i--)
//         {
//             if(flag[i]&&num[i]!=0)
//                 g++;
//         }
//         printf("%d",g);
//         g=0;
//         for(int i=1002;i>=0;i--)
//         {
//             if(flag[i]&&num[i]!=0)
//                 printf(" %d %.1f",i,num[i]);
//         } 
//         cout<<endl;
//     }
//     return 0;
// }
