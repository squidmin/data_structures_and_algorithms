#include <iostream>

struct node
{
   int data;
   node* link;
};

void PrintRevRecur(const int [], int);
void PrintRevRecur(node*);
int CalcSumRecur(int);
void FlipArrayRecur(int [], int);
void RevListRecur(node*&);
int FindMinRecur(const int [], int);
void FindMinRecurAux(const int [], int, int&);
int FindMinIndexRecur(const int [], int);
int CountNonNegRecur(const int [], int);
int BinSearch(const int [], int, int);
int BinSearchAux(const int [], int, int, int);

int main()
{
   int arr[3] = { -1, 0, 1 };
   PrintRevRecur(arr, 3);
   
   node* headPtr = 0;
   headPtr->

	return 0;
}

node* recursive_ordered_insert(node *node, int value)
{
   if ( !node || node->value >= value )
   { 
      node* new_node = new node;
      node->data = value;
      node->link = node;
      return node;
   }
   node->next = recursive_ordered_insert( node->next, value );
   return node;
}

/*
void PrintRevRecur(const int a[], int n)
{
   if (!n) return;
   else
   {
   	PrintRevRecur(a + 1, n - 1);
   	std::cout << a[0] << " ";
   }
   std::cout << std::endl;
}
*/

void PrintRevRecur(node* headPtr)
{
   if (!headPtr) return;
   else
   {
   	PrintRevRecur(headPtr->link);
   	std::cout << headPtr->data << " ";
   }
   std::cout << std::endl;
}

// "Uses invocation construct" (i.e. branching/function calling)
int CalcSumRecur(int n)
{
   if (!n) return 0;
   else if (n == 1) return 1;
   else return n + CalcSumRecur(n - 1);
}

void FlipArrayRecur(int a[], int n)
{
	if (n <= 1) return;
	else
	{
		FlipArrayRecur(a + 1, n - 2);
		int temp = a[0];
		a[0] = a[n - 1];
		a[n - 1] = temp;
	}
}

void RevListRecur(node*& headPtr)
{
	if (!headPtr || !headPtr->link) return;
	node* precursor = headPtr, * cursor = headPtr->link;
	while (cursor->link)
	{
		precursor = cursor;
		cursor = cursor->link;
	}
	precursor->link = 0;
	RevListRecur(headPtr);
	cursor->link = headPtr;
	headPtr = cursor;
}

/*
void RevListRecur(node*& headPtr) 
{ 
   if (!headPtr || !headPtr->link) return; 
   node *headListMinusHeadNode = headPtr->link; 
   RevListRecur(headListMinusHeadNode); 
   node *cursor = headListMinusHeadNode; 
   while (cursor->link != 0) 
      cursor = cursor->link; 
   cursor->link = headPtr; 
   headPtr->link = 0; 
   headPtr = headListMinusHeadNode; 
}
*/

/*
void RevListRecur(node*& headPtr) 
{ 
   if (!headPtr || !headPtr->link) return; 
   node *headListMinusHeadNode = headPtr->link; 
   node *tailListMinusHeadNodeReversed = headListMinusHeadNode; 
   RevListRecur(headListMinusHeadNode); 
   headPtr->link = 0; 
   tailListMinusHeadNodeReversed->link = headPtr; 
   headPtr = headListMinusHeadNode;
}
*/

int FindMinRecur(const int a[], int n)
// n >= 1 assumed
{
   if (n == 1) return a[0];
   int minArrayMinusFirst = FindMinRecur(a + 1, n - 1);
   if (a[0] < minArrayMinusFirst) return a[0];
   else return minArrayMinusFirst;
}

/*
int FindMinRecur(const int a[], int n)
// n >= 1 assumed
{
   if (n == 1) return a[0];
   int minArrayMinusLast = FindMinRecur(a, n - 1);
   if (a[n - 1] < minArrayMinusLast) return a[n - 1];
   else return minArrayMinusLast;
}
*/

