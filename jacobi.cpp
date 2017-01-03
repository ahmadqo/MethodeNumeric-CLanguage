#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
/* n = nmber of interior points (equations) */
#define n 250
 
FILE *foutput;
/* define variables and constants */
double tol=0.000001;
double a[n][n],b[n],h,
x[n],xnew[n],d[n],e[n],f[n],g[n],L2;

int k,i,j;

main()
{
/* h = spacing between points */
h=1.0/(double)(n+1);
/* initialize the A matrix */

for(i=1;i<=n+1;i++)
for(j=1;j<=n+1;j++)
a[i][j]=0.0;
/* The matrix generating routine.
029
d[], e[], and f[] are vectors of non-zero diags for tri-diag matrices */
a[1][1]=-(2.0+4.0*h*h); e[1]=a[1][1];
a[1][2]=1.0; f[1]=a[1][2];


/* generate the main body */

for(i=2;i<=n-1;i++)

{

a[i][i-1]=1.0; d[i]=a[i][i-1];

a[i][i]=-(2.0+4.0*h*h); e[i]=a[i][i];

a[i][i+1]=1.0; f[i]=a[i][i+1];

}

a[n][n-1]=1.0; d[n]=a[n][n-1];

a[n][n]=-(2.0+4.0*h*h); e[n]=a[n][n];

/* now generate the right hand side of vector of values */

for(i=1;i<=n-1;i++)

b[i]=h*h;

b[n]=h*h-1.0;

/* Initial guess of vector x is zero */

for(i=1;i<=n;i++)

x[i]=0.0;

/* performing the iteration */

/* Initialize count of number of iterations k */

k=0;

/* main body of iteration */

do

{

/* count up k */

k+=1;

/* by using Jacobi Iteration*/

xnew[1]=(b[1]-f[1]*x[2])/e[1];

for(i=2;i<=n-1;i++)

xnew[i]=(b[i]-d[i]*x[i-1]-f[i]*x[i+1])/e[i];

xnew[n]=(b[n]-d[n]*x[n-1])/e[n];

/* convergence test */

    L2=0.0;

    for(i=1;i<n;i++)

         {

/* applying the L2 exit criterion */

         g[i] = (fabs(fabs(xnew[i])-fabs(x[i])))*(fabs(fabs(xnew[i])-fabs(x[i])));

         L2 = L2+g[i];

         }

      L2=sqrt(L2);

 printf("iter %d  %.6lf\n",k,L2);

/* put xnew as x */

for(i=1;i<=n;i++)

x[i]=xnew[i];

}

while(L2>tol);

/* for print output */

foutput=fopen("prob1jacobioutput.txt","w");

printf ("Number of Iteration = %d\n",k);

fprintf(foutput,"Number of Iteration = %d\n",k);

for (i=190;i<=200;i++)

    {

    printf("x[%d]=%.6lf\n",i,x[i]);

    fprintf(foutput,"x[%d]=%.6lf\n",i,x[i]);

    }

fclose(foutput);

system("PAUSE");

return 0;

}
