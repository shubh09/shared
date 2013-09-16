// BEGIN CUT HERE
//// PROBLEM STATEMENT
// You are a carpenter and you want to build several pieces of furniture.  Unfortunately, you've lost all your tools.  You are given a vector <string> need, the i-th element of which is a space separated list of the tools required to construct the i-th piece of furniture.  Return the number of different tools you must buy to construct all the furniture.


// END CUT HERE
#line 46 "main.cpp"
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

vector <string> split(string a,char c) //splits a string wrt the delimiter c. returns only the non empty tokens in the vector.
{
    int i;
    int l=a.length();
    int pos=0,count=0;
    //if (a[0]==c) start=1;
    vector <string> ret;
    FOR(i,0,l)
    {
        if (a[i]==c)
        {
            string str=a.substr(pos,count);
            if (!str.empty()) ret.push_back(str);
            pos=i+1;
            count=0;
        }
        else count++;
    }
    string str=a.substr(pos,count);
    if (!str.empty()) ret.push_back(str);
    return ret;
}


class ToolsBox {
	public:
	int countTools(vector <string> v) 
	{
            map <string,int> arr;
            int s=v.size();
            int i,j;
            FOR(i,0,s)
            {
                string str=v[i];
                vstr splt=split(str,' ');
                int s2=splt.size();
                FOR(j,0,s2)
                {
                    if (arr.count(splt[j]))
                    {
                        arr[splt[j]]++;
                    }
                    else
                    {
                        arr.insert(make_pair(splt[j],0));
                    }
                }
            }
            return arr.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SAW HAMMER SCREWDRIVER","SCREWDRIVER HAMMER KNIFE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, countTools(Arg0)); }
	void test_case_1() { string Arr0[] = {"SAW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, countTools(Arg0)); }
	void test_case_2() { string Arr0[] = {"SAW","SAW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countTools(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ToolsBox ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
