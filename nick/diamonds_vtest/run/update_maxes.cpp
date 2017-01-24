#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

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
            redDrought = currRedDrought-1;
        }

    }
    return redDrought;
}

int longestYellowDrought(double rollsArray[], int numLines) {
    int currYellowDrought = 0;
    int yellowDrought = 0;
    double phNum = 0;

    for (int i = 0; i < numLines; i++) {
        phNum = rollsArray[i];

        if (phNum >= 0.00 && phNum <= 01.00) {
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
            blueDrought = currBlueDrought-1;
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
            greenDrought = currGreenDrought-1;
        }
    }
    return greenDrought;
}



int main() {
    const int rollSize = 2400;
    
    string seedNum;
    ifstream seedFile("../data/current_seed.txt");
    getline(seedFile, seedNum);

    vector<int> maxDroughtYellow;
    vector<int> maxDroughtGreen;
    vector<int> maxDroughtRed;
    vector<int> maxDroughtBlue;   

    int limit;
    stringstream(seedNum) >> limit;
    
    for (int currentSeed = 2; currentSeed < limit; currentSeed++) {
     
      double rolls[rollSize];      
    
      for (int y = 0; y < rollSize; y++) {
        rolls[y]  = 0;
      }

      string currSeed;
      ostringstream convert;
      convert << currentSeed;
      currSeed = convert.str();      
      string fileName = "../data/rolls/" + currSeed + "_rolls.txt";
      ifstream rollsFile(fileName.c_str());
      
      string rollValueAsString;
      double rollValue = 0;  
      int numLines = 0;
      int counter = 0;
      while (!rollsFile.eof()) {
        numLines++;
        getline(rollsFile, rollValueAsString);
        double rollValue;
        stringstream(rollValueAsString) >> rollValue;
        rolls[counter] = rollValue;
        counter++;
      } 
      
      numLines--;
    
      double xRed = pctRed(rolls, numLines);
      double xBlue = pctBlue(rolls, numLines);
      double xGreen = pctGreen(rolls, numLines);
      double xYellow = pctYellow(rolls, numLines);
      double yRed = floor(xRed * 10000) / 10000;
      double yBlue = floor(xBlue * 10000) / 10000;
      double yGreen = floor(xGreen * 10000) / 10000;
      double yYellow = floor(xYellow * 10000) / 10000;

      maxDroughtYellow.push_back(longestYellowDrought(rolls, numLines));
      maxDroughtGreen.push_back(longestGreenDrought(rolls, numLines));
      maxDroughtRed.push_back(longestRedDrought(rolls, numLines));
      maxDroughtBlue.push_back(longestBlueDrought(rolls, numLines));
    }
    
    ofstream outRed;
    outRed.open("../data/max/max_red_drought.txt");
    outRed << *max_element(maxDroughtRed.begin(), maxDroughtRed.end()) << endl;
 
    ofstream outBlue;
    outBlue.open("../data/max/max_blue_drought.txt");
    outBlue << *max_element(maxDroughtBlue.begin(), maxDroughtBlue.end()) << endl;

    ofstream outYellow;
    outYellow.open("../data/max/max_yellow_drought.txt");
    outYellow << *max_element(maxDroughtYellow.begin(), maxDroughtYellow.end()) << endl;

    ofstream outGreen;
    outGreen.open("../data/max/max_green_drought.txt");
    outGreen << *max_element(maxDroughtGreen.begin(), maxDroughtGreen.end()) << endl;

    outRed.close();
    outBlue.close();
    outYellow.close();
    outGreen.close();

    return 0;
} 
