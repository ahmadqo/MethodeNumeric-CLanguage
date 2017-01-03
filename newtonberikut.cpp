#include<iostream.h>
#include<math.h>

int main()
{
	double k1, error, k2, s, a, A, B, C, e, tol, imax;
	int i;
	awal:
	cout<<"Masukkan persamaan f(x) dengan format Ax^e+Bx+C :"<<endl;
	cout<<"Masukkan nilai A : "; cin>>A;
	cout<<"Masukkan nilai B : "; cin>>B;
	cout<<"Masukkan nilai C : "; cin>>C;
	cout<<"Masukkan nilai e : "; cin>>e;
	cout<<"Persamaan f(x) = "<<A<<"x^"<<e<<"+"<<B<<"x+"<<C<<endl;
	cout<<endl;
	cout<<"Masukkan nilai awal : ";cin>>k1;
	cout<<"Masukkan i max : "; cin>>imax;
	cout<<"Masukkan nilai toleransi : ";cin>>tol;
	cout<<endl;
	i=0;
	do{
		k2=k1-(((A)*pow(k1,e)) + (B*k1+C)) / ((3*A*pow(k1,(e-1)))+B);
		
		s=k1-k2;
		
		error=((A)-(pow(k2,e))) + (B*k2) + C;
		
		cout<<"nilai awal ke-"<<i<<" = "<<k1<<endl;
		cout<<"nilai k2 ke-"<<i+1<<" = "<<k2<<endl;
		cout<<"selisih "<<i<<" = "<<s<<endl;
		cout<<"error "<<i<<" = "<<error<<endl;
		cout<<endl;
		
		k1=k2;
		i++;
	}while (error>=tol && i<imax);
		cout<<"Nilai akarnya adalah : "<<k2;
		
	cout<<endl;
	char pil;
	cout<<"Hitung lagi ????? "; cin>>pil;
	while (pil=='y' || pil=='Y')
		goto awal;
	return 0;
}	