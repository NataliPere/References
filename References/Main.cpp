//Шаблон проекта С++
#include <iostream>
#include <cstdlib>
#include <ctime>

void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void p_swap(int *pn1, int *pn2) {
	int tmp = * pn1;
	*pn1 = *pn2;
	*pn2 = tmp;
}

void refswap(int& refn1, int& refn2) {
	int tmp = refn1;
	refn1 = refn2;
	refn2 = tmp;
}

int mx[10][2];
int& func(int index) {
	return mx[index][1];
}

template <typename T>
void show_arr(T arr[], const int length) {
	std::cout << "[ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] <<", ";
	std::cout <<"\b\b]\n ";

}

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
T& max_arr(T arr[], const int length) {
	int i_max = 0;
	for (int i = 1; i < length; i++)
		i_max = arr[i] > arr[i_max] ? i : i_max;
		return arr[i_max];
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n = 10, m = 20;
	int a = 10, b = 20, c = 30;
	//Нейтральный указатель
	/*int* pn = 0; //Первый способ
	//int* pn = NULL; //Второй способ
	int* pn = nullptr; //Третий способ. nullptr не является числом 

	if (pn == nullptr)
	std::cout << "Указатель не инициализирован\n";
	else
	std::cout << *pn << "\n";*/
	 //Указатель на константу. Используя разыменование нельзя поменять значение переменной, на которую указывает.
	/*int a = 10, b = 20, c = 30;
	int const * pa;
	pa = &a;
	std::cout << *pa << "\n";
	pa = &b;
	std::cout << *pa << "\n";
	*pa = 15; //поменять значение нельзя, можно применить только переменную
	std::cout << *pa << "\n";*/
	//Константный указатель
	/*int a = 10, b = 20, c = 30;
	const int* pb;
	pb = &b;
	std::cout << *pb << "\n";
	pb = &c;
	std::cout << *pb << "\n";
	//*pb = 35; //Ошибка*/
	//Константный указатель на константу. Нельзя менять значение переменной, а также нельзя перенаправлять указатель.
	/*const int* const pc = &c;
	std::cout << *pc << "\n";
	pc = &a; //Ошибка
	*pc = 50; //Ошибка*/
	//Ссылка на переменную 
	/*int& refn = n; //ref + имя_переменной. Любая ссылка должна быть сразу инициализирована и связана с переменной.
	std::cout << refn << "\n"; //Ссылки разыменовываются автоматически, * ставить не надо
	std::cout << "n =" << n << "\n";
	std::cout <<"refn = " << refn << "\n";
	refn = 15;
	std::cout << "Новая n = " << n << "\n";

	//Области применения ссылок:
	//1. Работа с объектами из разных частей кода;
	//2. Экономия выделяемой памяти.
	//Ссылки - альтернативные имена (псевдонимы уже существующих перенных). Не хранят в себе ни какие адреса.
	// Можно создавать несколько ссылок на одну и ту же переменную.*/
	
	//Ссылки как параметры функции
	/*std::cout << n << ' ' << m << "\n";
	//my_swap(n, m); // удобно, но не работает
	//p_swap(&n, &m); //работает, но передавать адреса переменных - не удобно
	refswap(n, m);
	std::cout << n << ' ' << m << "\n";*/

	//
	for (int i = 0; i < 10; i++) {
		std::cout << "Ряд № " << i + 1 << "- ";
		std::cin >> mx[i][0];
		func(i) = mx[i][0];
	}
	std::cout << "Итоговый массив: \n";
	for (int i = 0; i < 10; i++)
		std::cout << mx[i][0] << '\t' << func(i) << "\n";


	const int size = 5;
	int arr[size]{ 5, 6, 10, 25, 3 };
	std::cout << "Изначальный масссив: \n";
	show_arr(arr, size);
	std::cout << "Максимум = " << max_arr(arr, size) <<"\n";
	std::cout << "Обнуляем максимум.. \nИтоговый массив: ";
	max_arr(arr, size) = 0;
	show_arr(arr, size);


	return 0;
}