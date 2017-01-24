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
#include <vector>

using namespace std;

double average(double rollsArray[], int numLines) {
    double average = 0;

    for (int i = 0; i < numLines; i++) {
        average += rollsArray[i];
    }
    average /= numLines;

    return average;
}

int numRed(double rollsArray[], int numLines) {
    int numRed = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 0 && phNum <= 47.49) {
            numRed++;
        }
    }
    return numRed;
}

int numBlue(double rollsArray[], int numLines) {
    int numBlue = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 52.50 && phNum <= 99.99) {
            numBlue++;
        }
    }
    return numBlue;
}

int numGreen(double rollsArray[], int numLines) {
    int numGreen = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 47.50 && phNum <= 52.49) {
            numGreen++;
        }
    }
    return numGreen;
}

int numYellow(double rollsArray[], int numLines) {
    int numYellow = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum <= 0.99) {
            numYellow++;
        }
    }
    return numYellow;
}

double pctRed(double rollsArray[], int numLines) {
    double pctRed = 0;
    int phNumRed = numRed(rollsArray, numLines);
    pctRed = (phNumRed/(double)numLines) * 100;
    return pctRed;
}

double pctBlue(double rollsArray[], int numLines) {
    double pctBlue = 0;
    int phNumBlue = numBlue(rollsArray, numLines);
    pctBlue = (phNumBlue/(double)numLines) * 100;
    return pctBlue;
}

double pctGreen(double rollsArray[], int numLines) {
    double pctGreen = 0;
    int phNumGreen = numGreen(rollsArray, numLines);
    pctGreen = (phNumGreen/(double)numLines) * 100;
    return pctGreen;
}

double pctYellow(double rollsArray[], int numLines) {
    double pctYellow = 0;
    int phNumYellow = numYellow(rollsArray, numLines);
    pctYellow = (phNumYellow/(double)numLines) * 100;
    return pctYellow;
}

double redPctDiff(double rollsArray[], int numLines) {
    double phNum = pctRed(rollsArray, numLines);

    return phNum - 47.50;

}

double bluePctDiff(double rollsArray[], int numLines) {
    double phNum = pctBlue(rollsArray, numLines);

    return phNum - 47.50;

}

int longestRedDrought(double rollsArray[], int numLines) {
    int currRedDrought = 0;
    int redDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 0.00 && phNum <= 47.49) {
            currRedDrought = 0;
        } else {
            currRedDrought++;
        }

        if (currRedDrought > redDrought) {
            redDrought = currRedDrought;
        }

    }
    return redDrought;
}

int longestBlueDrought(double rollsArray[], int numLines) {
    int currBlueDrought = 0;
    int blueDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 52.50 && phNum <= 99.99) {
            currBlueDrought = 0;
        } else {
            currBlueDrought++;
        }

        if (currBlueDrought > blueDrought) {
            blueDrought = currBlueDrought;
        }

    }
    return blueDrought;
}

int longestGreenDrought(double rollsArray[], int numLines) {
    int currGreenDrought = 0;
    int greenDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 47.50 && phNum <= 52.49) {
            currGreenDrought = 0;
        } else {
            currGreenDrought++;
        }

        if (currGreenDrought > greenDrought) {
            greenDrought = currGreenDrought;
        }
    }
    return greenDrought;
}

int longestYellowDrought(double rollsArray[], int numLines) {
    int currYellowDrought = 0;
    int yellowDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 0.00 && phNum <= 0.99) {
            currYellowDrought = 0;
        } else {
            currYellowDrought++;
        }

        if (currYellowDrought > yellowDrought) {
            yellowDrought = currYellowDrought;
        }

    }
    return yellowDrought;
}

int currentRedDrought(double rollsArray[], int numLines) {
    int currentRedDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = rollsArray[i];

        if (phNum >= 47.50) {
            currentRedDrought++;
        } else {
            break;
        }
    }
    return currentRedDrought;
}

int currentBlueDrought(double rollsArray[], int numLines) {
    int currentBlueDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = rollsArray[i];

        if (phNum <= 52.49) {
            currentBlueDrought++;
        } else {
            break;
        }
    }
    return currentBlueDrought;
}

int currentGreenDrought(double rollsArray[], int numLines) {
    int currentGreenDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = rollsArray[i];

        if (phNum <= 47.49 || phNum >= 52.50) {
            currentGreenDrought++;
        } else {
            break;
        }
    }
    return currentGreenDrought;
}

int currentYellowDrought(double rollsArray[], int numLines) {
    int currentYellowDrought = 0;
    double phNum = 0;

    for (int i = numLines-1; i >= 0; i--) {
        phNum = rollsArray[i];

        if (phNum >= 1) {
            currentYellowDrought++;
        } else {
            break;
        }
    }
    return currentYellowDrought;
}

