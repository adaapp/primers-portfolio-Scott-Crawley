#include <ctype.h>

void fahrenheitCentigradeConversion(void) {

  using namespace std;
 
  float temp  = 0.0;
  float conv  = 0.0;
  long  kelv  = 0.0;
  string inp  = "0";
  char choice = '0';

  // Starting temp + looped numerical validation
  cout << "Please enter the starting temperature: ";
  while (true) {
    try {
      cin >> inp;
      temp = stof(inp);
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
    kelv = conv + 273.15;
    cout << temp << " degrees Fahrenheit is " << conv << " Centigrade\n";
    cout << "Or " << kelv << " Kelvin\n";
    if (conv < -273.15) {
      cout << "Breaks the laws of physics!\n";
    }
  } 
  else if (choice == 'f') {
    conv = (temp * 9 / 5) + 32;
    kelv = (conv + 459.67) * 5 / 9;
    cout << temp << " degrees Centigrade is " << conv << " Fahrenheit\n";
    cout << "Or " << kelv << " Kelvin\n";
    if (conv < -459.67) {
      cout << "Breaks the laws of physics!\n";
    }
  } 
  else {
    cout << "Not a valid option\n";
  }
}

void selfServiceCheckout(void) {

	using namespace std;

  int itemNum     = 1;
  int quantity    = 0;
  float cost      = 0.0;
  float subtotal  = 0.0;
  float tax       = 0.0;
  string input    = "1";

  // Prompt user continuously until they enter 0
  while (stoi(input) != 0) {
    cout << "Please enter a quantity for item " << itemNum << " (or 0 to finish): ";
    cin >> input;
    quantity = stoi(input);
    cout << "Please enter item " << input << "'s cost: ";
    cin >> input;
    cost = stof(input);
    
    subtotal += (quantity * cost);
    itemNum++;
  }

  // Calculate tax
  tax = subtotal * (5.5 / 100);

  // Output
  cout << "Thank you.\n";
  cout << "Subtotal: £" << subtotal << "\n";
  cout << "Shopping Tax: £" << tax << "\n";
  cout << "Total: £" << subtotal + tax;
}
