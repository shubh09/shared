#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

//346 points

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

int c2i(char c)
{
    return (int)c-48;
}

char i2c(int i)
{
    return (char)(i+48);
}

int f(int s,int a)
{
    int ans=s-a;
    ans=ans<0?ans+10:ans;
    return ans;
}

class RevealTriangle{ 
public: 
    
  vector <string> calcTriangle(vector <string> v)
  {
      int s=v.size();
      int i,j;
      //s-i
      for(i=s-2;i>=0;i--)
      {
          FOR(j,0,s-i)
          {
              if (v[i][j]!='?') break;
          }
          int jt=j;
          //v[i+1][j]
          FOR(j,jt+1,s-i)
          {
              v[i][j]=i2c(f(v[i+1][j-1],v[i][j-1]));
          }
          //v[i+1][j],v[i][j+1]
          for(j=jt-1;j>=0;j--)
          {
              v[i][j]=i2c(f(v[i+1][j],v[i][j+1]));
          }
      }
      return v;
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
