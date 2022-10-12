#include <stdio.h>
#include <stdbool.h>

int t;
void swap(float *x, float *y); //allazei tis times metaxy dyo metavlhtwn
void ascend(float a[], int n); //katatassei tis times me auxousa seira
float median(float a[], int n); // vriskei th statistikh diameso

int main(void)
{
    int col, row;
    printf("Type the number of columns:\n");
    scanf("%d", &col);
    printf("Type the number of rows:\n");
    scanf("%d", &row);

    const int R=row;
    const int CL=col; // kanw tis metavlhtes const gia na mh mporoun na allaksoun mesa sto programma


    int k, g, h=65; //h=65 pou ston ASCII einai to A

    for (g=1; g<=CL; g++) // ektypwnw ta A,B,C,D,...(ws arithmhsh gia tis sthles tou pinaka)
        {printf("%8c   ", h);
        h++;}

    printf("\n");

    for (k=1; k<=R; k++)
        printf("\n\n%d\n\n", k); // ektypwnw ta 1,2,3,4,...(ws arithmhsh gia tis seires tou pinaka)

float array[R][CL];

for (int i=0; i<R*CL; i++)
{
   printf("Type number of row and letter of column of the cell you want to fill in:\n");
   int r1;
   char c1;
   float num;
start:
   scanf("%d%c", &r1, &c1);    //prepei oi syntetagmenes na einai ths morfhs 2B,4C klp.
   if (r1<=0 || r1>R || c1<'A' || c1>(64+CL)) // elegxos gia to an o user evale syntetagmenes yparxontos keliou
    {
        printf("Error. Select an existing cell:\n");
        goto start;
    }

   else
    {
       printf("Type the number:\n");
       scanf("%f", &num);
       array[r1-1][c1-65] = num;
       printf("array[%d][%d] = %f\n", r1-1, c1-65, num);   // symplhrwsh tou pinaka array
       printf("You have filled in the cell in row %d and column %c\n\n", r1, c1);
    }


}

printf("The final table is:\n\n");
h=65;
for (g=1; g<=CL; g++)  // ektypwnw ton symplhrwmeno pinaka
        {printf("   %10c   ", h);
        h++;}
printf("\n\n");

int j,m,o=1;
for (j=0; j<R; j++)
        {
            printf("%d", o);
            o++;
            for (m=0; m<CL; m++)

            {printf("      %f    ", array[j][m]);}
          printf("\n\n\n");
        }
int x, *ptr;
ptr=&x;
do
{printf("Available functions:\n1.Sum\n2.Average\n3.Max\n4.Min\n5.Median\n6.Multiplication\n\n");

int q;
int y,e;// y for a function and e for a column/row
begin:
 h=65;
for (g=1; g<=CL; g++) //ektypwnw ton symplhrwmeno pinaka
        {printf("   %10c   ", h);
        h++;}
printf("\n\n");

int j,m,o=1;
for (j=0; j<R; j++)
        {
            printf("%d", o);
            o++;
            for (m=0; m<CL; m++)

            {printf("      %f    ", array[j][m]);}
          printf("\n\n\n");
        }
printf("Available functions:\n1.Sum\n2.Average\n3.Max\n4.Min\n5.Median\n6.Multiplication\n\n");
printf("Choose a function:\n");
scanf("%d", &y);
if (y>6 || y<=0)  //elegxos gia to an o user epelekse yparxousa function
        {puts("Incorrect answer. Choose an existing function. Try again.\n");
        goto begin;}
printf("Apply it to a row or column? Type 1 for row and 2 for column:\n");
scanf("%d", &e);
int r2, c2; // ayta pou tha epileksei o user

float max=-999999;
float min=100000;
float sum=0;
float multi=1;
int n;
float v;
float table[R*CL];

if (e==1) // dhladh an o user epelekse ROW gia na efarmosei mia function
{
    printf("Select a row.\n");
    scanf("%d", &r2);

    switch (y)
    {
    case 1:
        sum=0;
        float sum1;
        for (t=0; t<CL; t++)
        {sum = sum+array[(r2-1)][t];} // -1 giati o pinakas ksekinaei apo to 0
        sum1=sum;
        printf("The sum of row %d is: %f\n", r2, sum1);
        break;
    case 2:
        sum=0;
        float sum2;
        for (t=0; t<CL; t++)
        {sum = sum+array[(r2-1)][t];}
        sum2=sum;
        printf("The average of row %d is: %f\n", r2, sum2/t);
        break;
    case 3:
        for (t=0; t<CL; t++)
        {
            if (array[(r2-1)][t]>max)
                max=array[(r2-1)][t];
        }
        printf("The max of row %d is: %f\n", r2, max);
        break;
    case 4:
        for (t=0; t<CL; t++)
        {
            if (array[(r2-1)][t]<min)
                min=array[(r2-1)][t];
        }
        printf("The min of row %d is: %f\n", r2, min);
        break;
    case 5:
        n=CL;
        for (t=0; t<CL; t++)
        {
            table[t]=array[(r2-1)][t];
        }
        ascend(table,CL); //klhsh ths synarthshs ascend
        v=median(table,CL);
        printf("Median of row %d is: %f\n",r2, v);
        break;
    case 6:
        multi=1;
        for (t=0; t<CL; t++)
            multi=multi*array[(r2-1)][t];
       printf("All numbers of row %d multiplied by each other equal to: %f\n", r2, multi);

    }


    printf("If you want to exit type 0, else type 1\n"); //elegxos gia to an o user thelei na termatisei to programma h' oxi
    scanf("%d", ptr);
    if (*ptr==0)
        goto end;
    else if (*ptr==1)
        goto begin;
}
else if(e==2); //dhladh o user epelekse column gia na efarmosei mia function
{
  printf("Select a column.\n"); //type 1 for column A, 2 for column B ktl
    scanf("%d", &c2); //c2 gia thn column pou epelekse


    switch (y)
    {
    case 1:
        sum=0;
        float sum1;
        for (t=0; t<R; t++)
        {sum = sum+array[(t)][(c2-1)];} // -1 giati o pinakas ksekinaei apo to 0
        sum1=sum;
        printf("The sum of column %d is: %f\n", c2, sum1);
        break;
    case 2:
        sum=0;
        float sum2;
        for (t=0; t<R; t++)
        {sum = sum+array[t][(c2-1)];}
        sum2=sum;
        printf("The average of column %d is: %f\n",c2, sum2/t);
        break;
    case 3:
        for (t=0; t<R; t++)
        {
            if (array[t][(c2-1)]>max)
                max=array[t][(c2-1)];
        }
        printf("The max of column %d is: %f\n", c2, max);
        break;
    case 4:
        for (t=0; t<R; t++)
        {
            if (array[t][(c2-1)]<min)
                min=array[t][(c2-1)];
        }
        printf("The min of column %d is: %f\n", c2, min);
        break;
    case 5:
        n=R;
        for (t=0; t<R; t++)
        {
            table[t]=array[t][(c2-1)];
        }
        ascend(table,R); // klhsh ths synarthshs ascend
        v=median(table,R);
        printf("Median of column %d is: %f\n",c2, v);
        break;
    case 6:
        multi=1;
        for (t=0; t<R; t++)
            multi=multi*array[t][(c2-1)];
       printf("All numbers of column %d multiplied by each other equal to: %f\n", c2, multi);

    }


}
printf("If you want to exit type 0, else type 1\n");
    scanf("%d", ptr);
    if (*ptr==0)
        goto end;
    else if (*ptr==1)
        goto begin;

}
while (*ptr!=0); // oso *ptr dhladh to x einai diaforo tou 0, h epanalhpsh synexizetai kai o user mporei na kanei kai alles praxeis gia perissoteres seires kai sthles. an x=0 tote termatizetai to programme










end:
return 0;
}



