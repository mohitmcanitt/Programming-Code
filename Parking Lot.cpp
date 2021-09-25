
class ParkingLot
{
    string name;
    Address address;

    vector<ParkingFloor>parkingFloors;
    vector<Entrance>entrances;
    vector<Exit>exist;

    bool isParkingSpaceAvailableForVehicle(Vehicle vehicle);
    bool updateParkingAttendant(ParkingAttendant parkingAttendant,int gateId);

}

class ParkingFloor
{
    int levelId;
    bool isFull;
    ParkingDisplayBoard parkingDisplayBoard;
    List<ParkingSpaces>parkingSpaces;
};

class Gate
{
    int gateId;
    ParkingAttendant parkingAttendant;
};

class Entrance:public Gate
{
    ParkingTicket getParkingTicket(Vehicle vehicle);
};

class Exit:public Gate
{
    ParkingTicket payForParking(PaymentType aymentType,ParkingTicket);
};

class Address
{
    string country;
    string state;
    string city;
    string street;
    int pincode;
};

class ParkingSpace
{
    int spaceId;
    bool isFree;
    double cost_per_hour;
    ParkingType parkingtype;
};

class ParkingDisplayBoard
{
    map<ParkingSpaceType,int>freeSpotsAvailable;
    void updateFreeSpotsAvailable(ParkingSpaceType parkingSpace,int spaces);
};

class Account
{
    string name;
    string email;
    string password;
    string empId;
    Address address;
};

class Admin:public Account
{
    void addParkingFloor(ParkingLot parkingLot,ParkingFloor floor);
    void addParkingSpaces(ParkingFloor parkingfloor,parkingSpace parkingspace);
    void addParkingDisplayBoard(ParkingFloor parkingfloor,ParkingDisplayBoard parkingDisplayBoard);
}

class ParkingAttendant:public Account
{
    bool processVehicleEntry(Vehicle vehicle);
    PaymentInfo processPayment(ParkingTicket parkingTicket, PaymentType paymentType);
};

class Vehicle
{
    string licenceNumber;
    VehicleType vehicle;
    ParkingTicket parkingTicket;
    PaymentInfo paymentInfo;
};

class ParkingTicket
{
    int ticketId;
    int levelId;
    int spaceId;

    Date VehicleEntryTime;
    Date VehicleExitTime;

    ParkingSpaceType parkingSpaceType;
    double totalCost;
    ParkingTicketStatus parkingTicketStatus;
    
    void updateTotalCost();
    void updateVehicleExitTime(Date vehicleExitDateTime)    
};

enum ParkingType{
    CASH,CREDIT_CARD,UPI,DEBIT_CARD;
}
enum ParkingSpaceType
{
    BIKE_PARKING,CAR_PARKING,TRUCK_PARKING;
}
class Payment
{
    PaymentInfo makePayment(ParkingTicket parkingTicket,PaymentType paymentType);
}

class paymentInfo
{
    double amount;
    Date paymentDate;
    int transactionId;
    ParkingTicket parkingTicket;
    PaymentStatus paymentStatus;
};

enum Vehicle
{
    BIKE,CAR,TRUCK;
}

enum ParkingTicketStatus
{
    PAID,ACTIVE;
}
enum PaymentStatus
{
    UNPAID,COMPLETE,DECLINE,CANCELLED;
}
