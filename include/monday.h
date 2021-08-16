#include <ctype.h>

void fahrenheitCentigradeConversion(void) {
  using namespace std;

  float temp  = 0.0;
  char choice = '0';

	cout << "Please enter the starting temperature: ";
  cin >> temp;
  cout << "Press 'C' to convert from Fahrenheit to Centigrade." << endl;
  cout << "Press 'F' to convert from Centigrade to Fahrenheit." << endl;
  cin >> choice;

  if (tolower(choice) == 'c') {
    cout << "";
  } else if (tolower(choice) == 'f') {
    cout << "";
  } else {
    cout << "Not a valid option";
  }
}

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

