#include <ctype.h>

/* ====================== PRIMER 3 ====================== */

int calculatePasswordStrength(std::string pwd) {
  int alphabetic  = 0;
  int digit       = 0; 
  int special     = 0;
  int length      = pwd.length();

  for (char& c : pwd) {
    if (isalpha(c)) {
      alphabetic++;
    }
    else if (isdigit(c)) {
      digit++;
    }
    else {
      special++;
    }
  }

  // Determine strength
  // Ternary: no special chars = 'Strong', otherwise 'Very Strong'
  if (length >= 8 && digit >= 2 && alphabetic >= 4) {
    return special == 0 ? 3 : 4;
  }
  // Ensure mixed character types for 'Moderate'
  // Ternary: ensure length is greater/equal to 4 before returning 'Moderate'
  if (!(alphabetic == length || digit == length || special == length)) {
    return length < 4 ? 1 : 2;
  }
  return 1;
}

void passwordComplexityChecker(void) {
  std::string pwd;
  std::string strength;

	std::cout << "Enter a password: ";
  getline(std::cin, pwd);

  switch (calculatePasswordStrength(pwd)) {
    case 1:
      strength = "Weak";
      break;
    case 2:
      strength = "Moderate";
      break;
    case 3:
      strength = "Strong";
      break;
    case 4:
      strength = "Very Strong";
      break;
    default:
      strength = "U broke it";
  }
  std::cout << "The password '" << pwd << "' is " << strength << "\n";
}

/* ====================== PRIMER 4 ====================== */

void printEmployees(std::vector<std::string> employees) {
  int len = employees.size();
  std::cout << "\nThere are " << len << " employees:\n";
  for (std::string e : employees) {
    std::cout << e << std::endl;
  }
}

void employeeListRemoval(void) {
	using namespace std;

  string input;
  vector<string> employees = { "John Smith", "Jaelynn Stuart", "Kaley Barajas", 
                               "Walter Collier", "Cale Myers" };

  printEmployees(employees);  

  cout << "\nEnter an employee name to remove: ";
  getline(cin, input);
  
  // Use standard library's `find` and vector's `.begin()/.end()` functions
  // If returned iterator is not `.end()`, we found them and can erase them
  auto it = find(employees.begin(), employees.end(), input);
  if (it != employees.end()) {
    employees.erase(it);
  }
  
  printEmployees(employees);
}
