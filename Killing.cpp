// Killing 0.6 by Eznibuil
#include<bits/stdc++.h>
#include<conio.h>
#include<shlobj.h>
#include<windows.h>
using namespace std;
typedef long long ll;
bool fl;
char s[1001][1001]={
" �ϵ�\0S\0\0S",
"aȭ  \0o\0\0o",
"s��  \0/\0\0\\",
"w˫��\0//\0\\\\",
"dǹ  \0>\0\0<",
"e˫ǹ\0>>\0<<",
"q��Ѫ\0^\0\0^",
"cת  \0*\0\0*",
"\0��  \0X\0\0X"};
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
		puts("��ը�ˣ�");
		return 1;
	}
	if(pw[1]<0ll||arm[1]>6ll)
	{
		puts("��Ӯ�ˣ�");
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
	SHGetSpecialFolderPath(0,c,CSIDL_DESKTOP,0),strcat(c,"\\��֤��.txt");
	FILE*f=fopen(c,"w");
	ll x,y,t;
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
			system("cls"),printf("Killing 0.6\nby Eznibuil\n\nSpace����ʼ��Ϸ\nR������\nF����л\nQ���˳�\nAlt+F4: �㶮��:)\n"),c[0]=getch(),system("cls");
			if(c[0]==' ')
				break;
			else if((c[0]|' ')=='r')
			{
				system("cls"),puts("��ʼ��1Ѫ0.5����\nSpace���ϵ� ��1����");
				for(ll i=1ll;i<6ll;i++)
					printf("%c��%s ���ѣ�%g����\t\b\b�˺���%gѪ\n",s[i][0],s[i]+1,chan[i][1]/2.0,i^1ll?chan[i][1]/2.0:0.25);
				printf("%c����Ѫ ��0.5Ѫ\n%c��ת   �޵� ��0.5Ѫ��1����\n�����ַ����� �޵� ����7��ֱ������\n�˺�����ȡ��\nȭ�ֵ�\n���Ի�Ѫ0.5�˺�\nȭ��˫���Ի�Ѫ1�˺�\n",s[6][0],s[7][0]);
			}
			else if((c[0]|' ')=='f')
				puts("��лHCJ��֧�֣�");
			else if((c[0]|' ')=='q')
			{
				puts("����Ϊ��������˳���");
				if((getch()|' ')=='q')
				{
					system("cls"),printf("��л���棡\n\n��������˳�..."),getch();
					return 0;
				}
				continue;
			}
			else if(c[0]=='\0'&&getch()=='k')
				return 0;
			else
				continue;
			printf("\n����������ز˵�..."),getch();
		}
		while(1)
		{
			t=clock(),c[0]=getch();
			if((clock()-t)/CLOCKS_PER_SEC>5.0)
			{
				puts("����ʱ������");
				break;
			}
			system("cls"),x=tran(c[0]),y=gen(x);
			if(kill(x,y))
				break;
		}
		printf("\n����������ز˵�..."),getch();
	}
	return 0;
}
