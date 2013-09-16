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

bool isCool(int n)
{
    vector <int> digits;
    while (n>0)
    {
        digits.push_back(n%10);
        n/=10;
    }
    int s=digits.size();
    if (s==1) return true;
    int i;
    int d=digits[0]-digits[1];
    FOR(i,1,s-1)
    {
        if (digits[i]-digits[i+1]!=d) return false;
    }
    return true;
}

class MegaCoolNumbersEasy{ 
public: 
    
  int count(int n)
  {
      int i,ans=0;
      FOR(i,0,n)
      {
          ans+=isCool(i+1);
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
