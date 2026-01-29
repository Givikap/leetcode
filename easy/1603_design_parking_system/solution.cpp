using namespace std;

#include <vector>

class ParkingSystem {
private:
  vector<int> parking;

public:
  ParkingSystem(int big, int medium, int small) {
    parking = vector<int>{big, medium, small};
  }

  bool addCar(int carType) {
    if (parking[carType - 1] > 0) {
      --parking[carType - 1];
      return true;
    }

    return false;
  }
};
