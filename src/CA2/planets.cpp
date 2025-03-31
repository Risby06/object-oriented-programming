#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream> // Add this for file operations
#include "point.h"

# define PI 3.14159265358979323846

using namespace std;
using namespace geom;

int main() {
    // Constants
    const double SUN_EARTH_DISTANCE = 193e6; // 193 million km
    const double EARTH_MOON_DISTANCE = 384000; // 384,000 km
    
    const int DAYS_IN_YEAR = 365;
    const int DAYS_IN_LUNAR_MONTH = 27;
    
    const double EARTH_DAILY_ANGLE = 2 * PI / DAYS_IN_YEAR; // radians per day
    const double MOON_DAILY_ANGLE = 2 * PI / DAYS_IN_LUNAR_MONTH; // radians per day
    
    // Create output files
    ofstream earthFile("earth.txt");
    ofstream moonFile("moon.txt");
    
    // Check if files opened successfully
    if (!earthFile.is_open() || !moonFile.is_open()) {
        cerr << "Error opening output files" << endl;
        return 1;
    }
    
    // Initial positions
    Point sun(0, 0);
    Point earth(SUN_EARTH_DISTANCE, 0); // Earth starts at (193e6, 0)
    Point moon = earth; // Start moon at Earth's position
    moon.translate(EARTH_MOON_DISTANCE, 0); // Move moon to Earth+distance
    
    cout << "Simulation of Earth and Moon orbits over 1 year" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Day 0:" << endl;
    cout << "  Sun: " << sun << endl;
    cout << "  Earth: " << earth << endl;
    cout << "  Moon: " << moon << endl;
    cout << "  Earth-Sun distance: " << fixed << setprecision(0) << earth.distance(sun) << " km" << endl;
    cout << "  Moon-Earth distance: " << fixed << setprecision(0) << moon.distance(earth) << " km" << endl;
    cout << endl;
    
    // Write initial positions to files
    earthFile << "0 " << earth.x() << " " << earth.y() << endl;
    moonFile << "0 " << moon.x() << " " << moon.y() << endl;
    
    // Simulate each day of the year
    for (int day = 1; day <= DAYS_IN_YEAR; day++) {
        // Calculate the positions for this day
        
        // 1. Store the old earth position to calculate moon's new position later
        Point old_earth = earth;
        
        // 2. Earth rotates around the Sun
        earth.rotate(sun, EARTH_DAILY_ANGLE);
        
        // 3. Moon rotates around the old Earth position
        moon.rotate(old_earth, MOON_DAILY_ANGLE);
        
        // 4. Moon translates with Earth (move moon by the same vector Earth moved)
        moon.translate(earth.x() - old_earth.x(), earth.y() - old_earth.y());
        
        // Write current positions to files
        earthFile << day << " " << earth.x() << " " << earth.y() << endl;
        moonFile << day << " " << moon.x() << " " << moon.y() << endl;
        
        cout << "Day " << day << ":" << endl;
        cout << "  Earth: " << earth << endl;
        cout << "  Moon: " << moon << endl;
        
        // Calculate distances to verify
        double earth_sun_distance = earth.distance(sun);
        double moon_earth_distance = moon.distance(earth);
        
        cout << "  Earth-Sun distance: " << fixed << setprecision(0) << earth_sun_distance << " km" << endl;
        cout << "  Moon-Earth distance: " << fixed << setprecision(0) << moon_earth_distance << " km" << endl;
        cout << endl;
    }
    
    cout << "Final position of the Moon after 1 year: " << moon << endl;
    cout << "Distance from Earth: " << fixed << setprecision(0) << moon.distance(earth) << " km" << endl;
    
    // Close the files
    earthFile.close();
    moonFile.close();
    
    cout << "Coordinates written to earth.txt and moon.txt" << endl;
    
    return 0;
}