# Primer Portfolio

## Section 1 - Primer Challenges
### Primer 1 - Fahrenheit / Centigrade Conversion
This challenge requires us to allow a user to enter a value before selecting whether to convert it from Fahrenheit to Centigrade or Centigrade to Fahrenheit.  As part of the initial design the conversion algorithms were needed for both calculations. 

To help complete this challenge I needed to break the overall problem down into the following main tasks: 
* Get data from the user
* Verify the data is in a suitable format
* Create a method to convert F->C
* Create a method to convert C->F

Constraints:
- Upper and lowercase characters for C and F 
- Use as few output statements as possible

Additional Revisions:
- Prevent the user from continuing if the starting temperature is not numeric
- Support Kelvin
 
#### Reflection (as well as issues, challenges & resolutions)
I had no significant issues or challenges with this primer. Only the introduction of Kelvin proved more complex than I anticipated. Were I to add another option for the user to choose Kelvin -> Centigrade/Fahrenheit conversion, I would've needed to add **4 additional** functions and another case in the switch. Instead, to reduce complexity and lines of code, I added Kelvin conversion within the existing Fahrenheit/Centigrade converters; requiring only two functions instead.

### Primer 2 - Self-service Checkout
A simple Self-Service Checkout program to calculate the total cost of a number of items and a new 5.5% shopping tax.

Example output:
```Please enter a quantity for item 1 (or 0 to finish): 3
Please enter item 1’s cost: 0.99
Please enter a quantity for item 2 (or 0 to finish): 2
Please enter item 2’s cost: 1.50
Please enter a quantity for item 3 (or 0 to finish): 1
Please enter item 3’s cost: 2.99
Please enter a quantity for item 3 (or 0 to finish): 0
Thank you.
Subtotal: £8.96
Shopping Tax: £0.4928
Total: £9.4528
```
Constraints:
- Store the shopping tax as a constant of 5.5.

Expansion:
- Values are rounded to two decimal places; for example: £0.4928 becomes: £0.49.

#### Reflection (as well as issues, challenges & resolutions)
I had no significant issues or challenges with this primer. The single piece of functionality requiring most debugging was the 2 decimal point rounding as this required, counter-intuitively, multiplying the value by 100 and then dividing by 100 after rounding. By removing this, the value is rounded to the nearest whole number.  

### Primer 3 - Password Complexity Checker
This challenge requires the development of a password's complexity checker with the following criteria:
• Weak (value: 1) – only numeric or only alphabetic characters
• Moderate (value: 2) – at least 4 characters and is not ‘Weak’, ‘Strong’ or ‘Very Strong’
• Strong (value: 3) – at least 8 characters; including at least 2 numeric and at least 4 alphabetic
• Very Strong (value: 4) – at least 8 characters; including at least 2 numeric, at least 4 alphabetic and 1 special

Example Output:
```The password ‘12345678’ is Weak
The password ‘AB235’ is Moderate
The password ‘Password2021’ is Strong
The password ‘Password2021!’ is Very Strong
```

Constraints:
- Calculation function that accepts a password as a passed argument and returns the value as an integer
- Use a single output statement to display the result

#### Reflection (as well as issues, challenges & resolutions)
The password complexity checker required significant thought to determine the most efficient and least cognitively-complex method of implementation. Given the chained conditionals and the relationships between them, formatting was a top-most priority to ensure readability. I opted for a switch statement when translating the calculation into a string due to this. For the calculation itself, evaluating the password required if-statements - some even nested. To clean this up, I opted for a ternary operator when deciding between the 'Strong' and 'Very Strong' distinctions and a terminating nested if-statement for 'Moderate' which allowed for an unwrapped default return in the case of 'Weak'. 

I'm still not the most happy with the calculation conditionals but was unable to find a cleaner and equally efficient way to implement it.  

### Primer 4 - Employee List Removal
Tasked with: displaying a list of employee names, prompting the user for an employee name and then removing that name from the list; displaying the remaining names, each on its own line, once complete.

