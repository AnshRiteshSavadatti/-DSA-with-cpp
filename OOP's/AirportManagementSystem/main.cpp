#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

class Ticket;
class Flight;
class Crew;
class Transaction;

class SeatType {
public:
    virtual void getSeatInfo() const = 0;
    virtual bool isAvailable() const = 0;
    virtual ~SeatType() = default;
};

class Economy : public SeatType {
public:
    void getSeatInfo() const override {
        cout << "Economy Class Seat" << endl;
    }

    bool isAvailable() const override {
        return true; // assume always available
    }
};

class PremiumEconomy : public SeatType {
public:
    void getSeatInfo() const override {
        cout << "Premium Economy Class Seat" << endl;
    }

    bool isAvailable() const override {
        return true; //assume always available
    }
};

class Business : public SeatType {
public:
    void getSeatInfo() const override {
        cout << "Business Class Seat" << endl;
    }

    bool isAvailable() const override {
        return true; // assume always available
    }
};

class First : public SeatType {
public:
    void getSeatInfo() const override {
        cout << "First Class Seat" << endl;
    }

    bool isAvailable() const override {
        return true; //  assume always available
    }
};

class Premium : public SeatType {
public:
    void getSeatInfo() const override {
        cout << "Premium Class Seat" << endl;
    }

    bool isAvailable() const override {
        return true; // assume always available
    }
};

class SeatFactory {
public:
    static SeatType* createSeat(const string& seatType) {
        if (seatType == "Economy") {
            return new Economy();
        } else if (seatType == "PremiumEconomy") {
            return new PremiumEconomy();
        } else if (seatType == "Business") {
            return new Business();
        } else if (seatType == "First") {
            return new First();
        } else if (seatType == "Premium") {
            return new Premium();
        } else {
            throw invalid_argument("Unknown seat type");
        }
    }
};

class Passenger {
protected:
    string name;
    string passport_number;
    string contact_info;
    string date_of_birth;
    bool hasSeat;

public:
    Passenger(const string& name, const string& passport_number, const string& contact_info, const string& date_of_birth)
        : name(name), passport_number(passport_number), contact_info(contact_info), date_of_birth(date_of_birth), hasSeat(false) {}

    void checkIn() const {
        if (!hasSeat) {
            throw runtime_error(name + " cannot check in without a seat");
        }
        cout << name << " checked in" << endl;
    }

    void getBoardingPass() const {
        if (!hasSeat) {
            throw runtime_error(name + " cannot receive boarding pass without a seat");
        }
        cout << name << " received boarding pass" << endl;
    }

    string getName() const {
        return name;
    }

    void bookSeat() {
        hasSeat = true;
    }
};

class Flight {
protected:
    string departure_time;
    string arrival_time;
    string flight_number;
    int duration;
    string airline;
    vector<SeatType*> seats;
    vector<Passenger*> passengers;
    int max_seats;
    int reserved_seats;

public:
    Flight(const string& departure_time, const string& arrival_time, const string& flight_number, int duration, const string& airline, int max_seats)
        : departure_time(departure_time), arrival_time(arrival_time), flight_number(flight_number), duration(duration), airline(airline), max_seats(max_seats), reserved_seats(0) {}

    void reserveSeat(SeatType* seat) {
        if (reserved_seats >= max_seats) {
            throw runtime_error("No available seats for flight " + flight_number);
        }
        seats.push_back(seat);
        reserved_seats++;
        cout << "Seat reserved" << endl;
    }

    void addPassenger(Passenger* passenger, SeatType* seat) {
        if (reserved_seats >= max_seats) {
            throw runtime_error("No more reservations can be done as no available seats for flight " + flight_number);
        }
        reserveSeat(seat);
        passengers.push_back(passenger);
        passenger->bookSeat();
        cout << "Passenger added to the flight" << endl;
    }

    void getFlightDetails() const {
        cout << "Flight " << flight_number << " from " << departure_time << " to " << arrival_time << " by " << airline << endl;
    }

    ~Flight() {
        for (auto seat : seats) {
            delete seat;
        }
    }
};

class Transaction {
protected:
    int transaction_id;
    int flight_id;
    int passenger_id;
    double amount;

public:
    Transaction(int transaction_id, int flight_id, int passenger_id, double amount)
        : transaction_id(transaction_id), flight_id(flight_id), passenger_id(passenger_id), amount(amount) {}

    void processPayment() const {
        cout << "Payment of " << amount << " processed for transaction ID: " << transaction_id << endl;
    }

    void validateTransaction() const {
        cout << "Transaction ID: " << transaction_id << " validated" << endl;
    }

    void refund() const {
        cout << "Refund issued for transaction ID: " << transaction_id << endl;
    }
};

class Ticket {
protected:
    int ticket_number;
    int seat_number;
    string booking_date;
    double price;

public:
    Ticket(int ticket_number, int seat_number, const string& booking_date, double price)
        : ticket_number(ticket_number), seat_number(seat_number), booking_date(booking_date), price(price) {}

    void getTicketDetails() const { 
        cout << "Ticket Number: " << ticket_number << " Seat Number: " << seat_number << " Booking Date: " << booking_date << " Price: " << price << endl;
    }

    void updateTicket() const {
        cout << "Ticket Number: " << ticket_number << " updated" << endl;
    }

    void validateTicket() const {
        cout << "Ticket Number: " << ticket_number << " validated" << endl;
    }

    void cancelTicket() const {
        cout << "Ticket Number: " << ticket_number << " canceled" << endl;
    }
};

