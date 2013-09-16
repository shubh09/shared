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

class OlympicCandles{ 
public: 
    
  int numberOfNights(vector <int> arr)
  {
      int ans=1;
      int s=arr.size();
      int i;
      while(ans<=s)
      {
          sort(arr.begin(),arr.end());
          for (i=s-1;i>s-ans-1;i--)
          {
              if (arr[i]==0) return ans-1;
              arr[i]--;
          }
          ans++;
      }
      return s;
  }
};

//for testing
int main()
{
    OlympicCandles cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
