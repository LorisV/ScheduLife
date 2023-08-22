#include "activity.h"
#include "QDebug"

Activity::Activity(std::string descr,short int strtH, short int strtM, short int endH, short int endM):
description(descr), startHh(strtH),startMm(strtM),endHh(endH),endMm(endM){
};

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
    //QString qdescr=QString::fromStdString(description);
    QString txtActivity=QString::fromStdString(description)+" from "+QString::number(startHh)+
            ":"+QString::number(startMm)+" to "+ QString::number(endHh)+":"+QString::number(endMm);
    return txtActivity;
}
