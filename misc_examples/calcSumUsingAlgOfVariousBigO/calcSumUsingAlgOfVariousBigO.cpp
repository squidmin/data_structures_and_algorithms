#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned long calcSumO1(unsigned long n);
unsigned long calcSumOln(unsigned long n);
unsigned long calcSumOn(unsigned long n);
unsigned long calcSumOnln(unsigned long n);
unsigned long calcSumOn2(unsigned long n);

int main()
{
   time_t start, stop;
   int n;
   cout << "Enter n (>= 1): ";
   cin >> n;

   time(&start);
   cout << "SumO1  : " << calcSumO1(n) << endl;
   time(&stop);
   cout << "Elapsed time: " << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(2) << difftime(stop, start)*1000000000 << endl;

   time(&start);
   cout << "SumOln : " << calcSumOln(n) << endl;
   time(&stop);
   cout << "Elapsed time: " << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(2) << difftime(stop, start)*1000000000 << endl;

   time(&start);
   cout << "SumOn  : " << calcSumOn(n) << endl;
   time(&stop);
   cout << "Elapsed time: " << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(2) << difftime(stop, start)*1000000000 << endl;

   time(&start);
   cout << "SumOnln: " << calcSumOnln(n) << endl;
   time(&stop);
   cout << "Elapsed time: " << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(2) << difftime(stop, start)*1000000000 << endl;

   time(&start);
   cout << "SumOn2 : " << calcSumOn2(n) << endl;
   time(&stop);
   cout << "Elapsed time: " << setiosflags(ios::fixed | ios::showpoint)
        << setprecision(2) << difftime(stop, start)*1000000000 << endl;

   return EXIT_SUCCESS;
}

unsigned long calcSumO1(unsigned long n) // n >= 1
{
   return n * (n + 1) / 2;
}

unsigned long calcSumOln(unsigned long n) // n >= 1
{
   unsigned long i, sum = 0;
   for (i = 1; 2*i < n; i *= 2)
          sum += (3*i - 1)*i / 2;
   sum += (i + n) * (n - i + 1) / 2;

   return sum;
}

unsigned long calcSumOn(unsigned long n) // n >= 1
{
   unsigned long sum = 0;
   for (unsigned long i = 1; i <= n; ++i)
      sum += i;
   return sum;
}

unsigned long calcSumOnln(unsigned long n) // n >= 1
{
   unsigned long sum = 0, i, numIter;
   for (i = 1, numIter = 0; 2*i < n; i *= 2, ++numIter)
      for (unsigned long j = 1; j <= n; ++j)
         sum += j;
   sum /= numIter;

   return sum;
}

unsigned long calcSumOn2(unsigned long n) // n >= 1
{
   unsigned long sum = 0;
   for (unsigned long i = 1; i <= n; ++i)
      for (unsigned long j = 1; j <= i; ++j)
         ++sum;
   return sum;
}
