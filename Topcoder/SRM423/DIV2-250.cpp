#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

class TheSimpleGame{ 
public: 
    
  int count(int n,vector <int> xn,vector<int> yn)
  {
      int ans=0;
      int s=xn.size();
      int i;
      FOR(i,0,s)
      {
          int x=xn[i];
          int y=yn[i];
          int d1=abs(x-1)+abs(y-1);
          int d2=abs(x-1)+abs(y-n);
          int d3=abs(x-n)+abs(y-1);
          int d4=abs(x-n)+abs(y-n);
          ans+=min(d1,min(d2,min(d3,d4)));
      }
      return ans;
  }
};

//for testing
int main()
{
    className cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
