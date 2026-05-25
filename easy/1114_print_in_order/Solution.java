import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Foo {
  private final Lock lock = new ReentrantLock();

  private final Condition firstCompleted = lock.newCondition();
  private final Condition secondCompleted = lock.newCondition();

  private volatile boolean isFirstCompleted;
  private volatile boolean isSecondCompleted;

  public Foo() {}

  public void first(Runnable printFirst) throws InterruptedException {
    lock.lock();
    try {
      printFirst.run();
      isFirstCompleted = true;
      firstCompleted.signal();
    } finally {
      lock.unlock();
    }
  }

  public void second(Runnable printSecond) throws InterruptedException {
    lock.lock();
    try {
      while (!isFirstCompleted) {
        firstCompleted.await();
      }

      printSecond.run();
      isSecondCompleted = true;
      secondCompleted.signal();
    } finally {
      lock.unlock();
    }
  }

  public void third(Runnable printThird) throws InterruptedException {
    lock.lock();
    try {
      while (!isSecondCompleted) {
        secondCompleted.await();
      }

      printThird.run();
    } finally {
      lock.unlock();
    }
  }
}
