#include<stdio.h>
main()
 {int a, b, m, o, p, i, d, j, sum, c;
    int arra[16], arrb[16], arrand[16], arror[16], arrxor[16], arrandresult[16], arrorresult[16], arrxorresult[16];
    int n=5, k=4;
    m=0;
      o=0;
      p=0;
  for(a=1;a<n;a++)
  {
      for(b=1;b<n;b++)
      {
          for(i=0;a!=0;i++)
          {
              d=a%2;
              a=a/2;
              arra[15-i]=d;
              if(a==0)
              {
                 for(j=0;j<15-i;j++)
                 {
                     arra[j]=0;
                 }
              }
          }
           for(i=0;b!=0;i++)
          {
              d=b%2;
              b=b/2;
              arrb[15-i]=d;
              if(b==0)
              {
                 for(j=0;j<15-i;j++)
                 {
                     arrb[j]=0;
                 }
              }
          }
          for(i=0;i<16;i++)
          {
              arrand[i]=arra[i]&arrb[i];
              arror[i]=arra[i]|arrb[i];
              arrxor[i]=arra[i]^arrb[i];
          }
         sum=0;
          for(i=15;i>=0;i--)
          {
              sum=sum+arrand[i]*pow(2,(15-i));
          }
          arrandresult[m]=sum;
          sum=0;
          for(i=15;i>=0;i--)
          {
              sum=sum+arror[i]*pow(2,(15-i));
          }
          arrorresult[o]=sum;
          sum=0;
          for(i=15;i>=0;i--)
          {
              sum=sum+arrxor[i]*pow(2,(15-i));
          }
          arrxorresult[p]=sum;
          o++;
          m++;
          p++;

      }
  }
  printf("%d", m);


  }
