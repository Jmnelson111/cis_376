// Program 0 3501.cpp : 
//Jacob Nye
//Date created 1/20/2021
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

class Employee {
protected:
    string firstName, lastName, ssn, hideSsn, id;
public:
    Employee() {
        firstName = "";
        lastName = "";
        ssn = "";
        hideSsn = "";
        id = "";
    }
    string getFirstName() {
        return firstName;
    }
    void setFirstName(string fName) {
        firstName = fName;
    }
    string getLastName() {
        return lastName;
    }
    void setLastName(string lName) {
        lastName = lName;
    }
    string getId() {
        return id;
    }
    void setId(string input, bool& methodStatus)
    {

        if (input.length() == 5) {
            for (int i = 0; i < 5; i++) {
                if (i == 3) {
                    if (input[i] != '-') {
                        methodStatus = false;
                        break;
                    }
                }
                else if (i == 4) {
                    switch (input[i]) {
                    case 'A':
                    case 'a':
                        input[i] = 'A';
                        methodStatus = true;
                        break;
                    case 'B':
                    case 'b':
                        input[i] = 'B';
                        methodStatus = true;
                        break;
                    case 'C':
                    case 'c':
                        input[i] = 'C';
                        methodStatus = true;
                        break;
                    case 'D':
                    case 'd':
                        input[i] = 'D';
                        methodStatus = true;
                        break;
                    case 'E':
                    case 'e':
                        input[i] = 'E';
                        methodStatus = true;
                        break;
                    case 'F':
                    case 'f':
                        input[i] = 'F';
                        methodStatus = true;
                        break;
                    case 'G':
                    case 'g':
                        input[i] = 'G';
                        methodStatus = true;
                        break;
                    case 'H':
                    case 'h':
                        input[i] = 'H';
                        methodStatus = true;
                        break;
                    case 'I':
                    case 'i':
                        input[i] = 'I';
                        methodStatus = true;
                        break;
                    case 'J':
                    case 'j':
                        input[i] = 'J';
                        methodStatus = true;
                        break;
                    case 'K':
                    case 'k':
                        input[i] = 'K';
                        methodStatus = true;
                        break;
                    case 'L':
                    case 'l':
                        input[i] = 'L';
                        methodStatus = true;
                        break;
                    case 'M':
                    case 'm':
                        input[i] = 'M';
                        methodStatus = true;
                        break;
                    default: methodStatus = false;

                    }
                }
                else {
                    if (isdigit(input[i]) == true)
                        methodStatus = true;
                    if (isdigit(input[i]) == false) {
                        methodStatus = false;
                        break;
                    }
                }


            }

        }
        if (methodStatus == true) {
            id = input;
        }


    }

    string getSsn() { return hideSsn; }
    void setSsn(string input, bool& methodStatus) {
        methodStatus = false;
        if (input.length() == 11) {
            for (int i = 0; i < 11; i++) {
                if ((i == 3) || (i == 6)) {
                    if (input[i] != '-')
                        methodStatus = false;
                }
                else {
                    if (isdigit(input[i]) == false) {
                        methodStatus = false;

                    }

                }

                if (i == 10) {
                    if (isdigit(input[i]))
                        methodStatus = true;
                }

            }
            if (methodStatus == true) {
                hideSsn = input;
                ssn = input;

                for (int i = 0; i < 11; i++) {
                    if (i <= 6) {
                        hideSsn[i] = 'x';
                    }
                    if (i == 3)
                        hideSsn[i] = '-';
                    if (i == 6)
                        hideSsn[i] = '-';
                }
            }
        }
        else
            methodStatus = false;
    }
    void printEmployee(ofstream& ofs) {
        cout << "first name: " << firstName << endl;
        cout << "last name: " << lastName << endl;
        cout << "ssn: " << hideSsn << endl;
        cout << "id: " << id << endl;
        ofs << "first name: " << firstName << endl;
        ofs << "last name: " << lastName << endl;
        ofs << "ssn: " << hideSsn << endl;
        ofs << "id: " << id << endl;
        ofs.flush();

    }


};
class SalaryEmployeePay : public Employee {
protected:
    float annualPay, weeklyPay, taxRate;
    int taxRateCode;
public:
    SalaryEmployeePay() {
        annualPay = 0.0;
        weeklyPay = 0.0;
        taxRateCode = 1;
        taxRate = 0;
    }
    void setAnnualPay(float input, bool& methodStatus) {

        if (input >= 0) {
            methodStatus = true;
            annualPay = input;
            weeklyPay = annualPay / 52;
        }
        else {
            methodStatus = false;
        }
    }

