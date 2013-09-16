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

class ColorfulChocolates{ 
public: 
    
  int maximumSpread(string str,int c)
  {
      int i,j,k;
      int arr[26][50];
      memset(arr,0,sizeof(arr));
      int l=str.length();
      int count[26];
      memset(count,0,sizeof(count));
      FOR(i,0,l)
      {
          count[str[i]-65]++;
      }
      FOR(i,0,26)
      {
          if (str[0]-65==i) arr[i][0]=0;
          else arr[i][0]=1;
          FOR(j,1,l)
          {
              if (str[j]-65==i) arr[i][j]=arr[i][j-1];
              else arr[i][j]=arr[i][j-1]+1;
          }
      }
      int spr=1;
      int temp,temp2;
      FOR(i,0,26)
      {
          FOR(k,0,l)
          {
              temp=arr[i][k];
              if (temp<=c&&spr<k&&k<count[i]) spr=k;
          }
          FOR(j,0,l)
          {
              FOR(k,j+1,l)
              {
                  temp=arr[i][k]-arr[i][j];
                  temp2=k-j+1;
                  if (temp<=c&&spr<temp2&&temp2<=count[i]) spr=temp2;
              }
          }
      }
      return spr;
  }
};

//for testing
int main()
{
    ColorfulChocolates cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        string s;int c;
        cin>>s>>c;
        p(cls.maximumSpread(s,c));
    }
}
