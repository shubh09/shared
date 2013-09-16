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

//slight catch!!
//find the prime factorization of the number; if it contains a factor other than 2,3,5,7 - return -1.  n=(2^h2)*(3^h3)*(5^h5)*(7^h7). h2/3 + h3/2 + h5 + h7. max of 2 2's and 1 3 still remaining. NOTE that 1 2 and 1 3 can be combined into a 6.

int highestPow(int n,int p) //assumes p>m
{
    int ans=0;
    while (n>0&&n%p==0)
    {
        n/=p;
        ans++;
    }
    return ans;
}

int epow(int a,int p)
{
	if (p==0) return 1;
	int t=epow(a,p/2);
	t*=t;
	if (p&1) t*=a;
	return t;
}

class ProductOfDigits{ 
public: 
    
  int smallestNumber(int n)
  {
      if (n==1) return 1;
      int h2=highestPow(n,2);
      int h3=highestPow(n,3);
      int h5=highestPow(n,5);
      int h7=highestPow(n,7);
      //printf("%d %d %d %d\n",h2,h3,h5,h7);
      if (epow(2,h2)*epow(3,h3)*epow(5,h5)*epow(7,h7)!=n) return -1;
      int ans2=(h2/3);
      //int add2=(h2%3==0)?0:1;
      //ans2+=add2;
      int ans3=(h3/2);
      //int add3=h3%2;
      //ans3+=add3;
      int add[2][3];
      add[0][0]=0;add[0][1]=1;add[0][2]=1;
      add[1][0]=1;add[1][1]=1;add[1][2]=2;
      return ans2+ans3+h5+h7+add[h3%2][h2%3];
  }
};

//for testing
int main()
{
    ProductOfDigits cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        sd(n);
        p(cls.smallestNumber(n));
    }
}
