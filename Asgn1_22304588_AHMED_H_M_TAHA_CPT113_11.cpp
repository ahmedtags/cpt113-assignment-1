#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Employee class to store personal information
class Employee {
private:
    string Emp_name;
    string Emp_ID;
    int Emp_DOB, Emp_MonthofBirth, Emp_YearofBirth;

public:
    Employee() {}

    void set_personal_info(const string &name, const string &id, int dob, int mob, int yob) {
        Emp_name = name;
        Emp_ID = id;
        Emp_DOB = dob;
        Emp_MonthofBirth = mob;
        Emp_YearofBirth = yob;
    }

    // Getters for accessing private members
    int get_dob() const { return Emp_DOB; }
    int get_mob() const { return Emp_MonthofBirth; }
    int get_yob() const { return Emp_YearofBirth; }
    string get_name() const { return Emp_name; }
    string get_id() const { return Emp_ID; }

    ~Employee() {}
};

// Service_Info class to store employment details
class Service_Info {
private:
    int Appointment_Day, Appointment_Month, Appointment_Year;
    float Last_Salary, Total_Allowance;

public:
    Service_Info() {}

    void set_appointment_date(int day, int month, int year) {
        Appointment_Day = day;
        Appointment_Month = month;
        Appointment_Year = year;
    }

    void set_last_salary(float salary) { Last_Salary = salary; }
    void set_total_allowance(float allowance) { Total_Allowance = allowance; }

    // Getters for private members
    int get_appointmentday() const { return Appointment_Day; }
    int get_appointmentmonth() const { return Appointment_Month; }
    int get_appointmentyear() const { return Appointment_Year; }
    float get_last_salary() const { return Last_Salary; }
    float get_total_allowance() const { return Total_Allowance; }

    int calculate_service_years(int end_year) const { // number of years between appointment and pension
        return end_year - Appointment_Year;
    }

    int calculate_service_months(int end_year, int end_month) const {
        int total_months = (end_year - Appointment_Year) * 12 + (end_month - Appointment_Month); // converts into months
        if (total_months > 360) { // Cap it at 30 years (360 months)
            return 360;
        } else {
            return total_months;
        }
    }

    ~Service_Info() {}
};

// Pension_Info class inheriting from Service_Info and using Employee
class Pension_Info : public Service_Info {
private:
    int Pension_Day, Pension_Month, Pension_Year;
    Employee agent;

public:
    // Declare friend functions for input handling
    friend void input_personal_info(Pension_Info &emp);
    friend void input_service_info(Pension_Info &emp);

    void set_pension_date(int day, int month, int year) {
        Pension_Day = day;
        Pension_Month = month;
        Pension_Year = year;
    }

    void calculate_eligibility() {
        cout << "\nPension Eligibility Calculation:\n";

        // Calculate agent's age and service duration
        int age = Pension_Year - agent.get_yob();
        int service_years = calculate_service_years(Pension_Year);
        int service_months = calculate_service_months(Pension_Year, Pension_Month);

        // Display age if less than 40
        if (age < 40) {
            cout << "Age: " << age << " years (below 40)\n";
        }

        // Eligibility check
        if (age < 40 || service_years < 10) {
            cout << "Not Eligible for Pension.\n";
            if (age < 40) cout << "- Reason: Age is less than 40.\n";
            if (service_years < 10) cout << "- Reason: Years of service less than 10 years.\n";

            // Display service months if ineligible
            cout << "Total Service Duration: " << service_months << " months.\n";
            return; // Don't show pension calculation if not eligible
        }

        // If eligible, show the years and months of service
        cout << "Pension Eligibility Confirmed!\n";
        cout << "Service Duration: " << service_years << " years and " << service_months % 12 << " months (" << service_months << " months total).\n";

        // Calculate pension
        float pension = 0.00167 * service_months * get_last_salary();
        float gratuity = 0.075 * service_months * get_last_salary();

        cout << "Estimated Monthly Pension: RM" << pension << endl;
        cout << "Gratuity: RM" << gratuity << endl;
    }

    void display_service_info() const {
        cout << "\nService Information:\n";
        cout << "Name: " << agent.get_name() << endl;
        cout << "ID: " << agent.get_id() << endl;
        cout << "Date of Birth: " << agent.get_dob() << "/" << agent.get_mob() << "/" << agent.get_yob() << endl;
        cout << "Date of Appointment: " << get_appointmentday() << "/" << get_appointmentmonth() << "/" << get_appointmentyear() << endl;
        cout << "Last Salary: RM" << get_last_salary() << endl;
        cout << "Total Allowance: RM" << get_total_allowance() << endl;
    }
};

