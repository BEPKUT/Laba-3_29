
/*Вариант 29
В одномерном массиве, состоящем из n вещественных элементов, вычислить:
-длину самой длинной упорядоченной цепочки подряд идущих элементов;
-произведение элементов массива, расположенных между максимальным по модулю и
минимальным по модулю элементами.
Упорядочить элементы на четных местах массива по убыванию, а на нечётных местах по
возрастанию.*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using std::cin;
using std::max;
using std::cout;
using std::swap;

//Выбор ввода массива
bool arrayFillType(int way)
{
	switch (way)
	{
	case 1:
		return false;
		break;
	case 2:
		return true;
		break;
	default:
		setlocale(LC_ALL, "Rus");
		cout << "Выберите способ заполнения массива: \n\t\t\t\t    1.Заполнение случайными значениями из диапазона [a,b]\n\t\t\t\t    2.Заполнение массива с клавиатуры\n";
		cin >> way;
		return  arrayFillType(way);
	}
}

//Заполнение массива
void arrayFill(int size, int* arr, int way) {
	int a, b;
	if (arrayFillType(way)) {
		cout << "\n" << "Введите элементы массива: ";
		for (int i = 0; i < size; i++)			//Ввод элементов с клавиатуры
		{
			cin >> arr[i];
		}
	}
	else {
		cout << "Введите диапазон [a,b] : \n a = ";
		cin >> a;
		cout << "\n b = ";
		cin >> b;
		if (b < a) {
			swap(a, b);
		}
		srand(time(NULL));
		for (int i = 0; i < size; i++) {				//Ввод элементов рандомом
			arr[i] = rand() % (b - a + 1) + a;
		}

	}
}

//Вывод массива
void arrayOutput(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		cout << " " << arr[i];
	}
}

//Нахождение упорядоченной цепочки
void orderedChain(int size, int* arr, int len = 1, int max_len = 1) {
	for (int i = 0; i < size; i++)			//Проверка всего массива 
	{
		if (arr[i] <= arr[i + 1])			//сравнение очередного и следующего элемента массива
		{
			len += 1;
		}
		else {
			if (len > max_len) {
				max_len = len;
				len = 1;
			}
		}
	}
	if (len > max_len)
	{
		max_len = len;
	}
	cout << "\n" << "Длина самой длинной упорядоченной цепочки подряд идущих элементов: " << max_len << " элементов." << "\n";
}

//Нахождение минимального и максимального по модулю элемента и произведения
void findMaxMinEl(int size, int* arr, int min_ind, int max_ind, long long result) {
	for (int i = 1; i < size; i++)			//Проверка всего массива для макс и мин элементов
	{
		if (abs(arr[i]) > abs(arr[max_ind]))	//Нахождение индекса минимального по модуля элемента
		{
			max_ind = i;
		}
		if (abs(arr[i]) < abs(arr[min_ind]))
		{
			min_ind = i;

		}
	}
	cout << "\n" << "Минимальный по модулю элемент " << arr[min_ind] << ". \nМаксимальный по модулю элемент " << arr[max_ind] << "\n";
	if (min_ind < max_ind)
	{
		while ((min_ind + 1) < max_ind)
		{
			result *= arr[min_ind + 1];
			min_ind++;
		}
	}
	else
	{
		while ((min_ind - 1) > max_ind)
		{
			result *= arr[max_ind + 1];
			max_ind++;
		}
	}
	if (result == 1) {
		result = 0;
	}
	cout << "\n" << "Произведение элементов массива, расположенных  между максимальным по модулю и минимальным по модулю элементами = " << result << '\n';

}

//Расположение элементов на четных местах массива по убыванию, а на нечётных местах по возрастанию.//

//Сортировка элементов на четных местах по убыванию
void evenInd(int size, int* arr)
{
	cout << "\nРасположение элементов на четных местах массива по убыванию, а на нечётных местах по возрастанию.\n";
	for (int i = 0; i < size; i += 2)
	{
		for (int j = i + 2; j < size; j += 2)
		{
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

// Сортировка элементов на нечетных местах по возрастанию
void oddInd(int size, int* arr) {
	for (int i = 1; i < size; i += 2)
		for (int j = i + 2; j < size; j += 2)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
}

//Вывод конечного массива
void finalArrayOutput(int size, int* arr)
{
	evenInd(size, arr);
	oddInd(size, arr);
	cout << "Изменённый массив" << "\n";
	arrayOutput(size, arr);
	cout << "\n";
}


int main()
{

	setlocale(LC_ALL, "Rus");
	int size, len, max_len, way, min_ind = 0, max_ind = 0;
	long long result = 1;

	cout << "Вариант 29\nВ одномерном массиве, состоящем из n вещественных элементов, вычислить:\n-длину самой длинной упорядоченной цепочки подряд идущих элементов;\n-произведение элементов массива, расположенных между максимальным по модулю и\nминимальным по модулю элементами.\nУпорядочить элементы на четных местах массива по убыванию, а на нечётных местах по\nвозрастанию.\n\n";

	cout << "Введите размер массива: ";
	cin >> size;							//Вводим число элементов
	int* arr = new int[size];

	cout << "Выберите способ заполнения массива: \n\t\t\t\t    1.Заполнение случайными значениями из диапазона [a,b]\n\t\t\t\t    2.Заполнение массива с клавиатуры\n";
	cin >> way;
	arrayFillType(way);

	arrayFill(size, arr, way);
	cout << "Введёный массив" << "\n";

	arrayOutput(size, arr);
	cout << "\n";

	orderedChain(size, arr, len = 1, max_len = 1);

	findMaxMinEl(size, arr, min_ind, max_ind, result);

	finalArrayOutput(size, arr);

	return 0;
}
	