void printColorBreakdown(double rollsArray[], int numLines) {
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

void printLongestDroughts(double rollsArray[], int numLines) {
    int phRedDrought = longestRedDrought(rollsArray, numLines);
    int phBlueDrought = longestBlueDrought(rollsArray, numLines);
    int phGreenDrought = longestGreenDrought(rollsArray, numLines);
    int phYellowDrought = longestYellowDrought(rollsArray, numLines);

    cout << "| Largest Red Drought:    " << phRedDrought << endl;
    cout << "| Largest Blue Drought:   " << phBlueDrought << endl;
    cout << "| Largest Green Drought:  " << phGreenDrought << endl;
    cout << "| Largest Yellow Drought: " << phYellowDrought << endl;
}

void printDataInTable(double rollsArray[], int numLines) {

    double xRed = pctRed(rollsArray, numLines);
    double xBlue = pctBlue(rollsArray, numLines);
    double xGreen = pctGreen(rollsArray, numLines);
    double xYellow = pctYellow(rollsArray, numLines);
    double yRed = floor(xRed * 10000) / 10000;
    double yBlue = floor(xBlue * 10000) / 10000;
    double yGreen = floor(xGreen * 10000) / 10000;
    double yYellow = floor(xYellow * 10000) / 10000;

    cout << "Roll #:  " << numLines << endl;
    cout << "Average: " << average(rollsArray, numLines) << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|          |  # Rolls  |    Roll %    |  Current Drought  |  Max Drought  |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Red     |" << setw(7) << numRed(rollsArray, numLines) <<  "    |   " << setprecision(4) << fixed << xRed << "%   |         " << currentRedDrought(rollsArray, numLines) << "         |      " << longestRedDrought(rollsArray, numLines) << "        |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Blue    |" << setw(7) << numBlue(rollsArray, numLines) << "    |   " << setprecision(4) << fixed << xBlue << "%   |         " << currentBlueDrought(rollsArray, numLines) << "         |      " << longestBlueDrought(rollsArray, numLines) << "       |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Green   |" << setw(7) << numGreen(rollsArray, numLines) << "     |   " << setprecision(5) << fixed << xGreen << "%   |         " << currentGreenDrought(rollsArray, numLines) << "        |      " << longestGreenDrought(rollsArray, numLines) << "       |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|  Yellow  |" << setw(7) << numYellow(rollsArray, numLines) << "     |   " << setprecision(5) << fixed << xYellow << "%   |        "<< currentYellowDrought(rollsArray, numLines) << "        |      " << longestYellowDrought(rollsArray, numLines) << "      |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << endl;
}

void outputAllDroughts(double rollsArray[], int numLines) {
    vector<int> yellowDroughts;

    double phNum = 0;
    int yellowDroughtCounter = 0;
    double yellowDroughtAvg = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];
        if (!(phNum >= 00.00 && phNum <= 0.99)) { 
            yellowDroughtCounter++; 
        } else { 
            yellowDroughts.push_back(yellowDroughtCounter); 
            yellowDroughtCounter = 0; 
        }

        if ((i == (numLines-1)) && (!(phNum >= 00.00 && phNum <= 0.99))) { 
            yellowDroughts.push_back(yellowDroughtCounter);
        }
    }

    cout << "Yellow Droughts: " << endl;

    for (int i = 0; i < yellowDroughts.size(); i++) {
        cout << (i+1) << ". ";
        cout << yellowDroughts.at(i) << endl;
    }

    phNum = 0;
    for (int i = 0; i < yellowDroughts.size(); i++) {
        phNum = yellowDroughts.at(i);
        yellowDroughtAvg += phNum;

    }

    yellowDroughtAvg /= yellowDroughts.size();

    cout << "Yellow Drought Average: " << yellowDroughtAvg << endl;

}

void fileoutRedDroughts(double rollsArray[], int numLines, int seedNum) {

    string seedNumString = to_string(seedNum);

    ofstream outfile;
    outfile.open("../data/droughts/ " + seedNumString + "_red_droughts.txt");

    vector<int> redDroughts;

    double phNum = 0;
    int redDroughtCounter = 0;
    double redDroughtAvg = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];
        if (!(phNum >= 00.00 && phNum <= 47.49)) { 
            redDroughtCounter++;
        } else {
            redDroughts.push_back(redDroughtCounter); 
            redDroughtCounter = 0; 
        }

        if ((i == (numLines-1)) && (!(phNum >= 00.00 && phNum <= 47.49))) { 
            redDroughts.push_back(redDroughtCounter);
        }
    }

    for (int i = 0; i < redDroughts.size(); i++) {
        outfile << redDroughts.at(i) << endl;
    }

    outfile.close();
}

