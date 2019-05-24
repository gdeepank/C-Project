# c-project
Metro Reservation System

A C based application built to handle the booking of Metro trains tickets and manage various user subscription features.

This applications is used to supervise the booking of "Namma Metro" trains and manage various special e-metro card features.

Namma Metro, also known as Bengaluru Metro is a metro system serving the city of Bengaluru, India. It is currently the second 
longest operational metro network in India after the Delhi Metro. 

The Metro Network consists of 4 colour coded lines namely: Red, Yellow, Green and Purple.
Through this application, We can buy tickets to travel in any one of the colour coded trains, view stations of any colour coded
train, create metro Cards, modify metro cards, pay through the card and delete the metro card.
The main purpose of this application was to reduce queues in metro counters by booking train tickets digitally. 


System Software Info:

Operating System --> Windows 10 

IDE --> Dev C version 5.11 (TDM-GCC version 4.9.2)


Files Includes With This Project:

metro.c

metro.txt

metro.csv


Header files and functions used:

stdio.h --> printf(),fread(),fwrite(),fgets(),fclose(),fopen(),remove(),rename(),fseek(),ftell(),feof(),getchar(),scanf()

stdlib.h --> atoi(),malloc(),exit(),system(),rand()

string.h --> strcmp(),strtok(),strcpy(),strlen()

time.h --> localtime(),strftime()


User defined functions used:

bgfont() --> Function to change the console colour in the program

dispStation() --> Function to display stations of each line

tcost() --> Function to calculate the cost of tickets

create_card() --> Function to create a metro card

modify_card() --> Function to modify metro card details

pay_cash() --> Function to pay the cost of tickets via cash/e-wallet/credit/debit card

pay_card() --> Function to pay the cost of tickets through metro card 

delete_card() --> Function to delete the metro card

readcsv() --> Function to read a csv file and store the data in a user defined structure


Project Issues:

Tickets are available only for a single line at a time.

The intersecting stations are not displayed in the program.

Details of each train has to be viewed separately.

User can create only a single metro card. 

User cannot recharge the card in the program once it goes out of balance.   
