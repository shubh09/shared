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

int str2int(string s)
{
    istringstream buffer(s);
    int ans;
    buffer>>ans;
    return ans;
}

int mnths[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool isDateValid(string date)
{
    string year_temp=date.substr(0,4);
    int year=str2int(year_temp);
    if (year>2011||year<1900) return false;
    bool isLeap=(year%400==0||(year%100!=0&&year%4==0));
    string month_temp=date.substr(4,2);
    int month=str2int(month_temp);
    if (month<1||month>12) return false;
    string day_temp=date.substr(6,2);
    int day=str2int(day_temp);
    if (day<1) return false;
    if (isLeap)
    {
        if (month==2)
        {
            if (day>29) return false;
        }
        else
        {
            if (day>mnths[month-1]) return false;
        }
    }
    else
    {
        if (day>mnths[month-1]) return false;
    }
    return true;
}

class IDNumberVerification {
	public:
	string verify(string id, vector <string> v)
	{
		int i,j;
                int n=sz(v);
                string rc=id.substr(0,6);
                FOR(i,0,n)
                {
                    if (rc.compare(v[i])==0) break;
                }
                if (i==n) return "Invalid";
                string bd=id.substr(6,8);
                if (!isDateValid(bd)) return "Invalid";
                string sc=id.substr(14,3);
                if (sc.compare("000")==0) return "Invalid";
                int sci=str2int(sc);
                int checksum=0;
                int p=2;
                FOR(i,0,17)
                {
                    int add=(id[16-i]-'0')*p;
                    p*=2;
                    checksum+=add;
                }
                checksum--;
                checksum*=(-1);
                int x=checksum%11;
                if (x<0) x+=11;
                if (x<10&&id[17]-'0'!=x) return "Invalid";
                if (x==10&&id[17]!='X') return "Invalid";
                if (sci&1) return "Male";
                return "Female";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "441323200312060636"; string Arr1[] = {"441323"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Male"; verify_case(0, Arg2, verify(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "62012319240507058X"; string Arr1[] = {"620123"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Female"; verify_case(1, Arg2, verify(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "321669197204300886"; string Arr1[] = {"610111","659004"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(2, Arg2, verify(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "230231198306900162"; string Arr1[] = {"230231"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(3, Arg2, verify(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "341400198407260005"; string Arr1[] = {"341400"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(4, Arg2, verify(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "520381193206090891"; string Arr1[] = {"532922","520381"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid"; verify_case(5, Arg2, verify(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        IDNumberVerification ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE
