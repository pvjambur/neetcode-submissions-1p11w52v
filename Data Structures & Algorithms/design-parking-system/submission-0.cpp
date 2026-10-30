class ParkingSystem {
private:
    vector<int> slots;

public:
    ParkingSystem(int big, int medium, int small) {
        slots.resize(3,0);
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }

    bool addCar(int carType) {
        if (slots[carType-1]>=1){
            slots[carType-1]--;
            return true;
        }
        return false;
    }
};
