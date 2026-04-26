#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    int target_month, target_day;
    time_t now;
    struct tm target_tm = {0};
    struct tm *current_tm;

    // 1. Get user input for the target date
    printf("Enter target date (Month Day, e.g., 12 25): ");
    if (scanf("%d %d", &target_month, &target_day) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // 2. Get current system time
    time(&now);
    current_tm = localtime(&now);

    // 3. Set up the target date structure
    target_tm.tm_mon = target_month - 1; // Months are 0-11 in struct tm
    target_tm.tm_mday = target_day;
    target_tm.tm_year = current_tm->tm_year; // Start with current year
    target_tm.tm_isdst = -1; // Let mktime determine Daylight Saving Time

    // 4. Convert target_tm to time_t to compare
    time_t target_time = mktime(&target_tm);

    // 5. If the target date has already passed this year, set it for next year
    if (difftime(target_time, now) < 0) {
        target_tm.tm_year++;
        target_time = mktime(&target_tm);
    }

    // 6. Calculate the difference in seconds and convert to days
    double seconds = difftime(target_time, now);
    int days = (int)ceil(seconds / (60 * 60 * 24));

    if (days == 0) {
        printf("The specified date is today!\n");
    } else {
        printf("Days until %02d/%02d: %d days\n", target_month, target_day, days);
    }

    return 0;
}

