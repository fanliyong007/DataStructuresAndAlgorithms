#include <iostream> 
using namespace std;
int vt[100008];
void sort(int l,int r)
{
    
}
int low_bound()
{

}
int main(int argc, const char** argv) 
{
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int n,m;
    int tmp;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>tmp; 
        vt[i].value=tmp;
        vt[i].next=i+1;
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        int sum=0;
        int posi=0;
        while(posi<100001)
        {
            if(vt[posi].value==a)
            {
                sum++;
            }

        }
        cout<<sum<<endl;
    }
    #ifdef LOCAL
    system("pause");
    #endif
    return 0;
}