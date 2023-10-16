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
    DateTime birthday;
    DateTime study_start; // 01.09.2022 

    // TO DO:  

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    // TO DO: practice and exams 

public:
    Student() :Student("Minho", "lee", { 9, 10, 2000 }, { 1, 9, 2022 }) {}

    Student(string name, string surname) :Student("Minho", "Lee", { 9, 10, 2000 }, { 1, 9, 2022 }) {}

    Student(string name, string surname, DateTime birthday, DateTime study_start)
    {
        SetName(name);
        SetSurname(surname);
        SetBirthday(birthday);
        SetStudyStart(study_start);
    }
    /*Student()
    {
        SetName("");
        SetSurname("");
        SetBirthday({ 9, 10, 2000 });
        SetStudyStart({ 1, 9, 2022 });
    }*/

    // TO DO: constructors overloading !!! 

    // TO DO: make copy c-tor 

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

    // There should not be a setter for the number of grades in a class, because there is a special way to add a grade, and there is no other way to influence this process.

    // TO DO: show what can happen if return pointer to array
    /* int* GetHometaskRates() const
    {
        int* copy = new int[hometask_rates_count];
        for (int i = 0; i < hometask_rates_count; i++)
        {
            copy[i] = hometask_rates[i];
        }
        return copy;
    }*/

    // TO DO: a lot of work here...
};

int main()
{
    Student s;
    s.AddHometaskRate(10);
    s.AddHometaskRate(12);
    s.AddHometaskRate(5);
    s.AddHometaskRate(2);
    s.PrintHometaskRates();
    s.AddHometaskRate(7);
    s.AddHometaskRate(7);
    s.AddHometaskRate(8);
    s.AddHometaskRate(8);
    s.PrintHometaskRates();
    cout << s.GetHometasksRatesCount() << "\n"; // 8
}
