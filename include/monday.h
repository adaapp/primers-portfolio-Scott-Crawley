#include <ctype.h>
#include <math.h>

/* ====================== PRIMER 1 ====================== */

/* Fahrenheit to Centigrade */
float ftoc(float temp) {
  return (temp - 32) * 5 / 9;
}

/* Centigrade to Fahrenheit */
float ctof(float temp) {
  return (temp * 9 / 5) + 32;
}

/* Fahrenheit to Kelvin */
float ftok(float temp) {
  return (temp + 459.67) * 5 / 9;
}

/* Centigrade to Kelvin */
float ctok(float temp) {
  return temp + 273.15;
}

void converterChoice(float temp, char choice) {
  using namespace std;

  float conv  = 0.0;
  long  kelv  = 0.0;
  float abs0  = 0.0;
  string from;
  string to;

  // Choice evaluation (with case insensitivity)
  choice = tolower(choice);
  switch (choice) {
    case 'c':
      kelv = ftok(temp);
      conv = ftoc(temp);
      abs0 = -273.15;
      from = "Fahrenheit";
      to   = "Centigrade";
      break;
    case 'f':
      kelv = ctok(temp);
      conv = ctof(temp);
      abs0 = -459.67;
      from = "Centigrade";
      to   = "Fahrenheit";
      break;
    default:
      cout << "Not a valid option\n";
  }
  cout << temp << " degrees " << from << " is " << conv << " " << to << "\n";
  cout << "Or " << kelv << " Kelvin\n";

  // Figure out if it's below 'absolute zero' (impossible)
  if (conv < abs0) {
    cout << "Breaks the laws of physics!\n";
  }
}

void fahrenheitCentigradeConversion(void) {
  using namespace std;
 
  float temp  = 0.0;
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

  // Conversion mode
  cout << "\nPress 'C' to convert from Fahrenheit to Centigrade.\n";
  cout << "Press 'F' to convert from Centigrade to Fahrenheit.\n\n";
  cout << "Your choice: ";
  cin >> choice;
  converterChoice(temp, choice);
}

/* ====================== PRIMER 2 ====================== */

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
      try {
        cost = stof(input);
      }
      catch (invalid_argument ignored) {
        cout << "Invalid integer: assuming price of £0.00\n";
      }
      
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
