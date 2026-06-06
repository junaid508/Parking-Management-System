#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
private:
    string vehicleNumber;
    string vehicleType;
    int hours;

public:
    Vehicle(string num, string type, int h)
    {
        vehicleNumber = num;
        vehicleType = type;
        hours = h;
    }

    string getVehicleNumber()
    {
        return vehicleNumber;
    }

    string getVehicleType()
    {
        return vehicleType;
    }

    int getHours()
    {
        return hours;
    }

    void display()
    {
        cout << "\nVehicle Number : " << vehicleNumber;
        cout << "\nVehicle Type   : " << vehicleType;
        cout << "\nHours Parked   : " << hours << endl;
    }
};

class ParkingManagement
{
private:
    vector<Vehicle> vehicles;
    int totalSlots;
    int occupiedSlots;

public:
    ParkingManagement(int slots)
    {
        totalSlots = slots;
        occupiedSlots = 0;
    }

    void vehicleEntry()
    {
        if (occupiedSlots >= totalSlots)
        {
            cout << "\nParking Full!\n";
            return;
        }

        string number, type;
        int hours;

        cout << "\nEnter Vehicle Number: ";
        cin >> number;

        cout << "Enter Vehicle Type (Bike/Car/Truck): ";
        cin >> type;

        cout << "Expected Parking Hours: ";
        cin >> hours;

        Vehicle v(number, type, hours);
        vehicles.push_back(v);

        occupiedSlots++;

        cout << "\nVehicle Parked Successfully!";
        cout << "\nAvailable Slots: "
             << totalSlots - occupiedSlots << endl;
    }

    void vehicleExit()
    {
        string number;
        cout << "\nEnter Vehicle Number: ";
        cin >> number;

        bool found = false;

        for (int i = 0; i < vehicles.size(); i++)
        {
            if (vehicles[i].getVehicleNumber() == number)
            {
                int fee = calculateFee(
                    vehicles[i].getVehicleType(),
                    vehicles[i].getHours());

                cout << "\nVehicle Found!";
                vehicles[i].display();

                cout << "\nParking Fee = Rs. "
                     << fee << endl;

                vehicles.erase(vehicles.begin() + i);

                occupiedSlots--;
                found = true;

                cout << "\nVehicle Exited Successfully!\n";
                break;
            }
        }

        if (!found)
        {
            cout << "\nVehicle Not Found!\n";
        }
    }

    int calculateFee(string type, int hours)
    {
        if (type == "Bike" || type == "bike")
            return hours * 10;

        else if (type == "Car" || type == "car")
            return hours * 20;

        else if (type == "Truck" || type == "truck")
            return hours * 50;

        return 0;
    }

    void showVehicles()
    {
        if (vehicles.empty())
        {
            cout << "\nNo Vehicles Parked.\n";
            return;
        }

        cout << "\n----- Parked Vehicles -----\n";

        for (int i = 0; i < vehicles.size(); i++)
        {
            vehicles[i].display();
            cout << "-------------------------\n";
        }
    }

    void showAvailability()
    {
        cout << "\nTotal Slots     : "
             << totalSlots;

        cout << "\nOccupied Slots  : "
             << occupiedSlots;

        cout << "\nAvailable Slots : "
             << totalSlots - occupiedSlots
             << endl;
    }
};

int main()
{
    ParkingManagement parking(10);

    int choice;

    do
    {
        cout << "\n\n===== PARKING MANAGEMENT SYSTEM =====";
        cout << "\n1. Vehicle Entry";
        cout << "\n2. Vehicle Exit";
        cout << "\n3. Show Parked Vehicles";
        cout << "\n4. Show Available Slots";
        cout << "\n5. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            parking.vehicleEntry();
            break;

        case 2:
            parking.vehicleExit();
            break;

        case 3:
            parking.showVehicles();
            break;

        case 4:
            parking.showAvailability();
            break;

        case 5:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while (choice != 5);

    return 0;
}