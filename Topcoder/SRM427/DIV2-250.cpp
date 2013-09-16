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

int score(string a,string b)
{
    int L=0,O=0,V=0,E=0;
    int l1=a.length();
    int l2=b.length();
    int i;
    FOR(i,0,l1)
    {
        if (a[i]=='L') L++;
        if (a[i]=='O') O++;
        if (a[i]=='V') V++;
        if (a[i]=='E') E++;
    }
    FOR(i,0,l2)
    {
        if (b[i]=='L') L++;
        if (b[i]=='O') O++;
        if (b[i]=='V') V++;
        if (b[i]=='E') E++;
    }
    return ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;
}

int comp(string a,string b)
{
    int l1=a.length();
    int l2=b.length();
    int l=min(l1,l2);
    int i;
    FOR(i,0,l)
    {
        if (a[i]>b[i])
        {
            return -1;
        }
        if (a[i]<b[i])
        {
            return 1;
        }
    }
    if (l1==l2) return 0;
    if (l1<l2) return 1;
    return -1;
}

class LoveCalculator{ 
public: 
    
  string findBoy(string girl, vector<string> boys)
  {
      int s=boys.size();
      int i;
      string ans=boys[0];
      int sc=score(girl,boys[0]);
      FOR(i,1,s)
      {
          int temp=score(girl,boys[i]);
          if (temp>sc)
          {
              sc=temp;
              ans=boys[i];
          }
          else
          {
              if (temp==sc)
              {
                  if (ans.compare(boys[i])>0)
                  {
                      ans=boys[i];
                  }
              }
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

