#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
using namespace std;
int a;
int b;
int k = 0;
void Create(int* mas, int size)
{
	for (int i = 0; i < size; i++)
		mas[i] = -100 + rand() % (-200 + 1);
}


void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(2) << a[i] << " ";
}
int Max(int* mas, const int size)
{
	int max = mas[0];
	for (int i = 0; i < size; i++)
		if (max < mas[i])
			max = mas[i];
	return max;
}
int Sum(int* mas, const int size)
{
	int S = 0;
	int k = 0;
	for (int j = size; j < 0 || mas[j] > 0; j--)
	{
		k++;
	}
	k++;
	for (int i = 0; i < size - k; i++)
	{
		S += mas[i];
	}
	return S;
}
void Shrink(int* mas, int size)
{

	for (int i = 0; i < size; i++)
		if (abs(mas[i]) >= a && abs(mas[i]) <= b)
		{
			mas[i] = 0;
			if (abs(mas[size - k - 1]) >= a && abs(mas[size - k - 1]) <= b)
			{
				mas[size - k - 1] = 0;
				swap(mas[i], mas[size - k - 2]);
				k += 2;
			}
			else
			{
				swap(mas[i], mas[size - k - 1]);
				k++;
			}
		}

}
int main()
{
	srand((unsigned)time(NULL));
	int n;
	cout << "n = "; cin >> n;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	int* mas;
	mas = new int[n];
	Create(mas, n);
	cout << "a[";
	Print(mas, n);
	cout << "]" << endl;
	cout << "Max Element = " << Max(mas, n) << endl;
	cout << "Sum = " << Sum(mas, n) << endl;
	Shrink(mas, n);
	n -= k ;
	cout << "a[";
	Print(mas, n);
	cout << "]" << endl;
	return 0;
}