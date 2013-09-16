#line 2 "main.cpp"
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

class FoxAndHandleEasy {
	public:
	string isPossible(string a, string b) 
	{
            int l=a.length();
            int i;
            FOR(i,0,l+1)        //i being the position of insertion
            {
                //constructing the new string
                string s1=a.substr(0,i);
                string s2=a.substr(i,l-i);
                string c=(s1.append(a)).append(s2);
                if (c.compare(b)==0) return "Yes";
            }
            return "No";
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
