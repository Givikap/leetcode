#include <functional>

class Foo {
private:
  std::condition_variable cv;
  std::mutex m;

  uint state;

public:
  Foo() { state = 0; }

  void first(std::function<void()> printFirst) {
    {
      auto lock = std::lock_guard{m};
      printFirst();
      state = 1;
    }
    cv.notify_all();
  }

  void second(std::function<void()> printSecond) {
    {
      auto lock = std::unique_lock{m};
      cv.wait(lock, [&]() { return state == 1; });
      printSecond();
      state = 2;
    }
    cv.notify_all();
  }

  void third(std::function<void()> printThird) {
    auto lock = std::unique_lock{m};
    cv.wait(lock, [&]() { return state == 2; });

    printThird();
    state = 3;
  }
};
