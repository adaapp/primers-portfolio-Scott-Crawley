#include <chrono>
#include <thread>

/* ============ PRIMER 7 ============ */

void sleep(int seconds = 10) {
  const int ms = seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void sleepTimer(void) {
  // Lambda is required for optional parameters
  std::thread t( []{ sleep(); });

  // Block thread (essentially an 'await')
  t.join();
}

/* ============ PRIMER 8 ============ */

void timer1(int seconds = 5) {
  std::cout << "Thread 1: " << std::this_thread::get_id() << " started\n";
  const int ms = seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  std::cout << "Thread 1: " << std::this_thread::get_id() << " ended\n";
}

void timer2(int seconds = 10) {
  std::cout << "Thread 2: " << std::this_thread::get_id() << " started\n";
  const int ms = seconds * 1000;
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  std::cout << "Thread 2: " << std::this_thread::get_id() << " ended\n";
}

void joinDetachThreads(void) {
	std::cout << "Main thread: " << std::this_thread::get_id() << " started\n";
  
  // Start async timer threads
  // Lambda; see Primer 7
  std::thread thread1( []{ timer1(); });
  std::thread thread2( []{ timer2(); });
  
  // Subscribe to async timer threads (blocking main thread)
  // thread2 -> thread1 for expected/example output (essentially an 'await')
  thread2.join();
  thread1.join();

  // Continue processing on main thread (unblock)
  std::cout << "Main thread: " << std::this_thread::get_id() << " ended\n";
}