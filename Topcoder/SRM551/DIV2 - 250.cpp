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

class ColorfulBricks{ 
public: 
    
  int countLayouts(string s)
  {
      int i;
      int l=s.length();
      int arr[26];
      memset(arr,0,sizeof(arr));
      FOR(i,0,l)
      {
          arr[s[i]-65]++;
      }
      int c=0;
      FOR(i,0,26)
      {
          if (arr[i]) c++;
      }
      if (c>2) return 0;
      if (c==2) return 2;
      return 1;
  }
};
