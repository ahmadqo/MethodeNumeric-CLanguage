//		   ===METODE NUMERIK===
// ==PROGRAM ITERASI DENGAN METODE JACOBI==
//			   AHMAD QOMARUDDIN
//				 145410028
//		   ====STMIK AKAKOM====
#include<iostream>
#include<conio>
#include<iomanip>
using namespace std;

void main()
{
	awal:
	cout<<"		   ===METODE NUMERIK===\n";
	cout<<" 	==PROGRAM ITERASI DENGAN METODE JACOBI==\n";
	cout<<"		        AHMAD QOMARUDDIN\n";
	cout<<"		               145410028\n";
	cout<<"		  ====STMIK AKAKOM====\n";
	cout<<endl<<endl;
	
	int i, j, k, l, ukuran, iterasi, btsiterasi;
	float f[10], a[10][10],b[10],x[10], toleransi, sigma[10];
	char ulang;
	
	//input ukuran matrik
	cout<<"MASUKKAN BESARAN MATRIK : ";	cin>>ukuran;
	cout<<"===================="<<endl;
	
	//masukkan matrik a
	for(i=1;i<=ukuran;i++){
		for(j=1;j<=ukuran;j++){
			cout<<"Elemen matrik a[" <<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}
	}
	cout<<"===================="<<endl;
	for(i=1;i<=ukuran;i++){
		for(j=1;j<=ukuran;j++){
			cout<<setw(4)<<a[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<"===================="<<endl;
	//masukkan matrik b
	for(i=1;i<=ukuran;i++){
		cout<<"Elemen matrik b["<<i<< "] = ";
		cin>>b[i];
	}
	cout<<"===================="<<endl;
	for(i=1;i<=ukuran;i++){
		cout<<"= "<<b[i]<<endl;
	}
	cout<<"===================="<<endl;
	cout<<"Batas jumlah iterasi yaitu s/d: "; cin>>btsiterasi;
	cout<<"===================="<<endl;
	cout<<"Batas Toleransi = ";cin>>toleransi;
	cout<<"===================="<<endl;
	//inisialisasi nilai awal
	for(i=1;i<=ukuran;i++){
		x[i]=0;
	}
	iterasi=0;

	//ITERASI JACOBI
	while(toleransi>0.00001){
		iterasi++;
		cout<<"---------------------------------------\n";
		cout<<"Iterasi ke " <<iterasi<<" : "<<endl;
		if(iterasi>btsiterasi){
			cout<<"Berhenti karena batas iterasi s/d "<<btsiterasi<<" iterasi...!"<<endl;
			cout<<"===============================\n";
			cout<<"Jika ingin menggunakan metode iterasi jacobi kembali, tekan (y) : "; cin>>ulang;
			cout<<"==========================================\n";
			cout<<endl;
			while(ulang=='y' || ulang=='Y')
				goto awal;
			break;
		}

		//menghitung jumlah total sigma
		for(k=1;k<=ukuran;k++){
			sigma[k]=0;
			for(l=1;l<=ukuran;l++){
				if(k!=l){
					sigma[k]=sigma[k]+(a[k][l]*x[l]);
				}
			}
			f[k]=(b[k]-sigma[k])/a[k][k];
			cout<<"x["<<k<< "] = " <<f[k]<<endl;
		}

		toleransi=(f[1]-x[1])+(f[2]-x[2])+(f[3]-x[3]);
		if(toleransi<0){
			toleransi*=-1;
		}

		for(i=0;i<=ukuran;i++){
			x[i]=f[i];
		}
	}
}