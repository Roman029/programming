#include <iostream> 
#include <iomanip> 
#include <ctime>
using namespace std;

void func(int** arr, int n)
{
  int temp = 0;
  int* sum_row = new int[n];
  for (int i = 0; i < n; i++)
  {
    sum_row[i] = 0;
    for (int j = 0; j < n; j++)
    {
      arr[i][j] = rand() % 20;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "\t" << arr[i][j];
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sum_row[i] += arr[i][j];
    }    
  }

  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Cума " << i << " рядка = " << sum_row[i] << endl;
  }

  int min = sum_row[0], max = sum_row[0];
  int min_index = 0, max_index = 0;
  for (int i = 0; i < n; i++)
  {
    if (sum_row[i] < min)
    {
      min = sum_row[i];
      min_index = i;
    }
    if (sum_row[i] > max)
    {
      max = sum_row[i];
      max_index = i;
    }
  }

  for (int i = 0; i < n; i++)
  {
    temp = arr[min_index][i];
    arr[min_index][i] = arr[max_index][i];
    arr[max_index][i] = temp;
  }

  cout << endl;
  cout << "Змiнена матриця" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "\t" << arr[i][j];
    }
    cout << endl;
  }
  
}

int main()
{
  srand(time(NULL));
  setlocale(LC_ALL, "rus");
  int** arr, n;
  cout << "Введiть розмiр квадратної матрицi: ";
  cin >> n;
  cout << "_________________________________________________" << endl;
  arr = new int* [n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];

  }
  func(arr, n);


  for (int i = 0; i < n; i++)
  {
    delete[] arr[i];

  }
  delete[] arr;
  return 0;
}