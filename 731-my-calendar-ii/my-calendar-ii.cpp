class MyCalendarTwo {
public:
    map<int, int> events;

    bool book(int start, int end) {
        // Mark the start and end of the event
        events[start]++;
        events[end]--;

        int count = 0;
        for (auto it : events) {
            count += it.second;  // Add the number of active events at this point in time
            if (count >= 3) {    // If at any point, 3 events overlap, we must cancel this booking
                events[start]--;  // Revert the booking
                events[end]++;
                return false;
            }
        }
        return true;  // Booking was successful
    }
};
