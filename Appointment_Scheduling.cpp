//Farhan Azad 11/27/2018
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

struct TimeInterval
{
    int start;
    int end;
};

struct Appointment
{
    TimeInterval time;
    bool emergency;
};

vector <Appointment>  DailySchedule;

bool overlapsWith(TimeInterval current, TimeInterval other);
bool  conflictsWith(Appointment current , Appointment other);
void clearConflicts(Appointment apt);
bool addAppointment(Appointment appt);

int main()
{
    Appointment a1={{2,5},false};
    Appointment a2={{6,8},false};
    Appointment a3={{10,12},false};
    Appointment a4={{1,4},false};
    Appointment a5={{3,6},false};
    Appointment a6={{1,6},false};
    Appointment b1={{7,9},false};
    Appointment b2={{3,4},true};
    cout<<"add a1 returns "<<addAppointment(a1)<<endl;
    cout<<"add a2 returns "<<addAppointment(a2)<<endl;
    cout<<"add a3 returns "<<addAppointment(a3)<<endl;
    cout<<"add a4 returns "<<addAppointment(a4)<<endl;
    cout<<"add a5 returns "<<addAppointment(a5)<<endl;
    cout<<"add a6 returns "<<addAppointment(a6)<<endl;
    cout<<"add b1 returns "<<addAppointment(b1)<<endl;
    cout<<"add b2 returns "<<addAppointment(b2)<<endl;

    cout<<"Appointment"<<setw(10)<<"starts "<<setw(5)<<"ends "<<setw(5)<<" isEmergency\n";

    for (int i =0; i<DailySchedule.size(); i++)
    {
        cout<< "Apt" << i+1<<setw(12)<<DailySchedule[i].time.start<<setw(7)<<DailySchedule[i].time.end<<setw(10);
        if (DailySchedule[i].emergency == true)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;

}

bool overlapsWith(TimeInterval current, TimeInterval other)
{
    if((current.start <= other.end) && (current.start >= other.start))
        return true;
    else if ((current.end <= other.end) && (current.end > other.start))
        return true;
    else
        return false;


}
bool  conflictsWith(Appointment current , Appointment other)
{
    if (current.time.start <= other.time.end && current.time.start >= other.time.start)
        return true;
    else if (current.time.end <= other.time.end && current.time.end >= other.time.start)
        return true;
    else
        return false;
}

void clearConflicts(Appointment apt)
{
    int sizel = DailySchedule.size();
    for(int i=0; i< sizel; i++)
    {
        if(conflictsWith(apt, DailySchedule[i]))
        {
            for (int k = i; k < sizel; k++)
            {
                DailySchedule[k] = DailySchedule[k+1];
            }
            //DailySchedule.erase(DailySchedule.begin()+i);
            DailySchedule.pop_back();
        }

    }
}

bool addAppointment(Appointment appt)
{
    if(appt.emergency==true)
    {
        clearConflicts(appt);
    }
    else
    {
        for(int i=0;i<DailySchedule.size();i++)
        {
            if(conflictsWith(appt, DailySchedule[i]))
                return false;
        }

    }
    DailySchedule.push_back(appt);
    return true;
}
