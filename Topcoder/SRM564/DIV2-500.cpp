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
#define clr(a)					memset(a,0,sizeof(a))

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

string ret(int k)
{
    k=k%3;
    if (k<0) k+=3;
    if (k==0) return "RED";
    else
    {
        if (k==1) return "GREEN";
        return "BLUE";
    }
}

class AlternateColors {
	public:
	string getColor(long long r, long long g, long long b, long long k) 
	{
            ll mn=min(r,min(g,b));
            ll mx=max(r,max(g,b));
            ll mn2=r+g+b-mn-mx;
            int bmx,bmn2,bmn;
            if (mn==r) bmn=0;
            else {
                if (mn==g) bmn=1;
                else bmn=2;
            }
            
            if (mn2==r&&bmn!=0)bmn2=0;
            else {
                if (mn2==g&&bmn!=1) bmn2=1;
                else bmn2=2;
            }
            
            bmx=3-bmn-bmn2;
            if (k<=3*mn)
            {
                int r=(int)(k%3);
                return ret(r-1);
            }
            mn2-=mn;mx-=mn;
            k-=(3*mn);
            if (k<=2*mn2)
            {
                int r=(int)(k%2);
                if (r==0)
                {
                    return ret(max(bmn2,bmx));
                }
                else return ret(min(bmn2,bmx));
            }
            return ret(bmx);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 3LL; string Arg4 = "BLUE"; verify_case(0, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 5LL; long long Arg3 = 4LL; string Arg4 = "RED"; verify_case(1, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 7LL; long long Arg1 = 7LL; long long Arg2 = 1LL; long long Arg3 = 7LL; string Arg4 = "GREEN"; verify_case(2, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 1000000000002LL; string Arg4 = "RED"; verify_case(3, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 653LL; long long Arg1 = 32LL; long long Arg2 = 1230LL; long long Arg3 = 556LL; string Arg4 = "BLUE"; verify_case(4, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        AlternateColors ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
