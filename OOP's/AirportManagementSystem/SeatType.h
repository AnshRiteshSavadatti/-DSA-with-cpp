#ifndef SEATTYPE_H
#define SEATTYPE_H

#include <string>

class SeatType {
public:
    virtual void getSeatInfo() const = 0;
    virtual bool isAvailable() const = 0;
};

class Economy : public SeatType {
public:
    std::string mealOptions;

    Economy(const std::string& mealOptions);
    void getSeatInfo() const override;
    bool isAvailable() const override;
};

class Business : public SeatType {
public:
    int seatWidth;
    bool lieFlatSeats;

    Business(int seatWidth, bool lieFlatSeats);
    void getSeatInfo() const override;
    bool isAvailable() const override;
};

// Define other seat types similarly

#endif // SEATTYPE_H
