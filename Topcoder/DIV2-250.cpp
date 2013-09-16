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

class MultiNumber{ 
public: 
    
  string check(int a)
  {
      vector <int> arr;
      while (a>0)
      {
          int r=a%10;
          arr.push_back(r);
          a/=10;
      }
      int s=arr.size();
      //p(s);
      int i,j;
      bool succ=false;
      FOR(i,1,s)        //0...i-1;i...s-1
      {
          int m1=1;
          int m2=1;
          FOR(j,0,i) m1*=arr[j];
          FOR(j,i,s) m2*=arr[j];
          //p(m1);
          //p(m2);
          if (m1==m2)
          {
              succ=true;
              break;
          }
      }
      string no="NO";
      string yes="YES";
      if (succ) return yes;
      else return no;
      
  }
};

//for testing
int main()
{
    MultiNumber cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        sd(n);
        cout<<cls.check(n)<<endl;
    }
}
