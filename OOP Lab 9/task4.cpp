#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int availableSeats;
    vector<string> bookedPassengers; 
    bool isPassengerBooked(const string& passengerId) const {
        for (const auto& id : bookedPassengers) {
            if (id == passengerId) return true;
        }
        return false;
    }
public:
    Flight(const string& fn, const string& dep, const string& arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), availableSeats(cap) {}
    bool bookSeat(const string& passengerId) {
        if (availableSeats <= 0) {
            cout << "Flight " << flightNumber << " is fully booked." << endl;
            return false;
        }
        if (isPassengerBooked(passengerId)) {
            cout << "Passenger " << passengerId << " already has a seat." << endl;
            return false;
        }
        bookedPassengers.push_back(passengerId);
        availableSeats--;
        cout << "Seat booked for passenger " << passengerId << " on flight " << flightNumber << endl;
        return true;
    }

    bool cancelSeat(const string& passengerId) {
        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == passengerId) {
                bookedPassengers.erase(it);
                availableSeats++;
                cout << "Booking cancelled for passenger " << passengerId << " on flight " << flightNumber << endl;
                return true;
            }
        }
        cout << "Passenger " << passengerId << " not found on flight " << flightNumber << endl;
        return false;
    }

    bool upgradeSeat(const string& passengerId) {
        if (!isPassengerBooked(passengerId)) {
            cout << "Cannot upgrade - passenger " << passengerId << " not booked on flight " << flightNumber << endl;
            return false;
        }
        cout << "Seat upgraded for passenger " << passengerId << " on flight " << flightNumber << endl;
        return true;
    }

    string getFlightInfo() const {
        return "Flight " + flightNumber + ": " + departure + " to " + arrival + 
               " (" + to_string(availableSeats) + "/" + to_string(capacity) + " seats available)";
    }

    int getAvailableSeats() const { return availableSeats; }
};

class Passenger {
private:
    string id;
    string name;
    vector<Flight*> bookedFlights;

public:
    Passenger(const string& pid, const string& n) : id(pid), name(n) {}

    bool requestBooking(Flight& flight) {
        if (flight.bookSeat(id)) {
            bookedFlights.push_back(&flight);
            return true;
        }
        return false;
    }

    bool requestCancellation(Flight& flight) {
        if (flight.cancelSeat(id)) {
            // Remove from bookedFlights
            for (auto it = bookedFlights.begin(); it != bookedFlights.end(); ++it) {
                if (*it == &flight) {
                    bookedFlights.erase(it);
                    break;
                }
            }
            return true;
        }
        return false;
    }

    bool requestUpgrade(Flight& flight) {
        return flight.upgradeSeat(id);
    }

    string getPassengerInfo() const {
        return "Passenger " + id + ": " + name + " (" + to_string(bookedFlights.size()) + " flights booked)";
    }
};

int main() {
 
    Flight nycTorom("BA112", "New York", "Rome", 200);
    Flight parToTok("AF289", "Paris", "Tokyo", 350);
    Passenger john("P105", "John Smith");
    Passenger emma("P106", "Emma Johnson");
    cout << nycTorom.getFlightInfo() << endl;
    cout << parToTok.getFlightInfo() << endl;

    john.requestBooking(nycTorom);
    emma.requestBooking(nycTorom);
    john.requestBooking(parToTok);

    cout << "\nAfter bookings:\n";
    cout << nycTorom.getFlightInfo() << endl;
    cout << parToTok.getFlightInfo() << endl;
    cout << john.getPassengerInfo() << endl;
    cout << emma.getPassengerInfo() << endl;

    john.requestBooking(nycTorom);

    john.requestCancellation(nycTorom);
    cout << "\nAfter cancellation:\n";
    cout << nycTorom.getFlightInfo() << endl;
    cout << john.getPassengerInfo() << endl;

    emma.requestUpgrade(nycTorom);
    john.requestUpgrade(nycTorom); 

    return 0;
}