#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	double a1, a2, a3, a0, b2, b1, b0, delta, x1, x2, y1, y2, r, s, m, t, num_solution; //Using appropriate data types, declare a3, a2, a1, a0, b2, b1, b0, Delta, x1, x2, y1, y2, r, s, m, t, num_solution, stop; 
	//Ask the user politely to input a3, a2, a1, a0;

	cout << "Please enter a number for a3 : ";
	cin >> a3;
	cout << endl;
	cout << "Please enter a number for a2 : ";
	cin >> a2;
	cout << endl;
	cout << "Please enter a number for a1 : ";
	cin >> a1;
	cout << endl;
	cout << "Please enter a number for a0 : ";
	cin >> a0;
	cout << endl;

	while (cin) //If a3 is no greater than zero,Output ¡°Invalid input¡±; Terminate;

	{
		if (a3 <= 0)
		{
			cout << "Invalid input" << endl;
			system("pause");
			return 0;
		}


		//b2 = (3)(a3); b1 = (2)(a2); b0 = a1; Delta = (b1)2 ¨C(4)(b2)(b0);

		else
		{
			b2 = 3 * a3;
			b1 = 2 * a2;
			b0 = a1;

			delta = pow(b1, 2) - 4 * b2 * b0;
		}

		//If Delta is no greater than 0num_solution = 1,

		if (delta <= 0) {
			num_solution = 1;
			cout << num_solution << endl;
		}
		else { //Otherwise, x1 = [-b1 ¨C square_root(Delta)] / [(2)(b2)]; x2 = [-b1 + square_root(Delta)] / [(2)(b2)]; y1 = (a3)(x1)3 + (a2)(x1)2 + (a1)(x1)+a0; y2 = (a3)(x2)3 + (a2)(x2)2 + (a1)(x2)+a0;

			x1 = (-b1 - sqrt(delta)) / (2 * b2);
			x2 = (-b1 + sqrt(delta)) / (2 * b2);
			y1 = a3 * pow(x1, 3) + a2 * pow(x1, 2) + a1 * x1 + a0;
			y2 = a3 * pow(x2, 3) + a2 * pow(x2, 2) + a1 * x2 + a0;

			// If y1 and y2 are both positive, num_solution = 1
			if (y1 > 0 && y2 > 0) {
				num_solution = 1;
			}
			// f y1 and y2 are both negative num_solution = 1
			else if (y1 < 0 && y2 < 0) {
				num_solution = 1;
			}
			//If one of y1 and y2 is 0 num_solution = 2
			else if (y1 == 0 || y2 == 0) {
				num_solution = 2;
			}
			//If both y1 and y2 are 0 Output ¡°Precision error¡±; Terminate;
			else if (y1 == 0 && y2 == 0) {

				cout << "Precision error" << endl;
				return 0;
			}
			//If y1 is positive and y2 is negative num_solution = 3
			else if (y1 > 0 && y2 < 0) {
				num_solution = 3;
			}
			//    If y1 is negative and y2 is positive num_solution = 3

			else if (y1 < 0 && y2 > 0) {
				num_solution = 3;
			}
			// Output num_solution;
			cout << num_solution << endl;
		}

		//If num_solution is 1
		if (num_solution == 1) {
			s = 1;
			while (a3 * pow(s, 3) + a2 * pow(s, 2) + a1 * s + a0 <= 0)
				s *= 2;

			r = -1;
			while (a3 * pow(r, 3) + a2 * pow(r, 2) + a1 * r + a0 >= 0)
				r *= 2;


			double y_m;
			bool stop = false;
			while (stop == false) {
				m = (r + s) / 2;
				y_m = (a3 * pow(m, 3) + a2 * pow(m, 2) + a1 * m + a0);
				if (y_m == 0 || (s - r) < 0.000001) {
					t = m;
					cout << setprecision(6) << fixed << t << endl;
					stop = true;
				}

				else if (y_m > 0)
					s = m;

				else if (y_m < 0)
					r = m;

			}
		}
		system("pause");
		return 0;

	}
}