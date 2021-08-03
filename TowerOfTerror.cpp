// File Name: TowerOfTerror.cpp
//
// Auther Samuel Manzanares
// Date: 06/17/2021
// Assignment Number: 4
// CS 2308.501 Summer 2021
// Instructor: Dr. J. Marcos Palacios

 The Twilight Zone Tower of Terroris a popular attraction at Disney's
 Hollywood Studios. It is very popular accelerated-dropelevator
 ride with a limit capacity per ride. due to covid restriction and
 long lines, the we were ask to wrrite a C++ program of a 
 dynamic queue of reservations to help with crowd managment.
 the program must alter the capacity per ride dependent on covid
 restriction regulations at current time. the queue will hold the name
 and size of the party and run FIFO implementation. each ride will
 be filled as much as possible without exceeding capacity, while
 respecting the queue and not skipping any parties in queue.

//****************This is the line of 80 characters in length*******************

#include <iostream>
#include "Queue.h"
using namespace std;

#include <iomanip>
#include <fstream>
#include <string>


//***********************************************************
// inputData: inputs data from file
//
// iQueue: input queue passby reference 
// num: perctage capacity passby reference 
// void return type 
//***********************************************************
void inputData(Queue &iQueue, double &num) {

    ifstream fin; 

    fin.open("reservations.txt");

    // Error check to ensure the input file opened:
    if (!fin) {
        cout << "Could not open file. Terminating program.\n";
    }

    fin >> num;

    while (!fin.eof()) {
        string party = "";
        int num = 0;

        fin >> party;
        fin >> num;

        iQueue.enqueue(num, party);
    }
}

//***********************************************************
// titalOutput: tital output 
//
// regCap: normal capcity for ride
// curCap: covid-19 restriction campacity 
// void return type 
//***********************************************************
void titalOutput (const int regCap, int curCap) {
    cout << "\nTower of Terror Schedule\n";
    cout << "\nRegular capacity: " << regCap << endl;
    cout << "\nCurrent capacity: " << curCap << endl << endl;
}

//***********************************************************
// rideNumOutput: outputs ride number
//
// rideNum: number of rides at current pass of loop 
// void return type 
//***********************************************************
void rideNumOutput (int rideNum) {
    cout << "Ride #" << rideNum << endl;
}

//***********************************************************
// singlerideOutput: ouput for each dequeue on ride
//
// partyNum: value from front queue 
// partyName: name from front queue
// void return type 
//***********************************************************
void singlerideOutput (int partyNum, string partyName) {
    cout << partyName << " " << partyNum << endl;
}

//***********************************************************
// singleRideSumOutput: summary of single ride 
//
// rideGuest: number of guess per single ride 
// remCap:remaining capacity of single ride 
// void return type 
//***********************************************************
void singleRideSumOutput (int rideGuest, int remCap) {
    cout << "Total guests: " << rideGuest << endl;
    cout << "Remaining capacity: " << remCap << endl << endl;
}

//***********************************************************
// totalSumOutput: summary of rides from entire queue
//
// totalGuest: total guest on ride from entire queue
// rideNum: number of rides given from queue
// void return type 
//***********************************************************
void totalSumOutput (int totalGuest, int rideNum) {
    cout << "Overall number of guests: " << totalGuest << endl;
    cout << "Overall number of rides: " << rideNum << endl << endl;
}

int main() {
    int const CAP = 50;     // const ride capacity of elevator 
    int currentCap, rideCap, rideNum = 0, totGuest = 0;
    // todaysCap; ride capacity based off covid rescription capacity %
    // rideCap; ride capacity counter used for individual rides
    // rideNum; counts number of rides given 
    // totGuest; counts total number of riders from queue 

    double percCap; // takes in percetnage of capacity

    Queue partyQueue;

    inputData(partyQueue, percCap);

    currentCap = CAP * percCap;

    titalOutput(CAP, currentCap);

    while(!partyQueue.isEmpty()) {

        rideCap = currentCap;   // resets ride capacity for inidivual rides
        rideNum++;              // increments number of rides
        int size;               // counts value in front queue
        
        if (rideCap == currentCap) {            // reset for individual ride;
            int rideGuest = 0, remCap = 0;
            // rideGuest: counts guest per ride
            // remCap: counts remaining capacity for each ride

            rideNumOutput(rideNum);

            size = partyQueue.getSizeAtFront();

            while (size < rideCap && !partyQueue.isEmpty()) {
                int num; 
                string party;

                partyQueue.dequeue(num, party);
                singlerideOutput(num, party);

                rideCap -= num;
                rideGuest += num;

                if (!partyQueue.isEmpty()) {
                    size = partyQueue.getSizeAtFront();
                }
            }

            remCap = currentCap - rideGuest;
            totGuest += rideGuest;

            singleRideSumOutput(rideGuest, remCap);
        }
    }

    totalSumOutput(totGuest, rideNum);

    return 0; 
}
