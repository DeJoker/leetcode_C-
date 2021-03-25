
#include "../common/debugger.h"



// dp[i][state]表示该填充第i列，第i-1列对它的影响是state的时候的方法数
// state 需要完整遍历全部解
 
int N, M;
int dp[1005][34];
const int MOD = 1e9+7;

void dfs(int i,int j,int state,int nex)
{
	if (j==N)
	{
		dp[i+1][nex]+=dp[i][state];
        dp[i+1][nex] %= MOD;
		return;
	}
	//如果这个位置已经被上一列所占用,直接跳过
	if (((1<<j)&state)>0)
		dfs(i,j+1,state,nex);

	//如果这个位置是空的，尝试放一个1*2的
	if (((1<<j)&state)==0)
		dfs(i,j+1,state,nex|(1<<j));

	//如果这个位置以及下一个位置都是空的，尝试放一个2*1的
	if (j+1<N && ((1<<j)&state)==0 && ((1<<(j+1))&state)==0)
		dfs(i,j+2,state,nex);
    
	return;
}
 
int main()
{
	while (cin>>N>>M)
	{
		memset(dp,0,sizeof(dp));
		if (N==0 && M==0) break;
		dp[1][0]=1; 
		for (int i=1;i<=M;i++)
		{
			for (int j=0;j<(1<<N);j++)
			if (dp[i][j])
			{
				dfs(i,0,j,0);
			}
		}
		cout<<dp[M+1][0]<<endl;
	}
}

