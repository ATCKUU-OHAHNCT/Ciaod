#include "stdlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <random>
#include <ctime>

using namespace std;

int bSearchAll2(vector<int> &arr, int x, int& c, int& A);
int bSearchAll1(vector<int> &arr, int x, int& c, int& A);
int bSearch2(vector <int> &arr, int x, int& c);
int bSearch1(vector <int> &arr, int x, int& c);
void ShellKnutSort(vector<int> &arr, int &m, int &c, int &g);
void ShellSort(vector <int> &arr, int &m, int &c, int &g);
void ShakerSort(vector<int>& arr, int& m, int& c);
void BubbleSort(vector<int>& arr, int& m, int& c);
void InsertSort(vector<int>& arr, int& m, int& c);
void SelectSort(vector<int>& arr, int& m, int& c);
void InsertSort(int *arr, int n, int& m, int& c);
void ShakerSort(int *arr, int n, int& m, int& c);
void BubbleSort(int *arr, int n, int& m, int& c);
void SelectSort(int *arr, int n, int& m, int& c);

void FillInc(int *arr, int n); // 
void FillDec(int *arr, int n); // 
void FillRand(int *arr, int n); //
void FillRand(vector<int>& arr);
int CheckSum(int *arr, int n); // 
int RunNumber(int *arr, int n); //
int RunNumber(vector <int> &arr); //
void PrintMas(int *arr, int n); // 
void clear();

//------------------------------------

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int m = 0, c = 0, k = 0, g = 0, A = 0;
    clear();

	cout << "n\tk-сорт\tm + c(shell)\tm + c(insert)\n";
	for (int n = 100; n < 600; n += 100) {
		vector <int> arr(n);
		cout << n << "\t";

		FillRand(arr);
		ShellKnutSort(arr, m, c, g);
		cout << g << "\t";
		cout << m + c << "\t\t";
		m = 0, c = 0, k = 0;

		FillRand(arr);
		InsertSort(arr, m, c);
		cout << m + c;
		m = 0, c = 0;

		cout << endl;

	}
	cout << endl;

	m = 0, c = 0, g = 0;
	cout << "n\tk-сорт (Кнут)\tm + c(shell)\tk-сорт (не Кнут)\tm + c(shell)\n";
	for (int n = 100; n < 600; n += 100) {

		vector <int> arr(n);
		cout << n << "\t\t";

		FillRand(arr);
		ShellSort(arr, m, c, g);
		cout << g << "\t" << m + c << "\t\t\t";
		m = 0, c = 0, g = 0;

		FillRand(arr);
		ShellKnutSort(arr, m, c, g);
		cout << g << "\t\t" << m + c;
		m = 0, c = 0, g = 0;

		cout << endl;
	}

	int x = 55;

