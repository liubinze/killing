// Killing 0.3 by Eznibuil
#include<bits/stdc++.h>
#include<conio.h>
#include<shlobj.h>
#include<windows.h>
using namespace std;
typedef long long ll;
bool fl;
char s[1001][1001]={
" �ϵ�",
"aȭ  ",
"s��  ",
"w˫��",
"dǹ  ",
"e˫ǹ",
"q��Ѫ",
"cת  "};
ll bl[2]={2ll,2ll},pw[2]={1ll,1ll},arm[2],chan[1001][1001]={
{0ll,-2ll},
{0ll,0ll},
{0ll,1ll},
{0ll,2ll},
{0ll,2ll},
{0ll,4ll},
{-1ll,0ll},
{1ll,-2ll}};
mt19937 rng(time(0));
inline ll tran(char c)
{
	for(ll i=0ll;i<8ll;i++)
		if((c|' ')==s[i][0])
		{
			printf("%s || ",s[i]+1),bl[0]=min(2ll,bl[0]-chan[i][0]),pw[0]-=chan[i][1],arm[0]=0ll;
			return i;
		}
	printf("��   || "),arm[0]++;
	return 8ll;
}
inline ll gen(ll x)
{
	ll y;
	if(pw[1]<10ll&&fl)
		if(x<2ll||x>5ll)
			y=0ll,puts("�ϵ�"),pw[1]++,arm[1]=0ll;
		else if(arm[1]<6ll)
			y=8ll,puts("��"),arm[1]++;
		else
			y=4ll,puts("ǹ"),pw[1]-=2ll,arm[1]=0ll;
	else
		fl=0,y=rng()%(bl[1]<2ll?7ll:8ll),printf("%s\n",s[y]+1),bl[1]=min(2ll,bl[1]-chan[y][0]),pw[1]-=chan[y][1],arm[1]=0ll;
	return y;
}
inline bool fire(ll x,ll y)
{
	if(pw[0]<0ll||arm[0]>6ll)
	{
		puts("��ը�ˣ�");
		return 1;
	}
	if(pw[1]<0ll||arm[1]>6ll)
	{
		puts("��Ӯ�ˣ�");
		return 1;
	}
	if(x==7ll||x==8ll||y==7ll||y==8ll);
	else if(x==6ll&&y&&y<4ll)
		bl[0]=0ll;
	else if(y==6ll&&x&&x<4ll)
		bl[1]=0ll;
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
		puts("�����ˣ�");
		return 1;
	}
	if(bl[1]<1ll)
	{
		puts("��Ӯ�ˣ�");
		return 1;
	}
	return 0;
}
int main()
{
	char c[1001],cc[1001]="del ";
	SHGetSpecialFolderPath(0,c,CSIDL_DESKTOPDIRECTORY,0),strcat(c,"\\��֤��.txt");
	FILE*f=fopen(c,"w");
	ll x,y;
	fprintf(f,"%.6lld",x=rng()%1000000ll),fclose(f);
	printf("��������֤�룺");
	scanf("%lld",&y),strcat(cc,c),system(cc);
	if(x^y)
	{
		printf("�ⶼ�䲻�ԣ��������BUG�أ�"),Sleep(3000);
		return 0;
	}
	while(1)
	{
		bl[0]=bl[1]=2ll,pw[0]=pw[1]=1ll,arm[0]=arm[1]=0ll,fl=1;
		while(1)
		{
			system("cls"),printf("Killing 0.3\nby Eznibuil\n\nSpace: ��ʼ��Ϸ\nR: ����\nF: ��л\nAlt+F4: �㶮��:)\n"),c[0]=getch(),system("cls");
			if(c[0]==' ')
				break;
			else if((c[0]|' ')=='r')
			{
				system("cls"),puts("Space���ϵ�");
				for(ll i=1ll;i<8ll;i++)
					printf("%c��%s\n",s[i][0],s[i]+1);
				puts("�����ַ�����\n������6��ֱ��������");
			}
			else if((c[0]|' ')=='f')
				puts("��лHCJ��֧�֣�");
			else
				continue;
			printf("\n����������ز˵�..."),getch();
		}
		while(1)
		{
			c[0]=getch(),system("cls"),x=tran(c[0]),y=gen(x);
			if(fire(x,y))
				break;
		}
		printf("\n����������ز˵�..."),getch();
	}
	return 0;
}
