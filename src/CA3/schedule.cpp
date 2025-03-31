#include "schedule.h"

 

using namespace std;

using namespace scheduler;

 

int main() {

   

    try {

        Meeting m( Date(2024, Date::mar, 12), Time(15,0,0), Time(16,0,0),

        "Boardroom A", "Patti Higgins");

    m.add_attendee("Leighton Washington");

    m.add_attendee("Zavier Austin");

    m.add_attendee("Alexis Massey");

    cout << m;
    } catch(Bad_time b) {

        cerr << "Bad time.\n";

    }

    catch (Bad_date){
        cerr << "Bad date\n";
    }

    return 0;

}