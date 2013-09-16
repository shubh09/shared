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

class SurroundingGameEasy{ 
public: 
    
  int score(vector <string> c, vector <string> b, vector <string> s)
  {
      int s1=c.size();
      int s2=c[0].size();
      int i,j;
      int cost=0,benefit=0;
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              if (s[i][j]=='o')
              {
                  cost+=c[i][j]-48;
                  benefit+=b[i][j]-48;
              }
              else
              {
                  bool dom=true;
                  if (i>0&&s[i-1][j]=='.') dom=false;
                  if (i<s1-1&&s[i+1][j]=='.') dom=false;
                  if (j>0&&s[i][j-1]=='.') dom=false;
                  if (j<s2-1&&s[i][j+1]=='.') dom=false;
                  if (dom) benefit+=b[i][j]-48;
              }
          }
      }
      return benefit-cost;
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
