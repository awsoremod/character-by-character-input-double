#include <conio.h>
#include <iostream>

using namespace std;

#define a 5  // Количество цифр перед точкой
#define b 5  // Количество цифр после точки 
#define c 5  // Количество цифр после e

int main()
{
	setlocale(LC_ALL, "Russian");

	char k;
	string s;

	s.clear();
	while (true)
	{
		k = _getch();
		if ((k == 8) && (s.empty() == false))       // backspace если есть символы 
		{
			cout << "\b \b";
			s.pop_back();     // удаляет последний символ 
		}
		if (                                                  // точки
			(((k == 47) || (k == 46) || (k == 44) || (k == -18) || (k == -95) || (k == -98) || (k == -127))
				// можно ставить если не начало строки и если нет точек    и   если нет е     и если предыдущим символом был не минус
				&& ((s.find(',') == -1) && (s.empty() == false) && (s.find('e') == -1) && (s[s.length() - 1] != '-'))
				// ешки 
				) || (((k == 116) || (k == 101) || (k == 84) || (k == 69) || (k == -91) || (k == -29) || (k == -109) || (k == -123))
					//     можно ставить если не начало строки и если нет е и если предыдущий не точка и если первый минус то вторым символом нельзя ставить е
					&& ((s.empty() == false) && (s.find('e') == -1) && (s[s.length() - 1] != ',') && (((s[0] == '-') && (s.length() > 1)) || (s[0] != '-')))
					//      минус можно ставить в начало строки или если предыдущий символ е
					) || ((k == '-') && ((s.empty() == true) || (s.find('e') == s.length() - 1))
						//        цифры
						) || (((k > 47) && (k < 58))
							&& (
								// если есть точка и нет е. не более 5 символов после точки
								((s.find(',') != -1) && (s.length() - s.find(',') < b+1) && (s.find('e') == -1))
								//   если есть е        и нет минуса после нее то не более 2 символов если есть минус не более 3
								|| ((s.find('e') != -1) && ((s.length() < s.find('e') + c+1) || ((s[s.find('e') + 1] == '-') && (s.length() < s.find('e') + c+2))))
								//    если нет е и точки       и нет вначале минуса не более 5 символов если есть не более 6
								|| ((s.find(',')) && (s.find('e') == -1) && ((s.length() < a) || ((s[0] == '-') && (s.length() < a+1))))
								)
							)
			)
		{
			if ((k == 47) || (k == 46) || (k == 44) || (k == -18) || (k == -95) || (k == -98) || (k == -127))   // точки
			{
				k = 44;             
				cout << ".";
			}
			else
			{
				if (((k == 116) || (k == 101) || (k == 84) || (k == 69) || (k == -91) || (k == -29) || (k == -109) || (k == -123)))
				{
					k = 101;         // все ешки на англ. маленькую e 
				}
				cout << k;
			}
			s.push_back(k);
		}
		else
		{          // пробел      enter    нельзя нажимать если начало строки     после точки             после е                                после минуса
			if (((k == ' ') || (k == 13)) && (s.empty() == false) && (s.length() - 1 != s.find(',')) && (s.length() - 1 != s.find('e')) && (s.find('-') != s.length() - 1))
			{
				//vec.push_back(atof(s.c_str()));
				cout <<"\n"<< atof(s.c_str());
				break;
			}
		}
	}
}
