#include <string>
#include <iostream>
#include <map>
#include <fstream>

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

map<string, string> deserialisePhonebook(ifstream file) {
  map<string, string> phonebook;
  char line[128];

  // Read each line, split it and add each key-value pair to a map
  while (file.getline(line, 128)) {
    string line_str(line, 128);
    vector<string> split_str = split(line_str, ',');
    phonebook.insert(pair<string,string>(vector[0], vector[1]));
  }
  file.close();
  return phonebook;
}

void phoneDirectory(void) {
	string input;
  
  ifstream file = openFile("contacts.csv");
  map<string, string> phonebook = deserialisePhonebook(file);

  cout << "Please enter a name or number to search: ";
  cin >> input;
  cout << "Searching " << phonebook.size() << " records...";

  // Search keys
  auto it = phonebook.find(input);
  if (it != phonebook.end()) {
    cout << it->first << ", T: " << it->second;
    return;
  }

  // Search values
  for (const auto& [key, value] : phonebook) {
    if (value == input) {
      cout << key << ", T: " << value;
    }
  }
}


void dataFileParser(void) {
	cout << " - dataFileParser: not yet implemented\n\n";
}