    void setTaxRateCode(int input, bool& methodStatus) {
        methodStatus = false;
        if ((input == 1) || (input == 2) || (input == 3)) {
            taxRateCode = input;
            methodStatus = true;
        }
        else
            methodStatus = false;
    }
    void printSalaryEmployeePay(ofstream& ofs) {
        float paymentDue, taxRate;
        if (taxRateCode == 1)
            taxRate = .25;
        if (taxRateCode == 2)
            taxRate = .2;
        if (taxRateCode == 3)
            taxRate = .15;
        paymentDue = weeklyPay - (weeklyPay * taxRate);
        cout << "Data for salary employee hourly Rate" << endl;
        cout << "first name: " << firstName << endl;
        cout << "last name: " << lastName << endl;
        cout << "ssn: " << hideSsn << endl;
        cout << "id: " << id << endl;
        cout << "Annual pay: $" << annualPay << endl;
        cout << "Weekly pay: $" << weeklyPay << endl;
        cout << "Tax Rate code: " << taxRateCode << " = " << taxRate * 100 << "%" << endl;
        cout << "Payment amount: $" << paymentDue << endl;

        ofs << "Data for Salary employee hourly Rate" << endl;
        ofs << "first name: " << firstName << endl;
        ofs << "last name: " << lastName << endl;
        ofs << "ssn: " << hideSsn << endl;
        ofs << "id: " << id << endl;
        ofs << "Annual pay: $" << annualPay << endl;
        ofs << "Weekly pay: $" << weeklyPay << endl;
        ofs << "Tax Rate code: " << taxRateCode << " = " << taxRate * 100 << "%" << endl;
        ofs << "Payment amount: $" << paymentDue << endl;
        ofs.flush();
    }
};
class HourlyEmployee : public Employee {
protected:
    float hourlyPay, weeklyPay;
    int numberOfHours;
public:
    HourlyEmployee() {
        weeklyPay = 0;
        numberOfHours = 0;
        hourlyPay = 0;
    }
    void setWeeklyPay(float input, bool& methodStatus) {
        methodStatus = false;
        if ((input >= 400) && (input <= 3000)) {
            methodStatus = true;
            weeklyPay = input;
            hourlyPay = weeklyPay / 40;

        }
        else
            methodStatus = false;
    }
    float getHourlyPay() { return hourlyPay; }
    float getWeeklyPay() { return weeklyPay; }
    void setNumberOfHours(int input, bool& methodStatus) {
        methodStatus = false;
        if ((input >= 1) && (input <= 60)) {
            methodStatus = true;
            numberOfHours = input;
        }
        else {
            methodStatus = false;
        }
    }
    int getNumberOfHours() { return numberOfHours; }
    void printHourlyEmployee(ofstream& ofs) {
        cout << "Data for hourly Employee" << endl;
        cout << "first name: " << firstName << endl;
        cout << "last name: " << lastName << endl;
        cout << "ssn: " << hideSsn << endl;
        cout << "id: " << id << endl;
        cout << "Weekly pay: $" << weeklyPay << endl;
        cout << "Hourly pay: $" << hourlyPay << endl;
        cout << "Hours worked: " << numberOfHours << endl;

        ofs << "Data for hourly Employee" << endl;
        ofs << "first name: " << firstName << endl;
        ofs << "last name: " << lastName << endl;
        ofs << "ssn: " << hideSsn << endl;
        ofs << "id: " << id << endl;
        ofs << "Weekly pay: $" << weeklyPay << endl;
        ofs << "Hourly pay: $" << hourlyPay << endl;
        ofs << "Hours worked: " << numberOfHours << endl;
        ofs.flush();
    }
};
class HourlyEmployeePay : public HourlyEmployee {
protected:
    float overtimePayRate;
    int taxRateCode;
    char workStatus;
    float taxRate;
    float paymentDue;
public:
    HourlyEmployeePay() {
        overtimePayRate = 0.0;
        taxRateCode = 1;
        workStatus = 'p';
        taxRate = 0.0;
        paymentDue = 0.0;
    }
    float getOvertimePay() { return overtimePayRate; }

