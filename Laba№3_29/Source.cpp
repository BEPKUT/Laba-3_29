
/*������� 29
� ���������� �������, ��������� �� n ������������ ���������, ���������:
-����� ����� ������� ������������� ������� ������ ������ ���������;
-������������ ��������� �������, ������������� ����� ������������ �� ������ �
����������� �� ������ ����������.
����������� �������� �� ������ ������ ������� �� ��������, � �� �������� ������ ��
�����������.*/

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>

using std::cin;
using std::max;
using std::cout;
using std::swap;

//����� ����� �������
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
		cout << "�������� ������ ���������� �������: \n\t\t\t\t    1.���������� ���������� ���������� �� ��������� [a,b]\n\t\t\t\t    2.���������� ������� � ����������\n";
		cin >> way;
		return  arrayFillType(way);
	}
}

//���������� �������
void arrayFill(int size, int* arr, int way) {
	int a, b;
	if (arrayFillType(way)) {
		cout << "\n" << "������� �������� �������: ";
		for (int i = 0; i < size; i++)			//���� ��������� � ����������
		{
			cin >> arr[i];
		}
	}
	else {
		cout << "������� �������� [a,b] : \n a = ";
		cin >> a;
		cout << "\n b = ";
		cin >> b;
		if (b < a) {
			swap(a, b);
		}
		srand(time(NULL));
		for (int i = 0; i < size; i++) {				//���� ��������� ��������
			arr[i] = rand() % (b - a + 1) + a;
		}

	}
}

//����� �������
void arrayOutput(int size, int* arr) {
	for (int i = 0; i < size; i++) {
		cout << " " << arr[i];
	}
}

//���������� ������������� �������
void orderedChain(int size, int* arr, int len = 1, int max_len = 1) {
	for (int i = 0; i < size; i++)			//�������� ����� ������� 
	{
		if (arr[i] <= arr[i + 1])			//��������� ���������� � ���������� �������� �������
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
	cout << "\n" << "����� ����� ������� ������������� ������� ������ ������ ���������: " << max_len << " ���������." << "\n";
}

//���������� ������������ � ������������� �� ������ �������� � ������������
void findMaxMinEl(int size, int* arr, int min_ind, int max_ind, long long result) {
	for (int i = 1; i < size; i++)			//�������� ����� ������� ��� ���� � ��� ���������
	{
		if (abs(arr[i]) > abs(arr[max_ind]))	//���������� ������� ������������ �� ������ ��������
		{
			max_ind = i;
		}
		if (abs(arr[i]) < abs(arr[min_ind]))
		{
			min_ind = i;

		}
	}
	cout << "\n" << "����������� �� ������ ������� " << arr[min_ind] << ". \n������������ �� ������ ������� " << arr[max_ind] << "\n";
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
	cout << "\n" << "������������ ��������� �������, �������������  ����� ������������ �� ������ � ����������� �� ������ ���������� = " << result << '\n';

}

//������������ ��������� �� ������ ������ ������� �� ��������, � �� �������� ������ �� �����������.//

//���������� ��������� �� ������ ������ �� ��������
void evenInd(int size, int* arr)
{
	cout << "\n������������ ��������� �� ������ ������ ������� �� ��������, � �� �������� ������ �� �����������.\n";
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

// ���������� ��������� �� �������� ������ �� �����������
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

//����� ��������� �������
void finalArrayOutput(int size, int* arr)
{
	evenInd(size, arr);
	oddInd(size, arr);
	cout << "��������� ������" << "\n";
	arrayOutput(size, arr);
	cout << "\n";
}


int main()
{

	setlocale(LC_ALL, "Rus");
	int size, len, max_len, way, min_ind = 0, max_ind = 0;
	long long result = 1;

	cout << "������� 29\n� ���������� �������, ��������� �� n ������������ ���������, ���������:\n-����� ����� ������� ������������� ������� ������ ������ ���������;\n-������������ ��������� �������, ������������� ����� ������������ �� ������ �\n����������� �� ������ ����������.\n����������� �������� �� ������ ������ ������� �� ��������, � �� �������� ������ ��\n�����������.\n\n";

	cout << "������� ������ �������: ";
	cin >> size;							//������ ����� ���������
	int* arr = new int[size];

	cout << "�������� ������ ���������� �������: \n\t\t\t\t    1.���������� ���������� ���������� �� ��������� [a,b]\n\t\t\t\t    2.���������� ������� � ����������\n";
	cin >> way;
	arrayFillType(way);

	arrayFill(size, arr, way);
	cout << "������� ������" << "\n";

	arrayOutput(size, arr);
	cout << "\n";

	orderedChain(size, arr, len = 1, max_len = 1);

	findMaxMinEl(size, arr, min_ind, max_ind, result);

	finalArrayOutput(size, arr);

	return 0;
}
	