void fileoutBlueDroughts(double rollsArray[], int numLines, int seedNum) {

    string seedNumString = to_string(seedNum);

    ofstream outfile;
    outfile.open("../data/droughts/ " + seedNumString + "_blue_droughts.txt");

    vector<int> blueDroughts;

    double phNum = 0;
    int blueDroughtCounter = 0;
    double blueDroughtAvg = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];
        if (!(phNum >= 52.50 && phNum <= 99.99)) { 
            blueDroughtCounter++; 
        } else { 
            blueDroughts.push_back(blueDroughtCounter); 
            blueDroughtCounter = 0; 
        }

        if ((i == (numLines-1)) && (!(phNum >= 52.50 && phNum <= 99.99))) { 
            blueDroughts.push_back(blueDroughtCounter);
        }
    }

    for (int i = 0; i < blueDroughts.size(); i++) {
        outfile << blueDroughts.at(i) << endl;
    }

    outfile.close();
}

void fileoutGreenDroughts(double rollsArray[], int numLines, int seedNum) {

    string seedNumString = to_string(seedNum);

    ofstream outfile;
    outfile.open("../data/droughts/ " + seedNumString + "_green_droughts.txt");

    vector<int> greenDroughts;

    double phNum = 0;
    int greenDroughtCounter = 0;
    double greenDroughtAvg = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];
        if (!(phNum >= 47.50 && phNum <= 52.49)) { 
            greenDroughtCounter++; 
        } else { 
            greenDroughts.push_back(greenDroughtCounter); 
            greenDroughtCounter = 0; 
        }

        if ((i == (numLines-1)) && (!(phNum >= 47.50 && phNum <= 52.49))) { 
            greenDroughts.push_back(greenDroughtCounter);
        }
    }

    for (int i = 0; i < greenDroughts.size(); i++) {
        outfile << greenDroughts.at(i) << endl;
    }

    outfile.close();
}

void fileoutYellowDroughts(double rollsArray[], int numLines, int seedNum) {

    string seedNumString = to_string(seedNum);

    ofstream outfile;
    outfile.open("../data/droughts/ " + seedNumString + "_yellow_droughts.txt");

    vector<int> yellowDroughts;

    double phNum = 0;
    int yellowDroughtCounter = 0;
    double yellowDroughtAvg = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];
        if (!(phNum >= 00.00 && phNum <= 0.99)) { 
            yellowDroughtCounter++; 
        } else {
            yellowDroughts.push_back(yellowDroughtCounter); 
            yellowDroughtCounter = 0;
        }

        if ((i == (numLines-1)) && (!(phNum >= 00.00 && phNum <= 0.99))) { 
            yellowDroughts.push_back(yellowDroughtCounter);
        }
    }

    for (int i = 0; i < yellowDroughts.size(); i++) {
        outfile << yellowDroughts.at(i) << endl;
    }

    outfile.close();
}

void updateAllFiles(double rollsArray[], int numLines, int seedNum) {

    fileoutRedDroughts(rollsArray, numLines, seedNum);
    fileoutBlueDroughts(rollsArray, numLines, seedNum);
    fileoutGreenDroughts(rollsArray, numLines, seedNum);
    fileoutYellowDroughts(rollsArray, numLines, seedNum);
}

int main(int argc, char *argv[]) {

    bool endProgram = false;
    int numLines = 0;
    const int rollSize = 2400;

    string seedNumAsString = (string)argv[1];
    int seedNum = stoi(seedNumAsString);

    double rolls[rollSize];

    numLines = 0; 

    for (int i = 0; i < rollSize; i++) { rolls[i] = 0; }

    string fileName = "../data/rolls/" + (string)argv[1] + "_rolls.txt";
    
    ifstream rollsFile(fileName);

    if ( !rollsFile ) {
       cerr << "Error: File could not be opened" << endl;
       exit( EXIT_FAILURE );
    }

    string rollValueAsString;
    double rollValue = 0;
    int counter = 0;
    while (!rollsFile.eof()) {
        numLines++; 
        getline(rollsFile, rollValueAsString);
        stringstream ss(rollValueAsString);
        ss >> rollValue;
        rolls[counter] = rollValue;
        counter++;
        ss.clear(); 
    } 
    numLines--;

    cout << "Red % difference from 47.5%: " << redPctDiff(rolls, numLines) << "%" << endl;

    cout << "Blue % difference from 47.5%: " << bluePctDiff(rolls, numLines) << "%" << endl;

    updateAllFiles(rolls, numLines, seedNum);

    return 0;
} 
