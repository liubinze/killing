// Killing 0.6 by Eznibuil
#include<bits/stdc++.h>
#include<conio.h>
#include<shlobj.h>
#include<windows.h>
using namespace std;
typedef long long ll;
bool fl;
char s[1001][1001]={
" 上弹\0S\0\0S",
"a拳  \0o\0\0o",
"s刀  \0/\0\0\\",
"w双刀\0//\0\\\\",
"d枪  \0>\0\0<",
"e双枪\0>>\0<<",
"q回血\0^\0\0^",
"c转  \0*\0\0*",
"\0防  \0X\0\0X"};
ll bl[2]={2ll,2ll},pw[2]={1ll,1ll},arm[2],chan[1001][1001]={
{0ll,-2ll},
{0ll,0ll},
{0ll,1ll},
{0ll,2ll},
{0ll,2ll},
{0ll,4ll},
{-1ll,0ll},
{1ll,-2ll}};
mt19937 rng(clock());
inline ll tran(char c)
{
	for(ll i=0ll;i<8ll;i++)
		if((c|' ')==s[i][0])
		{
			bl[0]=min(2ll,bl[0]-chan[i][0]),pw[0]-=chan[i][1],arm[0]=0ll;
			return i;
		}
	arm[0]++;
	return 8ll;
}
inline ll gen(ll x)
{
	ll y;
	if(pw[1]<10ll&&fl)
		if(x<2ll||x>5ll)
			y=0ll,pw[1]++,arm[1]=0ll;
		else if(arm[1]<6ll)
			y=8ll,arm[1]++;
		else
			y=4ll,pw[1]-=2ll,arm[1]=0ll;
	else
		fl=0,y=rng()%(bl[1]<2ll?7ll:8ll),bl[1]=min(2ll,bl[1]-chan[y][0]),pw[1]-=chan[y][1],arm[1]=0ll;
	return y;
}
inline void fire(ll x,ll y)
{
	ll a=0ll,b=11ll-strlen(s[y]+9);
	while(a+strlen(s[x]+6)<=b)
	{
		system("cls"),printf(" O             O\nIHV");
		for(ll i=0ll;i<a;i++)
			putchar(' ');
		if(a+strlen(s[x]+6)<=b||(!x||x>5ll)&&a+strlen(s[x]+6)>b)
			printf(s[x]+6);
		for(ll i=a+strlen(s[x]+6);i<b;i++)
			putchar(' ');
		if(a+strlen(s[x]+6)<=b||(!y||y>5ll)&&a+strlen(s[x]+6)>b)
			printf(s[y]+9);
		for(ll i=b+strlen(s[y]+9);i<11ll;i++)
			putchar(' ');
		if(a+strlen(s[x]+6)>b)
			printf("\b  ");
		puts("VHI\n/ \\           / \\");
		if(x&&x<6ll)
			a++;
		if(y&&y<6ll)
			b--;
		if((!x||x>5ll)&&(!y||y>5ll))
			break;
		Sleep(100);
	}
	return;
}
inline bool kill(ll x,ll y)
{
	if(pw[0]<0ll||arm[0]>6ll)
	{
		puts("你炸了！");
		return 1;
	}
	if(pw[1]<0ll||arm[1]>6ll)
	{
		puts("你赢了！");
		return 1;
	}
	fire(x,y);
	if(x==7ll||x==8ll||y==7ll||y==8ll);
	else if(x==6ll&&y&&y<4ll)
		if(y==2ll)
			bl[0]-=2ll;
		else
			bl[0]=0ll;
	else if(y==6ll&&x&&x<4ll)
		if(x==2ll)
			bl[1]-=2ll;
		else
			bl[1]=0ll;
	else if(x==6ll||y==6ll);
	else if(x==0ll)
		bl[0]-=max(0ll,chan[y][1]);
	else if(y==0ll)
		bl[1]-=chan[x][1];
	else if(x<4ll)
		if(y<4ll)
			bl[0]-=max(0ll,chan[y][1]-max(1ll,chan[x][1]));
		else
			bl[0]-=chan[y][1];
	else if(y<4ll)
		if(x<4ll)
			bl[1]-=max(0ll,chan[x][1]-max(1ll,chan[y][1]));
		else
			bl[1]-=chan[x][1];
	else if(x==4ll)
		bl[0]-=chan[y][1]-2ll;
	else if(y==4ll)
		bl[1]-=chan[x][1]-2ll;
	else;
	if(bl[0]<1ll)
	{
		puts("你死了！");
		return 1;
	}
	if(bl[1]<1ll)
	{
		puts("你赢了！");
		return 1;
	}
	return 0;
}
int main()
{
	char c[1001],cc[1001]="del ";
	SHGetSpecialFolderPath(0,c,CSIDL_DESKTOP,0),strcat(c,"\\验证码.txt");
	FILE*f=fopen(c,"w");
	ll x,y,t;
	fprintf(f,"%.6lld",x=rng()%1000000ll),fclose(f);
	printf("请输入验证码：");
	scanf("%lld",&y),strcat(cc,c),system(cc);
	if(x^y)
	{
		printf("这都输不对，搁这儿卡BUG呢？"),Sleep(3000);
		return 0;
	}
	while(1)
	{
		bl[0]=bl[1]=2ll,pw[0]=pw[1]=1ll,arm[0]=arm[1]=0ll,fl=1;
		while(1)
		{
			system("cls"),printf("Killing 0.6\nby Eznibuil\n\nSpace：开始游戏\nR：规则\nF：鸣谢\nQ：退出\nAlt+F4: 你懂的:)\n"),c[0]=getch(),system("cls");
			if(c[0]==' ')
				break;
			else if((c[0]|' ')=='r')
			{
				system("cls"),puts("初始：1血0.5能量\nSpace：上弹 加1能量");
				for(ll i=1ll;i<6ll;i++)
					printf("%c：%s 花费：%g能量\t\b\b伤害：%g血\n",s[i][0],s[i]+1,chan[i][1]/2.0,i^1ll?chan[i][1]/2.0:0.25);
				printf("%c：回血 加0.5血\n%c：转   无敌 扣0.5血加1能量\n其他字符：防 无敌 连续7次直接死亡\n伤害向下取半\n拳抵刀\n刀对回血0.5伤害\n拳和双刀对回血1伤害\n",s[6][0],s[7][0]);
			}
			else if((c[0]|' ')=='f')
				puts("感谢HCJ的支持！");
			else if((c[0]|' ')=='q')
			{
				puts("你以为这儿真是退出？");
				if((getch()|' ')=='q')
				{
					system("cls"),printf("感谢游玩！\n\n按任意键退出..."),getch();
					return 0;
				}
				continue;
			}
			else if(c[0]=='\0'&&getch()=='k')
				return 0;
			else
				continue;
			printf("\n按任意键返回菜单..."),getch();
		}
		while(1)
		{
			t=clock(),c[0]=getch();
			if((clock()-t)/CLOCKS_PER_SEC>5.0)
			{
				puts("你因超时而亡！");
				break;
			}
			system("cls"),x=tran(c[0]),y=gen(x);
			if(kill(x,y))
				break;
		}
		printf("\n按任意键返回菜单..."),getch();
	}
	return 0;
}
