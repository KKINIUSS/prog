#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <sstream>
#include <exception>
using namespace std;
class Date {
public:
    Date(int new_year , int new_month, int new_day){
        year = new_year;

        if(new_month >12 || new_month < 1 ){
            throw invalid_argument("Month value is invalid: " + to_string(new_month));
        }
        month = new_month;
        if(new_day > 31 || new_day < 1 ){
            throw invalid_argument("Day value is invalid: " + to_string(new_day));
        }
        day = new_day;
    }

    int GetYear() const{

        return year;

    }
    int GetMonth() const{

    return month;

    }

    int GetDay() const{

    return day;

    }
private:
    int month;
    int day;
    int year;
};
bool operator<(const Date& lhs, const Date& rhs){
    if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();
    }
    else {
        return lhs.GetDay() < rhs.GetDay();
    }

}
ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << setfill('0') << date.GetMonth() << "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}
class Database {
public:
  void AddEvent(const Date& date, const string& event){
      if(!event.empty())
        DB[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event){
    if(DB.count(date)>0 && DB[date].count(event)>0){
        DB[date].erase(event);
        return true;
    }
    return false;
  }
  int  DeleteDate(const Date& date){
    if(DB[date].size()==0){
        return 0;
    }
    else {
        int c = DB[date].size();
        DB.erase(date);
        return c;
    }
  }
  set<string> Find(const Date& date){
    if(DB[date].size()>0){
        set<string> s;
        s = DB[date];
        return s;
    }
    else{
    return {};
  }
  }
  void Print() const{
    for(const auto& i : DB){
        for(const auto& j : i.second){
            cout<< i.first << " " << j << endl;
        }
    }
  }

private:
    map<Date, set<string>> DB;
};
Date inputDate (const string& date){
  stringstream s(date);
  int year;
  int k = 0;
  if ((s >> year) && s.peek() == '-'){
  }else k++;
  s.ignore(1);
  int month;
  if ((s >> month) && s.peek() == '-') {
  }else k++;
  s.ignore(1);
  int day;
  string b;
  if ((s >> day)) {
        s >> b;
        if(!b.empty()){
            k++ ;
        }
    }
    else k++;
    if(k){
    throw invalid_argument("Wrong date format: " + date);
    }
  return Date(year, month, day);
}
int main() {
  Database db;
  string command;
  while (getline(cin, command)) {
    try{
    stringstream s (command);
    string cmd;
    s  >> cmd;
    if (cmd == "Add"){
        string date, event;
        s >> date >> event;
        Date data = inputDate(date);
        db.AddEvent(data, event);
    }
    else if (cmd == "Del"){
        string date;
        s >> date;
        string event;
        string b;
        s >> b;
        if(!b.empty()){
            event = b;
        }
        Date data = inputDate(date);
        if(event.empty()){
           int c = db.DeleteDate(data);
           cout<<"Deleted " << c << " events" << endl;
        }
        else{
            if(db.DeleteEvent(data, event)){
                cout << "Deleted successfully" << endl;
            }
            else{
                cout<<"Event not found"<<endl;
            }
        }
    }
    else if(cmd == "Find"){
        string date;
        s >> date;
        Date data = inputDate(date);
        for(const auto& i: db.Find(data)){
            cout<< i << endl;
        }
    }
    else if(cmd == "Print"){
        db.Print();
    }
    else if(cmd.empty()){
        continue;
    }
    else throw logic_error("Unknown command: " + cmd );
  }
  catch (const exception& ex){
    cout<< ex.what() << endl;
  }
  }


  return 0;
}
