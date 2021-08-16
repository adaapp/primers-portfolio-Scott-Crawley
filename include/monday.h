#include <ctype.h>
#include <math.h>

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
  int quantity    = 1;
  float cost      = 0.0;
  float subtotal  = 0.0;
  float total     = 0.0;
  float tax       = 0.0;
  string input    = "1";

  // Prompt user continuously until they enter 0
  while (quantity != 0) {
    cout << "Please enter a quantity for item " << itemNum << " (or 0 to finish): ";
    cin >> input;
    quantity = stoi(input);

    // Ensure it doesn't prompt for a price if they enter 0 for quantity
    if (quantity != 0) {
      cout << "Please enter item " << itemNum << "'s cost: ";
      cin >> input;
      cost = stof(input);
      
      subtotal += (quantity * cost);
      itemNum++;
    }
  }

  // Calculate final values (and format to 2dp for subtotal)
  subtotal  = roundf(subtotal * 100) / 100;
  tax       = roundf(subtotal * (5.5 / 100) * 100) / 100;
  total     = roundf((subtotal + tax) * 100) / 100;

  // Output
  cout << "Thank you.\n\n";
  cout << "Subtotal: £" << subtotal << "\n";
  cout << "Shopping Tax: £" << tax << "\n\n";
  cout << "Total: £" << total << "\n\n";
}
