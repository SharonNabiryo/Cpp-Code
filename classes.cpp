#include <iostream>
#include <string>
using namespace std;

enum Month {
    None, Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

class DOB {
    public:
    Month month;
    int day;
    int year;

    DOB(){
        month = None;
    day = 0;
    year = 0;
    }

    void setMonth(Month m){
        month = m;
    }
    void setDay(int d){
        day = d;
    }
    void setYear(int y) {
        year = y;
    }
    string getDate(){
        return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
    }
};

int main(){
    
    DOB dob;

    dob.setMonth(Mar);
    dob.setDay(14);
    dob.setYear(2012);

    cout<< dob.getDate() << endl;

    return 0;
}