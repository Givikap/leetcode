#include <chrono>
#include <functional>
#include <thread>

class Foo {
private:
  uint state;

public:
  Foo() { state = 0; }

  void first(std::function<void()> printFirst) {
    printFirst();
    state = 1;
  }

  void second(std::function<void()> printSecond) {
    while (state != 1)
      std::this_thread::sleep_for(std::chrono::milliseconds(1));

    printSecond();
    state = 2;
  }

  void third(std::function<void()> printThird) {
    while (state != 2)
      std::this_thread::sleep_for(std::chrono::milliseconds(1));

    printThird();
    state = 3;
  }
};
