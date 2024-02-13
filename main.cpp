#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

// global variables
std::vector<Point2D> point2DList;
std::vector<Point3D> point3DList;
std::vector<Line2D> line2DList;
std::vector<Line3D> line3DList;

// Function prototypes
void displayMenu();
void readData();
void specifyFilteringCriteria();
void specifySortingCriteria();
void specifySortingOrder();
void viewData();
void storeData();

int getUserChoice();



template<typename T>
void removeDuplicates(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}


// Function to display the menu 
void displayMenu() {
    std::cout << std::endl;
    std::cout << "Welcome to Assn3 program!" << std::endl;
    std::cout << "1) Read in data" << std::endl;
    std::cout << "2) Specify filtering criteria (current: Point2D)" << std::endl;
    std::cout << "3) Specify sorting criteria (current: x-coordinate)" << std::endl;
    std::cout << "4) Specify sorting order (current: ASC)" << std::endl;
    std::cout << "5) View data" << std::endl;
    std::cout << "6) Store data" << std::endl;
    std::cout << "0) Exit" << std::endl;
    

}

int getUserChoice()
{
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;

    // Handle invalid input
    while (std::cin.fail() || choice < 0 || choice > 6 ) {
        std::cout << "Invalid input. Please enter a number between 1 and 6: ";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> choice;
    }
    return choice;
}



void readData() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string objectType;
        std::getline(iss, objectType, ','); // Read object type until comma
        objectType.erase(std::remove(objectType.begin(), objectType.end(), ' '), objectType.end()); // Remove spaces
        std::cout << "Object type: " << objectType << std::endl; // Debug print

        if (objectType == "Point2D") {
            int x, y;
            char comma, leftBracket, rightBracket;
            iss >> leftBracket >> x >> comma >> y >> rightBracket;
            std::cout << "Point2D: (" << x << ", " << y << ")" << std::endl; // Debug print
            Point2D point(x, y);
            point2DList.push_back(point); // Store the Point2D object in the vector
        } else if (objectType == "Point3D") {
            int x, y, z;
            char comma, leftBracket, rightBracket;
            iss >> leftBracket >> x >> comma >> y >> comma >> z >> rightBracket;
            std::cout << "Point3D: (" << x << ", " << y << ", " << z << ")" << std::endl; // Debug print
            Point3D point(x, y, z);
            point3DList.push_back(point); // Store the Point3D object in the vector
        } else if (objectType == "Line2D") {
            int x1, y1, x2, y2;
            char comma, leftBracket1, rightBracket1, leftBracket2, rightBracket2;
            iss >> leftBracket1 >> x1 >> comma >> y1 >> rightBracket1 >> comma
                >> leftBracket2 >> x2 >> comma >> y2 >> rightBracket2;
            std::cout << "Line2D: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << std::endl; // Debug print
            Line2D line(Point2D(x1, y1), Point2D(x2, y2));
            line2DList.push_back(line); // Store the Line2D object in the vector
        } else if (objectType == "Line3D") {
            int x1, y1, z1, x2, y2, z2;
            char comma, leftBracket1, rightBracket1, leftBracket2, rightBracket2;
            iss >> leftBracket1 >> x1 >> comma >> y1 >> comma >> z1 >> rightBracket1 >> comma
                >> leftBracket2 >> x2 >> comma >> y2 >> comma >> z2 >> rightBracket2;
            std::cout << "Line3D: (" << x1 << ", " << y1 << ", " << z1 << "), (" << x2 << ", " << y2 << ", " << z2 << ")" << std::endl; // Debug print
            Line3D line(Point3D(x1, y1, z1), Point3D(x2, y2, z2));
            line3DList.push_back(line); // Store the Line3D object in the vector
        }
    }

    inputFile.close();

    // Removing duplicates
    removeDuplicates(point2DList);
    removeDuplicates(point3DList);
    removeDuplicates(line2DList);
    removeDuplicates(line3DList);

}

// for testing
void printVectors() {
    std::cout << std::endl;
    std::cout << "Point2D List:" << std::endl;
    for (const auto& point : point2DList) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ")" << std::endl;
    }

    std::cout << "\nPoint3D List:" << std::endl;
    for (const auto& point : point3DList) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << std::endl;
    }

    std::cout << "\nLine2D List:" << std::endl;
    for (const auto& line : line2DList) {
        std::cout << "Line: (" << line.getPt1().getX() << ", " << line.getPt1().getY() << "), ("
                  << line.getPt2().getX() << ", " << line.getPt2().getY() << ")" << std::endl;
    }

    std::cout << "\nLine3D List:" << std::endl;
    for (const auto& line : line3DList) {
        std::cout << "Line: (" << line.getPt1().getX() << ", " << line.getPt1().getY() << ", " << line.getPt1().getZ() << "), ("
                  << line.getPt2().getX() << ", " << line.getPt2().getY() << ", " << line.getPt2().getZ() << ")" << std::endl;
    }
}



// Function to specify filtering criteria
void specifyFilteringCriteria() {
    std::cout << "Specifying filtering criteria..." << std::endl;
}

// Function to specify sorting criteria
void specifySortingCriteria() {
    std::cout << "Specifying sorting criteria..." << std::endl;
}

// Function to specify sorting order
void specifySortingOrder() {
    std::cout << "Specifying sorting order..." << std::endl;
}

// Function to view data
void viewData() {
    std::cout << "Viewing data..." << std::endl;
}

// Function to store data
void storeData() {
    std::cout << "Storing data..." << std::endl;
}


int main(){


    int choice;    

    // Call the appropriate function based on user's choice
    do{
        displayMenu();
        choice = getUserChoice();
        switch (choice) {
            case 1:
                readData();
                printVectors();
                break;
            case 2:
                specifyFilteringCriteria();
                break;
            case 3:
                specifySortingCriteria();
                break;
            case 4:
                specifySortingOrder();
                break;
            case 5:
                viewData();
                break;
            case 6:
                storeData();
                break;
            case 0:
                // Code for sorting shape data
                std::cout << "Thanks for using the program !! " << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
                break;
        }
    }while (choice!=0);
    
    return 0;
}