class Crew {
protected:
    int crew_id;
    string name;
    string position;
    string shift_timing;

public:
    Crew(int crew_id, const string& name, const string& position, const string& shift_timing)
        : crew_id(crew_id), name(name), position(position), shift_timing(shift_timing) {}

    virtual void getDetails() const = 0;
    virtual ~Crew() = default;
};

class AirHostess : public Crew {
protected:
    vector<string> languages_spoken;
    int experience;

public:
    AirHostess(int crew_id, const string& name, const string& position, const string& shift_timing, const vector<string>& languages_spoken, int experience)
        : Crew(crew_id, name, position, shift_timing), languages_spoken(languages_spoken), experience(experience) {}

    void getDetails() const override {
        cout << "Air Hostess: " << name << " Experience: " << experience << " years" << endl;
    }
};

class Purser : public Crew {
protected:
    int seniority_level;
    vector<string> training_certifications;

public:
    Purser(int crew_id, const string& name, const string& position, const string& shift_timing, int seniority_level, const vector<string>& training_certifications)
        : Crew(crew_id, name, position, shift_timing), seniority_level(seniority_level), training_certifications(training_certifications) {}

    void getDetails() const override {
        cout << "Purser: " << name << " Seniority Level: " << seniority_level << " Certifications: ";
        for (const auto& cert : training_certifications) {
            cout << cert << " ";
        }
        cout << endl;
    }
};

// Singleton pattern
class Airport {
protected:
    string name;
    string location;
    int terminals;
    int runways;
    vector<Flight*> flights;
    vector<Passenger*> passengers;
    vector<Crew*> crew;
    vector<Transaction*> transactions;
    vector<Ticket*> tickets;

    static Airport* instance;

    Airport(const string& name, const string& location, int terminals, int runways)
        : name(name), location(location), terminals(terminals), runways(runways) {}

public:
    Airport(const Airport&) = delete;
    Airport& operator=(const Airport&) = delete;

    static Airport* getInstance(const string& name, const string& location, int terminals, int runways) {
        if (instance == nullptr) {
            instance = new Airport(name, location, terminals, runways);
        }
        return instance;
    }

    void addFlight(Flight* flight) {
        flights.push_back(flight);
    }

    void addPassenger(Passenger* passenger) {
        passengers.push_back(passenger);
    }

    void addCrew(Crew* crew_member) {
        crew.push_back(crew_member);
    }

    void addTransaction(Transaction* transaction) {
        transactions.push_back(transaction);
    }

    void addTicket(Ticket* ticket) {
        tickets.push_back(ticket);
    }

    void getFlights() const {
        cout << "Getting flights from " << name << endl;
        for (const auto& flight : flights) {
            flight->getFlightDetails();
        }
    }

    ~Airport() {
    }
};

Airport* Airport::instance = nullptr;

// Main function
int main() {
    try {
        Airport* airport = Airport::getInstance("Chhatrapati Shivaji Maharaj International Airport", "Mumbai", 3, 2);

        Flight* flight1 = new Flight("2024-06-15 10:00", "2024-06-15 13:00", "AI101", 3, "Air India", 2);
        airport->addFlight(flight1);

        Passenger* passenger1 = new Passenger("Rahul Sharma", "H123456789", "rahul@example.com", "1985-05-23");
        airport->addPassenger(passenger1);
        Passenger* passenger2 = new Passenger("Sunita Verma", "G987654321", "sunita@example.com", "1990-11-12");
        airport->addPassenger(passenger2);
        Passenger* passenger3 = new Passenger("Ravi Kumar", "F555555555", "ravi@example.com", "1975-03-15");
        airport->addPassenger(passenger3);

        Transaction* transaction1 = new Transaction(1, 1, 1, 5000.00);
        Transaction* transaction2 = new Transaction(2, 1, 2, 7000.00);
        airport->addTransaction(transaction1);
        airport->addTransaction(transaction2);

        Ticket* ticket1 = new Ticket(1, 101, "2024-06-01", 5000.00);
        Ticket* ticket2 = new Ticket(2, 102, "2024-06-02", 7000.00);
        airport->addTicket(ticket1);
        airport->addTicket(ticket2);

        SeatType* economySeat1 = SeatFactory::createSeat("Economy");
        SeatType* businessSeat1 = SeatFactory::createSeat("Business");

        flight1->addPassenger(passenger1, economySeat1);
        flight1->addPassenger(passenger2, businessSeat1);

        // Attempt to add a third passenger to a flight with max 2 seats to trigger an exception
        try {
            SeatType* premiumSeat1 = SeatFactory::createSeat("Premium");
            flight1->addPassenger(passenger3, premiumSeat1);
        } catch (const runtime_error& e) {
            cerr << "Exception: " << e.what() << endl;
        }

        flight1->getFlightDetails();

        transaction1->processPayment();
        transaction1->validateTransaction();

        transaction2->processPayment();
        transaction2->validateTransaction();

        ticket1->getTicketDetails();
        ticket2->getTicketDetails();

        AirHostess* hostess1 = new AirHostess(1, "Anita", "Air Hostess", "Morning", {"English", "Hindi"}, 5);
        Purser* purser1 = new Purser(2, "Ravi", "Purser", "Evening", 3, {"Safety Training", "Customer Service"});
        airport->addCrew(hostess1);
        airport->addCrew(purser1);

        hostess1->getDetails();
        purser1->getDetails();
        
        passenger1->checkIn();
        passenger1->getBoardingPass();

        passenger2->checkIn();
        passenger2->getBoardingPass();

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
