#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}
    
 
string int2str(int n)
{
    stringstream ss;
    string ans;
    ss<<n;
    ss>>ans;
    return ans;
}


class TheSwap{ 
public: 
    
  int findMax(int n,int k)
  {
      string sn=int2str(n);
      int l=sn.length();
      int i,j,maxd=0,ind=-1,strt=0;
      FOR(j,0,k)
      {
          maxd=0;ind=-1;
          for (i=l-1;i>strt;i--)
        {
            if (sn[i]-48>maxd)
            {
                maxd=sn[i]-48;
                ind=i;
            }
        }
        if (maxd==0) return -1;
        if (maxd>sn[strt]-48)
        {
            char tmp=sn[strt];
            sn[strt]=sn[ind];
            sn[ind]=tmp;
        }
        strt++;
      }
      return str2int(sn);
  }
};

//for testing
int main()
{
    TheSwap cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string temp;
        cin>>temp;
        p(str2int(temp));
//        int t2;
//        cin>>t2;
//        cout<<int2str(t2)<<endl;
    }
}