/*	cout << "\n\n\n\t\tbSearch1\tbSearch2\n";
	for (int n = 100; n <= 1000; n += 100) {

		c = 0;

		vector <int> arr(n);
		cout << n << "\t\t";

		FillRand(arr);
		ShellSort(arr, m, c, g);

		c = 0;

		bSearch1(arr, x, c);
		cout << c << "\t\t";
		c = 0;

		bSearch2(arr, x, c);
		cout << c << "\n";
	
	}

	cout << "\n\n\n\t\tbSearchAll1\tA\tbSearchAll2\t\tA\n";
	for (int n = 100; n <= 1000; n += 100) {

		c = 0; A = 0;

		vector <int> arr(n);
		cout << n << "\t\t";

		FillRand(arr);
		ShellSort(arr, m, c, g);
		
		c = 0;

		bSearchAll1(arr, x, c, A);
		cout << c << "\t\t" << A << "\t\t";

		c = 0; A = 0;

		bSearchAll2(arr, x, c, A);
		cout << c << "\t\t" << A << "\n";

	}


	int fl = 0;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))  //øðèôò íå çàãðóæàåòñÿ
	{
		cout << "ERROR";
	}

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(15);
	sf::RenderWindow window(sf::VideoMode(1280, 730), "SFML works!");
	sf::Vertex line[] =
	{
	sf::Vertex(sf::Vector2f(5.f, 10.f)),
	sf::Vertex(sf::Vector2f(10.f, 5.f))
	};

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (!fl) {
			fl = 1;
			window.clear();
			line[0] = sf::Vertex(sf::Vector2f(0.f, 15.f));
			line[1] = sf::Vertex(sf::Vector2f(10.f, 5.f));
			window.draw(line, 2, sf::Lines);
			line[0] = sf::Vertex(sf::Vector2f(10.f, 5.f));
			line[1] = sf::Vertex(sf::Vector2f(20.f, 15.f));
			window.draw(line, 2, sf::Lines);
			line[0] = sf::Vertex(sf::Vector2f(10.f, 5.f));
			line[1] = sf::Vertex(sf::Vector2f(10.f, 710.f));

			window.draw(line, 2, sf::Lines);
			line[0] = sf::Vertex(sf::Vector2f(10.f, 710.f));
			line[1] = sf::Vertex(sf::Vector2f(1260.f, 710.f));
			window.draw(line, 2, sf::Lines);
			line[0] = sf::Vertex(sf::Vector2f(1260.f, 710.f));
			line[1] = sf::Vertex(sf::Vector2f(1250.f, 700.f));
			window.draw(line, 2, sf::Lines);
			line[0] = sf::Vertex(sf::Vector2f(1260.f, 710.f));
			line[1] = sf::Vertex(sf::Vector2f(1250.f, 720.f));
			window.draw(line, 2, sf::Lines);

			for (int i = 50; i <= 500; i += 50) {
				text.setString("K");
				text.setPosition((float)((2.52 * i) - 20), 690.f);
				window.draw(text);
			}
			for (int i = 20000; i <= 350000; i += 20000) {
				text.setString("K");
				text.setPosition(20.f, (float)(710 - i / 493));
				window.draw(text);
			}
			int k = 10, l = 710;

			for (int i = 100; i <= 1000; i += 100) 
			{

				vector<int> arr(i);
				FillRand(arr);

				m = 0, c = 0;

				ShellSort(arr, m, c, g);

				m = 0, c = 0;

				bSearchAll1(arr, x, c, A);

				line[0] = sf::Vertex(sf::Vector2f((float)k, (float)l));
				line[1] = sf::Vertex(sf::Vector2f((float)(2.52 * i), (float)(710 - (m + c) / 493)));
				line[0].color = sf::Color::Yellow;
				line[1].color = sf::Color::Yellow;
				k = (int)(2.52 * i);
				l = 710 - (m + c) / 493;
				window.draw(line, 2, sf::Lines);

			}

			k = 10, l = 710;

			for (int i = 100; i <= 1000; i += 100)
			{

				vector<int> arr(i);
				FillRand(arr);

				m = 0, c = 0;

				ShellSort(arr, m, c, g);

				m = 0, c = 0;

				bSearchAll2(arr, x, c, A);

				line[0] = sf::Vertex(sf::Vector2f((float)k, (float)l));
				line[1] = sf::Vertex(sf::Vector2f((float)(2.52 * i), (float)(710 - (m + c) / 493)));
				line[0].color = sf::Color::Yellow;
				line[1].color = sf::Color::Yellow;
				k = (int)(2.52 * i);
				l = 710 - (m + c) / 493;
				window.draw(line, 2, sf::Lines);

			}

			

			window.display();
		}
		//Sleep(100);
	}*/


}


//___________________________________________________________________________
//                            
//___________________________________________________________________________


int bSearchAll2(vector<int> &arr, int x, int& c, int& A) // 
{
	int l = 1, r = arr.size(), m;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == x)
			A++;
		if (arr[i] > x)
			break;

		c += 2;
	}
/*	while (l < r)
	{
		m = (l + r) / 2;
		if (arr[m] <= x) 
			l = m + 1;
		else r = m;
		c += 2;
	}
	if (arr[r] == x)
		A++;
	else return 0;*/

	return 0;
}
//--------------------------------------------------

int bSearchAll1(vector<int> &arr, int x, int& c, int& A) //
{
	int l = 1, r = arr.size(), m;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == x)
			A++;
		if (arr[i] > x)
			break;
		c += 2;
	}
/*	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == x)
			A++;
		if (arr[m] <= x)
			l = m + 1;
		else
			r = m - 1;
		c += 3;
	}*/

	return 0;
}
//----------------------------------------------------

int bSearch2(vector<int> &arr, int x, int& c) // 
{
	int l = 1, r = arr.size(), m;

	while (l < r)
	{
		m = (l + r) / 2;
		if (arr[m] < x) l = m + 1;
		else r = m;
		c += 2;
	}
	if (arr[r] == x)
		return arr[r];
	else return 0;
}
//--------------------------------------------------

int bSearch1(vector<int> &arr, int x, int& c) // 
{
	int l = 1, r = arr.size(), m;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (arr[m] == x)
			return arr[m];
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
		c += 3;
	}

	return 0;
}
//----------------------------------------------------

void ShellKnutSort(vector<int> &arr, int &m, int &c, int &g)
{
	int n = (int)log2(arr.size()) - 1;
	g = n;
	vector<int> k(n);
	int temp, l;
	for (int i = n; i > 0; i--) {
		k[n - i] = pow(2, i) - 1;
	}
	for (int i = 0; i < n; i++) {
		for (unsigned j = k[i]; j < arr.size(); j++) {
			temp = arr[j];
			m++;
			l = j - k[i];
			while (l >= 0) {
				c++;
				if (temp < arr[l]) {
					arr[l + k[i]] = arr[l];
					m++;
					l = l - k[i];
				}
				else break;
			}
			arr[l + k[i]] = temp;
			m++;
		}
	}
}
//---------------------------------------------------

