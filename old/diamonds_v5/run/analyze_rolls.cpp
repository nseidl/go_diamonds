//
//  main.cpp runs simple statistical analysis on a rolls.txt file.
//  PROJECT_CSGODIAMONDS
//


#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <unistd.h>

using namespace std;

// numLines is the number of entries currently in the file
double average(double* rollsArray, int numLines) {
    double average = 0;

    for (int i = 0; i < numLines; i++) {
        average += *(rollsArray + i);
    }
    average /= numLines;

    return average;
}

int numRed(double* rollsArray, int numLines) {
    int numRed = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 0 && phNum <= 47.49) {
            numRed++;
        }
    }
    return numRed;
}

int numBlue(double* rollsArray, int numLines) {
    int numBlue = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 52.50 && phNum <= 99.99) {
            numBlue++;
        }
    }
    return numBlue;
}

int numGreen(double* rollsArray, int numLines) {
    int numGreen = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 47.50 && phNum <= 52.49) {
            numGreen++;
        }
    }
    return numGreen;
}

int numYellow(double* rollsArray, int numLines) {
    int numYellow = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum <= 0.99) {
            numYellow++;
        }
    }
    return numYellow;
}

double pctRed(double* rollsArray, int numLines) {
    double pctRed = 0;
    int phNumRed = numRed(rollsArray, numLines);
    pctRed = (phNumRed/(double)numLines) * 100;
    return pctRed;
}

double pctBlue(double* rollsArray, int numLines) {
    double pctBlue = 0;
    int phNumBlue = numBlue(rollsArray, numLines);
    pctBlue = (phNumBlue/(double)numLines) * 100;
    return pctBlue;
}

double pctGreen(double* rollsArray, int numLines) {
    double pctGreen = 0;
    int phNumGreen = numGreen(rollsArray, numLines);
    pctGreen = (phNumGreen/(double)numLines) * 100;
    return pctGreen;
}

double pctYellow(double* rollsArray, int numLines) {
    double pctYellow = 0;
    int phNumYellow = numYellow(rollsArray, numLines);
    pctYellow = (phNumYellow/(double)numLines) * 100;
    return pctYellow;
}

int longestRedDrought(double* rollsArray, int numLines) {
    int currRedDrought = 0;
    int redDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 0.00 && phNum <= 47.49) {
            currRedDrought = 0;
        } else {
            currRedDrought++;
        }

        if (currRedDrought > redDrought) {
            redDrought = currRedDrought-1;
        }

    }
    return redDrought;
}

int longestBlueDrought(double* rollsArray, int numLines) {
    int currBlueDrought = 0;
    int blueDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 52.50 && phNum <= 99.99) {
            currBlueDrought = 0;
        } else {
            currBlueDrought++;
        }

        if (currBlueDrought > blueDrought) {
            blueDrought = currBlueDrought-1;
        }

    }
    return blueDrought;
}

int longestGreenDrought(double* rollsArray, int numLines) {
    int currGreenDrought = 0;
    int greenDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 47.50 && phNum <= 52.49) {
            currGreenDrought = 0;
        } else {
            currGreenDrought++;
        }

        if (currGreenDrought > greenDrought) {
            greenDrought = currGreenDrought-1;
        }
    }
    return greenDrought;
}

int longestYellowDrought(double* rollsArray, int numLines) {
    int currYellowDrought = 0;
    int yellowDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = *(rollsArray + i);

        if (phNum >= 0.00 && phNum <= 0.99) {
            currYellowDrought = 0;
        } else {
            currYellowDrought++;
        }

        if (currYellowDrought > yellowDrought) {
            yellowDrought = currYellowDrought-1;
        }

    }
    return yellowDrought;
}

void printColorBreakdown(double* rollsArray, int numLines) {
    int phNumRed = numRed(rollsArray, numLines);
    int phNumBlue = numBlue(rollsArray, numLines);
    int phNumGreen = numGreen(rollsArray, numLines);
    int phNumYellow = numYellow(rollsArray, numLines);

    double phPctRed = pctRed(rollsArray, numLines);
    double phPctBlue = pctBlue(rollsArray, numLines);
    double phPctGreen = pctGreen(rollsArray, numLines);
    double phPctYellow = pctYellow(rollsArray, numLines);

    cout << "Red:    " << phNumRed <<  " (" << phPctRed << "%)." << endl;
    cout << "Blue:   " << phNumBlue <<  " (" << phPctBlue << "%)." << endl;
    cout << "Green:  " << phNumGreen <<  " (" << phPctGreen << "%)." << endl;
    cout << "Yellow: " << phNumYellow <<  " (" << phPctYellow << "%)." << endl;
}

void printLongestDroughts(double* rollsArray, int numLines) {
    int phRedDrought = longestRedDrought(rollsArray, numLines);
    int phBlueDrought = longestBlueDrought(rollsArray, numLines);
    int phGreenDrought = longestGreenDrought(rollsArray, numLines);
    int phYellowDrought = longestYellowDrought(rollsArray, numLines);

    cout << "Largest Red Drought:    " << phRedDrought << endl;
    cout << "Largest Blue Drought:   " << phBlueDrought << endl;
    cout << "Largest Green Drought:  " << phGreenDrought << endl;
    cout << "Largest Yellow Drought: " << phYellowDrought << endl;
}



int main(int argc, char *argv[]) {

    bool endProgram = false;
    int numLines = 0;
    const int rollSize = 2400;

    double* rolls = new double[rollSize];

    cout << endl;

    numLines = 0; // reset numLines to 0 each iteration

    // Populate array with all 0's
    for (int i = 0; i < rollSize; i++) {
        *(rolls + i) = 0;
    }

    string fileName = "../data/" + (string)argv[1] + "_rolls.txt";
    //cout << "Initializing PROJECT_CSGODIAMONDS" << endl;

    ifstream rollsFile(fileName, ios::in);

    // Error in opening crop file
    if ( !rollsFile ) {
       cerr << "Error: File could not be opened" << endl;
       exit( EXIT_FAILURE );
    }

    // Variable declarations for while loop below
    string rollValueAsString;
    double rollValue = 0;
    int counter = 0;
    // Convert each line from string to int and store in array
    while (!rollsFile.eof()) {
        numLines++; // Increment numLines to determine what current roll is

        getline(rollsFile, rollValueAsString);
        stringstream ss(rollValueAsString);
        ss >> rollValue;

        *(rolls + counter) = rollValue;

        counter++;

        ss.clear(); // Flush ss
    } //end while
    // Decrement number of lines in order to compensate for EOF \n
    numLines--;

    // Display number of lines
    cout << "Number of lines: " << numLines << endl;

    // Display average
    double phAverage = average(rolls, numLines);
    cout << "Average: " << phAverage << endl;

    // Display color breakdown
    printColorBreakdown(rolls, numLines);

    //Display color droughts
    printLongestDroughts(rolls, numLines);

    cout << endl;

    return 0;
} // end main()
