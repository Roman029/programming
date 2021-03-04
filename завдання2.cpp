#include <iostream>
using namespace std;

int main() {
	int n;
	int m_num;
	int min_num;
	int curent_num;

	cout << "Введіть натуральне n: ";
	cin >> n;
	cout << "\nВведіть 1 число: ";
	cin >> min_num;
	m_num = min_num;
	for (int i = 2; i <= n; ++i) {
		cout << "\nВведіть " << i << " число: ";
		cin >> cur_num;
		if (curent_num < min_num)
			min_num = cur_num;
		else
			if (curent_num > m_num) {
				m_num = curent_num;
			}
	}

	cout << "Сума мінімальних та максимальних чисел = " << m_num + min_num << endl;

	return 0;
}