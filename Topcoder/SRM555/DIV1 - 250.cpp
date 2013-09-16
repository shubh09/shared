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

#define INF 50

typedef long long ll;

int b2d(string s)
{
    int l=s.length();
    int i;
    int ans=0;
    FOR(i,0,l)
    {
        ans=2*ans+(s[i]-48);
    }
    return ans;
}

bool ispow(ll a)
{
    
//    while (a>0)
//    {
//        if (a==1) return true;
//        int r=a%5;
//        if (r!=0) return false;
//        a/=5;
//    }
//    return true;
    ll t=1;
    while (t<a)
    {
        t*=5;
    }
    if (t==a) return true;
    return false;
}

vector <int> cache(51,-2);

class CuttingBitString{ 
public: 
    
  int getmin(string str)
  {
      int l=str.length();
      if (l==0) return 0;
      //if (l<3) return -1;
      if (cache[l]>-2) return cache[l];
      if (str[0]=='0') return -1;
      //printf("here");
      int i;
      ll curr=0;
      int ans=0;
      FOR(i,0,l)
      {
          //if (curr==0 && (str[i]-48)==0) return -1;
          curr=2*curr+(str[i]-48);
          //p(curr);
          if (ispow(curr))
          {
              int temp=getmin(str.substr(i+1));
              //if (temp!=-1)
              //{
              if (ans==0) ans=1+temp;
              else
              {
                  if (temp>-1) ans=min(1+temp,ans);
              }
              //}
          }
      }
      if (ans==0) ans= -1;
      cache[l]=ans;
      return ans;
  }
};

//for testing
int main()
{
    CuttingBitString cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string str;
        cin>>str;
        p(cls.getmin(str));
    }
}
