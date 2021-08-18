#include <string>
#include <string.h>           // For memset()
#include <iostream>
#include <map>
#include <fstream>
#include <vector>

// Sorry, but the `std::` everywhere makes it almost unreadable! 
using namespace std;

// Split string
vector<string> split(string str, char delimiter) {
  vector<string> output;
  size_t substr_start = 0U;
  size_t substr_end = str.find(delimiter);

  // Create substring at start of delimiter until end of string 
  while (substr_end != string::npos) {
    output.push_back(str.substr(substr_start, substr_end - substr_start));
    substr_start = substr_end + 1;
    substr_end = str.find(delimiter, substr_start);
  }
  // Get last string after last delimiter until null terminator
  size_t it = str.find('\0', substr_start);
  output.push_back(str.substr(substr_start, it - substr_start));
  return output;
}

// Read-only stream
ifstream openFile(string filename) {
  ifstream file;

  file.open(filename);
  if (file.is_open()) {
    return file;
  }
}

map<string, string> deserialisePhonebook(istream& file) {
  map<string, string> phonebook;
  char line[27];

  if (!file) {
    cout << "Error opening file `contacts.csv`";
    return phonebook;
  }

  // Read each line, split it and add each key-value pair to a map
  while (file.getline(line, 27, '\n')) {
    string line_str(line, 27);
    vector<string> split_str = split(line_str, ',');
    phonebook.insert(pair<string,string>(split_str[0], split_str[1]));

    // Reset char array values
    memset(line, 0, 27);
  }
  return phonebook;
}

void phoneDirectory(void) {
	string input;
  map<string, string> phonebook;
  ifstream file;
  
  file = openFile("contacts.csv");
  phonebook = deserialisePhonebook(file);
  file.close();

  cout << "Please enter a name or number to search: ";
  getline(cin, input);
  cout << "Searching " << phonebook.size() << " records...\n\n";

  // Search keys
  auto it = phonebook.find(input);
  if (it != phonebook.end()) {
    cout << "Contact details:\n";
    cout << it->first << ", T: " << it->second;
    return;
  }

  // Search values
  for (const auto& [key, value] : phonebook) {
    if (value == input) {
      cout << "Contact details:\n";
      cout << key << ", T: " << value;
      return;
    }
  }

  cout << "Contact not found\n";
}


void dataFileParser(void) {
	cout << " - dataFileParser: not yet implemented\n\n";
}