#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Baggage;

class Passenger {
public:
    std::string name;
    std::string passportNumber;
    std::string contactInfo;
    std::string dateOfBirth;

    Passenger(const std::string& name, const std::string& passportNumber, const std::string& contactInfo, const std::string& dateOfBirth);
    void checkIn();
    void getBoardingPass() const;

    Baggage* baggage;
};

class Baggage {
public:
    double weight;
    std::string dimensions;
    std::string passengerID;

    Baggage(double weight, const std::string& dimensions, const std::string& passengerID);
    void getBaggageInfo() const;
    void updateDimensions(const std::string& newDimensions);
};

#endif // PASSENGER_H
