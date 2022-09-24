// Adrian Alejandro Montes Mendoza

#include <iostream>
using namespace std;
#include <conio.h>
#include <string>
#include <sstream>

void split_str(string);

class Date {
private:
	unsigned int year = 0; //unsigned = sin signo = solo valores positivos
	unsigned int month = 0;
	unsigned int day = 0;
	string dateInString;
	
public:
	int valid_date = 0;
	operator const char* ()
	{
		ostringstream formattedDate; // assists string construction
		formattedDate <<"La fecha reconvertida a string: " << day << " / " << month << " / " << year;
		dateInString = formattedDate.str();
		return dateInString.c_str();
	}

	Date(int, int, int);

	void set_year(int);
	void set_month(int);
	void set_day(int);
	int get_year(void) {return year; };
	int get_month(void) { return month; };
	int get_day(void) { return day; };

	void check_date(void) { //Me base en la pagina https://www.abrirllave.com/c/ejercicio-validar-fecha.php#:~:text=Nota%201%3A%20Para%20que%20una,a%C3%B1o%20introducidos%20por%20el%20usuario.
		
		if (get_month() >= 1 && get_month() <= 12) 
		{
			switch (get_month()) {
			case  1:
			case  3:
			case  5:
			case  7:
			case  8:
			case 10:
			case 12: if (get_day() < 1 || get_day() > 31 || get_year() < 1900 || get_year() > 2100)
				valid_date = 0;
				   else valid_date = 1;
				break;

			case  4:
			case  6:
			case  9:
			case 11: if (get_day() < 1 || get_day() > 30 || get_year() < 1900 || get_year() > 2100)
				valid_date = 0;
				   else valid_date = 1;
				break;

			case  2: if (get_year() % 4 == 0 && get_year() % 100 != 0 || get_year() % 400 == 0)
			{
				if (get_day() >= 1 && get_day() <= 29)
					valid_date = 1;
			}
				   else
				if (get_day() >= 1 && get_day() <= 28)
					valid_date = 1;
			}
		}

		if (valid_date == 0) {
			cout << "Fecha incorrecta" << endl;
		}
		else
		{
			cout << "Fecha correcta" << endl;
		}
	}


};

void Date::set_day(int _day) {
	if (_day < 0 || day > 31) {
		valid_date = 0;
	}
	else {
		day = _day;
	}
}

void Date::set_month(int _month) {
	if (_month < 0 || month > 12) {
		valid_date = 0;
	}
	else {
		month = _month;
	}
}

void Date::set_year(int _year) {
	if (_year < 0 || year > 3000) {
		valid_date = 0;
	}
	else {
		year = _year;
	}
}

Date::Date(int INPUT_YEAR, int INPUT_MONTH, int INPUT_DAY) { // Aun no entiendo como usar el constructor
	
}

void split_str(string _fulldate) {
	int nyear, nmonth, nday;
	string word = "";
	int i = 0;
	const int Tamvec = 4;
	string array[Tamvec] = {};
	int date_numbers[Tamvec] = {};
	
	_fulldate += '-';
	// Me base en el video de https://www.youtube.com/watch?v=BUy-SE6ZWGM&ab_channel=GeeksforGeeks
	for (auto x : _fulldate)
	{
		if (x == '-' || x == '/' || x == ' ' || x== '.')
		{
			i++;
			array[i] = word;
			date_numbers[i] = stoi(array[i]);
			word = "";		
		}
		else
		{
			word = word + x;
		}
		
	}
	nday = date_numbers[1];
	nmonth = date_numbers[2];
	nyear = date_numbers[3];	
	
	Date d1(nday, nmonth, nyear);
	
	d1.set_day(nday);
	d1.set_month(nmonth);
	d1.set_year(nyear);
	d1.check_date();
	cout << d1;
	
	

} 


int main()
{
	string full_date;
	cout << "Actividad 21-sep por |Adrian Alejandro Montes Mendoza| |22110135|" << endl;
	cout << "Ingrese una fecha con el formato 'dd-mm-aaaa' o 'dd/mm/aaaa' " << endl;
	getline(cin, full_date);
	split_str(full_date);
	
}
