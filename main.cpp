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
#include "MyTemplates.h"
#include "sortHelper.h"

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
int getUserChoice();



template<typename T>
void removeDuplicates(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

// for removing lines from oss
std::string removeTrailingNewlines(const std::string& str) {
    std::string result = str;
    while (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    return result;
}

// to get the current sorting criteria
std::string getCurrentSortingCriteria(int filteringCriteria, int sortingCriteria) {
    if (filteringCriteria == 1) {
        switch (sortingCriteria) {
            case 2:
                return "Y ordinate value";
            case 3:
                return "Dist. Fr Origin value";
            default:
                return "X ordinate value";
        }
    } else if (filteringCriteria == 2) {
        switch (sortingCriteria) {
            case 2:
                return "Y ordinate value";
            case 3:
                return "Z ordinate value";
            case 4:
                return "Dist. Fr Origin value";
            default:
                return "X ordinate value";
        }
    } else {
        switch (sortingCriteria) {
            case 2:
                return "X and Y coordinate values of Pt.2";
            case 3:
                return "Length value";
            default:
                return "X and Y coordinate values of Pt.1";
        }
    }
}

// to get current filtering criteria
std::string getCurrentFilteringCriteria(int filteringCriteria) {
    switch (filteringCriteria) {
        case 2:
            return "Point3D";
        case 3:
            return "Line2D";
        case 4:
            return "Line3D";
        default:
            return "Point2D";
    }
}

// to get current sorting order
std::string getCurrentSortingOrder(int sortingOrder) {
    if (sortingOrder == 2) {
        return "DSC";
    } else {
        return "ASC";
    }
}


// for data output records 
std::vector<std::string> outputRecords(const int &filteringCriteria, const int &sortingCriteria, const int &sortingOrder) {
    std::vector<std::string> records;
    std::vector<std::string> XY;
    XY.push_back("X");
    XY.push_back("Y");

    std::vector<std::string> XYZ; 
    XYZ.push_back("X");
    XYZ.push_back("Y");
    XYZ.push_back("Z");

    std::ostringstream oss;

    // Add view data criteria to records
    std::ostringstream criteria;
    criteria << "[View data..]" << std::endl;
    criteria << "Filtering criteria: ";
    switch (filteringCriteria) {
        case 1:
            criteria << "Point2D" << std::endl;
            break;
        case 2:
            criteria << "Point3D" << std::endl;
            break;
        case 3:
            criteria << "Line2D" << std::endl;
            break;
        case 4:
            criteria << "Line3D" << std::endl;
            break;
        default:
            criteria << "Unknown" << std::endl;
            break;
    }
    // Add sorting criteria to records
    criteria << "Sorting criteria: ";
    if (filteringCriteria == 1 || filteringCriteria == 2) {
        switch (sortingCriteria) {
            case 1:
                criteria << "X ordinate value" << std::endl;
                break;
            case 2:
                criteria << "Y ordinate value" << std::endl;
                break;
            case 3:
                criteria << "Dist. Fr Origin value" << std::endl;
                break;
            default:
                criteria << "Unknown" << std::endl;
                break;
        }
    } else {
        switch (sortingCriteria) {
            case 1:
                criteria << "X and Y coordinate values of Pt.1" << std::endl;
                break;
            case 2:
                criteria << "X and Y coordinate values of Pt.2" << std::endl;
                break;
            case 3:
                criteria << "Length value" << std::endl;
                break;
            default:
                criteria << "Unknown" << std::endl;
                break;
        }
    }
    // Add sorting order to records
    criteria << "Sorting order: ";
    if (sortingOrder == 1) {
        criteria << "ASC" << std::endl;
    } else {
        criteria << "DSC" << std::endl;
    }
    records.push_back(criteria.str());

    // Output data based on filtering criteria
    switch (filteringCriteria) {
        case 1: // Point2D
            switch (sortingCriteria) {
                case 1: // Sorting by X ordinate
                    std::sort(point2DList.begin(), point2DList.end(), (sortingOrder == 1) ? sortHelper::sortXByAscending : sortHelper::sortXByDescending);
                    break;
                case 2: // Sorting by Y ordinate
                    std::sort(point2DList.begin(), point2DList.end(), (sortingOrder == 1) ? sortHelper::sortYByAscending : sortHelper::sortYByDescending);
                    break;
                case 3: // Sorting by Distance from Origin
                    std::sort(point2DList.begin(), point2DList.end(), (sortingOrder == 1) ? sortHelper::sortPtByDistanceAscending : sortHelper::sortPtByDistanceDescending);
                    break;
                default:
                    std::cout << "Unknown sorting criteria for Point2D" << std::endl;
                    break;
            }
            // Output Point2D data
            oss << Format::addHeader(XY, "Dist. Fr Origin", true, true);
            records.push_back(removeTrailingNewlines(oss.str()));
            for (const auto& point : point2DList) {
            std::ostringstream oss_point; // create a new stringstream for each iteration
            oss_point << point;
            records.push_back(removeTrailingNewlines(oss_point.str()));
            }
            break;
        case 2: // Point3D
         
            switch (sortingCriteria) {
                case 1: // Sorting by X ordinate
                    std::sort(point3DList.begin(), point3DList.end(), (sortingOrder == 1) ? sortHelper::sortXByAscending : sortHelper::sortXByDescending);
                    break;
                case 2: // Sorting by Y ordinate
                    std::sort(point3DList.begin(), point3DList.end(), (sortingOrder == 1) ? sortHelper::sortYByAscending : sortHelper::sortYByDescending);
                    break;
                case 3: // Sorting by Z ordinate
                    std::sort(point3DList.begin(), point3DList.end(), (sortingOrder == 1) ? sortHelper::sortZByAscending : sortHelper::sortZByDescending);
                    break;
                case 4: // Sorting by Distance from Origin
                    std::sort(point3DList.begin(), point3DList.end(), (sortingOrder == 1) ? sortHelper::sortPtByDistanceAscending : sortHelper::sortPtByDistanceDescending);
                    break;
                default:
                    std::cout << "Unknown sorting criteria for Point3D" << std::endl;
                    break;
            }
            // Output Point3D data
                        
            oss << Format::addHeader(XYZ, "Dist. Fr Origin", false, true);
            records.push_back(removeTrailingNewlines(oss.str()));
            for (const auto& point : point3DList) {
                std::ostringstream oss_point;
                oss_point << point;
                records.push_back(removeTrailingNewlines(oss_point.str()));
            }
            break;
        case 3: // Line2D
           
            switch (sortingCriteria) {
                case 1: // Sorting by pt1 
                    std::sort(line2DList.begin(), line2DList.end(), (sortingOrder == 1) ? sortHelper::sortLine2DByXYPt1Ascending : sortHelper::sortLine2DByXYPt1Descending);
                    break;
                case 2: // Sorting by pt2 
                    std::sort(line2DList.begin(), line2DList.end(), (sortingOrder == 1) ? sortHelper::sortLine2DByXYPt2Ascending : sortHelper::sortLine2DByXYPt2Descending);
                    break;
                case 3: // Sorting by Distance from Origin
                    std::sort(line2DList.begin(), line2DList.end(), (sortingOrder == 1) ? sortHelper::sortLineByDistanceAscending : sortHelper::sortLineByDistanceDescending);
                    break;
                default:
                    std::cout << "Unknown sorting criteria for Line2D" << std::endl;
                    break;
            }
            // Output Line2D data
            oss << Format::addHeader(XY, "Length", true, false);
            records.push_back(removeTrailingNewlines(oss.str()));
            for (const auto& line : line2DList) {
                std::ostringstream oss_line;
                oss_line << line;
                records.push_back(removeTrailingNewlines(oss_line.str()));
            }
            break;
        case 4: // Line3D
    
            switch (sortingCriteria) {
                case 1: // Sorting by pt1 
                    std::sort(line3DList.begin(), line3DList.end(), (sortingOrder == 1) ? sortHelper::sortLine3DByXYPt1ascending : sortHelper::sortLine3DByXYPt1Descending);
                    break;
                case 2: // Sorting by pt2 
                    std::sort(line3DList.begin(), line3DList.end(), (sortingOrder == 1) ? sortHelper::sortLine3DByXYPt2ascending : sortHelper::sortLine3DByXYPt2Descending);
                    break;
                case 3: // Sorting by Distance from Origin
                    std::sort(line3DList.begin(), line3DList.end(), (sortingOrder == 1) ? sortHelper::sortLineByDistanceAscending : sortHelper::sortLineByDistanceDescending);
                    break;
                default:
                    std::cout << "Unknown sorting criteria for Line2D" << std::endl;
                    break;
            }
            // Output Line3D data
            oss << Format::addHeader(XYZ, "Length", false, false);
            records.push_back(removeTrailingNewlines(oss.str()));
            for (const auto& line : line3DList) {
                std::ostringstream oss_line;
                oss_line << line;
                records.push_back(removeTrailingNewlines(oss_line.str()));
            }
            break;
        default:
            std::cout << "Invalid filtering criteria." << std::endl;
            break;
    }

    return records;
}


// Function to display the menu 
void displayMenu() {
    std::cout << std::endl;
    std::cout << "Student ID     : 8215510" << std::endl;
    std::cout << "Student Name   : Aung Pyae Soe" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Welcome to Assn3 program!" << std::endl;
    std::cout << std::endl;
    std::cout << "1) Read in data" << std::endl;
    std::cout << "2) Specify filtering criteria (current: ";
    std::cout << getCurrentFilteringCriteria(filteringCriteria) << ") " << std::endl;
    std::cout << "3) Specify sorting criteria (current: ";
    std::cout << getCurrentSortingCriteria(filteringCriteria, sortingCriteria) << ") " << std::endl;
    std::cout << "4) Specify sorting order (current: ";
    std::cout << getCurrentSortingOrder(sortingOrder) << ") " << std::endl;
    std::cout << "5) View data" << std::endl;
    std::cout << "6) Store data" << std::endl;
    std::cout << "0) Exit" << std::endl;
    

}

// for getting user choice
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

// function to read data from file and store
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
    int numRecords = 0 ;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string objectType;
        std::getline(iss, objectType, ','); // Read object type until comma
        objectType.erase(std::remove(objectType.begin(), objectType.end(), ' '), objectType.end()); // Remove spaces
        //std::cout << "Object type: " << objectType << std::endl; // Debug print
        numRecords++;
        if (objectType == "Point2D") {
            int x, y;
            char comma, leftBracket, rightBracket;
            iss >> leftBracket >> x >> comma >> y >> rightBracket;
            //std::cout << "Point2D: (" << x << ", " << y << ")" << std::endl; // Debug print
            Point2D point(x, y);
            point2DList.push_back(point); // Store the Point2D object in the vector

        } else if (objectType == "Point3D") {
            int x, y, z;
            char comma, leftBracket, rightBracket;
            iss >> leftBracket >> x >> comma >> y >> comma >> z >> rightBracket;
            //std::cout << "Point3D: (" << x << ", " << y << ", " << z << ")" << std::endl; // Debug print
            Point3D point(x, y, z);
            point3DList.push_back(point); // Store the Point3D object in the vector

        } else if (objectType == "Line2D") {
            int x1, y1, x2, y2;
            char comma, leftBracket1, rightBracket1, leftBracket2, rightBracket2;
            iss >> leftBracket1 >> x1 >> comma >> y1 >> rightBracket1 >> comma
                >> leftBracket2 >> x2 >> comma >> y2 >> rightBracket2;
            //std::cout << "Line2D: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << std::endl; // Debug print
            Line2D line(Point2D(x1, y1), Point2D(x2, y2));
            line2DList.push_back(line); // Store the Line2D object in the vector
            
        } else if (objectType == "Line3D") {
            int x1, y1, z1, x2, y2, z2;
            char comma, leftBracket1, rightBracket1, leftBracket2, rightBracket2;
            iss >> leftBracket1 >> x1 >> comma >> y1 >> comma >> z1 >> rightBracket1 >> comma
                >> leftBracket2 >> x2 >> comma >> y2 >> comma >> z2 >> rightBracket2;
            //std::cout << "Line3D: (" << x1 << ", " << y1 << ", " << z1 << "), (" << x2 << ", " << y2 << ", " << z2 << ")" << std::endl; // Debug print
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

    std::cout << numRecords << " Records read successfully!!" << std::endl;
    std::cout << "Going back to main menu... " << std::endl;

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
    std::cout << "[ Specify filtering criteria (current: ";
    std::cout << getCurrentFilteringCriteria(filteringCriteria) << ") ]" << std::endl;
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

    std::cout << "Filter criteria successfully set to ' ";
    std::cout << getCurrentFilteringCriteria(filteringCriteria) << "'!" << std::endl;
}

void specifySortingCriteria(int filteringCriteria, int& sortingCriteria) {
    std::cout << "[ Specify sorting criteria (current: ";
    std::cout << getCurrentSortingCriteria(filteringCriteria, sortingCriteria) << ") ]" << std::endl;
    // Point 2D
    if (filteringCriteria == 1 ) {
        std::cout << "1) X ordinate value (default)" << std::endl;
        std::cout << "2) Y ordinate value" << std::endl;
        std::cout << "3) Dist. Fr Origin value" << std::endl;
    }else if (filteringCriteria == 2){  // Point 3D
        std::cout << "1) X ordinate value (default)" << std::endl;
        std::cout << "2) Y ordinate value" << std::endl;
        std::cout << "3) Z ordinate value" << std::endl;
        std::cout << "4) Dist. Fr Origin value" << std::endl;
    }else {
        std::cout << "1) X and Y coordinate values of Pt.1 (default)" << std::endl;
        std::cout << "2) X and Y coordinate values of Pt.2" << std::endl;
        std::cout << "3) Length value" << std::endl;
    }

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 4:
            sortingCriteria = 4; // z ordinate
            break;
        case 2:
            sortingCriteria = 2; // Y ordinate value for Point2D 
            break;
        case 3:
            sortingCriteria = 3; // Dist. Fr Origin value for Point2D or  z for Point3D, Length value for Line2D or Line3D
            break;
        default:
            sortingCriteria = 1; // X ordinate value for Point2D or Point3D, X and Y coordinate values of Pt.1 for Line2D or Line3D
            break;
    }

    std::cout << "Sorting criteria successfully set to ' ";
    std::cout << getCurrentSortingCriteria(sortingCriteria, sortingCriteria) << "'!" << std::endl;
}


void specifySortingOrder(int& sortingOrder) {
    std::cout << "[ Specify sorting order (current: ";
    std::cout << getCurrentSortingOrder(sortingOrder) << ") ]" << std::endl;
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

    std::cout << "Sorting order successfully set to ' ";
    std::cout << getCurrentSortingOrder(sortingOrder) << "'!" << std::endl;
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

// Function to count the number of records to be outputted
int countRecords(const std::vector<std::string>& records) {
    return records.size();
}


void pressAnyKeyToContinue()
{
    std::cout << "\nPress any key to go back to main menu ...";
    std::cin.get();
}

// ----------------------------MAIN------------------------
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
                //pressAnyKeyToContinue();
                break;
            case 2:
                specifyFilteringCriteria(filteringCriteria);
                //pressAnyKeyToContinue();
                break;
            case 3:
                specifySortingCriteria(filteringCriteria, sortingCriteria);
                //pressAnyKeyToContinue();
                break;
            case 4:
                specifySortingOrder(sortingOrder);
                //pressAnyKeyToContinue();
                break;
            case 5:
                // View data function
                // Get records based on specified criteria
                records = outputRecords(filteringCriteria, sortingCriteria, sortingOrder);
                // Output the records
                std::cout << "View data:" << std::endl;
                for (const auto& record : records) {
                    std::cout << record << std::endl;
                }
                //pressAnyKeyToContinue();
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
                //pressAnyKeyToContinue();
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