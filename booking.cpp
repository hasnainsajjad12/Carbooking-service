#include <iostream>
#include <string>
#include <vector>

class Car {
public:
    Car(const std::string& make, const std::string& model, int year) 
        : make_(make), model_(model), year_(year), isAvailable_(true) {}

    const std::string& getMake() const {
        return make_;
    }

    const std::string& getModel() const {
        return model_;
    }

    int getYear() const {
        return year_;
    }

    bool isAvailable() const {
        return isAvailable_;
    }

    void book() {
        isAvailable_ = false;
    }

    void cancelBooking() {
        isAvailable_ = true;
    }

private:
    std::string make_;
    std::string model_;
    int year_;
    bool isAvailable_;
};

class CarBookingService {
public:
    void addCar(const Car& car) {
        cars_.push_back(car);
    }

    void displayAvailableCars() const {
        std::cout << "Available Cars:" << std::endl;
        for (const auto& car : cars_) {
            if (car.isAvailable()) {
                std::cout << car.getMake() << " " << car.getModel() << " (" << car.getYear() << ")" << std::endl;
            }
        }
    }

    bool bookCar(const std::string& make, const std::string& model, int year) {
        for (auto& car : cars_) {
            if (car.getMake() == make && car.getModel() == model && car.getYear() == year && car.isAvailable()) {
                car.book();
                return true;
            }
        }
        return false;
    }

    bool cancelBooking(const std::string& make, const std::string& model, int year) {
        for (auto& car : cars_) {
            if (car.getMake() == make && car.getModel() == model && car.getYear() == year && !car.isAvailable()) {
                car.cancelBooking();
                return true;
            }
        }
        return false;
    }

private:
    std::vector<Car> cars_;
};

int main() {
    CarBookingService carBookingService;

    // Adding some cars to the booking service
    carBookingService.addCar(Car("Toyota", "Camry", 2022));
    carBookingService.addCar(Car("Honda", "Civic", 2021));
    carBookingService.addCar(Car("Ford", "Mustang", 2023));

    // Displaying available cars
    carBookingService.displayAvailableCars();

    // Booking a car
    if (carBookingService.bookCar("Toyota", "Camry", 2022)) {
        std::cout << "Car booked successfully!" << std::endl;
    } else {
        std::cout << "Car booking failed." << std::endl;
    }

    // Displaying available cars after booking
    carBookingService.displayAvailableCars();

    // Canceling booking
    if (carBookingService.cancelBooking("Toyota", "Camry", 2022)) {
        std::cout << "Booking canceled successfully!" << std::endl;
    } else {
        std::cout << "Booking cancellation failed." << std::endl;
    }

    // Displaying available cars after cancellation
    carBookingService.displayAvailableCars();

    return 0;
}
