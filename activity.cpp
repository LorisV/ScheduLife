#include "activity.h"
#include "QDebug"

Activity::Activity(std::string descr,short int strtH, short int strtM, short int endH, short int endM):
description(descr), startHh(strtH),startMm(strtM),endHh(endH),endMm(endM){
}

bool Activity::operator<(const Activity& that){
    if((startHh<that.startHh)||
        ((startHh==that.startHh)&&(startMm<that.startMm))){
        return true;
    }
      else return false;
}

const std::string &Activity::getDescription() const {
    return description;
}

void Activity::setDescription(const std::string &description) {
    Activity::description = description;
}

short Activity::getStartHh() const {
    return startHh;
}

void Activity::setStartHh(short startHh) {
    Activity::startHh = startHh;
}

short Activity::getStartMm() const {
    return startMm;
}

void Activity::setStartMm(short startMm) {
    Activity::startMm = startMm;
}

short Activity::getEndHh() const {
    return endHh;
}

void Activity::setEndHh(short endHh) {
    Activity::endHh = endHh;
}

short Activity::getEndMm() const {
    return endMm;
}

void Activity::setEndMm(short endMm) {
    Activity::endMm = endMm;
}

QString Activity::readActivity() const {
    QTime startTime(startHh,startMm,0,0);
    QTime endTime(endHh,endMm,0,0);
    QString startDisplay = startTime.toString("hh:mm");
    QString endDisplay = endTime.toString("hh:mm");
    QString txtActivity=QString::fromStdString(description)+" from "+ startDisplay+ " to "+endDisplay;

    return txtActivity;
}
