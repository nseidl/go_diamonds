#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

using namespace std;

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

int currentRedDrought(double* rollsArray, int numLines) {
    int currentRedDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = *(rollsArray + i);

        if (phNum >= 47.50) {
            currentRedDrought++;
        } else {
            break;
        }
    }
    return currentRedDrought;
}

int currentBlueDrought(double* rollsArray, int numLines) {
    int currentBlueDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = *(rollsArray + i);

        if (phNum <= 52.49) {
            currentBlueDrought++;
        } else {
            break;
        }
    }
    return currentBlueDrought;
}

int currentGreenDrought(double* rollsArray, int numLines) {
    int currentGreenDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = *(rollsArray + i);

        if (phNum <= 47.49 || phNum >= 52.50) {
            currentGreenDrought++;
        } else {
            break;
        }
    }
    return currentGreenDrought;
}

int currentYellowDrought(double* rollsArray, int numLines) {
    int currentYellowDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = *(rollsArray + i);

        if (phNum >= 1) {
            currentYellowDrought++;
        } else {
            break;
        }
    }
    return currentYellowDrought;
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

    cout << "| Red:    " << phNumRed <<  " (" << phPctRed << "%)." << endl;
    cout << "| Blue:   " << phNumBlue <<  " (" << phPctBlue << "%)." << endl;
    cout << "| Green:  " << phNumGreen <<  " (" << phPctGreen << "%)." << endl;
    cout << "| Yellow: " << phNumYellow <<  " (" << phPctYellow << "%)." << endl;
}

void printLongestDroughts(double* rollsArray, int numLines) {
    int phRedDrought = longestRedDrought(rollsArray, numLines);
    int phBlueDrought = longestBlueDrought(rollsArray, numLines);
    int phGreenDrought = longestGreenDrought(rollsArray, numLines);
    int phYellowDrought = longestYellowDrought(rollsArray, numLines);

    cout << "| Largest Red Drought:    " << phRedDrought << endl;
    cout << "| Largest Blue Drought:   " << phBlueDrought << endl;
    cout << "| Largest Green Drought:  " << phGreenDrought << endl;
    cout << "| Largest Yellow Drought: " << phYellowDrought << endl;
}

void printDataInTable(double* rollsArray, int numLines) {
    double xRed = pctRed(rollsArray, numLines);
    double xBlue = pctBlue(rollsArray, numLines);
    double xGreen = pctGreen(rollsArray, numLines);
    double xYellow = pctYellow(rollsArray, numLines);
    double yRed = floor(xRed * 10000) / 10000;
    double yBlue = floor(xBlue * 10000) / 10000;
    double yGreen = floor(xGreen * 10000) / 10000;
    double yYellow = floor(xYellow * 10000) / 10000;

    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|          |  # Rolls  |    Roll %    |  Current Drought  |  Max Drought  |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Red     |    " << numRed(rollsArray, numLines) <<  "    |   " << setprecision(4) << fixed << xRed << "%   |         " << currentRedDrought(rollsArray, numLines) << "         |      " << longestRedDrought(rollsArray, numLines) << "        |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Blue    |    " << numBlue(rollsArray, numLines) << "    |   " << setprecision(4) << fixed << xBlue << "%   |         " << currentBlueDrought(rollsArray, numLines) << "         |      " << longestBlueDrought(rollsArray, numLines) << "       |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Green   |    " << numGreen(rollsArray, numLines) << "     |   " << setprecision(5) << fixed << xGreen << "%   |         " << currentGreenDrought(rollsArray, numLines) << "         |      " << longestGreenDrought(rollsArray, numLines) << "       |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Yellow  |    " << numYellow(rollsArray, numLines) << "     |   " << setprecision(5) << fixed << xYellow << "%   |        "<< currentYellowDrought(rollsArray, numLines) << "        |      " << longestYellowDrought(rollsArray, numLines) << "      |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}



int main(int argc, char *argv[]) {

    bool endProgram = false;
    int numLines = 0;
    const int rollSize = 2400;

    double* rolls = new double[rollSize];

    numLines = 0; // reset numLines to 0 each iteration

    for (int i = 0; i < rollSize; i++) {
        *(rolls + i) = 0;
    }

    string fileName = "../data/rolls/" + (string)argv[1] + "_rolls.txt";

    ifstream rollsFile(fileName, ios::in);

    if ( !rollsFile ) {
       cerr << "Error: File could not be opened" << endl;
       exit( EXIT_FAILURE );
    }

    string rollValueAsString;
    double rollValue = 0;
    int counter = 0;
    
    while (!rollsFile.eof()) {
        numLines++; // Increment numLines to determine what current roll is

        getline(rollsFile, rollValueAsString);
        stringstream ss(rollValueAsString);
        ss >> rollValue;

        *(rolls + counter) = rollValue;

        counter++;

        ss.clear(); // Flush ss
    } 

    numLines--;

    printDataInTable(rolls, numLines);

    return 0;
} 
