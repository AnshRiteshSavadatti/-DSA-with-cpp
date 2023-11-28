#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cnt=0;
    for(int i=2;i<=pow(n,1.0/2);i++)
    {   
        if(n%i==0)
        {
           cnt++;
            if(n/i!=i)
            {
                cnt++;
            }
        }
    }
    cnt=cnt+2;//include 1 and n
    cout<<cnt<<endl;
    return 0;
}