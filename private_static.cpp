// using namespace std;


class A {
  private:
    static int xp[]/* = {1, 2, 3, 4, 5}*/;
};

int A::xp[] = {1, 2, 3, 4, 5};


class B {
  private:
    static A* ar[3];
  public:
    // class C {
      // public:
        // int x;
    // };
};

A* B::ar[3] = {new A(), new A(), new A()};

// B::NestedEnum ne = B::NestedEnum.C;

// enum B::En {A, B, C, D};