// Friend function for inputting personal info
void input_personal_info(Pension_Info &emp) {
    string name, id;
    int dob, mob, yob;

    cout << "Enter Employee ID: ";
    cin >> id;

    cin.ignore(); // Clear buffer before reading the name

    cout << "Enter Employee Name: ";
    getline(cin, name);

    // Get valid day
    cout << "Your Date of Birth Information:\n";
    do {
        cout << "Day: ";
        cin >> dob;
        if (dob < 1 || dob > 31) {
            cout << "Please enter a valid day (1-31).\n";
        }
    } while (dob < 1 || dob > 31);

    // Get valid month
    do {
        cout << "Month: ";
        cin >> mob;
        if (mob < 1 || mob > 12) {
            cout << "Please enter a valid month (1-12).\n";
        }
    } while (mob < 1 || mob > 12);

    cout << "Year: ";
    cin >> yob;

    emp.agent.set_personal_info(name, id, dob, mob, yob);
}

// Friend function for inputting service info


void input_service_info(Pension_Info &emp) {
    int day, month, year;
    float salary, allowance;

    cout << "\nService Information:\n";
    cout << "Set Appointment Date:\n";

    // Get a valid day
    do {
        cout << "Day: ";
        cin >> day;
        if (day < 1 || day > 31) {
            cout << "Please enter a valid day (1-31).\n";
        }
    } while (day < 1 || day > 31);

    // Get a valid month
    do {
        cout << "Month: ";
        cin >> month;
        if (month < 1 || month > 12) {
            cout << "Please enter a valid month (1-12).\n";
        }
    } while (month < 1 || month > 12);

    cout << "Year: ";
    cin >> year;

    emp.set_appointment_date(day, month, year);

    do {
        cout << "Enter Last Salary: RM";
        cin >> salary;
        if (salary < 0) cout << "Salary cannot be negative. Please try again.\n";
    } while (salary < 0);
    emp.set_last_salary(salary);

    do {
        cout << "Enter Total Allowance: RM";
        cin >> allowance;
        if (allowance < 0) cout << "Allowance cannot be negative. Please try again.\n";
    } while (allowance < 0);
    emp.set_total_allowance(allowance);
}

// Input function for pension date


void input_pension_date(Pension_Info &emp) {
    int day, month, year;

    do {
        cout << "Day: ";
        cin >> day;
        if (day < 1 || day > 31) {
            cout << "Please enter a valid day (1-31).\n";
        }
    } while (day < 1 || day > 31);

    do {
        cout << "Month: ";
        cin >> month;
        if (month < 1 || month > 12) {
            cout << "Please enter a valid month (1-12).\n";
        }
    } while (month < 1 || month > 12);

    cout << "Year: ";
    cin >> year;

    emp.set_pension_date(day, month, year);
}



// Main function

int main() {
    Pension_Info emp; // single object
    int choice;
    bool personalInfoEntered = false, serviceInfoEntered = false; // no info added yet

	// Display menu
    do {
        cout << "\n===== Pension Eligibility and Calculation App (PECA) =====\n";
        cout << "1. Input Personal Information\n";
        cout << "2. Input Service and Wages Information\n";
        cout << "3. Display Service and Wages Information\n";
        cout << "4. Set Pension Date and Calculate Pension Estimation\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

	// Menu selection switch statement
        switch (choice) {
            case 1:
                input_personal_info(emp);
                personalInfoEntered = true;
                break;
            case 2:
                if (!personalInfoEntered) {
                    cout << "Please enter Personal Information first (Option 1).\n";
                } else {
                    input_service_info(emp);
                    serviceInfoEntered = true;
                }
                break;
            case 3:
                if (!personalInfoEntered) {
                    cout << "Please enter Personal Information first (Option 1).\n";
                } else if (!serviceInfoEntered) {
                    cout << "Please enter Service Information first (Option 2).\n";
                } else {
                    emp.display_service_info();
                }
                break;
            case 4:
                if (!personalInfoEntered) {
                    cout << "Please enter Personal Information first (Option 1).\n";
                } else if (!serviceInfoEntered) {
                    cout << "Please enter Service Information first (Option 2).\n";
                } else {
                    cout << "Set Pension Date:\n";
                    input_pension_date(emp);
                    cout << "\n===== Employee Details =====\n";
                        emp.display_service_info();
                    emp.calculate_eligibility();
                }
                break;
            case 5:
                cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please select again.\n";
        }
    } while (choice != 5);

    return 0;
}

