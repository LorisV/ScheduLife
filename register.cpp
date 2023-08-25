#include "register.h"
#include "algorithm"
#include "activity.h"
#include "QMessageBox"

Register::Register(int year,int month,int day)
{
    registerDate.setDate(year,month,day);
}

void Register::createActivity(Activity& something){
    for(auto& activity:activities){
        if((activity.getDescription()==something.getDescription())&&
           (activity.getStartHh()==something.getStartHh())&&
           (activity.getStartMm()==something.getStartMm())&&
           (activity.getEndHh()==something.getEndHh())&&
           (activity.getEndMm()==something.getEndMm())){
            QMessageBox::warning(nullptr,"Conflict","The written activity is already registered");
            qDebug()<<"Already registered";
            return;
        }
    }
    activities.push_back(something);
}

QString Register::readScheduledActivities(){

    std::sort(activities.begin(),activities.end());
    QString temptxt;
    for(auto& activity:activities){
        temptxt=temptxt+"\n"+activity.readActivity();
    }
    qDebug()<<temptxt;
    return temptxt;
}

bool Register::operator<(const Register& that){
    if((registerDate.year()<that.registerDate.year())||
       ((registerDate.year()==that.registerDate.year())&&(registerDate.month()<that.registerDate.month()))||
        ((registerDate.year()==that.registerDate.year())&&(registerDate.month()<that.registerDate.month())&&(registerDate.day()<that.registerDate.day()))){
        return true;
    }
     else return false;
}
