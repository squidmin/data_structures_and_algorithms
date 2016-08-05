#include <iostream>
#include <cstdlib>
#include "llcpInt.h"
using namespace std;

// PROTOTYPES for functions used by this test program:

void ShowMenu();
// Pre:  (none)
// Post: A menu of choices for this program is written to cout.

char GetChoice(int argc);
// Pre:  (none)
// Post: The user is prompted to enter a one character command.
//       The next character is read (skipping blanks and newline
//       characters), and this character is returned.

int GetListNum(int argc);
// Pre:  (none)
// Post: The user is prompted to enter either 1 or 2. The
//       prompt is repeated until a valid integer can be read
//       and the integer's value is either 1 or 2. The valid
//       integer read is returned. The input buffer is cleared
//       of any extra input until and including the first
//       newline character.

int GetInteger(int argc);
// Pre:  (none)
// Post: The user is prompted to enter an integer. The prompt
//       is repeated until a valid integer can be read. The
//       valid integer read is returned. The input buffer is
//       cleared of any extra input until and including the
//       first newline character.

void DrawCaseSeparator();
// Pre:  (none)
// Post: "==================================================\n"
//       is inserted into the standard output stream.

int main(int argc, char *argv[])
{
   char choice;
   int listNum,
       givenValue;
   Node *head1 = 0, *head2 = 0;

   cout << "2 empty list of integers have been created..." << endl
        << "you can do some predefined processing with them..."
        << endl;

   do
   {
      if (argc < 2)
         ShowMenu();
      choice = GetChoice(argc);
      switch (choice)
      {
      case '1':
         // add code to incorporate practice function 1
         break;
      case '2':
         // add code to incorporate practice function 2
         break;

      // add more cases to incorporate still more functions

      case '^':
         listNum = GetListNum(argc);
         givenValue = GetInteger(argc);
         if (listNum == 1)
            InsertAsHead(head1, givenValue);
         else
            InsertAsHead(head2, givenValue);
         break;
      case '+':
         listNum = GetListNum(argc);
         givenValue = GetInteger(argc);
         if (listNum == 1)
            InsertAsTail(head1, givenValue);
         else
            InsertAsTail(head2, givenValue);
         break;
      case '!':
         listNum = GetListNum(argc);
         givenValue = GetInteger(argc);
         if (listNum == 1)
         {
            if ( ! IsSortedUp(head1) )
               cout << "List 1 is not non-decreasingly sorted "
                    << "- can't do requested insertion" << endl;
            else
               InsertSortedUp(head1, givenValue);
         }
         else
         {
            if ( ! IsSortedUp(head2) )
               cout << "List 2 is not non-decreasingly sorted "
                    << "- can't do requested insertion" << endl;
            else
               InsertSortedUp(head2, givenValue);
         }
         break;
      case '-':
         listNum = GetListNum(argc);
         givenValue = GetInteger(argc);
         if (listNum == 1)
            DelFirstTargetNode(head1, givenValue);
         else
            DelFirstTargetNode(head2, givenValue);
         break;
      case '<':
         listNum = GetListNum(argc);
         givenValue = GetInteger(argc);
         if (listNum == 1)
            DelNodeBefore1stMatch(head1, givenValue);
         else
            DelNodeBefore1stMatch(head2, givenValue);
         break;
      case '>':
         listNum = GetListNum(argc);
         givenValue = GetInteger(argc);
         if (listNum == 1)
            DelNodeAfter1stMatch(head1, givenValue);
         else
            DelNodeAfter1stMatch(head2, givenValue);
         break;
      case 'a': case 'A':
         listNum = GetListNum(argc);
         if (listNum == 1)
         {
            if (head1 == 0)
               cout << "List 1 is empty - no relevant "
                    << "average value" << endl;
            else
            {
               cout.setf(ios::showpoint | ios::fixed);
               cout.precision(2);
               cout << "Average of the values currently "
                    << "in list 1 is: "
                    << FindAverage(head1) << endl;
            }
         }
         else
         {
            if (head2 == 0)
               cout << "List 2 is empty - no relevant "
                    << "average value" << endl;
            else
            {
               cout.setf(ios::showpoint | ios::fixed);
               cout.precision(2);
               cout << "Average of the values currently "
                    << "in list 2 is: "
                    << FindAverage(head2) << endl;
            }
         }
         break;
      case 'e': case 'E':
         listNum = GetListNum(argc);
         if (listNum == 1)
         {
            if (head1 == 0)
               cout << "List 1 is already empty" << endl;
            else
            {
               cout << "Emptying list 1 of all exiting values"
                    << endl;
               ListClear(head1);
               cout << "List 1 is now empty" << endl;
            }
         }
         else
         {
            if (head2 == 0)
               cout << "List 2 is already empty" << endl;
            else
            {
               cout << "Emptying list 2 of all exiting values"
                    << endl;
               ListClear(head2);
               cout << "List 2 is now empty" << endl;
            }
         }
         break;
      case 'l': case 'L':
         listNum = GetListNum(argc);
         if (listNum == 1)
         {
            if (head1 == 0)
               cout << "List 1 is empty" << endl;
            else
            {
               cout << "List 1 contains "
                    << FindListLength(head1)
                    << " values" << endl;
            }
         }
         else
         {
            if (head2 == 0)
               cout << "List 2 is empty" << endl;
            else
            {
               cout << "List 2 contains "
                    << FindListLength(head2)
                    << " values" << endl;
            }
         }
         break;
      case 'M':
         listNum = GetListNum(argc);
         if (listNum == 1)
         {
            if (head1 == 0)
               cout << "List 1 is empty - no relevant "
                    << "minimum/maximum values" << endl;
            else
            {
               int minValue, maxValue;
               FindMinMax(head1, minValue, maxValue);
               cout << "Minimum value currently in list 1 is: "
                    << minValue << endl;
               cout << "Maxmum value currently in list 1 is: "
                    << maxValue << endl;
            }
         }
         else
         {
            if (head2 == 0)
               cout << "List 2 is empty - no relevant "
                    << "minimum/maximum values" << endl;
            else
            {
               int minValue, maxValue;
               FindMinMax(head2, minValue, maxValue);
               cout << "Minimum value currently in list 2 is: "
                    << minValue << endl;
               cout << "Maxmum value currently in list 2 is: "
                    << maxValue << endl;
            }
         }
         break;
      case 'R': // for use with recursion in the future
         listNum = GetListNum(argc);
         if (listNum == 1)
            ; // replace null statement your code
         else
            ; // replace null statement your code
         break;
      case 'r':
         listNum = GetListNum(argc);
         if (listNum == 1)
            ; // replace null statement your code
         else
            ; // replace null statement your code
         break;
      case 's': case 'S':
         listNum = GetListNum(argc);
         if (listNum == 1)
         {
            if (head1 == 0)
               cout << "List 1 is empty" << endl;
            else
            {
               cout << "List 1 contains: "
                    << endl;
               ShowAll(cout, head1);
            }
         }
         else
         {
            if (head2 == 0)
               cout << "List 2 is empty" << endl;
            else
            {
               cout << "List 2 contains: "
                    << endl;
               ShowAll(cout, head2);
            }
         }
         break;
      case 'q': case 'Q':
         if (head1 != 0)
            ListClear(head1);
         if (head2 != 0)
            ListClear(head2);
         break;
      case '=':
         DrawCaseSeparator();
         break;
      default:
         cout << choice << " is not a valid choice...try again."
              << endl;
      }
   } while (choice != 'q' && choice != 'Q');

   cout << "Press Enter or Return when ready..." << endl;
   cin.get();
   return EXIT_SUCCESS;
}

