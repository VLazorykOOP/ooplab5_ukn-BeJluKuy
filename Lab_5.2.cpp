#include <iostream>
#include <string>

class Room {
private:
    double area;

public:
    Room(double area) {
        this->area = area;
    }

    double getArea() {
        return area;
    }
};

class OneBedroomApartment {
private:
    Room room;
    double kitchenArea;
    int floor;

public:
    OneBedroomApartment(double roomArea, double kitchenArea, int floor) : room(roomArea) {
        this->kitchenArea = kitchenArea;
        this->floor = floor;
    }

    double getRoomArea() {
        return room.getArea();
    }

    double getKitchenArea() {
        return kitchenArea;
    }

    int getFloor() {
        return floor;
    }
};

class CityApartment : public OneBedroomApartment {
private:
    std::string cityName;

public:
    CityApartment(double roomArea, double kitchenArea, int floor, const std::string& cityName)
        : OneBedroomApartment(roomArea, kitchenArea, floor) {
        this->cityName = cityName;
    }

    void print() {
        std::cout << "City: " << cityName << std::endl;
        std::cout << "Floor: " << getFloor() << std::endl;
        std::cout << "Room area: " << getRoomArea() << std::endl;
        std::cout << "Kitchen area: " << getKitchenArea() << std::endl;
    }
};

int main() {
    CityApartment apartment(50.0, 10.0, 5, "New York");
    apartment.print();

    return 0;
}
