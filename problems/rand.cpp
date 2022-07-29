#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <random>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>
#include <sys/time.h>

#define MOD (1000000007)
#define INF (0x3f3f3f3f)
#define PREC (0.0000001)
#define X first
#define Y second

#define MIN 1
#define MAX 30
#define MU 10
#define SIGMA 1
#define SUCC 0.5

#define MX 10000

#define DEBUG

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

default_random_engine gen;
normal_distribution<double> dn(MU, SIGMA);
bernoulli_distribution db(SUCC);
uniform_int_distribution<int> du(MIN, MAX);
uniform_real_distribution<double> dr(0.0, 1.0);


struct timeval sysTime;

void init()
{
	gettimeofday(&sysTime, NULL);
	gen = default_random_engine((unsigned int)sysTime.tv_usec);
	
}
 
void solve()
{
	int n, a;
	
	n = du(gen);
	a = du(gen) % n + 1;
	
	//Output
	printf("%d %d\n", n, a);
}
 
int main()
{
	// int n;
	// scanf("%d", &n);
	
	// while(n--)
	{
		init();
		solve();
		
	}
	return 0;
}
