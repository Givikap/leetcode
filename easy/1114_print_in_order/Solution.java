class Foo {
  private int state;

  public Foo() {
    state = 0;
  }

  public void first(Runnable printFirst) throws InterruptedException {
    printFirst.run();
    state = 1;
  }

  public void second(Runnable printSecond) throws InterruptedException {
    while (state != 1) {
      Thread.sleep(1);
    }

    printSecond.run();
    state = 2;
  }

  public void third(Runnable printThird) throws InterruptedException {
    while (state != 1) {
      Thread.sleep(1);
    }

    printThird.run();
    state = 3;
  }
}
