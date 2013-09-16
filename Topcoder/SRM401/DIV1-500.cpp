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

double pi=3.14159265358979323846;

double diff=1e-9;

bool check(int vx, int vy, int vz, int x0, int y0, int z0,double t1,double t2)
{
    double x2=(vx*t2)+x0;
    double y2=(vy*t2)+y0;
    double z2=(vz*t2)+z0;
    double x1=cos(pi*t1);
    double y1=sin(pi*t1);
    double z1=t1;
    return ((abs(x1-x2)<diff)&&(abs(y1-y2)<diff)&&(abs(z1-z2)<diff));
}

vector<double> solve(double t1)
{
    vector<double> ans;
    ans.pb(cos(pi*t1));
    ans.pb(sin(pi*t1));
    ans.pb(t1);
    return ans;
}

class ParticleCollision {
	public:
	vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0) 
	{
            vector <double> ans;ans.clear();
            int a=(vx*vx)+(vy*vy);
            int b=2*((vy*y0)+(vx*x0));
            int c=(x0*x0)+(y0*y0)-1;
            int D=(b*b)-(4*a*c);
            if (a!=0)
            {
                if (D>0)
                {
                    double t21=((double)(-b)+sqrt(D))/(2*a);
                    double t22=((double)(-b)-sqrt(D))/(2*a);
                    double t11=(vz*t21)+z0;
                    double t12=(vz*t22)+z0;
                    if (check(vx,vy,vz,x0,y0,z0,t11,t21)&&check(vx,vy,vz,x0,y0,z0,t12,t22))
                    {
                        ans.pb(0);ans.pb(0);ans.pb(0);
                    }
                    else
                    {
                        if (check(vx,vy,vz,x0,y0,z0,t11,t21))
                        {
                            ans=solve(t11);
                        }
                        else
                        {
                            if (check(vx,vy,vz,x0,y0,z0,t12,t22))
                            {
                                ans=solve(t12);
                            }
                        }
                    }
                }
                else
                {
                    if(D==0)
                    {
                        double t2=(double)(-b)/(2*a);
                        double t1=(vz*t2)+z0;
                        if (check(vx,vy,vz,x0,y0,z0,t1,t2))
                        {
                            ans.pb(cos(pi*t1));
                            ans.pb(sin(pi*t1));
                            ans.pb(t1);
                        }
                    }
                }
            }
            else
            {
                //a is 0
                if (b!=0)
                {
                    double t2=(double)(-c)/b;
                    double t1=(vz*t2)+z0;
                    if (check(vx,vy,vz,x0,y0,z0,t1,t1))
                    {
                        ans.pb(cos(pi*t1));
                        ans.pb(sin(pi*t1));
                        ans.pb(t1);
                    }
                }
                else
                {
                    //a=b=0; check for infinitely many solutions
                    //the number of solutions is indeed infinitely many if the second trajectory is indeed a straight line; but what if its just a point?
                    
                    if (vx==0&&vy==0&&((x0*x0+y0*y0)==1))
                    {
                        if (vz!=0)
                        {
                                ans.pb(0);ans.pb(0);ans.pb(0);
                        }
                        else
                        {
                            //the second trajectory is a point; just check whether this point lies on the first trajectory
                            if (check(0,0,0,x0,y0,z0,z0,0))
                            {
                                ans.pb(x0);ans.pb(y0);ans.pb(z0);
                            }
                                
                        }
                    }
                }
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <double> &Expected, const vector <double> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; double Arr6[] = { }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(0, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = -1; int Arg4 = -1; int Arg5 = 0; double Arr6[] = {0.0, 1.0, 0.5 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(1, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 4; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(2, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; double Arr6[] = {0.0, 0.0, 0.0 }; vector <double> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); verify_case(3, Arg6, collision(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        ParticleCollision ___test; 
        ___test.run_test(-1); 
        double p=1e-10;
        printf("%.10f\n",p);
} 
// END CUT HERE
