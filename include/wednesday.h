#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <vector>

/* ====================== SHARED ====================== */

// Sorry, but the `std::` everywhere makes it almost unreadable! 
using namespace std;

// Read-only stream
ifstream openFile(string filename) {
  ifstream file;

  file.open(filename);
  return file;
}

/* ====================== PRIMER 5 ====================== */

struct contactResult {
  // Array of contacts (supports duplicates)
  vector<vector<string>> foundContacts;
  int totalContacts;
};

contactResult searchPhonebook(istream& file, string input) {
  vector<vector<string>> foundContacts;
  contactResult result;
  string name   = "";
  string number = "";
  int totalNums = 0;

  if (!file) {
    cout << "Error opening file `contacts.csv`";
    return result;
  }

  // Divide each line by comma separator, compare to input
  while (!file.eof()) {
    getline(file, name, ',');
    getline(file, number);

    if (name == input || number == input) {
      vector<string> v{ name, number };
      foundContacts.push_back(v);
    }
    totalNums++;
  }

  // Return custom struct that includes contact + total contacts (for output reasons)
  result.foundContacts = foundContacts;
  result.totalContacts = totalNums;
  return result;
}

void phoneDirectory(void) {
	string input;
  ifstream file;
  contactResult result;
  
  cout << "Please enter a name or number to search: ";
  getline(cin, input);

  // Open and search file
  file = openFile("contacts.csv");
  result = searchPhonebook(file, input);
  file.close();
 
  // Output results
  cout << "Searched " << result.totalContacts << " records.\n\n";
  if (result.foundContacts.size() > 0) {
    cout << "Contact details:\n";
    for (vector<string>& contact : result.foundContacts) {
      cout << contact[0] << ", T: " << contact[1] << "\n";
    }
    return;
  }
  cout << "Contact not found\n";
}

/* ====================== PRIMER 6 ====================== */

/*  -Breakdown-
* vector<vector<string>>:
* vector<              > = Table
*        vector<string>  = Line
*/
vector<vector<string>> deserialiseSalaries(istream& file) {
  const size_t initialSize  = 7; 
  size_t nameMaxSize        = 0;
  size_t salaryMaxSize      = 0;

  string firstname;
  string lastname;
  string salary;
  string initial;

  vector<vector<string>> salaries;

  if (!file) {
    cout << "Error opening file `salaries.csv`";
    return salaries;
  }

  // Get max lengths and store values as vectors (so we only read the file once)
  while (!file.eof()) {
    getline(file, firstname, ',');
    getline(file, lastname, ',');
    getline(file, salary);

    initial = firstname[0];
    initial += '.';
    initial.resize(initialSize + 1, ' ');

    if (lastname.length() > nameMaxSize) {
      nameMaxSize = lastname.length();
    }
    if (salary.length() > salaryMaxSize) {
      salaryMaxSize = salary.length();
    }

    vector<string> v{ initial, lastname, salary };
    salaries.push_back(v);
  }
    
  // Format strings
  for (vector<string>& line : salaries) {
    line[1].resize(nameMaxSize + 1, ' ');
    line[2].resize(salaryMaxSize + 1, ' ');
  }

  return salaries;
}

void printTable(vector<vector<string>> table) {
  size_t initialSize;
  size_t nameSize;
  size_t salarySize;
  string separator = "";

  // Output table header
  initialSize = table[0][0].length();
  nameSize    = table[1][1].length();
  salarySize  = table[2][2].length();

  string col1("Initial");
  string col2("Last");
  string col3("Salary");

  col1.resize(initialSize, ' ');
  col2.resize(nameSize, ' ');
  col3.resize(salarySize, ' ');
  
  cout << col1 << col2 << col3 << "\n";

  // Output separators
  separator.resize(initialSize + nameSize + salarySize, '-');
  cout << separator << "\n";

  // Output formatted table
  for (const vector<string>& line : table) {
    cout << line[0] << line[1] << "£" << line[2] << "\n";
  }
}

void dataFileParser(void) {
	ifstream file;
  vector<vector<string>> table;

  file = openFile("salaries.csv");
  table = deserialiseSalaries(file);
  file.close();

  printTable(table);
}