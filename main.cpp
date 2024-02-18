#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

// global variables
// Declare variables to store filtering and sorting criteria
int filteringCriteria = 1; // Default to Point2D
int sortingCriteria = 1; // Default to X ordinate value
int sortingOrder = 1; // Default to ASC
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
    std::cout << "2) Specify filtering criteria (current: ";
    switch (filteringCriteria) {
        case 2:
            std::cout << "Point3D)" << std::endl;
            break;
        case 3:
            std::cout << "Line2D)" << std::endl;
            break;
        case 4:
            std::cout << "Line3D)" << std::endl;
            break;
        default:
            std::cout << "Point2D)" << std::endl;
            break;
    }
    std::cout << "3) Specify sorting criteria (current: ";
    if (filteringCriteria == 1 || filteringCriteria == 2) {
        switch (sortingCriteria) {
            case 2:
                std::cout << "Y ordinate value)" << std::endl;
                break;
            case 3:
                std::cout << "Dist. Fr Origin value)" << std::endl;
                break;
            default:
                std::cout << "X ordinate value)" << std::endl;
                break;
        }
    } else {
        switch (sortingCriteria) {
            case 2:
                std::cout << "X and Y coordinate values of Pt.2)" << std::endl;
                break;
            case 3:
                std::cout << "Length value)" << std::endl;
                break;
            default:
                std::cout << "X and Y coordinate values of Pt.1)" << std::endl;
                break;
        }
    }
    std::cout << "4) Specify sorting order (current: ";
    if (sortingOrder == 2) {
        std::cout << "DSC)" << std::endl;
    } else {
        std::cout << "ASC)" << std::endl;
    }
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
       
        std::cout << std::fixed << std::setprecision(3) << "Dist from Origin: " << point.getScalarValue() << std::endl;  // setting to 3 decimals 
        
    }

    std::cout << "\nPoint3D List:" << std::endl;
    for (const auto& point : point3DList) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << std::endl;
        std::cout << std::fixed << std::setprecision(3) << "Dist from Origin: " << point.getScalarValue() << std::endl;
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



void specifyFilteringCriteria(int& filteringCriteria) {
    std::cout << "Specify filtering criteria:" << std::endl;
    std::cout << "a) Point2D (default)" << std::endl;
    std::cout << "b) Point3D" << std::endl;
    std::cout << "c) Line2D" << std::endl;
    std::cout << "d) Line3D" << std::endl;

    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 'b':
            filteringCriteria = 2; // Point3D
            break;
        case 'c':
            filteringCriteria = 3; // Line2D
            break;
        case 'd':
            filteringCriteria = 4; // Line3D
            break;
        default:
            filteringCriteria = 1; // Point2D
            break;
    }
}

void specifySortingCriteria(int filteringCriteria, int& sortingCriteria) {
    std::cout << "Specify sorting criteria:" << std::endl;
    if (filteringCriteria == 1 || filteringCriteria == 2) {
        std::cout << "1) X ordinate value (default)" << std::endl;
        std::cout << "2) Y ordinate value" << std::endl;
        std::cout << "3) Dist. Fr Origin value" << std::endl;
    } else {
        std::cout << "1) X and Y coordinate values of Pt.1 (default)" << std::endl;
        std::cout << "2) X and Y coordinate values of Pt.2" << std::endl;
        std::cout << "3) Length value" << std::endl;
    }

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 2:
            sortingCriteria = 2; // Y ordinate value for Point2D or Point3D
            break;
        case 3:
            sortingCriteria = 3; // Dist. Fr Origin value for Point2D or Point3D, Length value for Line2D or Line3D
            break;
        default:
            sortingCriteria = 1; // X ordinate value for Point2D or Point3D, X and Y coordinate values of Pt.1 for Line2D or Line3D
            break;
    }
}


void specifySortingOrder(int& sortingOrder) {
    std::cout << "Specify sorting order:" << std::endl;
    std::cout << "a) ASC (Ascending order) (default)" << std::endl;
    std::cout << "b) DSC (Descending order)" << std::endl;

    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice == 'b') {
        sortingOrder = 2; // DSC
    } else {
        sortingOrder = 1; // ASC
    }
}

