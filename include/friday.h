#include <iostream>
#include <string>

/* ====================== PRIMER 9 ====================== */

class Car {
  private:
    std::string colour;
    std::string make;
    bool engine_state;
    bool locked_state;

    std::string engine_word() { return engine_state ? "On" : "Off"; }
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
    std::cout << "\n";
  }
}

void carClass(void) {
	Car car("Red", "Ferrari");
  carMenu(car);
}

/* ====================== PRIMER 10 ====================== */

int shapeDeletions = 0;

class Shape {
  public:
    ~Shape() { shapeDeletions++; }
};
class Circle: public Shape {
  public:
    float radius;
    Circle() { 
      radius  = 10; 
    }
    Circle(float _radius) { 
      radius  = _radius;
    }
};
class Square: public Shape {
  public:
    float length;
    Square() { 
      length  = 10; 
    }
    Square(float _length) { 
      length  = _length; 
    }
};
class Rectangle: public Shape {
  public:
    float width;
    float height;
    Rectangle() { 
      width   = 10; 
      height  = 10;
    }
    Rectangle(float _width, float _height) { 
      width   = _width; 
      height  = _height;
    }
};
class Triangle: public Shape {
  public:
    float base;
    float height;
    Triangle() {
      base    = 10; 
      height  = 10;
    }
    Triangle(float _base, float _height) { 
      base    = _base;
      height  = _height;
    }
};
class Trapezoid: public Shape {
  public:
    float base;
    float height;
    float tbase;
    Trapezoid() { 
      base    = 10;
      height  = 10;
      tbase   = 10;
    }
    Trapezoid(float _base, float _height, float _tbase) { 
      base    = _base;
      height  = _height;
      tbase   = _tbase;
    }
};

class AreaOf {
  private:
    const float PI = 3.14159;
  public:
    float size(Circle c)      { return PI*(c.radius * c.radius); }
    float size(Square s)      { return s.length * s.length; }
    float size(Rectangle r)   { return r.width * r.height; }
    float size(Triangle tl)   { return (tl.base * tl.height) / 2; }
    float size(Trapezoid tz)  { return ((tz.base + tz.tbase) / 2) * tz.height; }
};

void areaOf(void) {
  AreaOf areaOf;
  Circle c(4.5);
  Square s(6.1);
  Rectangle r(4, 5.9);
  Triangle tl(8, 12);
  Trapezoid tz(14, 7.5, 6);
  
  // Hardcoded - would require several degrees more complexity to neaten up
  std::cout << "Area of Circle(r = 4.5): " << areaOf.size(c) << "\n";
  std::cout << "Area of Square(a = 6.1): " << areaOf.size(s) << "\n";
  std::cout << "Area of Rectangle(w = 4, l = 5.9): " << areaOf.size(r) << "\n";
  std::cout << "Area of Triangle(b = 8, h = 12): " << areaOf.size(tl) << "\n";
  std::cout << "Area of Trapezoid(b = 14, h = 7.5, a = 6): " << areaOf.size(tz) << "\n";

  // Just to demonstrate the deletions and inheritance:
  // Should always be 5
  std::cout << "\nTotal Shapes Deleted: " << shapeDeletions << "\n";
}