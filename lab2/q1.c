#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int opcount1, opcount2, opcount3;
int euclidGCD(int n, int m)
{
  unsigned int r;
  int opcount = 0;
  while (n != 0)
  {
    opcount++;
    r = m % n;
    m = n;
    n = r;
  }
  printf("Operation count of Euclid's GCD method = % d\n", opcount);
  return m;
}

int consecutiveInt(int n, int m)
{
  int t = m > n ? n : m;
  int opcount = 0;
  while (t > 0)
  {
    if (m % t == 0)
      if (n % t == 0)
      {
        printf("Operation count of Consecutive Integer method = %d\n", opcount);
        return t;
      }
    t--;
    opcount++;
  }
}

int *Sieve(int n)
{
  int p, j, *A, *L;
  opcount1 = 0;
  A = (int *)malloc(sizeof(int) * (n+1));
  L = (int *)malloc(sizeof(int) * 200);
  for(int i=0; i<200; i++)L[i]=0;
  for (p = 2; p <= n; p++)
  {
    A[p] = p;
  }
  for (int p = 2; p < sqrt(n); p++)
  {
    opcount1++;
    if (A[p] != 0)
    {
      j = p * p;
      while (j <= n)
      {
        A[j] = 0;
        j += p;
      }
    }
  }
  int i = 0;
  for (p = 2; p <= n; p++)
  {
    if (A[p] != 0)
    {
      L[i] = A[p];
      i++;
    }
  }
  return L;
}

int *Divide(int m, int *Prime)
{
  int *PrimeFactor, i;
  PrimeFactor = (int *)malloc(sizeof(int) * 200);
  for(int i=0; i<200; i++)PrimeFactor[i]=0;
  opcount2 = 0;
  i = 0;
  int j = 0;
  while (m > 0 && j <= 9 && Prime[j]!=0)
  {
    opcount2++;
    while (m % Prime[j] == 0 && Prime[j]!=0)
    {
      PrimeFactor[i] = Prime[j];
      i++;
      m /= Prime[j];
    }
    j++;
  }
  return PrimeFactor;
}

int middleSchool(int m, int n)
{
  int *PrimesM, *PrimesN, *PrimeFactorsM, *PrimeFactorsN, *CommonFactors;
  PrimesM = (int *)malloc(sizeof(int) * 200);
  PrimesN = (int *)malloc(sizeof(int) * 200);
  PrimeFactorsM = (int *)malloc(sizeof(int) * 200);
  PrimeFactorsN = (int *)malloc(sizeof(int) * 200);
  CommonFactors = (int *)malloc(sizeof(int) * 200);
  for(int i=0; i<200; i++)CommonFactors[i]=0;
  PrimesM = Sieve(m);
  for (int i = 0; i < 200 && PrimesM[i]!=0; i++)
    printf("Prime Number = %d\n", PrimesM[i]);
  PrimeFactorsM = Divide(m, PrimesM);
  for (int i = 0; i < 200 && PrimeFactorsM[i]!=0; i++)
    printf("Prime Factor of M = %d\n", PrimeFactorsM[i]);
  PrimeFactorsN = Divide(n, PrimesM);
  for (int i = 0; i < 200 && PrimeFactorsN[i]!=0; i++)
    printf("Prime Factor of N = %d\n", PrimeFactorsN[i]);
  int k = 0;
  opcount3 = 0;
  for (int i = 0, j = 0; (i < 200 && PrimeFactorsM[i]==0) || (j < 200 && PrimeFactorsN[j]==0);)
  {
    opcount3++;
    if (PrimeFactorsM[i] > PrimeFactorsN[j])
      j++;
    else if (PrimeFactorsM[i] < PrimeFactorsN[j])
      i++;
    else if (PrimeFactorsM[i] == PrimeFactorsN[j])
    {
      CommonFactors[k] = PrimeFactorsM[i];
      k++;
      i++;
      j++;
    }
  }
  for (int i = 0; i < 200 && CommonFactors[i]!=0; i++)
  {
    printf("Common Factor = %d\n", CommonFactors[i]);
  }
  int gcd = 1;
  for (int i = 0; i<k; i++)
  {
    gcd *= CommonFactors[i];
  }
  if((PrimeFactorsN[0]==0 || PrimeFactorsM[0]==0))
  {
    opcount1>opcount2?printf("OPCOUNT1 = %d\n",opcount1):printf("OPCOUNT2 = %d\n", opcount2);
    return gcd;
  }
  if (opcount3 > opcount2 && opcount3 > opcount1)
    printf("OPCOUNT3 = %d\n", opcount3);
  else if (opcount2 > opcount3 && opcount2 > opcount1)
    printf("OPCOUNT2 = %d\n", opcount2);
  else
    printf("OPCOUNT1 = %d\n", opcount1);
  return gcd;
}

int main()
{
  int m, n;
  printf("Enter the numbers whose GCD needs to be calculated : \n");
  printf("Number 1 : ");
  scanf("%d", &n);
  printf("Number 2 : ");
  scanf("%d", &m);
  printf("GCD using Euclid's GCD method = %d\n", euclidGCD(n, m));
  printf("GCD using Consecutive Integer method = %d\n", consecutiveInt(n, m));
  printf("GCD using Middle School method = %d\n", middleSchool(n, m));
}