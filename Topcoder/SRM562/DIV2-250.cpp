#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                   push_back(n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

class CucumberMarket{ 
public: 
    
  string check(row arr,int b,int k)
  {
      sort(arr.begin(),arr.end());
      int i,s=arr.size(),sum=0;
      FOR(i,0,k)
      {
          sum+=arr[s-1-i];
      }
      if (sum>b)
      {
          return "NO";
      }
      return "YES";
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
