/***************************************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ * Programmer: Yusuf Halim                                                                                  / *
/ * Date: 09/06/2022                                                                                         / *
/ * Name: averageData.cpp                                                                                    / *
/ * Description: Reads censor data from a CSV file, asks the user for minimum height of corn, calculates     / *
/                the average and standard deviation, and output the results in a user-friendly way.          / *
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
***************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

int main() {

    // Initializing the in file stream
    ifstream inFS;
    string file = "baumerRadarSensorData.csv";

    // Opening the file and making sure it's open correctly
    inFS.open(file);
    // Return and error code and a message to the user if file was not opened
    if (!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }


    // Initializing the vector that will collect data for every line.
    vector<string> data;
    // String variables that will hold the lines and each data in the wile loop
    string line, numbers;

    // A counter for the while loop to know how many data was collected for the average equation
    int count = 0,
        heightCount = 0,
        aboveCornCount = 0,
        aboveGroundCount = 0;

    // The minimum corn height determined by the user
    double minHeight;

    // Ask the user for the minimum height for the corn
    cout << "Enter minimum height of a corn plant in inches: ";
    cin >> minHeight;

    // Initializing double variable to sum all data and get the average
    double speedTotal = 0,
            altTotal = 0,
            satTotal = 0,
            tempTotal = 0,
            heightTotal = 0,
            humidityAbove = 0,
            humidityTotal = 0;

    // Variables to get the difference of each data with the average and square it for the standard deviation
    double speedDeviation = 0,
            altDeviation = 0,
            satDeviation = 0,
            tempDeviation = 0,
            heightDeviation = 0,
            humidityAboveDeviation = 0,
            humidityDeviation = 0;

    // Read the first line of the file
    getline(inFS, line);
    // Start reading from the second line of the file
    while(getline(inFS, line)){
        // make sure the vector is clear and ready for new data
        data.clear();

        // converting each line in the file to a string stream
        stringstream  lineStream(line);
        // break each line into single data and add it to the vector
        while(getline(lineStream, numbers, ',')) {
            data.push_back(numbers);
        }
        // convert vector data from string to double and add it to it's assigned variable
        speedTotal += stod(data[4]);
        altTotal += stod(data[6]);
        satTotal += stod(data[7]);
        tempTotal += stod(data[9]);
        // checking if the corn height meets the minimum user requirements
        if((stod(data[15]) - stod(data[12]) >= minHeight)){
            heightTotal += (stod(data[15]) - stod(data[12]));
            heightCount++;
        }
        // Checking if the sensor is above the corn to get relative humidity above corn
        if ((stod(data[15]) - stod(data[12]) >= minHeight)){
            humidityAbove += stod(data[8]);
            aboveCornCount++;
        }
        // if the sensor is not above corn get the relative humidity above ground
        else {
            humidityTotal += stod(data[8]);
            aboveGroundCount++;
        }
        // An accumulator to get the number of lines in the file
        count++;
    }

    // Close the file
    inFS.close();

    // Reopen the file to get the data for standard deviation.
    inFS.open(file);
    // Return and error code and a message to the user if file was not opened
    if (!inFS.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    // Read the first line
    getline(inFS, line);
    // Start collecting data from second line
    while(getline(inFS, line)){
        // clearing all data in the vector
        data.clear();

        // converting each line in the file to a string stream
        stringstream  lineStream(line);
        // break each line into single data and add it to the vector
        while(getline(lineStream, numbers, ',')) {
            data.push_back(numbers);
        }
        // convert vector data from string to double and add it to it's assigned variable
        speedDeviation += (stod(data[4]) - speedTotal/count) * (stod(data[4]) - speedTotal/count);
        altDeviation += (stod(data[6]) - altTotal/count) * (stod(data[6]) - altTotal/count);
        satDeviation += (stod(data[7]) - satTotal/count) * (stod(data[7]) - satTotal/count);
        tempDeviation += (stod(data[9]) - tempTotal/count) * (stod(data[9]) - tempTotal/count);
        // checking if the corn height meets the minimum user requirements
        if((stod(data[15]) - stod(data[12]) >= minHeight)){
            heightDeviation += ((stod(data[15]) - stod(data[12])) - heightTotal/heightCount) *
                    ((stod(data[15]) - stod(data[12])) - heightTotal/heightCount);
        }
        // Checking if the sensor is above the corn to get relative humidity above corn
        if ((stod(data[15]) - stod(data[12]) >= minHeight)){
            humidityAboveDeviation += (stod(data[8]) - humidityAbove/aboveCornCount) *
                    (stod(data[8]) - humidityAbove/aboveCornCount);
        }
            // if the sensor is not above corn get the relative humidity above ground
        else
            humidityDeviation += (stod(data[8]) - humidityTotal/aboveGroundCount) *
                    (stod(data[8]) - humidityTotal/aboveGroundCount);
    }

    // Close the file
    inFS.close();

    // A space to separate user input from output message
    cout << endl;
    // Outputting the average and standard deviation in a user-friendly way
    cout << "The average speed of the sprayer was " << speedTotal/count
         << " mph with standard deviation " << sqrt(speedDeviation/count) << " mph." << endl;
    cout << "The average altitude above mean sea level was " << altTotal/count
         << " m with standard deviation " << sqrt(altDeviation/count) << " m." << endl;
    cout << "The average number of satellites was " << satTotal/count
         << " with standard deviation " << sqrt(satDeviation/count) << "." << endl;
    cout << "The average temperature was " << tempTotal/count
         << " C with standard deviation " << sqrt(tempDeviation/count) << " C." << endl;
    cout << "The average height of the corn plants was " << heightTotal/heightCount
         << " in with standard deviation " << sqrt(heightDeviation/heightCount) << " in." << endl;
    cout << "The average relative humidity when above corn plants was " << humidityAbove/aboveCornCount
         << "% with standard deviation " << sqrt(humidityAboveDeviation/aboveCornCount) << "%." << endl;
    cout << "The average relative humidity when not above corn plants was " << humidityTotal/aboveGroundCount
         << "% with standard deviation " << sqrt(humidityDeviation/aboveGroundCount) << "%." << endl;

    return 0;
}
