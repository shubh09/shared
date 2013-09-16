/* 
 * File:   main.cpp
 * Author: shubham
 *
 * Created on 29 July, 2012, 12:02 AM
 */

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
#define MAXN 10

typedef long long ll;

bool isPrime(int n)
{
    int s=(int)(sqrt(n)+0.5);
    int i;
    FOR(i,2,s+1)
    {
        if (n%i==0) return false;
    }
    return true;
}

ll epow(int a,int b)
{
    if (b==0) return (ll) 1;
    ll t=epow(a,b/2);
    t*=t;
    if (b&1) t*=(ll)a;
    return t;
}

class StrongPrimePower{ 
public: 
    
  vector <int> baseAndExponent(string s)
  {
      ll n=0;
      int len=s.length();
      int i;
      vector <int> ans;
      FOR(i,0,len)
      {
          n=(n*10)+(ll) ((int)s[i]-48);
      }
      FOR(i,2,60)
      {
          double p=pow((double)n,(double)(1)/i);
          //printf("%d %f\n",i,p);
          int pi=(int)(p+0.5);
          if (epow(pi,i)==n)
          {
              p(pi);
              if (isPrime(pi))
              {
                  ans.push_back(i);
                  ans.push_back(pi);
                  return ans;
              }
          }
      }
      return ans;
  }
};

int main()
{
    StrongPrimePower spp;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string s;
        cin>>s;
        vector <int> a = spp.baseAndExponent(s);
    }
}