void swap(float *x,float *y) // antallassei tis times metaxy dyo metavlhtwn. pairnei ws eisodo tis diey8ynseis twn dyo metavlhtvn float (h' alliws pairnei ws eisodo 2 pointers se aritmous float) kai den epistrefei kapoia timh
{
   float w;

   w=*x;
   *x=*y;
   *y=w;
}

void ascend(float a[],int n) // katatassei aritmous se ayxousa seira. pairnei ws eisodo enan pinaka stoixeiwn float kai enan ari8mo int(deixnei to plhthos tvn ari8mwn/mhkos tou pinaka). den epistrefei kapoia timh
{
   int x,y;
   for (x=0; x<n; ++x)
        {
            for (y=x+1; y<n; ++y)
            {
                if (a[x]>=a[y])
                {
                    swap(&a[x],&a[y]); //klhsh ths synarthshs swap, wste na allaksoun timh ta stoixeia tou pinaka metaxy tous
                }

            }

        }

}


float median(float a[] , int n) // ypologizei th diameso enos synolou ari8mwn katatetagmenwn se ayxousa seira. pairnei ws eisodo enan pinaka stoixeiwn float pou periexei tous ari8mous kai enan ari8mo int(deixnei to plhthos twn ari8mwn/mhkos tou pinaka). epistrefei enan ari8mo float(thn timh ths diamesou)
{
    float median=0;
    if(n%2 == 0) // an to plh8os twn stoixeiwn ths row/column einai artio
        median = (a[(n/2)-1] + a[n/2])/2.0;
    else if (n%2!=0) // an to plh8os twn stoixeiwn ths row/column einai peritto
        median = a[(n-1)/2]; //-1 gt o pinakas ksekinaei apo to 0
return median;
}


