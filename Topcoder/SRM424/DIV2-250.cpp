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

//involves reversing a sub-string (not a proper substring) of the given string. E.g. *__**_**

typedef long long ll;

class MagicSpell{ 
public: 
    
  string fixTheSpell(string str)
  {
      int l=str.length();
      int i;
      vector <int> arr;
      FOR(i,0,l)
      {
          if (str[i]=='A'|| str[i]=='Z') arr.push_back(i);
      }
      int s=arr.size();
      int s2=s/2;
      FOR(i,0,s2)
      {
          char t;
          int ind1=arr[i];
          int ind2=arr[s-1-i];
          t=str[ind1];
          str[ind1]=str[ind2];
          str[ind2]=t;
      }
      return str;
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
