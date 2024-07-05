#include "Flight.h"
#include "Passenger.h"
#include <iostream>

Flight::Flight(const std::string& departureTime, const std::string& arrivalTime, const std::string& flightNumber, int duration, const std::string& airline, const std::string& status)
    : departureTime(departureTime), arrivalTime(arrivalTime), flightNumber(flightNumber), duration(duration), airline(airline), status(status) {}

void Flight::addPassenger(Passenger* passenger, SeatType* seat) {
    // Add passenger to flight
}

void Flight::removePassenger(Passenger* passenger) {
    // Remove passenger from flight
}

void Flight::getFlightDetails() const {
    std::cout << "Flight " << flightNumber << " from " << departureTime << " to " << arrivalTime << "\n";
}

void Flight::updateFlightDetails() {
    // Update flight details
}
