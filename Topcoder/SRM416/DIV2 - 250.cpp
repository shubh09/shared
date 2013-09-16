#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <sstream>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

vector <int> arr(26,0);

class MostCommonLetters{ 
public: 
    
    string i2c(int i)
    {
        char c=((char)(i+97));
        stringstream ss;
        string s;
        ss<<c;
        ss>>s;
        return s;
    }
  string listMostCommon(vector <string> v)
  {
      int s=v.size();
      int i,j;
      FOR(i,0,s)
      {
          int l=v[i].length();
          FOR(j,0,l)
          {
              if (v[i][j]!=' ') arr[v[i][j]-97]++;
          }
      }
      int mx=0;
      FOR(i,0,26)
      {
          mx=max(mx,arr[i]);
      }
      string ans="";
      FOR(i,0,26)
      {
          if (arr[i]==mx)
          {
              ans=ans.append(i2c(i));
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
