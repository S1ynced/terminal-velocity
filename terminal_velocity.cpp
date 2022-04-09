#include <iostream>
#include <cmath>
using namespace std;

double temperature_calculation(double altitude_calc) {
    double temperature = 15.04 - (0.00649 * altitude_calc);
    return temperature;
};

double pressure_calculation(double temperature_calc) {
    double pressure = 101.29 * pow(((temperature_calc + 273.1)/288.08),5.256);
    return pressure;
};

double density_calculation(double pressure_calc, double temp_calc) {
    double density = (pressure_calc/(0.2869 * (temp_calc + 273.1)));
    return density;
};

double cross_sectional_area_calculation(double diameter_calc, double beta_calc) {
    double cross_sectional_area = M_PI * ((diameter_calc/2) * (diameter_calc/2));
    return cross_sectional_area;
};


int main() {

    double altitude, vehicle_mass, drag_coefficient, diameter, terminal_velocity, beta;

    cout << "Enter the Altitude 0-11000(m): ";
    cin >> altitude;
    cout << "Enter the Vehicle Mass: ";
    cin >> vehicle_mass;
    cout << "Enter Vehicle Drag Co-Efficient: ";
    cin >> drag_coefficient;
    cout << "Enter Vehicle Diameter: ";
    cin >> diameter;

    double temperature = temperature_calculation(altitude);
    double pressure = pressure_calculation(temperature);
    double density = density_calculation(pressure,temperature);
    double cross_sectional_area = cross_sectional_area_calculation(diameter,beta);

    double numerator = 2 * vehicle_mass * 9.81;
    double denominator = density * cross_sectional_area * drag_coefficient;
    double terminal_velocity_calculation = (numerator/denominator);

//  cout << "Cross Sectional Area: "<<cross_sectional_area<<endl;
//  cout << "Denominator: "<< denominator << endl;

    terminal_velocity = sqrt(terminal_velocity_calculation);
    terminal_velocity = terminal_velocity * (18/5);
    cout << endl << "Terminal Velocity: "<< terminal_velocity <<"KM/H"<< endl;

    cout << endl;
    return 0;
}
