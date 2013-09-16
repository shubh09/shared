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

class TheEncryptionDivTwo{ 
public: 
    
  string encrypt(string str)
  {
      int l=str.length(),i,j;
      string ans=str;
      int arr1[26];
      bool arr2[26];
      memset(arr1,-1,sizeof(arr1));
      memset(arr2,0,sizeof(arr2));
      FOR(i,0,l)
      {
          int c=str[i]-97;
          if (arr1[c]>=0)
          {
              ans[i]=(char)(arr1[c]+97);
          }
          else
          {
              FOR(j,0,26)
              {
                  if (!arr2[j]) break;
              }
              arr2[j]=true;
              arr1[c]=j;
              ans[i]=(char)(arr1[c]+97);
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
