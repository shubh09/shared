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

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

string char2str(char c)
{
    stringstream ss;
    string ans;
    ss<<c;
    ss>>ans;
    return ans;
}

class WordsGame {
	public:
	int minimumSwaps(vector <string> v, string str) 
	{
            int n=sz(str),i,j;
            string str_sorted=str;
            sort(all(str_sorted));
            int ans=1000000000;
            //for each row and column
            FOR(i,0,2*n)
            {
                string str2;
                if (i<n) str2=v[i];
                else
                {
                    str2="";
                    FOR(j,0,n) str2.append(char2str(v[j][i-n]));
                }
                string str2_sorted=str2;
                sort(all(str2_sorted));
                if (str_sorted.compare(str2_sorted)) continue;
                vi perm(n);
                FOR(j,0,n) perm[j]=str.find(str2[j]);
                int ncycles=0;
                vi p2(n,0);
                FOR(j,0,n)
                {
                    if (p2[j]!=-1)
                    {
                        ncycles++;
                        int j2=j;
                        while (p2[j2]!=-1)
                        {
                            p2[j2]=-1;
                            int next=perm[j2];
                            j2=next;
                        }
                    }
                }
                ans=min(ans,n-ncycles);
            }
            if (ans==1000000000) ans=-1;
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Mu",
 "uM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Mu"; int Arg2 = 0; verify_case(0, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"sdf",
 "bca",
 "hgf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 2; verify_case(1, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"cdf",
 "bca",
 "agf"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "abc"; int Arg2 = 1; verify_case(2, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "bkHg"; int Arg2 = 2; verify_case(3, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "oDmWcJHGNk"; int Arg2 = 6; verify_case(4, Arg2, minimumSwaps(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"ab",
 "bA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "aB"; int Arg2 = -1; verify_case(5, Arg2, minimumSwaps(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        WordsGame ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
