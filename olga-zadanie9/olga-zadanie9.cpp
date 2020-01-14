#include <iostream>
/*ZADANIE 9*/
/*Temat: Referencje*/

//Nowe słówko: referencja (reference) - odwołanie się do czegoś, nawiązanie

//Funkcja do przykładu 9.3
//Dodaje dwa inty
int add(int no_ref_a, int no_ref_b) //argumentami funkcji są dwa inty
{
	return no_ref_a + no_ref_b;
}

//Funkcja do przykładu 9.3
//zamienia wartości dwóch intów
void swap_ints(int& ref_a, int& ref_b) //argumentami funkcji są referencje do dwóch intów
{
	int _temporary = ref_a;
	ref_a = ref_b;
	ref_b = _temporary;
}

//Funkcja do przykładu 9.4
//jeśli to możliwe dzieli dzielną przez dzielnik, zwraca bool czy nastąpiło dzielenie
bool divide_if_possible(int& dzielna, int dzielnik) //argumentami funkcji jest referencja do zmiennej typu int i zmienna typu int
{
	if (dzielnik != 0)
	{
		dzielna = dzielna / dzielnik; //dzieli dzielną przez dzielnik, przypisuje dzielnej wynik dzielenia
		return true; //zwraca true gdy dzielenie było możliwe
	}
	else
	{
		return false; //zwraca false gdy dzielenie było niemożliwe
	}
}

