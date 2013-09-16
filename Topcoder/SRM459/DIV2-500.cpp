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
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

vector<string> &split(string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(string &s, char delim) {
    vector<string> elems;
    return split(s, delim, elems);
}

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}

bool satisfy(double x,int sign,double c)
{
//    cout<<x<<" "<<sign<<" "<<c<<endl;
    if (sign==0&&x<c) return true;
    else if (sign==1&&x<=c) return true;
    else if (sign==2&&x==c) return true;
    else if (sign==3&&x>c) return true;
    else if (sign==4&&x>=c) return true;
    return false;
}

class Inequalities {
	public:
	int maximumSubset(vector <string> v)
	{
		int i,j;
                int s1=sz(v);
                //sign index - <: 0, <=: 1, =: 2,>: 3, >=: 4
                vi sign(s1,-1);
                vi constant(s1,-1);
                FOR(i,0,s1)
                {
                    string str=v[i];
                    vstr vt=split(str,' ');
                    string sgn=vt[1];
                    if (sgn.compare("<")==0) sign[i]=0;
                    else if (sgn.compare("<=")==0) sign[i]=1;
                    else if (sgn.compare("=")==0) sign[i]=2;
                    else if (sgn.compare(">")==0) sign[i]=3;
                    else if (sgn.compare(">=")==0) sign[i]=4;
                    constant[i]=str2int(vt[2]);
//                    cout<<sign[i]<<" "<<constant[i]<<endl;
                }
                int ans=0;
                vector<double> arr;
                FOR(i,0,2001) arr.pb(0.5*i);
                arr.pb(-1.0);
                arr.pb(1001.0);
                FOR(i,0,sz(arr))
                {
                    int temp_ans=0;
                    FOR(j,0,s1)
                    {
                        if (satisfy(arr[i],sign[j],(double)constant[j])) temp_ans++;
                    }
//                    cout<<temp_ans<<endl;
                    ans=max(ans,temp_ans);
                }
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maximumSubset(Arg0)); }
	void test_case_1() { string Arr0[] = {"X < 0","X <= 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, maximumSubset(Arg0)); }
	void test_case_2() { string Arr0[] = {"X = 1","X = 2","X = 3","X > 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, maximumSubset(Arg0)); }
	void test_case_3() { string Arr0[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, maximumSubset(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	Inequalities ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
