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

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

vector<string> &split(string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while(getline(ss, item, delim)) {
        if (!item.empty()) elems.push_back(item);
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

inline std::string trim_right_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

inline std::string trim_left_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return s.substr( s.find_first_not_of( delimiters ) );
}

inline std::string trim_copy(
  const std::string& s,
  const std::string& delimiters = " \f\n\r\t\v" )
{
  return trim_left_copy( trim_right_copy( s, delimiters ), delimiters );
}


class RunningLetters {
	public:
	int newsLength(vector <string> v) 
	{
            int s=sz(v);
            vstr v2;
            int i;
            string str1;
            FOR(i,0,s)
            {
                str1.append(v[i]);
            }
            v2=split(str1,' ');
            s=sz(v2);
//            FOR(i,0,s) cout<<i<<" "<<v2[i]<<" "<<endl;
            string str;
            int j;
            FOR(i,0,s)
            {
                if ((i&1))
                {
                    int n=str2int(trim_copy(v2[i-1]));
//                    p(n);
                    FOR(j,0,n) str=str.append(v2[i]);
                }
            }
//            cout<<str<<endl;
            //now str contains the expanded string
            s=sz(str);
            vi arr(s+1);
            arr[0]=arr[1]=0;
            FOR(i,2,s+1)
            {
                j=arr[i-1];
                while(1)
                {
                    if (str[j]==str[i-1])
                    {
                        arr[i]=j+1;
                        break;;
                    }
                    if (j==0)
                    {
                        arr[i]=0;
                        break;
                    }
                    j=arr[j];
                }
            }
            return s-arr[s];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 abc 1 ab"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, newsLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 babaaba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, newsLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 ba 1 c 1 bacba 3 cba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, newsLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"42 runningletters 42 runningletters 1 running"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(3, Arg1, newsLength(Arg0)); }
	void test_case_4() { string Arr0[] = {"1 b ", "1 a ", "1 b ", "1 a", " 1 b"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, newsLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RunningLetters ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
