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

class LinearPolyominoCovering{ 
public: 
    
  string findCovering(string str)
  {
      int l=str.length();
      string ans=str;
      int i=0;
      int cnt=0;
      while (i<l)
      {
          if (str[i]=='X')
          {
              cnt++;
              if (cnt==4)
                {
                    ans[i-3]='A';
                    ans[i-2]='A';
                    ans[i-1]='A';
                    ans[i]='A';
                    cnt=0;
                }
          }
          else
          {
              if (cnt==2)
              {
                  ans[i-2]='B';
                  ans[i-1]='B';
                  cnt=0;
              }
              
              else if (cnt>0) return "impossible";
          }
          i++;
      }
      if (cnt==2)
              {
                  ans[i-2]='B';
                  ans[i-1]='B';
                  cnt=0;
              }
              
              else if (cnt>0) return "impossible";
              
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
