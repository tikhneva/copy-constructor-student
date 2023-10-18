#include <iostream> 
using namespace std;

/// <summary> 
/// add the variables we will use. We call the class “DateTime” because in it we will determine the date we need
/// </summary> 
class DateTime
{
private:
    int day;
    int month;
    int year;

public:

    /// <summary> 
    /// a method to set day of birth 
    /// </summary> 
    /// <param name="day"></param> 
    void SetDay(int day)
    {
        if (day > 0 && day <= 31) // TO DO: february 28-29, april june 30 
        {
            this->day = day;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary> 
    /// a method to get day of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetDay() const
    {
        return day;
    }

    /// <summary> 
    /// a method to set month of birth 
    /// </summary> 
    /// <param name="month"></param> 
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            cout << "Invalid value!" << endl;
            throw "ERROR!\n";
        }
    }

    /// <summary> 
    /// a method to get month of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetMonth() const
    {
        return month;
    }

    /// <summary> 
    /// a method to set year of birth 
    /// </summary> 
    /// <param name="year"></param> 
    void SetYear(int year)
    {
        this->year = year;
    }

    /// <summary> 
    /// a method to get year of birth 
    /// </summary> 
    /// <returns></returns> 
    int GetYear() const
    {
        return year;
    }

    DateTime() : DateTime(23, 3, 2005) {}

    DateTime(int day, int month) : DateTime(day, month, 2004) {}

    DateTime(int day, int month, int year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }
    /// <summary>
    /// display our date on the screen
    /// </summary>
    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

////////////////////////////////////////////////////// 

/// <summary>
/// add the variables we will use. We call the class “Student” because in it we will describe student's personal information
/// </summary>
class Student
{
    string name;
    string surname;
    string father_name;
    string home_address;
    string phone_number;
    int age;
    DateTime birthday;
    DateTime study_start; // 25.10.1998 

    // TO DO:  

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    int* practice_rates = nullptr;
    int practice_rates_count = 0;

    int* exam_rates = nullptr;
    int exam_rates_count = 0;

public:
    Student() :Student("Minho", "lee", "Minsung" { 25, 10, 1998 }, "Seoul", "0325112014", { 1, 9, 2022 }) {}

    Student(string name, string surname, string father_name, string address, string phone_number) :Student("Minho", "Lee", "Minsung", { 25, 10, 1998 }, "Seoul", "0325112014", { 1, 9, 2022 }) {}

    Student(string name, string surname, string father_name, DateTime birthday, string address, string phone_number, DateTime study_start)
    {
        SetName(name);
        SetSurname(surname);
        SetFatherName(father_name);
        SetBirthday(birthday);
        SetAddress(address);
        SetPhoneNumber(phone_number);
        SetStudyStart(study_start);
    }

    /// <summary> 
    ///  Defines a destructor for the class "Student." This destructor checks for allocated memory for the "hometask_rates" array and removes it if there is, preventing a memory leak
    /// </summary> 
    ~Student()
    {
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }
    }

    /// <summary> 
    /// a method to set the name 
    /// </summary> 
    /// <param name="name"></param> 
    void SetName(string name)
    {
        this->name = name;
    }

