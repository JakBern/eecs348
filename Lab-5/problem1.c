#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char MONTHS[][10] = {
    "January", "February",
    "March", "April",
    "May", "June",
    "July", "August",
    "September", "October",
    "November", "December"};

int fileExists(char filename[], int filenum);

void sortedHi2Lo(int order[12], double sales[12]);

void movingAvg(double sales[], double avg[7]);

double avgSales(double sales[]);

int main() {
    double sales[12];
    char buff[256];
    FILE *data;

    while (1) {
        printf("Please input the file name: \n");
        scanf("%s", buff);
        data = fopen(buff, "r");
        if (data == NULL) {
            printf("The filename was invalid.\n");
            continue;
        }
        else break;
    }

    for (int i = 0; i < 12; i++) {
        fgets(buff, sizeof(buff), data);
        sscanf(buff, "%lf", &sales[i]);
    }
    
    fclose(data);

    int filenum;
    for (filenum = 0; fileExists(buff, filenum); filenum++);
    data = fopen(buff, "w");

    /* sales report section */

    fprintf(data, "Monthly Sales Report:\n\n%-18s%-18s\n\n", "Month", "Sales");
    for (int i = 0; i < 12; i++) {
        fprintf(data, "%-18s$%-18.2lf\n", MONTHS[i], sales[i]);
    }

    int sorted[12];
    sortedHi2Lo(sorted, sales);

    /* min, max, avg */

    fprintf(data, "\n\nSales summary:\n\n");
    fprintf(data, "Minimum sales:\t$%-18.2lf(%s)\n", sales[sorted[0]], MONTHS[sorted[0]]);
    fprintf(data, "Maximum sales:\t$%-18.2lf(%s)\n", sales[sorted[11]], MONTHS[sorted[11]]);
    fprintf(data, "Average sales:\t$%.2lf\n\n\n", avgSales(sales));

    /* moving avg */
    fprintf(data, "Six-Month Moving Average Report:\n\n");
    double movAvg[7];
    movingAvg(sales, movAvg);
    for (int i = 0; i < 7; i++) {
        fprintf(data, "%-13s  -  %-15s$%-18.2lf\n", MONTHS[i], MONTHS[i+5], movAvg[i]);
    }

    /* sales report sorted */

    fprintf(data, "\n\nSales Report (Highest to Lowest):\n\n   Month\t   Sales\n\n");

    for (int i = 11; i >= 0; i--) {
        fprintf(data, "%-18s$%-18.2lf\n", MONTHS[sorted[i]], sales[sorted[i]]);
    }

    fclose(data);

}


void quickSort(int order[12], double sales[12], int start, int end) {
    int size = end - start;
    if (size <= 0 || end < 0 || start < 0) return;
    int pivot = order[(size / 2) + start];
    int startPtr = start - 1;
    int endPtr = end + 1;
    while (1) {
        do {
            startPtr++;
        } while (sales[order[startPtr]] < sales[pivot]);
        do {
            endPtr--;
        } while (sales[order[endPtr]] > sales[pivot]);
        if (startPtr >= endPtr) {
            break;
        }
        else {
            int buf = order[startPtr];
            order[startPtr] = order[endPtr];
            order[endPtr] = buf;
        }
    }
    quickSort(order, sales, start, endPtr);
    quickSort(order, sales, endPtr + 1, end);

}

void sortedHi2Lo(int order[12], double sales[12]) {
    for (int i = 0; i < 12; i++) {order[i] = i;}
    int start = 0;
    int end = 11;
    quickSort(order, sales, start, end);
    return;
};

void movingAvg(double sales[12], double avg[7]) {
    double result = 0;
    for (int i = 0; i < 12; i++) {
        result += sales[i];
        if (i == 5) {
            avg[0] = result / 6.0;
        }
        else if (i > 5) {
            result -= sales[i - 6];
            avg[i-5] = result / 6.0;
        }
    }
    
};

double avgSales(double sales[]) {
    double result = 0;
    for (int i = 0; i < 12; i++) {
        result += sales[i];
    }
    return result / 12.0;
}

int fileExists(char filename[], int filenum) {
    strcpy(filename, "sales_report");
    // if the file number is zero, we don't want to append a number
    FILE *file;
    if (filenum == 0) {
        file = fopen(strcat(filename, ".txt"), "r");
        if (file == NULL) {return 0;}
        else {return 1;}
    }
    char buff[16];
    file = fopen(strcat(strcat(strcat(filename, "-"), itoa(filenum, buff, 10)), ".txt"), "r");
    if (file == NULL) {
        return 0;
    }
    else {
        return 1;
    }
}