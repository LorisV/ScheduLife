#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <iostream>
#include "QString"

class Activity {
public:
    Activity(std::string descr="nothing",short int strtH=0,short int strtM=0,short int endH=0,short int endMm=0);

    QString readActivity() const;

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    short getStartHh() const;

    void setStartHh(short startHh);

    short getStartMm() const;

    void setStartMm(short startMm);

    short getEndHh() const;

    void setEndHh(short endHh);

    short getEndMm() const;

    void setEndMm(short endMm);

private:
    std::string description;
    short int startHh,startMm,endHh,endMm;
};

#endif // ACTIVITY_H
