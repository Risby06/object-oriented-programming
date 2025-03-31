/*  Russel Makani  
    B00164413
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>

namespace scheduler{
    class event{
        private:
            class date {
                private:
                    int y,m,d; // year, month, day

                public:
                    date(int yy, int mm, int dd) {y = yy; m = mm; d = dd; }
                    int month() { return m; }
                    int day() { return d; }
                    int year() { return y; }
            };

            class start_time{
                private:
                    int hr, min ; // hours , minutes
                
                public:
                    start_time(int hrs, int mins) { hr = hrs ; min = mins;}
                    int hour() {return hr;}
                    int minutes(){return min;}

            };

            class end_time{
                private:
                    int hr, min ; // hours , minutes
                
                public:
                    end_time(int hrs, int mins) { hr = hrs ; min = mins;}
                    int hour() {return hr;}
                    int minutes(){return min;}

            };

        public:
            event()


    } ;   // end of event class indicated by semi colon
}   
#endif // SCHEDULER_H