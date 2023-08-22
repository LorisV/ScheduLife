#include "register.h"

Register::Register(int year,int month,int day)
{
    registerDate.setDate(year,month,day);
    number=progressiveNumber;
    progressiveNumber=progressiveNumber+1;
}

void Register::createActivity(Activity& something){
    activities.push_back(something);
}

QString Register::readScheduledActivities(){
    QString temptxt;
    for(auto& activity:activities){
        temptxt=temptxt+"\n"+activity.readActivity();
    }
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
