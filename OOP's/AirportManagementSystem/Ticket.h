#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
public:
    int ticketNumber;
    int seatNumber;
    std::string bookingDate;
    double price;

    Ticket(int ticketNumber, int seatNumber, const std::string& bookingDate, double price);
    void getTicketDetails() const;
    void updateTicketDetails();
    void validateTicket() const;
    void cancelTicket();
};

#endif // TICKET_H