void viewData(const std::vector<Point2D>& point2DList, const std::vector<Point3D>& point3DList, const std::vector<Line2D>& line2DList, const std::vector<Line3D>& line3DList, int filteringCriteria, int sortingCriteria, int sortingOrder) {
    // Print filtering criteria
    std::cout << "[View data..]" << std::endl;
    std::cout << "Filtering criteria: ";
    switch (filteringCriteria) {
        case 1:
            std::cout << "Point2D" << std::endl;
            break;
        case 2:
            std::cout << "Point3D" << std::endl;
            break;
        case 3:
            std::cout << "Line2D" << std::endl;
            break;
        case 4:
            std::cout << "Line3D" << std::endl;
            break;
        default:
            std::cout << "Unknown" << std::endl;
            break;
    }

    // Print sorting criteria
    std::cout << "Sorting criteria: ";
    if (filteringCriteria == 1 || filteringCriteria == 2) {
        switch (sortingCriteria) {
            case 2:
                std::cout << "Y ordinate value" << std::endl;
                break;
            case 3:
                std::cout << "Dist. Fr Origin value" << std::endl;
                break;
            default:
                std::cout << "X ordinate value" << std::endl;
                break;
        }
    } else {
        switch (sortingCriteria) {
            case 2:
                std::cout << "X and Y coordinate values of Pt.2" << std::endl;
                break;
            case 3:
                std::cout << "Length value" << std::endl;
                break;
            default:
                std::cout << "X and Y coordinate values of Pt.1" << std::endl;
                break;
        }
    }

    // Print sorting order
    std::cout << "Sorting order: ";
    if (sortingOrder == 1) {
        std::cout << "ASC" << std::endl;
    } else {
        std::cout << "DSC" << std::endl;
    }

    // Output data based on filtering criteria
    switch (filteringCriteria) {
        case 1:
            // Output Point2D data
            std::cout << "Point2D Data:" << std::endl;
            for (const auto& point : point2DList) {
                std::cout << point << std::endl;
            }
            break;
        case 2:
            // Output Point3D data
            std::cout << "Point3D Data:" << std::endl;
            for (const auto& point : point3DList) {
                std::cout << point << std::endl;
            }
            break;
        case 3:
            // Output Line2D data
            std::cout << "Line2D Data:" << std::endl;
            for (const auto& line : line2DList) {
                std::cout << line << std::endl;
            }
            break;
        case 4:
            // Output Line3D data
            std::cout << "Line3D Data:" << std::endl;
            for (const auto& line : line3DList) {
                std::cout << line << std::endl;
            }
            break;
        default:
            std::cout << "No data to display." << std::endl;
            break;
    }
}


// Function to save records to a file
void saveRecordsToFile(const std::string& filename, const std::vector<std::string>& records) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& record : records) {
            outputFile << record << std::endl;
        }
        outputFile.close();
        std::cout << records.size() << " records successfully saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

// Function to output records based on specified criteria
std::vector<std::string> outputRecords(int filteringCriteria, int sortingCriteria, int sortingOrder, const std::vector<Point2D>& point2DList, const std::vector<Point3D>& point3DList, const std::vector<Line2D>& line2DList, const std::vector<Line3D>& line3DList) {
    std::vector<std::string> records;

    // Output data based on filtering criteria
    switch (filteringCriteria) {
        case 1:
            // Output Point2D data
            for (const auto& point : point2DList) {
                std::ostringstream oss;
                oss << "Point2D: " << point;
                records.push_back(oss.str());
            }
            break;
        case 2:
            // Output Point3D data
            for (const auto& point : point3DList) {
                std::ostringstream oss;
                oss << "Point3D: " << point;
                records.push_back(oss.str());
            }
            break;
        case 3:
            // Output Line2D data
            for (const auto& line : line2DList) {
                std::ostringstream oss;
                oss << "Line2D: " << line;
                records.push_back(oss.str());
            }
            break;
        case 4:
            // Output Line3D data
            for (const auto& line : line3DList) {
                std::ostringstream oss;
                oss << "Line3D: " << line;
                records.push_back(oss.str());
            }
            break;
        default:
            std::cout << "Invalid filtering criteria." << std::endl;
            break;
    }

    // Logic to sort records based on sorting criteria and order
    // (You can implement sorting logic here)

    return records;
}
// Function to count the number of records to be outputted
int countRecords(const std::vector<std::string>& records) {
    return records.size();
}
// Function to store data
void storeData() {
    std::cout << "Storing data..." << std::endl;
}


int main(){


    int choice;    
    std::vector<std::string> records;
    std::string filename;
    // Call the appropriate function based on user's choice
    do{
        displayMenu();
        choice = getUserChoice();
        switch (choice) {
            case 1:
                readData();
                //zprintVectors();
                break;
            case 2:
                specifyFilteringCriteria(filteringCriteria);
                break;
            case 3:
                specifySortingCriteria(filteringCriteria, sortingCriteria);
                break;
            case 4:
                specifySortingOrder(sortingOrder);
                break;
            case 5:
                // View data function
                // Get records based on specified criteria
                records = outputRecords(filteringCriteria, sortingCriteria, sortingOrder, point2DList, point3DList, line2DList, line3DList);
                // Output the records
                std::cout << "View data:" << std::endl;
                for (const auto& record : records) {
                    std::cout << record << std::endl;
                }
                break;
            case 6:
                // Save data to file function
                if (!records.empty()) {
                    std::cout << "Please enter filename: ";
                    std::cin >> filename;
                    saveRecordsToFile(filename, records);
                } else {
                    std::cout << "No records to save." << std::endl;
                }
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