Example output:
```There are 5 employees:
John Smith
Jaelynn Stuart
Kaley Barajas
Walter Collier
Cale Myers

Enter an employee name to remove: Jaelynn Stuart
There are 4 employees:
John Smith
Kaley Barajas
Walter Collier
Cale Myers`
```

Constraints:
- Using with and dealing with arrays and their constraints

#### Reflection (as well as issues, challenges & resolutions)
Given the immutability of C++ arrays, I opted for an std::vector instead. This provided the most flexibility when it came to querying the number of elements, modification and passing by reference. Using an array required passing a pointer as a parameter to other functions; removing the metadata - such as number of elements - you'd otherwise be able to get in the scope it was declared in. Although memcpy/memset/remove could be used to modify the array, this would be unsafe, incur overhead and still doesn't fix the requirement of needing the original array's size. Vectors, on the other hand, have instance methods to get its size and to modify its contents without issue.

### Primer 5 - Phone Directory
Using an external data stream to permanently hold phone contacts, a user prompt should ask for either a name or phone number and provide any matched record(s).

Example Output:
```Please enter a name or number to search: 0203 105 0125
Searching 10 records ...
Contact details:
Ada College, T: 0203 105 0125
--OR—
Please enter a name or number to search: Ada College
Searching 10 records ...
Contact details:
Ada College, T: 0203 105 0125
--OR—
Please enter a name or number to search: 0203 105 0120
Searching 10 records ...
Sorry, no contact details found`
```

Constraints:
- The contact name or number must use a single input 
- The system must display the total number of records searched (based on the contacts present in the data file) 
- The user should be advised if no match was found

#### Reflection (as well as issues, challenges & resolutions)
The Phone Directory challenge has been the most difficult so far. This is due to requiring several independent and generalised methods to implement its functionality: IO functionality, phonebook deserialisation and a string splitter using a specified delimiter. Fortunately, these components can be re-used for Primer 6 (and potentially others) but their introduction increases the codebase and therefore the testing needed.

### Primer 6 - Data File Parser
Read and parse the following data from a file; using a formatted table to display its output:

- Noak,Jaylinn,21500
- Apollinaire,Venkata,29250
- Faith,Mara,30000
- Yasamin,Shukriyya,44500
- Zahir,Marcel,31200
- Maia,Ela,45600
- Liam,Oliver,43300
- Luka,Jones,45600
- Alexander,Smith,20500

Example Output:
```
Initial  Last            Salary
-------- --------------- -----------
N.       Jaylinn         £21500
A.       Venkata         £29250
F.       Mara            £30000
Y.       Shukriyya       £44500
Z.       Marcel          £31200
M.       Ela             £45600
L.       Oliver          £43300
L.       Jones           £45600
A.       Smith           £20500
```

Constraints:
- Do not use existing libraries or code for parsing/formatting
- Ensure columns are one space longer than longest value 

#### Reflection (as well as issues, challenges & resolutions)
Despite looking simple at first glance, this challenge required significant thought in order to maximise performance. Due to requiring the longest value to format the final output, the data needs to be iterated over once to determine that and again when formatting. I wanted to avoid reading all the data a second time but thought this was originally the only solution due to requiring a char array (buffer) of fixed size to imitate the space-formatted table. 

Fortunately, `std::string`'s have the `.resize()` method. Once I discovered this, I reformatted the code to instead only read the data from the file once, store it in a `vector<std::string>` and later resize each string in the vector corresponding to the longest value. Not only was this neater, it's also significantly faster than nested or duplicated IO operations. 

### Primer 7 - Sleep Timer
Using threads, asynchronously sleep for 10 seconds. Await the completion of this sleep timer on the main thread.

Example Output:
```
N/A
```

Constraints:
- The number of seconds to sleep for should be an optional parameter set, by default, to 10 seconds
- Use `this_thread` to block the execution on the appropriate thread 

#### Reflection (as well as issues, challenges & resolutions)
This task was very simple. However, passing optional parameters to a function passed-by-reference (such as in the constructor of the `std::thread` object) requires careful consideration. The second argument in the `std::thread` constructor takes the parameter for the function reference you provide it. In the case of an optional parameter, leaving this argument empty will throw an error. In order to get around this, I had to use a lambda and make a direct call as opposed to passing-by-reference. 

### Primer 8 - Joining & Detaching Threads (Part A)
Using threads, asynchronously sleep for 10 seconds. Await the completion of this sleep timer on the main thread.

Example Output:
```
N/A
```

Constraints:
- The number of seconds to sleep for should be an optional parameter set, by default, to 10 seconds
- Use `this_thread` to block the execution on the appropriate thread 

#### Reflection (as well as issues, challenges & resolutions)
This task was very simple. However, passing optional parameters to a function passed-by-reference (such as in the constructor of the `std::thread` object) requires careful consideration. The second argument in the `std::thread` constructor takes the parameter for the function reference you provide it. In the case of an optional parameter, leaving this argument empty will throw an error. In order to get around this, I had to use a lambda and make a direct call as opposed to passing-by-reference.

