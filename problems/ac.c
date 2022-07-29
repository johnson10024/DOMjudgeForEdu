#include <stdio.h>

int ans = 0, mx, cmx;

void sol(int total, int rCont, int wCont, int r, int w)
{
	if(rCont >= cmx)
	{
		ans++;
		return;
	}
	if(wCont >= cmx) return;
	
	if(total >= mx)
	{
		if(r >= w) ans++;
		return;
	}
	
	sol(total + 1, 0, wCont + 1, r, w + 1); //W
	sol(total + 1, rCont + 1, 0, r + 1, w); //R
}

int main()
{
	
	scanf("%d %d", &mx, &cmx);
	
	sol(1, 0, 1, 0, 1); //W
	sol(1, 1, 0, 1, 0); //R
	
	// int ans_2 = sol_2(1, 0, 1, 0, 1) + sol_2(1, 1, 0, 1, 0); // W R
	
	printf("%d\n", ans);
	
	return 0;
}

int sol_2(int total, int rCont, int wCont, int r, int w)
{
	if(rCont >= cmx) return 1;
	if(wCont >= cmx) return 0;
	
	if(total >= mx)
	{
		if(r >= w) return 1;
		else return 0;
	}
	
	return sol_2(total + 1, 0, wCont + 1, r, w + 1) + sol_2(total + 1, rCont + 1, 0, r + 1, w); //W + R
}


int iter()
{
	
}