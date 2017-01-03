#include <iostream>
#include <math.h>

using namespace std;

//1. deklarasi persamaan yang akan di cari akar persamaannya
double f(double x){
     return (cos(x)-x); 
	 }      
double fdiv(double x){
    return (-sin(x)-1);  
	}          
//----------------------------------------------------------------

int max_loop = 10;      	 /* max_loop, adalah deklarasi maksimum iterasi
							atau looping yang akan dilakukan saat penentuan akar persamaan yang dicari*/
double ralat = 1.0e-1;  	 /*ralat adalah deklarasi ralat atau ketelitian
							perhitungan akar persamaan yang dicari*/

//2. langkah newton raphson
double newton(double x)
{
    int i;
    double term;
   
    for (int i = 1; i <= max_loop; i++ )	/*syarat perhitungan maksimum iterasi harus sesuai dengan deklarasi maksimum
											iterasi (max_loop =10) maka iterasi akan berhenti pada looping kesepuluh*/
	{
        term = f(x)/fdiv(x);
        x = x - term;      
        if (fabs(term)<ralat)	/*deklarasi syarat hasil perhitungan bahwa nilai term harus kurang dari ralat
								maka perhitungan akan berhenti jika nilai term = ralat*/                     
        cout << "\niterasi akar = " << x << "\n";  
    }
       return x;
}
//----------------------------------------------------------------------------//
//pengaturan keluaran
int main()
{
    cout << "\n      Menentukan akar persamaan f(x) = cos x - x "<<endl;
    double x = 1.5;                       
    double root;
    cout << "\nnilai perkiraan akar persamaan: ";   
    cin >> x;      // masukkan nilai perkiraan akar persamaan 
    root = newton(x);                                  
    cout << "\n      akar persamaan f(x) = cos x - x adalah x = " << root<<endl;
    /*keluaran hasil perhitungan akar persamaan merupakan hasil perhitungan
    pada langkah newton raphson*/
                               
    for(;;);
    return 0;
}