### Primer 8 - Joining & Detaching Threads (Part B)
Using threads, asynchronously sleep for 10 seconds. Detach the sleeping thread(s) from the main thread and continue with execution.

Example Output:
```
N/A
```

Constraints:
- The same timer functions should be used as Part A

#### Reflection (as well as issues, challenges & resolutions)
No changes between Part A and Part B. Main thread output completed before the sleeping thread output due to detaching and not awaiting for completion.

### Primer 9 - Car Class
Create a Car class with the following criteria and instantiate it:
- Private internal properties, variables, attributes
- Public methods:
  - void set_colour(string)
  - string get_colour(void)
  - void set_make(string)
  - string get_make(void)
  - void engine_on(void)
  - void engine_off(void)
  - void locked(bool)
  - void status(void)

Then create an interactive menu to make use of the car's methods.

Example Output:
```
Car Status: colour: Blue, make: Honda, engine: Off, Unlocked
1. Turn Engine On
2. Turn Engine Off
3. Lock Car
4. Unlock Car
Please select an option (or 0 to finish): 2
Sorry, the engine is already off
Car Status: colour: Blue, make: Honda, engine: Off, Unlocked
1. Turn Engine On
2. Turn Engine Off
3. Lock Car
4. Unlock Car
Please select an option (or 0 to finish): 1
Turning the engine on
Car Status: colour: Blue, make: Honda, engine: Running, Unlocked
1. Turn Engine On
2. Turn Engine Off
3. Lock Car
4. Unlock Car
Please select an option (or 0 to finish): 4
Sorry, the car is already unlocked
```

Constraints:
- Ensure Car constructor provides support to initialise the private properties
- Methods that result in no change to state should ignore requests
- Car interaction menu should not be part of the class

#### Reflection (as well as issues, challenges & resolutions)
I found no significant problems and faced no challenges for this task. During development, I opted to clean up the engine_on/off functions as well as the outputs by creating a 'parent' function which handles both functionality. This meant less code duplication and neater code.

Additionally, whilst still meeting the first constraint, I chose to exclude the two private boolean properties in the Car constructor; engine_state and locked_state. It made sense to me for these to default to off and locked after initialisation, also reducing the amount of code needed to instantiate a new object. This also prevents the logical issue of creating a car that is locked but has its engine is on.    

### Primer 10 - AreaOf
Create an 'AreaOf' class that provides a single method `.size()`. This method should differentiate and correctly calculate the area of 3 - 5 different shape types from the following:
- Rectangles
- Circles
- Squares
- Triangles
- Trapezoids 

Example Output:
```
Area of Circle (r = 4.5): 63.6172
Area of Square (a = 6.1): 37.21
Area of Rectangle (w = 4, l = 5.9): 23.6
Area of Triangle (b = 8, h = 12): 48
Area of Trapezoid (b = 14, h = 7.5, a = 6): 75
```

Constraints:
- Ensure all methods (except output related) are pure functions
- Must include constructor, destructor and overload methods

#### Reflection (as well as issues, challenges & resolutions)
Figuring out the underlying structure of the shape classes was the most challenging part of this task. I wanted to make use of inheritance to simplify the different shape objects and potentially make use of the superclass' properties in an output function to prevent the need for custom outputs for different shapes...

However, due to noticing the increasing complexity and over-engineering, I steered away from implementing the latter instead keeping inheritance exclusively for the destructor method. As much as I think it could be neater, due to the above the outputs were therefore hardcoded for each tested shape. This meant significantly less code and less cognitive complexity with the caveat being its inflexibility.

For the 'AreaOf' class itself, `.size()` was overflown with different parameter types; one for each shape. The corresponding method then calculated the area of that specific shape and returned it.   

---
## Section 2 - Programming Paradigms
### Programming Paradigms
Programming paradigms are approaches which a developer might adopt to create a piece of software or solve a problem. Paradigms are rarely language-dependent and instead dictate the underlying structure or layout of the code. Although there are many others, the paradigms I'll be discussing are split into one of two groups:

- Imperative
- Declarative

An imperative programming paradigm explicitly states in which order operations occur and allows for 'side-effects' or state changes between different parts of the code. The two most common examples of an imperative programming paradigm are 'Object-Orientated (OOP)/Structural' and 'Procedural' programming. 

OOP/Structural makes use of inheritance and polymorphism to control the exact order of operations as well as modification. Each object will contain its own state and should, typically, only be changed by code within itself, child classes and concrete classes. When implemented properly, this results in a well-structured control flow with little cognitive or code overhead and should make debugging easier due to the isolated state changes.

