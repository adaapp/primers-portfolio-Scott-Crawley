#include <iostream>
#include <string>

/* ====================== PRIMER 9 ====================== */

class Car {
  private:
    std::string colour;
    std::string make;
    bool engine_state;
    bool locked_state;

    std::string engine_word() { return engine_state ? "Running" : "Off"; }
    std::string locked_word() { return locked_state ? "Locked" : "Unlocked"; }

    void engine_toggle(bool state) {
      if (engine_state == state) {
        std::cout << "Sorry, the engine is already " << engine_word() << "\n";
        return;
      }
      engine_state = state;
      std::cout << "Turning the engine " << engine_word() << "\n";
    }
  public:
    Car(std::string _colour, std::string _make) {
      colour        = _colour;
      make          = _make;
      engine_state  = false;
      locked_state  = true;
    }

    void set_colour(std::string value) { colour = value; }
    std::string get_colour(void) { return colour; }

    void set_make(std::string value) { make = value; }
    std::string get_make(void) { return make; }

    void engine_on(void) { engine_toggle(true); }
    void engine_off(void) { engine_toggle(false); }

    void locked(bool state) {
      if (locked_state == state) {
        std::cout << "Sorry, the car is already " << locked_word() << "\n";
        return;
      }
      locked_state = state;
      std::cout << "The car has been " << locked_word() << "\n";
    }

    void status(void) { 
      std::cout << "Car Status: ";
      std::cout << "colour: " << colour << ", make: " << make;
      std::cout << ", engine: " << engine_word() << ", " << locked_word() << "\n";
    }
};

void carMenu(Car car) {
  std::string input;
  char choice = '1';

  while (choice != '0') {
    car.status();
    std::cout << "1. Turn Engine On\n";
    std::cout << "2. Turn Engine Off\n";
    std::cout << "3. Lock Car\n";
    std::cout << "4. Unlock Car\n";
    
    std::cout << "Please select an option (or 0 to finish): ";
    getline(std::cin, input);
    choice = input[0];

    switch (choice) {
      case '0':
        return;
      case '1':
        car.engine_on();
        break;
      case '2':
        car.engine_off();
        break;
      case '3':
        car.locked(true);
        break;
      case '4':
        car.locked(false);
        break;
      default:
        std::cout << "Invalid Option\n";
    } 
  }
}

void carClass(void) {
	Car car("Red", "Ferrari");
  carMenu(car);
}

/* ====================== PRIMER 10 ====================== */

void areaOf(void) {
		std::cout << " - areaOf: not yet implemented\n\n";
}