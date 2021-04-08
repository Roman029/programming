
//TECT
// #include <iostream>
//  using namespace std;
// int main()
// {
//     int m, n;
//     std::cin >> m >> n;
 
//     int **mtrx = new int*[m];
//     for(int i=0; i<m; i++)
//     {
//         mtrx[i] = new int [n];
//         for(int j=0; j<n; j++)
//         {
//             mtrx[i][j] = rand()%2;
//             std::cout << mtrx[i][j];
//         }
//         std::cout << "\n";
//     }
    
//      for(int i =0;i<m;i++)
//     {
//         cout<<mtrx[i][i];
//     }
 
//     for(int i=0; i<m; i++)
//         delete [] mtrx[i];
//     delete [] mtrx;
    

// system("pause");
// return 0;
// }

#include <iostream> 
#include <iomanip> 
#include <ctime>
using namespace std;

void transpose(int** mat, int** tr, int N)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      tr[i][j] = mat[j][i];
    }
  }
}


bool isSymmetric(int** mat, int N)
{
  int** tr;
  tr = new int* [N];
  for (int i = 0; i < N; i++)
  {
    tr[i] = new int[N];
  }
  transpose(mat, tr, N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (mat[i][j] != tr[i][j])
      {
        return false;
      }
    }
  }
  return true;
}

void Input_Matrix(int** arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      arr[i][j] = rand() % 20;
    }
  }
}

void Print_Matrix(int** arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "\t" << arr[i][j];
    }
    cout << endl;
  }
}

bool isSingle(int** arr, int n)
{
  int counter_1 = 0,  counter_0 = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j && arr[i][j] == 1)
      {
        counter_1++;
      }
      else if(arr[i][j] == 0)
      {
        counter_0++;
      }
    }
    cout << endl;
  }

  if ((n * n - n) == counter_0 && n == counter_1)
  {
    return true;
  }
  return false;
}

bool isTriangular(int** arr, int n)
{
  int k = 0, s = 0, o = 0;
  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (arr[i][j] == 0)
      {
        s++;
      }
      if (arr[n - i - 1][n - j - 1] == 0) 
      {
        o++;
      }
      k++;
    }
  }
  if ((s == k) || (o == k))
  {
    return true;
  }
  return false;
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
  
  Input_Matrix(arr, n);
  Print_Matrix(arr, n);
  
  if (isSingle(arr, n))
  {
    cout << "Матриця одинична" << endl;
  }
  else
  {
    cout << "Матриця не одинична" << endl;
  }


  if (isSymmetric(arr, n))
  {
    cout << "Матриця симетрична" << endl;
  }
  else
  {
    cout << "Матриця не симетрична" << endl;
  }

  if (isTriangular(arr, n))
  {
    cout << "Матриця трикутна" << endl;
  }
  else
  {
    cout << "Матриця не трикутна" << endl;
  }
  
  for (int i = 0; i < n; i++)
  {
    delete[] arr[i];

  }
  delete[] arr;
  return 0;
}