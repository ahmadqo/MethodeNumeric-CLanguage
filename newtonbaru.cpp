#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <iomanip.h>
#include <stdlib.h>

main()
{
	int n, k, p, a, b, z;
	float koefisien[15];
	int pangkat[15];
	float x, xi, fx, fax, fxi, faxi;
	char lagi;
	atas:
	clrscr();
	cout<<"       ======Sistem Persamaan Non Linier======\n";
	cout<<"       =========Metode Newton-Raphson=========\n\n";
	cout<<"\n Input nilai pangkat tertinggi dari fungsi : ";
	cin>>n;
	cout<<"\n Input nilai koefisien !\n";
	for (k=0; k<=n; k++)
	{
		cout<<"   Koefisien X^"<<n-k<<" : ";
		cin>>koefisien[k];
	}
	for (p=0; p<=n; p++)
	{
		pangkat[p]=n-p;
	}
	cout<<"\n\n  F(X) = ";
	
	for (a=0; a<=n; a++)
	{
	   if (pangkat[a]==n && n!=1 && koefisien[a]>1)
	   {cout<<koefisien[a]<<"X^"<<pangkat[a];}
	   else if (pangkat[a]==n && n!=1 && koefisien[a]==1)
	   {cout<<"X^"<<pangkat[a];}
	   else if (pangkat[a]==n && n!=1 && koefisien[a]==-1)
	   {cout<<"-X^"<<pangkat[a];}
	   else if (pangkat[a]==n && n!=1 && koefisien[a]<-1)
	   {cout<<"-"<<-1*koefisien[a]<<"X^"<<pangkat[a];}
	   else if (pangkat[a]==n && n==1 && koefisien[a]>1)
	   {cout<<koefisien[a]<<"X";}
	   else if (pangkat[a]==n && n==1 && koefisien[a]==1)
	   {cout<<"X";}
	   else if (pangkat[a]==n && n==1 && koefisien[a]==-1)
	   {cout<<"-X";}
	   else if (pangkat[a]==n && n==1 && koefisien[a]<-1)
	   {cout<<"-"<<-1*koefisien[a]<<"X";}
	   else if (pangkat[a]==1 && koefisien[a]>1)
	   {cout<<" + "<<koefisien[a]<<"X";}
	   else if (pangkat[a]==1 && koefisien[a]==1)
	   {cout<<" + "<<"X";}
	   else if (pangkat[a]==1 && koefisien[a]==-1)
	   {cout<<" - X";}
	   else if (pangkat[a]==1 && koefisien[a]<-1)
	   {cout<<" - "<<-1*koefisien[a]<<"X";}
	   else if (pangkat[a]==0 && koefisien[a]>0)
	   {cout<<" + "<<koefisien[a]<<" = 0";}
	   else if (pangkat[a]==0 && koefisien[a]<0)
	   {cout<<" - "<<-1*koefisien[a]<<" = 0";}
	   else if (pangkat[a]==0 && koefisien[a]==0)
	   {cout<<" = 0";}
	   else if (pangkat[a]!=0 && koefisien[a]==0)
	   {cout<<"";}
	   else if (pangkat[a]>1 && pangkat[a]!=n && koefisien[a]==1)
	   {cout<<" + "<<"X^"<<pangkat[a];}
	   else if (pangkat[a]>1 && pangkat[a]!=n && koefisien[a]==-1)
	   {cout<<" - "<<"X^"<<pangkat[a];}
	   else if (pangkat[a]<n && koefisien[a]<0)
	   {cout<<" - "<<-1*koefisien[a]<<"X^"<<pangkat[a];}
		else
		{cout<<" + "<<koefisien[a]<<"X^"<<pangkat[a];}
	}

	cout<<"\n\n F'(X) = ";

	for (a=0; a<=n; a++)
	{

	   if (pangkat[a]-1==n-1 && n-1!=1 && koefisien[a]*pangkat[a]>1)
	   {cout<<koefisien[a]*pangkat[a]<<"X^"<<pangkat[a]-1;}
	   else if (pangkat[a]-1==n-1 && n-1!=1 && koefisien[a]*pangkat[a]==1)
	   {cout<<"X^"<<pangkat[a]-1;}
	   else if (pangkat[a]-1==n-1 && n-1!=1 && koefisien[a]*pangkat[a]==-1)
	   {cout<<"-X^"<<pangkat[a]-1;}
	   else if (pangkat[a]-1==n-1 && n-1!=1 && koefisien[a]*pangkat[a]<-1)
	   {cout<<"-"<<-1*koefisien[a]*pangkat[a]<<"X^"<<pangkat[a]-1;}
	   else if (pangkat[a]-1==n-1 && n-1==1 && koefisien[a]*pangkat[a]>1)
	   {cout<<koefisien[a]*pangkat[a]<<"X";}
	   else if (pangkat[a]-1==n-1 && n-1==1 && koefisien[a]*pangkat[a]==1)
	   {cout<<"X";}
	   else if (pangkat[a]-1==n-1 && n-1==1 && koefisien[a]*pangkat[a]==-1)
	   {cout<<"-X";}
	   else if (pangkat[a]-1==n-1 && n-1==1 && koefisien[a]*pangkat[a]<-1)
	   {cout<<"-"<<-1*koefisien[a]*pangkat[a]<<"X";}
	   else if (pangkat[a]-1==1 && koefisien[a]*pangkat[a]>1)
	   {cout<<" + "<<koefisien[a]*pangkat[a]<<"X";}
	   else if (pangkat[a]-1==1 && koefisien[a]*pangkat[a]==1)
	   {cout<<" + "<<"X";}
	   else if (pangkat[a]-1==1 && koefisien[a]*pangkat[a]==-1)
	   {cout<<" - X";}
	   else if (pangkat[a]-1==1 && koefisien[a]*pangkat[a]<-1)
	   {cout<<" - "<<-1*koefisien[a]*pangkat[a]<<"X";}
	   else if (pangkat[a]-1==0 && koefisien[a]*pangkat[a]>0)
	   {cout<<" + "<<koefisien[a]*pangkat[a]<<" = 0";}
	   else if (pangkat[a]-1==0 && koefisien[a]*pangkat[a]<0)
	   {cout<<" - "<<-1*koefisien[a]*pangkat[a]<<" = 0";}
	   else if (pangkat[a]-1==0 && koefisien[a]*pangkat[a]==0)
	   {cout<<" = 0";}
	   else if (pangkat[a]-1!=0 && koefisien[a]*pangkat[a]==0)
	   {cout<<"";}
	   else if (pangkat[a]-1>1 && pangkat[a]-1!=n && koefisien[a]*pangkat[a]==1)
	   {cout<<" + "<<"X^"<<pangkat[a]-1;}
	   else if (pangkat[a]-1>1 && pangkat[a]-1!=n && koefisien[a]*pangkat[a]==-1)
	   {cout<<" - "<<"X^"<<pangkat[a]-1;}
	   else if (pangkat[a]-1<n && koefisien[a]*pangkat[a]<0)
	   {cout<<" - "<<-1*koefisien[a]*pangkat[a]<<"X^"<<pangkat[a]-1;}
		else
		{cout<<" + "<<koefisien[a]*pangkat[a]<<"X^"<<pangkat[a]-1;}
	}
	cout<<"\n\n Input nilai tebakan awal : ";
	cin>>x;

	clrscr();
	cout<<endl<<endl;
	cout<<"-------------------------------------------------------------------------\n";
	cout<<"| Ke |   XI-1  |    XI    |    F(XI-1)   |    F'(XI-1)   |     F(XI)    |\n";
	cout<<"=========================================================================\n";
	for (z=1; z<100; z++)
	{
		fx=0;
		for (b=0; b<=n; b++)
		{
			fx = fx + (koefisien[b] * pow(x,pangkat[b]));
		}
		fax=0;
		for (b=0; b<=n; b++)
		{
			fax = fax + (koefisien[b]*pangkat[b] * pow(x,pangkat[b]-1));
		}
		xi=x-(fx/fax);
		fxi=0;
		for (b=0; b<=n; b++)
		{
			fxi = fxi + (koefisien[b] * pow(xi,pangkat[b]));
		}
		faxi=0;
		for (b=0; b<=n; b++)
		{
			faxi = faxi + (koefisien[b]*pangkat[b] * pow(xi,pangkat[b]-1));
		}

		cout<<"| "<<setw(3)<<setiosflags(ios::left)<<z;
		cout<<"| "<<setw(8)<<setiosflags(ios::left)<<x;
		cout<<"| "<<setw(9)<<setiosflags(ios::left)<<xi;
		cout<<"| "<<setw(13)<<setiosflags(ios::left)<<fx;
		cout<<"| "<<setw(14)<<setiosflags(ios::left)<<fax;
		cout<<"| "<<setw(13)<<setiosflags(ios::left)<<fxi<<"|\n";
		cout<<"-------------------------------------------------------------------------\n";

		x=xi;

		if (fx==fxi){
			break;
		}
		else{
			continue;
		}
	}
	cout<<"\n\n Tekan [1] untuk menghitung lagi atau tekan [2] untuk menutup program.";
	lagi=getche();
	if (lagi=='1')
	{
		goto atas;
	}
	else
	{
		exit(0);
	}
	getch();
}
