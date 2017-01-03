#include <iostream>
#include <math.h>
#include <conio.h>
#include<stdio.h>
using namespace std;
//Iterasi Jacobi

int main(){
    int i, j;
    int n = 3;
    double A['n']['n']={{4.,-10.,7.},
                       {3., -8., 3.},
                       {3., 2., -7.}};
    double b['n']={30., -8., 15.};
    double xi['n']={0., 0., 0.};
    double itmax = 10;
    double iter = 0;
    double xf['n'], sum;
    
    cout<<"Program Persamaan Metode Jacobi\n";
    
    cout<<"Matriks A : \n";
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            cout<<A[i][j]<<"\t";
            }
    cout<< "Vektor b : \n";
    
    for (i=0; i<n; i++){
        cout<< b[i]<<"\t";
        }
        
    cout<<"Tebakan awal x(k=0): \n";
    for(i=0; i<n; i++){
             cout<<xi[i]<<" ";
             }
    cout<<endl;
    
    cout<<"Nilai barisan Solusi x(k) : \n"<<endl;
    do{
       for (i=0; i<n; i++){
           sum = 0.;
           for(j=0; j<n; j++){
                    if (j != i){
                          sum = sum - A[i][j]*xi[j];
                          }
                    }
                    xf[i] = (b[i] + sum)/A[i][i];
                    }
                    
       for (i=0; i<n; i++){
           xi[i] = xf[i]; //tukAR X(K) DENGAN X(K+1)
           cout<<(" ",xf[i])<<endl;
           }
           
       cout<<endl;
       iter++;
       }
    while(itmax>iter);
    getch();
    return 0;
}
}