int main()
{
	bool example = true;
	if (example)
	{
		int current_example = 0;

		/*PRZYKŁAD 9.0*/
		/*Operator referencji*/
		if (current_example == 0)
		{
			int a = 250;

			//operatorem referencji jest symbol & za typem zmiennej
			int& b = a; 
			//czytamy: b jest referencją do zmiennej typu int o nazwie a
		}
		/*KONIEC PRZYKŁAD 9.1*/
		else if (current_example == 1)
		/*PRZYKŁAD 9.1*/
		/*Przykład bez referencji*/
		{
			std::string food		= "pizza";		//inicjalizujemy zmienną z wartością "pizza"
			std::string jedzonko	= "pizza";		//inicjalizujemy zmienną z wartością "pizza"

			jedzonko				= "spaghetti";	//zmieniamy wartość zmiennej na "spaghetti"

			std::cout << food		<< '\n';		//zwraca początkową wartość
			std::cout << jedzonko	<< '\n';		//zwraca zmienioną wartość

			//Wszystkie operacje na zwykłej zmiennej odbywają się na tej zmiennej
		}
		/*KONIEC PRZYKŁAD 9.1*/
		else if (current_example == 2)
		/*PRZYKŁAD 9.2*/
		/*Przykład z referencją*/
		{
			std::string  food		= "pizza";		//inicjalizujemy zmienną z wartością "pizza"
			std::string& jedzonko	= food;			//inicjalizujemy zmienną referencyjną z referencją ustawioną na zmienną food

			jedzonko				= "spaghetti";	//zmieniamy wartość zmiennej na "spaghetti"

			std::cout << food		<< '\n';		//zwraca zmienioną wartość
			std::cout << jedzonko	<< '\n';		//zwraca zmienioną wartość

			//Wszystkie operacje wykonane na referencji odbywają się na zmiennej do której jest dana referencja
			//To jest na przykład, że jeśli jedzonko jest referencją do food to:
			//std::cout << jedzonko;
			//oznacza std::cout << (to do czego referencją jest jedzonko);
			//a więc w tym wypadku std::cout << food;
		}
		/*KONIEC PRZYKŁAD 9.2*/
		else if (current_example == 3)
		/*PRZYKŁAD 9.3*/
		/*Praktyczne wykorzystanie referencji*/
		{
			//W normalnych warunkach funkcja jest w stanie zwrócić tylko jedną wartość:
			int a = 1;
			int b = 156;
			int c = add(a, b);
			std::cout << "Wartosc zwrocona przez funkcje: " << '\n';
			std::cout << c << '\n';

			std::cout << '\n';
			//Referencje pozwalają nam na ominięcie tego ograniczenia
			//W deklaracji funkcji add używamy zwykłe zmienne int no_ref_a i no_ref_b, oznacza to, że wywołania tej funkcji kopiuje wartość przekazanego mu a i b do zmiennych lokalnych no_ref_a i no_ref_b
			//W deklaracji funkcji swap_ints używamy zmienne referencyjne int& a i b, oznacza to, że wywołanie tej funkcji tworzy w tych zmiennych lokalnych referencję do przekazanych mu zmniennych a1 i b1

			int a1 = 1;
			int b1 = 156;

			std::cout << "Zmienne przed zamiana: " << '\n';
			std::cout << a1 << '\n';
			std::cout << b1 << '\n';
			std::cout << '\n';
			swap_ints(a1, b1);

			std::cout << "Zmienne po zamianie: " << '\n';
			std::cout << a1 << '\n';
			std::cout << b1 << '\n';
		}
		/*KONIEC PRZYKŁAD 9.3*/
		else if (current_example == 4)
		/*PRZYKŁAD 9.4*/
		/*Praktyczne wykorzystanie referencji 2*/
		{
			//Referencje można wykorzystać też, jeśli chcemy żeby funkcja wykonywała czynność w pewnych warunkach i chcemy i sprawdzić czy czynność została wykonana i uzyskać wynik tej czynności
			int a1 = 100;
			int a2 = 100;

			int b1 = 20;
			int b2 = 0;

			bool was_a1_divided = divide_if_possible(a1, b1); //dzielenie nastąpi, zmiennej a1 zostanie przypisany wynik a zmiennej was_a1_divided wartość true
			bool was_a2_divided = divide_if_possible(a2, b2); //dzielenie nie nastąpi, zmiennej a2 zostanie przypisany wynik a zmiennej was_a2_divided wartość false

			if (was_a1_divided)
			{
				std::cout << "Nastapilo dzielenie." << '\n';
				std::cout << "Wynik dzielenia to:" << a1 << '\n';
			}
			else
			{
				std::cout << "Nie nastapilo dzielenie." << '\n';
			}

			std::wcout << '\n';
			
			if (was_a2_divided)
			{
				std::cout << "Nastapilo dzielenie." << '\n';
				std::cout << "Wynik dzielenia to:" << a2 << '\n';
			}
			else
			{
				std::cout << "Nie nastapilo dzielenie." << '\n';
			}

		}
		/*KONIEC PRZYKŁAD 9.4*/else if (current_example == 4)
		/*PRZYKŁAD 9.4*/
		/*Praktyczne wykorzystanie referencji 2*/
		{
			//Referencje można wykorzystać też, jeśli chcemy żeby funkcja wykonywała czynność w pewnych warunkach i chcemy i sprawdzić czy czynność została wykonana i uzyskać wynik tej czynności
			int a1 = 100;
			int a2 = 100;

			int b1 = 20;
			int b2 = 0;

			bool was_a1_divided = divide_if_possible(a1, b1); //dzielenie nastąpi, zmiennej a1 zostanie przypisany wynik a zmiennej was_a1_divided wartość true
			bool was_a2_divided = divide_if_possible(a2, b2); //dzielenie nie nastąpi, zmiennej a2 zostanie przypisany wynik a zmiennej was_a2_divided wartość false

			if (was_a1_divided)
			{
				std::cout << "Nastapilo dzielenie." << '\n';
				std::cout << "Wynik dzielenia to:" << a1 << '\n';
			}
			else
			{
				std::cout << "Nie nastapilo dzielenie." << '\n';
			}

			std::wcout << '\n';
			
			if (was_a2_divided)
			{
				std::cout << "Nastapilo dzielenie." << '\n';
				std::cout << "Wynik dzielenia to:" << a2 << '\n';
			}
			else
			{
				std::cout << "Nie nastapilo dzielenie." << '\n';
			}

		}
		/*KONIEC PRZYKŁAD 9.4*/
		else if (current_example == 4)
		/*PRZYKŁAD 9.4*/
		/*Praktyczne wykorzystanie referencji 2*/
		{
			//Referencje można wykorzystać też, jeśli chcemy żeby funkcja wykonywała czynność w pewnych warunkach i chcemy i sprawdzić czy czynność została wykonana i uzyskać wynik tej czynności
			int a1 = 100;
			int a2 = 100;

			int b1 = 20;
			int b2 = 0;

			bool was_a1_divided = divide_if_possible(a1, b1); //dzielenie nastąpi, zmiennej a1 zostanie przypisany wynik a zmiennej was_a1_divided wartość true
			bool was_a2_divided = divide_if_possible(a2, b2); //dzielenie nie nastąpi, zmiennej a2 zostanie przypisany wynik a zmiennej was_a2_divided wartość false

			if (was_a1_divided)
			{
				std::cout << "Nastapilo dzielenie." << '\n';
				std::cout << "Wynik dzielenia to:" << a1 << '\n';
			}
			else
			{
				std::cout << "Nie nastapilo dzielenie." << '\n';
			}

			std::wcout << '\n';
			
			if (was_a2_divided)
			{
				std::cout << "Nastapilo dzielenie." << '\n';
				std::cout << "Wynik dzielenia to:" << a2 << '\n';
			}
			else
			{
				std::cout << "Nie nastapilo dzielenie." << '\n';
			}

		}
		/*KONIEC PRZYKŁAD 9.4*/
		else if (current_example == 4)
		/*PRZYKŁAD 9.5*/
		/*Ostrzeżenia*/
		{
			//swap_ints(5, 6);
			//jest niemożliwe. jeśli usuniesz z poprzedniej linijki znaczniki komentarza // to nastąpi błąd
			//funkcjom przyjmującym referencje nie można przekazać literals (dosłownych danych, stałych)

			//int& bad_ref = 6;
			//to samo tyczy się normalnego tworzenia zmiennych referencyjnych

			int referenced = 7;
			int referenced2 = 156;

			int& reference = referenced;
			reference = referenced2;
			//nie można zmienić do jakiej zmiennej jest referencja
			//takie coś jak powyżej spowoduje, że wszystkie trzy zmienne będą miały wartość 156
		}
		/*KONIEC PRZYKŁAD 9.5*/
	}
	else
	/*ZADANIE 9.1*/
	//Utwórz funkcję min_max_int typu bool;
	//1. funkcja przyjmuje trzy argumenty
	//2. funkcja zmienia wartość pierwszego argumentu jeśli jest mniejszy od drugiego argumentu i lub większy od trzeciego argumentu
	//	 tak aby był on ograniczony do przedziału <argument_drugi; argument_trzeci>
	//3. funkcja zwraca bool, którego wartość wynosi true, jeśli nastąpiła zmiana wartości pierwszego argumentu, albo false jeśli pierwszy argument znajdował się już w wspomnianym wyżej przedziale
	//4. poniżej wykorzystaj funkcję dla danych zestawów argumentów wypisując na konsolę informację, czy pierwszy argument został zmieniony i jeśli tak, to jego nową wartość:
	//   2		1		4
	//   8		2		5
	//   1000	1		100000
	//   1000	1		100
	//   -5		-10		20
	//   -5		10		20
	{
		
	}
	/*KONIEC ZADANIE 9.1*/
}