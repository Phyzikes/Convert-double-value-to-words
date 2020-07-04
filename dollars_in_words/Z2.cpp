#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Массив единиц
const pair<int, string> num1[10]{ {0,""}, {1,"one"}, {2,"two"}, {3,"three"}, {4,"four"}, {5,"five"}, {6,"six"}, {7,"seven"}, {8,"eight"}, {9,"nine"} };
// Массив круглых десятков до 100
const pair<int, string> num100[10]{ {0,""}, {1,"ten"}, {2,"twenty"}, {3,"thirty"}, {4,"fourty"}, {5,"fifty"}, {6,"sixty"}, {7,"seventy"}, {8,"eighty"}, {9,"ninety"} };
// Массив десятков от 10 до 20
const pair<int, string> num20[10]{ {0,""}, {1,"eleven"}, {2,"twelve"}, {3,"thirteen"}, {4,"fourteen"}, {5,"fifteen"}, {6,"sixteen"}, {7,"seventeen"}, {8,"eighteen"}, {9,"nineteen"} };
// Ввведенное число
double myNum;
// Количество цифр
int myN;
// Массивы для цифр
list<int> elem;
vector <pair<int, string>> numText;

// Функция десятков
void f10(int myN) {
	if (numText[myN-1].second == "" && numText[myN - 2].second == "") {
		cout << "";
	}
	if (numText[myN - 1].second != "" && numText[myN - 2].second == "") {
		cout << numText[1].second;
	}
	if (numText[myN - 1].second == "" && numText[myN - 2].second != "") {
		cout << num100[numText[myN - 2].first].second;
	}
	if (numText[myN - 1].second != "" && numText[myN - 2].second == "one") {
		cout << num20[numText[myN - 1].first].second;
	}
	if (numText[myN - 1].second != "" && numText[myN - 2].second != "one" && numText[myN - 2].second != "") {
		cout << num100[numText[myN - 2].first].second << "-" << numText[myN - 1].second;
	}
};

void hund(int myN) {
	if (numText[myN-3].second != "") {
		cout << numText[myN-3].second;
		cout << " hundred ";
	}
}

int main() {

	// Вводим число
	while (true) {
		std::cout << "Enter your num:\t";
		std::cin >> myNum;
		if (std::cin.fail() || myNum <= 0 || myNum > 1000000000) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "No valid input! Try again.\n";
		}
		else {
			std::cin.ignore(32767, '\n');
			break;
		}
	}

	// Разделяем доллары и центы
	int dollar = myNum;
	int cents = (100*(myNum - trunc(myNum)));

	// Получаем все цифры числа
	int k = 0;
	while (dollar / 10 != 0) {
		elem.push_front(dollar % 10);
		dollar /= 10;
		k++;
	}
	elem.push_front(dollar % 10);
	
	// Сколько элементов у массива (кол-во цифр)
	myN = size(elem);

	// Превращаем в текст
	int temp = 0;
	for (auto i : elem) {
		if (i == 0) { numText.push_back(num1[0]); }
		if (i == 1) { numText.push_back(num1[1]); }
		if (i == 2) { numText.push_back(num1[2]); }
		if (i == 3) { numText.push_back(num1[3]); }
		if (i == 4) { numText.push_back(num1[4]); }
		if (i == 5) { numText.push_back(num1[5]); }
		if (i == 6) { numText.push_back(num1[6]); }
		if (i == 7) { numText.push_back(num1[7]); }
		if (i == 8) { numText.push_back(num1[8]); }
		if (i == 9) { numText.push_back(num1[9]); }
	}
	
	// ОСНОВНАЯ ЧАСТЬ

	if (myN == 0) {
		cout << "Null" << endl;
	}
	if (myN == 1) {
		cout << numText[0].second;
	}
	if (myN == 2) {
		f10(myN);
	}
	if (myN == 3) {
		hund(myN);
		f10(myN);
	}
	if (myN == 4) {
		if (numText[0].second != "") { cout << numText[0].second; cout << " thousand ";}
		hund(myN);
		f10(myN);
	}
	if (myN == 5) {
		f10(myN-3);
		if (numText[0].second != "" || numText[1].second != "") { cout << " thousand "; }
		hund(myN);
		f10(myN);
	}
	if (myN == 6) {
		hund(myN - 3);
		f10(myN-3);
		if (numText[2].second != "") {
			if ((numText[0].second != "" && numText[1].second == "") || (numText[0].second == "" && numText[1].second == "")) {
				cout << numText[2].second; cout << " thousand ";
			}
		}
		if (numText[0].second != "" || numText[1].second != "" || numText[2].second != "") { 
			cout << " thousand "; 
		}
		hund(myN);
		f10(myN);
	}
	if (myN == 7) {
		if (numText[0].second != "") { cout << numText[0].second; cout << " million "; }
		hund(myN - 3);
		f10(myN - 3);
		if (numText[3].second != "") {
			if ((numText[1].second != "" && numText[2].second == "") || (numText[1].second == "" && numText[2].second == "")) {
				cout << numText[3].second; cout << " thousand ";
			}
		}
		if (numText[1].second != "" || numText[2].second != "" || numText[3].second != "") { cout << " thousand "; }
		hund(myN);
		f10(myN);
	}
	if (myN == 8) {
		f10(myN - 6);
		if (numText[0].second != "" || numText[1].second != "") {cout << " million "; }
		hund(myN - 3);
		f10(myN - 3);
		if (numText[4].second != "") {
			if ((numText[2].second != "" && numText[3].second == "") || (numText[2].second == "" && numText[3].second == "")) {
				cout << numText[4].second; cout << " thousand ";
			}
		}
		if (numText[2].second != "" || numText[3].second != "" || numText[4].second != "") { cout << " thousand "; }
		hund(myN);
		f10(myN);
	}
	if (myN == 9) {
		hund(myN - 6);
		f10(myN - 6);
		if (numText[0].second != "" || numText[1].second != "" || numText[2].second != "") { cout << " million "; }
		hund(myN - 3);
		f10(myN - 3);
		if (numText[5].second != "") {
			if ((numText[3].second != "" && numText[4].second == "") || (numText[3].second == "" && numText[4].second == "")) {
				cout << numText[5].second; cout << " thousand ";
			}
		}
		if (numText[3].second != "" || numText[4].second != "" || numText[5].second != "") { cout << " thousand "; }
		hund(myN);
		f10(myN);
	}
	if (myN == 10) {
		cout << "1 billion" << endl;
	}
	cout << " dollars";
	if (cents) {
		cout << " " << cents;
		(cents == 1) ? cout << " cent" : cout << " cents";
	}
	cout << ".";

	int yes;
	cout << "\nEnter '1' if you like it)";
	cin >> yes;
	
}
	
