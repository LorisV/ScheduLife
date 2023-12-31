#ifndef REGISTER_H
#define REGISTER_H
#include "activity.h"
#include "vector"
#include "QDate"

class Register
{
public:
    Register(int year=0,int month=0,int day=0);

    Register& operator=(const Register& that){
        activities=that.activities;
        registerDate=that.registerDate;
        return*this;
    }

    bool operator<(const Register&that);

    void createActivity(Activity& something);
    QString readScheduledActivities();


    int getYear(){
        return registerDate.year();
    }

    int getMonth(){
        return registerDate.month();
    }

    int getDay(){
        return registerDate.day();
    }

private:
    std::vector<Activity> activities;
    QDate registerDate;
};

#endif // REGISTER_H
