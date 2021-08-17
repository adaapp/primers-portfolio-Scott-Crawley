#include <ctype.h>

int calculatePasswordStrength(std::string pwd) {
  int alphabetic  = 0;
  int digit       = 0; 
  int special     = 0;
  int length      = pwd.length();

  // <ctype.h> isalpha / isdigit
  for (int i = 0; i < length; i++) {
    char c = pwd[i];
    if (isalpha(c)) {
      alphabetic++;
    }
    else if (isdigit(c)) {
      digit++;
    }
    else {
      // Neither letter or number; it's a special char
      special++;
    }
  }

  // Determine strength
  if (length >= 8 && digit >= 2 && alphabetic >= 4) {
    // Ternary: no special chars = 'Strong', otherwise 'Very Strong'
    return special != 0 ? 4 : 3;
  }
  if (length >= 4) {
    // 'Moderate' if mixed, 'Weak' if same (length is equal to any singular type) 
    if (!(alphabetic == length || digit == length || special == length)) {
      return 2;
    }
  }
  return 1;
}

void passwordComplexityChecker(void) {
  std::string pwd;
  std::string strength;

	std::cout << "Enter a password: ";
  std::cin >> pwd;

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
  std::cout << "The password '" << pwd << "' is " << strength;
}

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
  
  auto it = find(employees.begin(), employees.end(), input);
  if (it != employees.end()) {
    employees.erase(it);
  }
  
  printEmployees(employees);
}