    void setOvertimePay(int input) {
        if (input <= 40)
            overtimePayRate = 0;

        else {
            overtimePayRate = (1.5 * hourlyPay) * (input - 40);
        }
    }
    void setTaxRateCode(float input, bool& methodStatus) {
        if ((input <= 3) && (input >= 1)) {
            methodStatus = true;
            taxRateCode = input;
        }
        else
            methodStatus = false;
    }
    int getTaxRateCode() { return taxRateCode; }
    void setWorkStatus(char input, bool& methodStatus) {

        if ((input == 'f') || (input == 'F')) {
            input = 'F';
            methodStatus = true;
            workStatus = input;
        }
        else if ((input == 'p') || (input == 'P')) {
            input = 'P';
            methodStatus = true;
            workStatus = input;
        }
        else
            methodStatus = false;
    }
    char getWorkStatus() { return workStatus; }
    void printHourlyEmployeePay(ofstream& ofs) {

        if (taxRateCode == 1) {
            taxRate = .25;
        }
        if (taxRateCode == 2) {
            taxRate = .2;
        }
        if (taxRateCode == 3) {
            taxRate = .15;
        }
        if (numberOfHours > 40) {
            paymentDue = ((40 * hourlyPay) - (40 * hourlyPay * taxRate)) + ((overtimePayRate - overtimePayRate * taxRate));
        }
        if (numberOfHours <= 40) {
            paymentDue = ((numberOfHours * hourlyPay) - ((numberOfHours * hourlyPay) * taxRate));
        }
        cout << "Data for hourly employee pay" << endl;
        cout << "first name: " << firstName << endl;
        cout << "last name: " << lastName << endl;
        cout << "ssn: " << hideSsn << endl;
        cout << "id: " << id << endl;
        cout << "Weekly pay: " << weeklyPay << endl;
        cout << "Hourly pay: " << hourlyPay << endl;
        cout << "Hours worked: " << numberOfHours << endl;
        cout << "Overtime pay: $" << overtimePayRate << endl;
        cout << "Tax rate: " << taxRate << endl;
        cout << "Work status F for Full time P for Part Time: " << workStatus << endl;
        cout << "Payment due: $" << paymentDue << endl;

        ofs << "Data for hourly employee pay" << endl;
        ofs << "first name: " << firstName << endl;
        ofs << "last name: " << lastName << endl;
        ofs << "ssn: " << hideSsn << endl;
        ofs << "id: " << id << endl;
        ofs << "Weekly pay: " << weeklyPay << endl;
        ofs << "Hourly pay: " << hourlyPay << endl;
        ofs << "Hours worked: " << numberOfHours << endl;
        ofs << "Overtime pay: $" << overtimePayRate << endl;
        ofs << "Tax rate: " << taxRate << endl;
        ofs << "Work status F for Full time P for Part Time: " << workStatus << endl;
        ofs << "Payment due: $" << paymentDue << endl;
        ofs.flush();

    }

};
class AgencyEmployeePay : public HourlyEmployeePay {
protected:
    string companyToPay;

public:
    AgencyEmployeePay() {

        companyToPay = "";
    }

