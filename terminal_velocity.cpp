#include <iostream>
#include <cmath>
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
    double cross_sectional_area = M_PI * ((diameter/2) * (diameter/2));
    return cross_sectional_area;
};

int main() {

    double altitude, vehicle_mass, drag_coefficient, diameter, terminal_velocity;

    cout << "Enter the Altitude (m): ";
    cin >> altitude;
    cout << "Enter the Vehicle Mass: ";
    cin >> vehicle_mass;
    cout << "Enter Vehicle Drag Co-Efficient: ";
    cin >> drag_coefficient;
    cout << "Enter Vehicle Diameter: ";
    cin >> diameter;

    double temperature = temperature_calculation(altitude);
    double pressure = pressure_calculation(temperature,altitude);
    double density = density_calculation(pressure,temperature);
    double cross_sectional_area = cross_sectional_area_calculation(diameter);

    double numerator = 2 * vehicle_mass * 9.81;
    double denominator = density * cross_sectional_area * drag_coefficient;
    double terminal_velocity_calculation = (numerator/denominator);
    cout << endl;

//  Altitude in Kilometre
    double altitude_km = altitude/1000;

    cout << "Altitude (KM): " << altitude_km << endl;
//  Return temperature based on altitude.
    cout << "Temperature (C): "<< temperature << endl;

//  Return Pressure based on altitude.
    cout << "Pressure (K-pa): "<< pressure << endl;

// Return Density based on altitude.
    cout << "Density (Kg/cu m): "<< density << endl;

//  Return Cross-Sectional Area.
    cout << "Cross Sectional Area: "<< cross_sectional_area <<endl;

    terminal_velocity = sqrt(terminal_velocity_calculation);
//  cout << endl << "Terminal Velocity: "<< terminal_velocity << " m/s" << endl;
    terminal_velocity = terminal_velocity * (18/5);
    cout << endl << "Terminal Velocity: "<< terminal_velocity <<" KM/H" << endl;

    cout << endl;
    return 0;
}
