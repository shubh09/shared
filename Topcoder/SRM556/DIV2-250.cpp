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

bool check(string s)
{
    int arr[26];
    memset(arr,0,sizeof(arr));
    int l=s.length();
    int i;
    FOR(i,0,l)
    {
        int ind=s[i]-97;
        if (arr[ind]>0) return false;
        arr[ind]++;
    }
    return true;
}

class ChocolateBar{ 
public: 
    
  int maxLength(string str)
  {
      int l=str.length();
      int i,j;
      int ans=0;
      FOR(i,0,l)
      {
          FOR(j,1,l-i+1)
          {
              string temp=str.substr(i,j);
              if (check(temp)) ans=max(j,ans);
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