    void setCompanyToPay(string input) { companyToPay = input; }
    string getCompanyToPay() { return companyToPay; }
    void printAgencyEmployeePay(ofstream& ofs) {
        float paymentDue, taxRate;
        if (taxRateCode == 1) {
            taxRate = .25;
        }
        if (taxRateCode == 2) {
            taxRate = .2;
        }
        if (taxRateCode == 3) {
            taxRate = .15;
        }
        if (numberOfHours > 40) {
            paymentDue = ((40 * hourlyPay) - (40 * hourlyPay * taxRate)) + ((overtimePayRate - overtimePayRate * taxRate));
        }
        if (numberOfHours <= 40) {
            paymentDue = ((numberOfHours * hourlyPay) - ((numberOfHours * hourlyPay) * taxRate));
        }
        cout << "Data for agency employee pay" << endl;
        cout << "first name: " << firstName << endl;
        cout << "last name: " << lastName << endl;
        cout << "ssn: " << hideSsn << endl;
        cout << "id: " << id << endl;
        cout << "Weekly pay: " << weeklyPay << endl;
        cout << "Hourly pay: " << hourlyPay << endl;
        cout << "Hours worked: " << numberOfHours << endl;
        cout << "Overtime pay: $" << overtimePayRate << endl;
        cout << "Tax Rate code: " << taxRateCode << " = " << taxRate * 100 << "%" << endl;
        cout << "Work status F for Full time P for Part Time: " << workStatus << endl;
        cout << "Payment due: $" << paymentDue << endl;
        cout << "Company to pay: " << companyToPay << endl;

        ofs << "Data for agency employee pay" << endl;
        ofs << "first name: " << firstName << endl;
        ofs << "last name: " << lastName << endl;
        ofs << "ssn: " << hideSsn << endl;
        ofs << "id: " << id << endl;
        ofs << "Weekly pay: " << weeklyPay << endl;
        ofs << "Hourly pay: " << hourlyPay << endl;
        ofs << "Hours worked: " << numberOfHours << endl;
        ofs << "Overtime pay: $" << overtimePayRate << endl;
        ofs << "Tax Rate code: " << taxRateCode << " = " << taxRate * 100 << "%" << endl;
        ofs << "Work status F for Full time P for Part Time: " << workStatus << endl;
        ofs << "Payment due: $" << paymentDue << endl;
        ofs << "Company to pay: " << companyToPay << endl;
        ofs.flush();

    }
};


