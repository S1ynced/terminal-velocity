#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <windows.h>
# define M_PI 3.14159265358979323846  /* pi */

using namespace std;

double temperature_calculation(double altitude) {
    double temperature;
    if (altitude > 25000) {
        temperature = -131.21 + (0.00299 * altitude);
    }
    else if (altitude <= 25000 && altitude >= 11000) {
        temperature = -56.46;
    }
    else {
        temperature = 15.04 - (0.00649 * altitude);
    }
    return temperature;
};

double pressure_calculation(double temperature, double altitude) {
    double pressure, x;
    if (altitude > 25000) {
        pressure = 2.488 * pow(((temperature + 273.1)/216.6),-11.388);
    }
    else if (altitude <= 25000 && altitude >= 11000) {
        x = 1.73 - (0.000157 * altitude);
        pressure = 22.65 * exp(x);
    }
    else {
        pressure = 101.29 * pow(((temperature + 273.1)/288.08),5.256);
    }
    return pressure;
};

double density_calculation(double pressure, double temperature) {
    double density = (pressure/(0.2869 * (temperature + 273.1)));
    return density;
};

double cross_sectional_area_calculation(double diameter) {
    double cross_sectional_area = (M_PI / 4) * (diameter * diameter);
    return cross_sectional_area;
};

int main() {

     SetConsoleTitle("Terminal Velocity");

    double altitude, vehicle_mass, terminal_velocity, drag_coefficient, diameter;

    cout << "Enter Vehicle Mass (kg): ";
    cin >> vehicle_mass;
    cout << "Enter Vehicle Diameter (m): ";
    cin >> diameter;
    cout << "Enter Vehicle Drag Co-Efficient: ";
    cin >> drag_coefficient;
    cout << endl;

    cout << "Altitude (km)" << setw(23) << "Temperature (C)" << setw(23) << "Pressure (K-Pa)" << setw(25)
         << "Density (kg/cu m)" << setw(32) << "Terminal Velocity (KM/H)" << endl << endl;

    for (altitude = 80000; altitude > 10000; altitude -= 5000) {
        double temperature = temperature_calculation(altitude);
        double pressure = pressure_calculation(temperature, altitude);
        double density = density_calculation(pressure, temperature);
        double cross_sectional_area = cross_sectional_area_calculation(diameter);

        double numerator = 2 * vehicle_mass * 9.81;
        double denominator = density * cross_sectional_area * drag_coefficient;
        double terminal_velocity_calculation = (numerator / denominator);
        terminal_velocity = sqrt(terminal_velocity_calculation);
        terminal_velocity = terminal_velocity * (18 / 5);

        this_thread::sleep_for(1s);

        cout << fixed
             << setw(7) << setprecision(0) << altitude / 1000
             << setw(25);

        // Setting temperature 'Red'
        if (temperature < 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        }

        cout << setprecision(2) << temperature;

        // Reseting text color to cyan
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        cout << setw(25) << setprecision(2) << pressure
             << setw(25) << setprecision(2) << density
             << setw(25) << setprecision(2) << terminal_velocity
             << endl;
    }

    for (altitude = 10000; altitude >= 0; altitude -= 1000) {
        double temperature = temperature_calculation(altitude);
        double pressure = pressure_calculation(temperature, altitude);
        double density = density_calculation(pressure, temperature);
        double cross_sectional_area = cross_sectional_area_calculation(diameter);

        double numerator = 2 * vehicle_mass * 9.81;
        double denominator = density * cross_sectional_area * drag_coefficient;
        double terminal_velocity_calculation = (numerator / denominator);
        terminal_velocity = sqrt(terminal_velocity_calculation);
        terminal_velocity = terminal_velocity * (18 / 5);

        this_thread::sleep_for(1s);

        cout << fixed
             << setw(7) << setprecision(0) << altitude / 1000
             << setw(25);

        // Setting temperature 'Red'
        if (temperature < 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        }

        cout << setprecision(2) << temperature;

        // Reseting text color to cyan
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

        cout << setw(25) << setprecision(2) << pressure
             << setw(25) << setprecision(2) << density
             << setw(25) << setprecision(1) << terminal_velocity
             << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}