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

//if mn==mx return mx - wrong, because only proper factors of the number are present in the vector. mn=mx implies that the number has only one proper factor, namely mn, in which case the number can only by mn*mn.

class InverseFactoring{ 
public: 
    
  int getTheNumber(vector <int> arr)
  {
      int mn=1000001;
      int mx=0;
      int s=arr.size();
      int i;
      FOR(i,0,s)
      {
          mn=min(arr[i],mn);
          mx=max(arr[i],mx);
      }
      //if (mn==mx) return mx;
      return mn*mx;
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