int main()
{
    ofstream ofs;
    ofs.open("pay.dat");
    char choice;
    int intInput;
    float floatInput;
    string stringInput;
    char charInput;
    char sentinel = 'y';
    bool methodStatus = false;
    int hoursWorked = 0;
    Employee employee;
    SalaryEmployeePay salaryEmployee;
    HourlyEmployee hourlyEmployee;
    HourlyEmployeePay hourlyEmployeePay;
    AgencyEmployeePay agencyEmployeePay;


    if (ofs.is_open()) {
        while (sentinel != 'n') {
            cout << "1. Employee" << endl;
            cout << "2. Salary employee pay" << endl;
            cout << "3. Hourly employee" << endl;
            cout << "4. Hourly employee pay" << endl;
            cout << "5. Agency employee pay" << endl;
            cout << "Which type of employee would you like to create? ";
            cin >> choice;
            if (choice == '1') {
                cout << "Please enter employee's first name. ";
                cin >> stringInput;
                employee.setFirstName(stringInput);
                cout << endl << "Please enter employee's last name. ";
                cin >> stringInput;
                employee.setLastName(stringInput);
                cout << endl << "Please enter employee's ssn. ";
                cin >> stringInput;
                methodStatus = false;
                employee.setSsn(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx ";
                    cin >> stringInput;
                    employee.setSsn(stringInput, methodStatus);
                };

                cout << endl << "Please enter employee's id. ";
                cin >> stringInput;
                employee.setId(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter id in format xxx-L: letter a-m ";
                    cin >> stringInput;
                    employee.setId(stringInput, methodStatus);
                };
                employee.printEmployee(ofs);

            }
            if (choice == '2') {
                cout << "Please enter employee's first name. ";
                cin >> stringInput;
                salaryEmployee.setFirstName(stringInput);
                cout << endl << "Please enter employee's last name. ";
                cin >> stringInput;
                salaryEmployee.setLastName(stringInput);
                cout << endl << "Please enter employee's ssn. ";
                cin >> stringInput;
                salaryEmployee.setSsn(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx  ";
                    cin >> stringInput;
                    salaryEmployee.setSsn(stringInput, methodStatus);
                };
                cout << endl << "Please enter employee's id. ";
                cin >> stringInput;
                salaryEmployee.setId(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter id in format xxx-L: letter a-m  ";
                    cin >> stringInput;
                    salaryEmployee.setId(stringInput, methodStatus);
                };
                cout << endl << "Please enter the employee's annual pay. ";
                cin >> floatInput;
                salaryEmployee.setAnnualPay(floatInput, methodStatus);
                while (methodStatus == false) {
                    cout << "error, enter a value greater than 0. ";
                    cin >> floatInput;
                    salaryEmployee.setAnnualPay(floatInput, methodStatus);
                };
                cout << endl << "Please enter tax rate: ";
                cin >> intInput;
                salaryEmployee.setTaxRateCode(intInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, enter a tax rate code 1-3. ";
                    cin >> intInput;
                    salaryEmployee.setTaxRateCode(intInput, methodStatus);
                };
                salaryEmployee.printSalaryEmployeePay(ofs);
            }
            if (choice == '3') {
                cout << "Please enter employee's first name. ";
                cin >> stringInput;
                hourlyEmployee.setFirstName(stringInput);
                cout << endl << "Please enter employee's last name. ";
                cin >> stringInput;
                hourlyEmployee.setLastName(stringInput);
                cout << endl << "Please enter employee's ssn. ";
                cin >> stringInput;
                hourlyEmployee.setSsn(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx  ";
                    cin >> stringInput;
                    hourlyEmployee.setSsn(stringInput, methodStatus);
                };
                cout << endl << "Please enter employee's id. ";
                cin >> stringInput;
                hourlyEmployee.setId(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter id in format xxx-L: letter a-m  ";
                    cin >> stringInput;
                    hourlyEmployee.setId(stringInput, methodStatus);
                };
                cout << endl << "Please enter weekly pay. ";
                cin >> floatInput;
                hourlyEmployee.setWeeklyPay(floatInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a value between $400 - $3,000 ";
                    cin >> floatInput;
                    hourlyEmployee.setWeeklyPay(floatInput, methodStatus);
                };
                cout << endl << "Please enter how many hours worked. ";
                cin >> intInput;
                hourlyEmployee.setNumberOfHours(intInput, methodStatus);
                while (methodStatus == false) {
                    cout << "Error, please enter a value 1-60 ";
                    cin >> intInput;
                    hourlyEmployee.setNumberOfHours(intInput, methodStatus);
                };
                hourlyEmployee.printHourlyEmployee(ofs);
            }
            if (choice == '4') {
                cout << "Please enter employee's first name. ";
                cin >> stringInput;
                hourlyEmployeePay.setFirstName(stringInput);
                cout << endl << "Please enter employee's last name. ";
                cin >> stringInput;
                hourlyEmployeePay.setLastName(stringInput);
                cout << endl << "Please enter employee's ssn. ";
                cin >> stringInput;
                hourlyEmployeePay.setSsn(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx";
                    cin >> stringInput;
                    hourlyEmployeePay.setSsn(stringInput, methodStatus);
                };
                cout << endl << "Please enter employee's id. ";
                cin >> stringInput;
                hourlyEmployeePay.setId(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter id in format xxx-L: letter a-m";
                    cin >> stringInput;
                    hourlyEmployeePay.setId(stringInput, methodStatus);
                };
                cout << endl << "Please enter weekly pay. ";
                cin >> floatInput;
                hourlyEmployeePay.setWeeklyPay(floatInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a value greater than 0. ";
                    cin >> floatInput;
                    hourlyEmployeePay.setWeeklyPay(floatInput, methodStatus);
                };
                cout << endl << "Please enter the number of hours worked. ";
                cin >> intInput;
                hoursWorked = intInput;
                hourlyEmployeePay.setNumberOfHours(intInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a value 1-60. ";
                    cin >> intInput;
                    hourlyEmployeePay.setNumberOfHours(intInput, methodStatus);
                };
                hourlyEmployeePay.setOvertimePay(hoursWorked);
                cout << endl << "Please enter the tax rate code. ";
                cin >> intInput;
                hourlyEmployeePay.setTaxRateCode(intInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a tax rate code 1-3. ";
                    cin >> intInput;
                    hourlyEmployeePay.setTaxRateCode(intInput, methodStatus);
                };
                cout << endl << "Please enter work status. ";
                cin >> charInput;
                hourlyEmployeePay.setWorkStatus(charInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a work status 'F' for full time or 'P' for part time. ";
                    cin >> charInput;
                    hourlyEmployeePay.setWorkStatus(charInput, methodStatus);
                };
                hourlyEmployeePay.printHourlyEmployeePay(ofs);
            }
            if (choice == '5') {
                cout << "Please enter employee's first name. ";
                cin >> stringInput;
                agencyEmployeePay.setFirstName(stringInput);
                cout << endl << "Please enter employee's last name. ";
                cin >> stringInput;
                agencyEmployeePay.setLastName(stringInput);
                cout << endl << "Please enter employee's ssn. ";
                cin >> stringInput;
                agencyEmployeePay.setSsn(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter ssn in format xxx-xx-xxxx ";
                    cin >> stringInput;
                    agencyEmployeePay.setSsn(stringInput, methodStatus);
                };
                cout << endl << "Please enter employee's id. ";
                cin >> stringInput;
                agencyEmployeePay.setId(stringInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, invalid format. Please enter id in format xxx-L: letter a-m ";
                    cin >> stringInput;
                    agencyEmployeePay.setId(stringInput, methodStatus);
                };
                cout << endl << "Please enter weekly pay. ";
                cin >> floatInput;
                agencyEmployeePay.setWeeklyPay(floatInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a value greater than 0. ";
                    cin >> floatInput;
                    agencyEmployeePay.setWeeklyPay(floatInput, methodStatus);
                };

                cout << endl << "Please enter the number of hours worked. ";
                cin >> intInput;
                hoursWorked = intInput;
                agencyEmployeePay.setNumberOfHours(intInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a value 1-60. ";
                    cin >> intInput;
                    agencyEmployeePay.setNumberOfHours(intInput, methodStatus);
                };
                agencyEmployeePay.setOvertimePay(hoursWorked);
                cout << endl << "Please enter the tax rate code. ";
                cin >> intInput;
                agencyEmployeePay.setTaxRateCode(intInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a tax rate code 1-3. ";
                    cin >> intInput;
                    agencyEmployeePay.setTaxRateCode(intInput, methodStatus);
                };
                cout << endl << "Please enter work status. ";
                cin >> charInput;
                agencyEmployeePay.setWorkStatus(charInput, methodStatus);
                while (methodStatus == false) {
                    cout << endl << "Error, please enter a work status 'F' for full time or 'P' for part time. ";
                    cin >> charInput;
                    agencyEmployeePay.setWorkStatus(charInput, methodStatus);
                };
                cout << endl << "Please enter the company you work for. ";
                cin >> stringInput;
                agencyEmployeePay.setCompanyToPay(stringInput);
                agencyEmployeePay.printAgencyEmployeePay(ofs);
            }
            cout << endl << "Would you like to add another employee? press 'y' for yes or 'n' to exit. ";
            cin >> sentinel;
        }

    }
    else {
        cout << "File could not be opened.";
    }
    ofs.close();
    return 0;
}