/*
int FindMinRecur(const int a[], int n)
// n >= 1 assumed
{
   if (n == 1) return a[0];
   int minLowerHalf = FindMinRecur(a, n / 2);
   int minUpperHalf = FindMinRecur(a + n / 2, n - n / 2);
   if (minLowerHalf < minUpperHalf) return minLowerHalf;
   else return minUpperHalf;
}
*/

/*
int FindMinRecur(const int a[], int n)
// n >= 1 assumed
{
   int min = a[0];
   FindMinRecurAux(a + 1, n - 1, min);
   return min;
}
void FindMinRecurAux(const int a[], int n, int& min)
{
   if (n == 0) return;
   if (a[0] < min) min = a[0];
   FindMinRecurAux(a + 1, n - 1, min);
}
*/

/*
int FindMinRecur(const int a[], int n)
{
   static int min = a[0];
   if (n == 0) return min;
   if (a[0] < min) min = a[0];
   FindMinRecur(a+1, n-1);
   return min; 
}
*/

int FindMinIndexRecur(const int a[], int n)
// n >= 1 assumed
// in case of tie, returns lowest index of tied bunch
{
   if (n == 1) return 0;
   int minIndexTheRest = FindMinIndexRecur(a + 1, n - 1);
   if (a[0] <= a[minIndexTheRest + 1]) return 0;
   else return 1 + minIndexTheRest;
}

/*
int FindMinIndexRecur(const int a[], int n)
// n >= 1 assumed
// in case of tie, returns lowest index of tied bunch
{
   if (n == 1) return 0;
   int minIndexTheRest = FindMinIndexRecur(a, n - 1);
   if (a[n - 1] < a[minIndexTheRest]) return n - 1;
   else return minIndexTheRest;
}
*/

int CountNonNegRecur(const int a[], int n)
// n >= 1 assumed
{
   if (n == 1)
   {
      if (a[0] >= 0) return 1;
      else return 0;
   }
   else
   {
      if (a[0] >= 0) return 1 + CountNonNegRecur(a + 1, n - 1);
      else return CountNonNegRecur(a + 1, n - 1);
   }
}

int BinSearch(const int a[], int n, int key) 
// returns index of matched item or -1 if no match 
{ 
   if (n < 1) return -1; 
   return BinSearchAux(a, 0, n - 1, key); 
}
int BinSearchAux(const int a[], int lo, int hi, int key)
// n >= 1 
{ 
   if (lo > hi) return -1;
   int mid = (lo + hi) / 2;
   if ( key == a[mid] ) return mid;
   else if ( key > a[mid] ) return BinSearchAux(a, mid + 1, hi, key);
   else return BinSearchAux(a, lo, mid - 1, key);
}

/*
int BinSearch(const int a[], int n, int key) 
// returns index of matched item or -1 if no match 
{ 
   if (n < 1) return -1; 
   return BinSearchAux(a, 0, n - 1, key); 
}
int BinSearchAux(const int a[], int lo, int hi, int key) 
// n >= 1 
{ 
   int foundIndex = -1, mid; 
   while (foundIndex == -1 && lo <= hi) 
   { 
      mid = (lo + hi) / 2; 
      if ( key == a[mid] ) foundIndex = mid; 
      else if ( key > a[mid] ) lo = mid + 1; 
      else hi = mid - 1; 
   } 
   return foundIndex 
}
*/

/*
int BinSearch(const int a[], int n, int key) 
// returns index of matched item or -1 if no match 
{ 
   if (n < 1) return -1;
   int foundIndex = -1, lo = 0, hi = n - 1, mid; 
   while (foundIndex == -1 && lo <= hi) 
   { 
      mid = (lo + hi) / 2; 
      if ( key == a[mid] ) foundIndex = mid; 
      else if ( key > a[mid] ) lo = mid + 1; 
      else hi = mid - 1; 
   } 
   return foundIndex 
}
*/
