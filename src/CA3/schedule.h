#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include <vector>

namespace scheduler {

class Bad_date {};

// Custom exception class for bad time values
class Bad_time {};

// Date class
class Date {
public:
    // Month enumeration
    enum Month {
        jan = 1, feb, mar, apr, may, jun, 
        jul, aug, sep, oct, nov, dec
    };

private:
    int year;
    Month month;
    int day;

    // Check if date is valid
    bool check_date() const {
        if (year < 0) return false;
        if (day < 1) return false;
        
        switch (month) {
            case feb:
                return day <= 28; // Fixed at 28 days for February
            case apr: case jun: case sep: case nov:
                return day <= 30;
            default:
                return day <= 31;
        }
    }

public:
    // Constructor
    Date(int y, Month m, int d) : year(y), month(m), day(d) {
        if (!check_date()) {
            throw Bad_date();  // Simple string exception instead of std::invalid_argument
        }
    }

    // Getters
    int get_year() const { return year; }
    Month get_month() const { return month; }
    int get_day() const { return day; }

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        return os << date.year << '/' << date.month << '/' << date.day;
    }
};

// Time class
class Time {
private:
    int hour;
    int minute;
    int second;

    // Check if time is valid
    bool check_time() const {
        return (hour >= 0 && hour < 24) && 
               (minute >= 0 && minute < 60) && 
               (second >= 0 && second < 60);
    }

public:
    // Constructor
    Time(int h, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        if (!check_time()) {
            throw Bad_time();
        }
    }

    // Getters
    int get_hour() const { return hour; }
    int get_minute() const { return minute; }
    int get_second() const { return second; }

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << (time.hour < 10 ? "0" : "") << time.hour << ':';
        os << (time.minute < 10 ? "0" : "") << time.minute;
        if (time.second > 0) {
            os << ':' << (time.second < 10 ? "0" : "") << time.second;
        }
        return os;
    }
};

class Event {
    protected:
        Date date;
        Time start_time;
        Time end_time;
        std::string location;
        std::vector<std::string> attendees;
    
    public:
        // Constructor using initializer list
        Event(const Date& d, const Time& start, const Time& end, 
              const std::string& loc) 
            : date(d), start_time(start), end_time(end), 
              location(loc) {}
    
        // Add attendee to the vector
        void add_attendee(const std::string& attendee) {
            attendees.push_back(attendee);
        }
    
        // Overload stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Event& event) {
            // Print event details on one line
            os << event.date << " " 
               << event.start_time << "-" << event.end_time << " "
               << "Location: " << event.location;
            
            // Print attendees if any
            if (!event.attendees.empty()) {
                os << " Attendees: ";
                for (size_t i = 0; i < event.attendees.size(); ++i) {
                    os << "\n" << event.attendees[i] << std::endl;
                }
            }
            
            return os;
        }
    };

    class Meeting : public Event {
        private:
            std::string chair;
        
        public:
            // Constructor 
            Meeting(const Date& d, const Time& start, const Time& end, 
                    const std::string& loc, const std::string& meeting_chair)
                : Event(d, start, end, loc), chair(meeting_chair) {}
        
            // Override stream insertion operator
            friend std::ostream& operator<<(std::ostream& os, const Meeting& meeting) {
                // Directly output the base Event details
                os << meeting.date << " " 
                   << meeting.start_time << "-" << meeting.end_time << " "
                   << "Location: " << meeting.location;
                
                // Print attendees
                if (!meeting.attendees.empty()) {
                    os << " \nAttendees:\n ";
                    for (size_t i = 0; i < meeting.attendees.size(); ++i) {
                        os <<  meeting.attendees[i] << "\n";
                        
                    }
                }
                
                // Add chair information
                os << " \nChairperson: " << meeting.chair;
                
                return os;
            }
        };        
} // namespace scheduler

#endif // SCHEDULER_H