void ShowMenu()
{
   cout << endl;
   cout << "Following choices are available: " << endl;
   cout << "  1  Practice function 1" << endl;
   cout << "  2  Practice function 2" << endl;

   // add entries for more practice functions

   cout << "  ^  Add new value (as FIRST value) to unsorted list" << endl;
   cout << "  +  Add new value (as LAST value) to unsorted list" << endl;
   cout << "  !  Add new value to non-decreasingly sorted list" << endl;
   cout << "  -  Delete 1st node matching given value" << endl;
   cout << "  <  Delete node before 1st node matching given value" << endl;
   cout << "  >  Delete node after 1st node matching given value" << endl;
   cout << "  A  Find average of values in list" << endl;
   cout << "  E  Empty (clear all values in) list" << endl;
   cout << "  L  Find list length (# of nodes in list)" << endl;
   cout << "  M  Find minimum/maximum values in list" << endl;
   cout << "  R  Reverses list recursively" << endl;
   cout << "  r  Reverses list iteratively" << endl;
   cout << "  S  Show list content" << endl;
   cout << "  Q  Quit" << endl;
   cout << "  =  Insert "
        << "\"==================================================\" to cout"
        << endl;
}

char GetChoice(int argc)
{
   char choice;

   cout << "Enter choice: ";
   cin >> choice;
   if (argc < 2)
      cin.ignore(999, '\n');

   cout << "You entered ";
   cout << choice << endl;
   return choice;
}

int GetListNum(int argc)
{
   int result;

   cout << "Enter list # (1 or 2) ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid integer input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter list # (1 or 2) ";
      cin  >> result;
   }
   if (argc < 2)
      cin.ignore(999, '\n');

   while (result != 1 && result != 2)
   {
      cerr << "Invalid list # (must be 1 or 2)..." << endl;
      cout << "Re-enter list # (1 or 2) ";
      cin  >> result;
      while ( ! cin.good() )
      {
         cerr << "Invalid integer input..." << endl;
         cin.clear();
         cin.ignore(999, '\n');
         cout << "Re-enter list # (1 or 2) ";
         cin  >> result;
      }
      cin.ignore(999, '\n');
   }

   cout << "You entered ";
   cout << result << endl;
   return result;
}

int GetInteger(int argc)
{
   int value;

   cout << "Enter integer value: ";
   cin >> value;
   while ( ! cin.good() )
   {
      cerr << "Invalid input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter integer value: ";
      cin  >> value;
   }
   if (argc < 2)
      cin.ignore(999, '\n');

   cout << "You entered ";
   cout << value << endl;
   return value;
}

void DrawCaseSeparator()
{
   cout << "==================================================\n";
}

