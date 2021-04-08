#include <iostream>
using namespace std;

int* deleteElements(int n, int i_, int j_, int* arr)
{
    int n1 = n - (j_ - i_ - 1);
    int counter = 0;
    int* arr1 = new int[n1];
    
    for(int i = i_; i <= j_; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    for(int i = 0; i < n; i++)
        if(i < i_ || i > j_)
        {
            arr1[counter] = arr[i];
            counter++;
        }
            
    for (int i = 0; i < counter; i++)
        cout << arr1[i] << " ";
    cout << endl;
    
    return arr1;
}

int main()
{
    int* arr;
    arr = new int[5];
    
    for (int i = 0; i < 5; i++)
        arr[i] = i + 1;
        
    deleteElements(5, 1, 3, arr);
    return 0;
}