void ShellSort(vector <int> &arr, int &m, int &c, int &g)  //
{
	int h = 1;
	int t;
	int l, r; //
	while (h <= arr.size() / 2) {
		h = h * 2;
		g++;
	}

	for (h; h > 0; h = (h - 1) / 3)
		for (r = h; r < arr.size(); r++)
		{
			t = arr[r];
			for (l = r; l >= h; l -= h)
			{
				c++;
				if (t < arr[l - h]) {
					arr[l] = arr[l - h];
					m++;
				}
				else
					break;
			}
			arr[l] = t;
		}

}
//-----------------------------------------------------

void ShakerSort(vector<int>& arr, int& m, int& c) // 
{
	int t, l = 0, r = arr.size() - 1, k = r;
	do {
		for (int i = r; i > l; i--) {
			c++;
			if (arr[i] < arr[i - 1]) {
				m += 3;
				t = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = t;
				k = i;
			}
		}
		l = k;
		for (int i = l; i < r; i++) {
			c++;
			if (arr[i] > arr[i + 1]) {
				m += 3;
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				k = i;
			}
		}
		r = k;
	} while (l < r);
}
//-----------------------------------------------

void BubbleSort(vector<int>& arr, int& m, int& c) // 
{
	int t;
	for (unsigned i = 0; i < arr.size(); i++) {
		for (unsigned j = 0; j < arr.size() - 1 - i; j++) {
			c++;
			if (arr[j] > arr[j + 1]) {
				m += 3;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
//-------------------------------------------------

void InsertSort(vector<int>& arr, int& m, int& c) { // 
	int i, j, t;

	for (i = 0; i < arr.size(); i++) {
		j = i;
		c++;
		while (j > 0 && arr[j] < arr[j - 1]) {
			m += 3;
			t = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = t;
			j--;
		}
	}
}
//--------------------------------------------------

void SelectSort(vector<int>& arr, int& m, int& c) {  // 
	int i, j, k, t;

	for (i = 0; i < arr.size() - 1; i++) {
		k = i;
		for (j = i + 1; j < arr.size(); j++) {
			c++;
			if (arr[j] < arr[k])
				k = j;
		}
		t = arr[i];
		arr[i] = arr[k];
		arr[k] = t;
		m += 3;
	}
}
//--------------------------------------------------

void InsertSort(int *arr, int n, int& m, int& c)
{
	int i, j, t;

	for (i = 0; i < n; i++) {
		j = i;
		c++;
		while (j > 0 && arr[j] < arr[j - 1]) {
			m += 3;
			t = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = t;
			j--;
		}
	}
}
//-----------------------------------------------------

void ShakerSort(int *arr, int n, int& m, int& c) // 
{
	int t, l = 0, r = n - 1, k = r;

	do {
		for (int i = r; i > l; i--) {
			c++;
			if (arr[i] < arr[i - 1]) {
				m += 3;
				t = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = t;
				k = i;
			}
		}
		l = k;
		for (int i = l; i < r; i++) {
			c++;
			if (arr[i] > arr[i + 1]) {
				m += 3;
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				k = i;
			}
		}
		r = k;
	} while (l < r);
}
//---------------------------------------------------------------

void BubbleSort(int *arr, int n, int& m, int& c) // 
{
	int t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			c++;
			if (arr[j] > arr[j + 1]) {
				m += 3;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}
//-------------------------------------------------------------

void SelectSort(int *arr, int n, int& m, int& c)// 
{
	int i, j, k, t;

	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			c++;
			if (arr[j] < arr[k])
				k = j;
		}
		t = arr[i];
		arr[i] = arr[k];
		arr[k] = t;
		m += 3;
	}
}
//-------------------------------------------------------------

void FillInc(int *arr, int n) // 

{
	int i;

	for (i = 0; i < n; i++)
		arr[i] = i + 1;

	//cout << a[i] << ' ';}

}
//-------------------------------------

void FillDec(int *arr, int n) // 
{
	int i;

	for (i = 0; i < n; i++)
		arr[i] = 2 * n - i;

	//cout << a[i] << ' ';}

}
//---------------------------------------

void FillRand(int *arr, int n) // 
{
	int i;

	for (i = 0; i < n; i++)
		arr[i] = rand() % 101;

	//     cout << a[i] << ' ';}

}
//-------------------------------------

void FillRand(vector<int>& arr)
{
	int i;

	for (i = 0; i < arr.size(); i++)
		arr[i] = rand() % 101;
}
//-------------------------------------

int CheckSum(int *arr, int n) // 
{
	int i, k = 0;

	for (i = 0; i < n; i++)
		k += arr[i];

	return k;
}
//------------------------------------ 

int RunNumber(int *arr, int n)
{ //
	int i, max1 = 1;

	for (i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			max1++;

	return max1;
}
//-------------------------------------

int RunNumber(vector <int> &arr) { //
	int i, max1 = 1;

	for (i = 0; i < arr.size() - 1; i++)
		if (arr[i] > arr[i + 1])
			max1++;

	return max1;
}
//------------------------------------

void PrintMas(int *arr, int n) { // 
	int i;


	for (i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;

}
//------------------------------------

void clear() {
  printf("\033[2J");
  printf("\033[0;0f");
}