However, OOP is usually reliant on an appropriate Software Design Pattern for object management/processing. The objects themselves need to be instantiated and processed efficiently and, in most cases, are constructed using individual pieces of data generated elsewhere. When combined with an unsuitable design pattern, the benefits of OOP can very easily be negated and the juggling of objects more of a nuisance than an improvement - especially on lower memory systems.

In contrast, procedural programming is entirely based around the concept of procedures; code blocks that will complete a specific task every time they're called. This provides a good level of control whilst remaining very simple and is well-suited to 'general purpose programming' as well as independent library/module development. A side-effect of this simple structure also means a reduced memory footprint compared to other paradigms.

The drawback to procedural programming is, unlike OOP, the lack of room for scaling due to its precise and strict nature. Whereas OOP provides isolated objects to process with varying degrees of complexity, procedural programming demands compliance to its structure and puts a stronger focus on operation over data. This also means more tedious debugging as state manipulation is reliant on scope and is not as traceable/predictable as object-based state changes. 

A declarative programming paradigm is one that abstracts away control flow and logic for an action/process, instead stating what the outcome or process is. It is the direct opposite of an imperative programming paradigm and tries to minimise or eliminate side-effects. The two most common declarative paradigms are 'Purely Functional' and 'Logic' programming.

Purely functional programming treats functions as pure and deterministic. This requires that functions always return the exact same output given an identical input and will not be influenced by any mutable state. A clear benefit of this is the software's testability; no state has to be mocked and no instances configured when writing unit tests or when adopting a Test Driven Development approach. Others have claimed this paradigm also reduces bugs as functions are more predictable and minimise side-effects.

A common criticism of functional programming is the difficulty involved with upscaling. Due to the nature of functions being pure with no side-effects, greater degrees of complexity may be required to accommodate for increased demand. This will be particularly evident where concurrency is used/needed as that is fundamentally a stateful concept. Similarly, any reliance on I/O operations - another inherently stateful concept - will also break the core tenet of functional programming.

Logic programming focuses on 'formal logic' and, in most cases, explicitly states rules in the form of declarative clauses such as `canfly(X) :- bird(X), not abnormal(X).`. Due to its simple syntax, logic programming can be used for introductions to programming and in education but can also be scaled up, through chaining, into complex use-cases such as artificial intelligence or natural language processing. Once the rules are declared, a query will be run against the program and its output decided using the facts provided.

Fundamentally, logic programming is suited to a task - with only one explicit solution - that requires solving. As a result, this restricts the ability to develop solutions based on a generic problem or with multiple outcomes. Unlike the other paradigms discussed, logic programming will therefore typically be language dependent (with its own syntax), computationally inefficient (extensive comparisons/branches) and unable to transform, manipulate or mutate data in more traditional ways.

---
## Section 3 - Continued Professional Development
### Benefits of becoming a Polyglot Programmer
A polyglot programmer is someone who has technical competence in several programming languages and related tools. Usually, this will also be linked to a more holistic understanding of software development and programming concepts. As a result, polyglot programmers will tend to be more employable as most companies see this as an indication to easily adapt; an invaluable skill.

The other more explicit benefits to being a polyglot programmer are the opportunities it unlocks both professionally and when learning. Many programming languages will offer different approaches to solve problems, some usually being more suitable than others. Whilst the syntax might not, understanding the logic behind a solution is translatable between all languages and will build confidence universally. On the other hand, knowing the alternative approaches may prove beneficial when outlining requirements for a new project or if a company evolves its software engineering department and puts a greater focus on those approaches...

Due to being a malleable employee, an evolution like the above will also pose as a growth experience instead of a threat. Where a company might otherwise have to retrain or hire new specialists, a polyglot programmer will already have the flexibility to adjust to new tools and will often even have had the experience to be able to make full use of them. In some cases, changes like this can even accompany a better job position or pay rise.

Outside of the internal opportunities, polyglots also get a natural advantage in an already competitive industry. With the ever increasing number of software developer roles, multiple skills are even becoming required qualifications - web development alone requiring any/all of: PHP, CSS, HTML, JavaScript and TypeScript (+ its multiple frameworks). In these cases, being a polyglot is essentially required just to have your application reviewed. Integration Developers or Backend Developers are not exempt either as most are usually required to understand how to use database querying languages, microservices, message queues, data streaming platforms and more.

Above all else, being a polyglot demonstrates desirable personal qualities. By mastering a wide array of tools and languages, someone shows dedication, creativity, flexibility and will typically be happier due to the greater variety their career involves. All these characteristics are guaranteed to support a developer's career and even their out-of-work life by making them appealing to employers, colleagues and clients.  