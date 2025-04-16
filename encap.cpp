#include <iostream>
#include <string>
using namespace std;

enum  Month {None, Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

class DOB {
    private:
    int doy;
    int year;


    int encode(Month m, int d, int y) const {
        int limits[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4) == 0)
            limits[2] =  29;
        for (int i = 2, acc = limits[1]; i<13; i++){
            acc += limits[i];
            limits[i] = acc;
        }
        if ((m == None) && (d == 0))
        return 0;
        else
        return limits[int(m)-1] +d;
    }

    void decode(int dy, Month & m, int & d, int y) const {
        int limits[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year % 4) == 0)
        limits[2] =  29;
        for (int i = 2, acc = limits[1]; i<13; i++){
            acc += limits[i];
            limits[i] = acc;
        }
        if (dy > limits[12]) {
            m = None;
            d = 0;
        }
        else {
            for (int i=1; i<12; i++){
                if(dy <= limits[i]){
                    m = Month(i);
                    d = dy - limits[i-1];
                    break;
                }
            }
        }
    }

    public:
    DOB(){
        doy = 0;
        year = 0;
    }
    DOB(Month m, int d, int y){
        doy = encode(m,d,y);
        year = y;
    }
    void setMonth(Month m){
        Month mon;
        int d;
        decode(doy, mon, d, year);
        doy = encode(m, d, year);
    }
    void setDay(int d){
    Month m;
    int day;
    decode(doy, m, day, year);
    }

    void setYear(int y){
        year = y;
    }
    string getDate() const {
        Month m;
        int d;
        decode(doy, m, d, year);
        return to_string(m) + "/" + to_string(d) + "/"+ to_string(year);
    }
};

int main(){
    DOB dob(Mar, 14, 2012), phd(Feb, 23, 1998);
    cout << dob.getDate() << " - " << phd.getDate() << endl;
    return 0;
}