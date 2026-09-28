C
/*
* Colossus Airlines Reservation System
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define SEATS 24
#define NAME_LEN 30
 
struct seat {
int id;
int assigned;
char first[NAME_LEN];
char last[NAME_LEN];
};
 
void initialize(struct seat flight[]);
void showEmptySeats(struct seat flight[]);
void showEmptyCount(struct seat flight[]);
void showAlphabetical(struct seat flight[]);
void deleteSeat(struct seat flight[]);
void assignSeat(struct seat flight[]);
void flightMenu(struct seat flight[], char flightName[]);
void stripNewline(char str[]);
 
int main(void)
{
struct seat outbound[SEATS];
struct seat inbound[SEATS];
 
initialize(outbound);
initialize(inbound);
 
char choice[10];
 
while (1)
{
printf("\n===== COLOSSUS AIRLINES =====\n");
printf("a) Outbound Flight\n");
printf("b) Inbound Flight\n");
printf("c) Quit\n");
printf("Enter choice: ");
 
fgets(choice, sizeof(choice), stdin);
 
switch (choice[0])
{
case 'a':
flightMenu(outbound, "Outbound");
break;
 
case 'b':
flightMenu(inbound, "Inbound");
break;
 
case 'c':
printf("Program terminated.\n");
return 0;
 
default:
printf("Invalid choice.\n");
}
}
}
 
void initialize(struct seat flight[])
{
int i;
 
for (i = 0; i < SEATS; i++)
{
flight[i].id = i + 1;
flight[i].assigned = 0;
 
strcpy(flight[i].first, "");
strcpy(flight[i].last, "");
}
}
 
void flightMenu(struct seat flight[], char flightName[])
{
char choice[10];
 
while (1)
{
printf("\n--- %s Flight ---\n", flightName);
printf("a) Show number of empty seats\n");
printf("b) Show list of empty seats\n");
printf("c) Show alphabetical list of seats\n");
printf("d) Assign customer to seat\n");
printf("e) Delete seat assignment\n");
printf("f) Return to main menu\n");
printf("Enter choice: ");
 
fgets(choice, sizeof(choice), stdin);
 
switch (choice[0])
{
case 'a':
showEmptyCount(flight);
break;
 
case 'b':
showEmptySeats(flight);
break;
 
case 'c':
showAlphabetical(flight);
break;
 
case 'd':
assignSeat(flight);
break;
 
case 'e':
deleteSeat(flight);
break;
 
case 'f':
return;
 
default:
printf("Invalid choice.\n");
}
}
}
 
void showEmptyCount(struct seat flight[])
{
int count = 0;
int i;
 
for (i = 0; i < SEATS; i++)
{
if (flight[i].assigned == 0)
count++;
}
 
printf("Empty seats: %d\n", count);
}
 
void showEmptySeats(struct seat flight[])
{
int i;
 
printf("Empty seats:\n");
 
for (i = 0; i < SEATS; i++)
{
if (flight[i].assigned == 0)
printf("Seat %d\n", flight[i].id);
}
}
 
void showAlphabetical(struct seat flight[])
{
int i;
int found = 0;
 
printf("\nAssigned Seats:\n");
 1 || seat > 24)
{
printf("Invalid seat number.\n");
return;
}
 
if (flight[seat - 1].assigned)
{
printf("Seat already occupied.\n");
return;
}
 
printf("Enter first name (ABORT to cancel): ");
fgets(flight[seat - 1].first,
sizeof(flight[seat - 1].first),
stdin);
 
stripNewline(flight[seat - 1].first);
 
if (strcmp(flight[seat - 1].first, "ABORT") == 0)
{
printf("Assignment cancelled.\n");
return;
}
 
printf("Enter last name (ABORT to cancel): ");
fgets(flight[seat - 1].last,
sizeof(flight[seat - 1].last),
stdin);
 
stripNewline(flight[seat - 1].last);
 
if (strcmp(flight[seat - 1].last, "ABORT") == 0)
{
printf("Assignment cancelled.\n");
return;
}
 
flight[seat - 1].assigned = 1;
 
printf("Seat assigned successfully.\n");
}
 
void deleteSeat(struct seat flight[])
{
char buffer[100];
int seat;
 
printf("Enter seat number to delete or 0 to cancel: ");
fgets(buffer, sizeof(buffer), stdin);
 
seat = atoi(buffer);
 
if (seat == 0)
{
for (i = 0; i < SEATS; i++)
{
if (flight[i].assigned)
{
printf("Seat %d: %s, %s\n",
flight[i].id,
flight[i].last,
flight[i].first);
 
found = 1;
}
}
 
if (!found)
printf("No assigned seats.\n");
}
 
void assignSeat(struct seat flight[])
{
char buffer[100];
int seat;
 
printf("Enter seat number (1-24) or 0 to cancel: ");
fgets(buffer, sizeof(buffer), stdin);
 
seat = atoi(buffer);
 
if (seat == 0)
{
printf("Assignment has been cancelled.\n");
return;
}
 
if (seat < 
printf("Delete has been cancelled.\n");
return;
}
 
if (seat < 1 || seat > 24)
{
printf(" This is an invalid seat number.\n");
return;
}
 
if (flight[seat - 1].assigned == 0)
{
printf("Seat is empty.\n");
return;
}
 
flight[seat - 1].assigned = 0;
 
strcpy(flight[seat - 1].first, "");
strcpy(flight[seat - 1].last, "");
 
printf("The Seat assignment has been  removed.\n");
}
 

void stripNewline(char str[])
{
str[strcspn(str, "\n")] = '\0';
}





