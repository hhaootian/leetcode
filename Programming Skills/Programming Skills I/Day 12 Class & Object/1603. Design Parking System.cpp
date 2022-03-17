class ParkingSystem {
public:
    unordered_map<int, int> slot;

    ParkingSystem(int big, int medium, int small) {
        slot[1] = big;
        slot[2] = medium;
        slot[3] = small;
    }
    
    bool addCar(int carType) {
        slot[carType] --;
        return slot[carType] >= 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */