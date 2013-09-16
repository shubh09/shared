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

class SkiFriction{ 
public: 
    
  int bestPosition(string ski,string path)
  {
      int m=ski.length();
      int n=path.length();
      bool b=m<n;
      int i,j;
      int ans=0;
      FOR(i,0,abs(m-n))
      {
          int temp=0;
          if (b)
          {
              FOR(j,0,m)
              {
                  temp=max(temp,ski[j]-48+path[i+j]-48);
              }
              ans+=temp;
          }
          else
          {
              FOR(j,0,n)
              {
                  temp=max(temp,ski[j+i]-48+path[j]-48);
              }
              ans+=temp;
          }
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
