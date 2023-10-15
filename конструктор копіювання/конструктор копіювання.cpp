#include <iostream> 
using namespace std;

/// <summary> 
/// add the variables we will use 
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

    void Print() const
    {
        cout << "Date: " << day << "." << month << "." << year << endl;
    }
};

////////////////////////////////////////////////////// 

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
    ///  
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
    DateTime GetBirthday() const
    {
        return birthday;
    }

    void SetStudyStart(const DateTime& study_start)
    {
        this->study_start = study_start;
    }

    DateTime GetStudyStart() const
    {
        return study_start;
    }

    /// <summary> 
    /// а method that allows you to change a student's last name 
    /// </summary> 
    /// <param name="surname">some new