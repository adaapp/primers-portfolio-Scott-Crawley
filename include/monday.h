#include <ctype.h>

void fahrenheitCentigradeConversion(void) {
  using namespace std;
 
  float temp  = 0.0;
  float conv  = 0.0;
  string inp  = "0";
  char choice = '0';

  // Starting temp + looped numerical validation
  cout << "Please enter the starting temperature: ";
  while (true) {
    try {
      cin >> inp;
      temp = stoi(inp);
      break;
    } 
    catch (invalid_argument ignored) {
      cout << "Please enter a valid integer: ";
    }
  }

  // Conversion mode and choice evaluation (with case insensitivity)
  cout << "\nPress 'C' to convert from Fahrenheit to Centigrade.\n";
  cout << "Press 'F' to convert from Centigrade to Fahrenheit.\n\n";
  cout << "Your choice: ";

  cin >> choice;
  choice = tolower(choice);
  if (choice == 'c') {
    conv = (temp - 32) * 5 / 9;
    cout << temp << " degrees Fahrenheit is " << conv << " Centigrade\n";
    if (conv < -273.15) {
      cout << "Breaks the laws of physics!\n";
    }
  } 
  else if (choice == 'f') {
    conv = (temp * 9 / 5) + 32;
    cout << temp << " degrees Centigrade is " << conv << " Fahrenheit\n";
    if (conv < -459.67) {
      cout << "Breaks the laws of physics!\n";
    }
  } 
  else {
    cout << "Not a valid option\n";
  }
}

void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