    /// <summary> 
    /// a method to get the name 
    /// </summary> 
    /// <returns></returns> 
    string GetName() const
    {
        return name;
    }

private:
    void SetBirthday(const DateTime& birthday)
    {
        this->birthday = birthday;
    }

public:
    /// <summary>
    /// a method to get birthday
    /// </summary>
    /// <returns></returns>
    DateTime GetBirthday() const
    {
        return birthday;
    }
    /// <summary>
    /// a method to set the date of study start
    /// </summary>
    /// <param name="study_start"></param>
    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }
    /// <summary>
    /// a method to get the date of study start
    /// </summary>
    /// <returns></returns>
    DateTime GetStudyStart() const
    {
        return study_start;
    }

    /// <summary>
    /// а method that allows you to change a student's last name
    /// </summary>
    /// <param name="surname">some new value for student surname</param>
    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// a method to get the surname
    /// </summary>
    /// <returns></returns>
    string GetSurname() const
    {
        return surname;
    }

    /// <summary>
    ///  а method that allows you to change a student's father name
    /// </summary>
    /// <param name="father_name"></param>
    void SetFatherName(string father_name) {
        this->father_name = father_name;
    }

    /// <summary>
    /// a method to get the father name
    /// </summary>
    /// <returns></returns>
    string GetFatherName() const {
        return father_name;
    }

    /// <summary>
    /// а method that allows you to change a student's address
    /// </summary>
    /// <param name="home_address"></param>
    void SetAddress(string home_address) {
        this->home_address = home_address;
    }

    /// <summary>
    /// a method to get the adress
    /// </summary>
    /// <returns></returns>
    string GetAddress() const {
        return home_address;
    }

    /// <summary>
    /// а method that allows you to change a student's phone number
    /// </summary>
    /// <param name="phone_number"></param>
    void SetPhoneNumber(string phone_number) {
        this->phone_number = phone_number;
    }

    /// <summary>
    /// a method to get the phone number
    /// </summary>
    /// <returns></returns>
    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    int GetAge() const
    {
        return age;
    }
    /// <summary>
    /// This method involves adding a grade to the student's homework grade list, and the grade should be between 1 and 12 points 
    /// </summary>
    /// <param name="rate">value from 1 to 12</param>
    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter rate. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            int* temp = new int[hometask_rates_count + 1];
            for (int i = 0; i < hometask_rates_count; i++)
                temp[i] = hometask_rates[i];
            temp[hometask_rates_count] = rate;
            delete[] hometask_rates;
            hometask_rates = temp;
        }
        hometask_rates_count++;
    }
    /// <summary>
    /// shows grades for the student's hometask
    /// </summary>
    void PrintHometaskRates() const
    {
        cout << "Hometasks rates: ";
        for (int i = 0; i < hometask_rates_count; i++)
        {
            cout << hometask_rates[i] << ", ";
        }
        cout << "\n";
    }
    /// <summary>
    /// returns the hometask grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetHometaskRateByIndex(unsigned int index) const //to get the grade by index, but without returning a pointer to the original data array, we need to add the "const" keyword to this method
    {
        if (index >= hometask_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return hometask_rates[index];
    }
    /// <summary>
    /// a method to get the hometasks grade count
    /// </summary>
    /// <returns></returns>
    int GetHometasksRatesCount() const
    {
        return hometask_rates_count;
    }

    /// <summary>
    /// This method involves adding a grade to the student's practice grade list, and the grade should be between 1 and 12 points
    /// </summary>
    /// <param name="rate"></param>
    void AddPracticeRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (practice_rates_count == 0)
        {
            practice_rates = new int[1];
            practice_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[practice_rates_count + 1];

            for (int i = 0; i < practice_rates_count; i++)
            {
                temp[i] = practice_rates[i];
            }
            temp[practice_rates_count] = rate;

            delete[] practice_rates;

            practice_rates = temp;
        }

        practice_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's practice
    /// </summary>
    void PrintPracticeRates() const
    {
        cout << "Practice rates: ";
        for (int i = 0; i < practice_rates_count; i++)
        {
            cout << practice_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the practice grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetPracticeRateByIndex(unsigned int index) const
    {
        if (index >= practice_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return practice_rates[index];
    }

    /// <summary>
    ///  a method to get the practice grade count
    /// </summary>
    /// <returns></returns>
    int GetPracticeRatesCount() const
    {
        return practice_rates_count;
    }

    /// <summary>
    /// This method involves adding a grade to the student's exam rate list, and the grade should be between 1 and 12 points
    /// </summary>
    /// <param name="rate"></param>
    void AddExamRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (exam_rates_count == 0)
        {
            exam_rates = new int[1];
            exam_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[exam_rates_count + 1];

            for (int i = 0; i < exam_rates_count; i++)
            {
                temp[i] = exam_rates[i];
            }
            temp[exam_rates_count] = rate;

            delete[] exam_rates;

            exam_rates = temp;
        }

        exam_rates_count++;
    }

    /// <summary>
    /// shows grades for the student's exams
    /// </summary>
    void PrintExamRates() const
    {
        cout << "Exam rates: ";
        for (int i = 0; i < exam_rates_count; i++)
        {
            cout << exam_rates[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// returns the exam grade at the specified index, and at first checks that the index doesn't exeed a valid range
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int GetExamRateByIndex(unsigned int index) const
    {
        if (index >= exam_rates_count)
        {
            cout << "Incorrect index when accessing the evaluation array\n";
            throw "ERROR!";
        }
        return exam_rates[index];
    }

    /// <summary>
    ///  a method to get the exam grade count
    /// </summary>
    /// <returns></returns>
    int GetExamRatesCount() const
    {
        return exam_rates_count;
    }

    /// <summary>
    /// print's student's whole information, but without grades
    /// </summary>
    void ShowStudent() const {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Birthday: " << address << endl;
        cout << "Father Name: " << father_name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Study Start: " << phone_number << endl;
    }

};

int main()
{
    Student s;
    s.AddHometaskRate(10);
    s.AddHometaskRate(12);
    s.AddHometaskRate(9);
    s.AddHometaskRate(8);
    s.PrintHometaskRates();

    s.AddPracticeRate(7);
    s.AddPracticeRate(10);
    s.AddPracticeRate(9);
    s.AddPracticeRate(11);
    s.PrintPracticeRates();

    s.AddExamRate(12);
    s.AddExamRate(10);
    s.AddExamRate(11);
    s.AddExamRate(9);
    s.PrintExamRates();

    s.ShowStudent();
    cout << s.GetHometasksRatesCount() << "\n";
    cout << s.GetPracticeRatesCount() << "\n";
    cout << s.GetExamRatesCount() << "\n";
}
