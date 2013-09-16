#line 72 "main.cpp"
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

class TheTournamentDivTwo {
	public:
	int find(vector <int> arr) 
	{
            int s=arr.size(),i;
            int sum=0;
            FOR(i,0,s) sum+=arr[i];     //should be equal to the total no. of matches played * 2
            if (sum&1) return -1;
            return sum/2;
	}
};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
