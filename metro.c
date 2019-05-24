#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX 72
#define FARE 5


typedef struct {
	int num;
	char station[30];
	char line[10];
	int intpt;
	int status;
} metro;


typedef struct {
	char cno[4];
	char name[100];
	int age;
	char number[20];
	int balance;
} card;


void bgfont(char line[10]) {
	if(strcmp(line,"Green")==0) 
		system("COLOR 2");
	
	if(strcmp(line,"Yellow")==0) 
		system("COLOR 6");
		
	if(strcmp(line,"Purple")==0) 
		system("COLOR 5");
		
	if(strcmp(line,"Red")==0) 
		system("COLOR 4");
}


void dispStation(metro train[80],char line[10]) {
	system("cls");
	int i;
	for(i=1;i<MAX;++i) {
		if(strcmp(line,train[i].line)==0) {
			printf("%d	%s	%d\n",train[i].num,train[i].station,train[i].intpt);
		}
	}
	bgfont(line);	
	getchar();
}	


int tcost(metro train[80]) {
	system("cls");
	card t;
	FILE *f;
	char line[10];
	int i,sno,dno,no,cost,dist,age;
	time_t timeNow;
  	struct tm* time_info;
    char timeStr[sizeof"HH:MM"];
    f=fopen("cards.bin","rb+");
    while(!feof(f)) {
    	fread(&t,sizeof(card),1,f);
    	age=t.age;
	}
	fclose(f);
	printf("Enter the line you want to travel(G/P/R/Y)\n");
	scanf("%s",line);
	while((strcmp(line,"Green")!=0)&&(strcmp(line,"Red")!=0)&&(strcmp(line,"Yellow")!=0)&&(strcmp(line,"Purple")!=0)){
		printf("Invalid Option! No such line exists\n");
		printf("Enter the line you want to travel(G/P/R/Y)\n");
		scanf("%s",line);		
	}
	dispStation(train,line);
	system("COLOR 7");
	printf("Enter the source station number\n");
	scanf("%d",&sno);
	if(strcmp(line,"Green")==0){
		while(sno<=0||sno>22) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the source station number\n");
			scanf("%d",&sno);
		}
	}
	if(strcmp(line,"Red")==0){
		while(sno<23||sno>38) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the source station number\n");
			scanf("%d",&sno);
		}
	}
	if(strcmp(line,"Yellow")==0){
		while(sno<39||sno>52) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the source station number\n");
			scanf("%d",&sno);
		}
	}
	if(strcmp(line,"Purple")==0){
		while(sno<53||sno>71) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the source station number\n");
			scanf("%d",&sno);
		}
	}
	printf("Enter the destination station number\n");
	scanf("%d",&dno);
	if(strcmp(line,"Green")==0){
		while(dno<=0||dno>22) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the destination station number\n");
			scanf("%d",&dno);
		}
	}
	if(strcmp(line,"Red")==0){
		while(dno<23||dno>38) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the destination station number\n");
			scanf("%d",&dno);
		}
	}
	if(strcmp(line,"Yellow")==0){
		while(dno<39||dno>52) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the destination station number\n");
			scanf("%d",&dno);
		}
	}
	if(strcmp(line,"Purple")==0){
		while(dno<53||dno>71) {
			printf("Invalid Option!,Please try again\n");
			printf("Enter the destination statiom number\n");
			scanf("%d",&dno);
		}
	}
	dist = dno-sno;
	printf("Enter the no of tickets\n");
	scanf("%d",&no);
	while(no<0) {
		printf("Invalid choice,Please try again\n");	
	}
	time(&timeNow);
	timeNow += 60*(train[sno].status);
    time_info = localtime(&timeNow);
    strftime(timeStr, sizeof(timeStr), "%H:%M", time_info);
    printf("The next train will arrive in : %s\n", timeStr);
	if(age<60)
		cost=(dist)*no*FARE;
	else
		cost=(dist)*no*(FARE-2);
	if(cost<0)
		cost=cost*(-1);
	printf("Total cost = Rs.%d\n",cost);
	return cost;
}


void create_card() {
	system("cls");
	FILE *f;
	card c;
	char email[20];
	f=fopen("cards.bin","wb+");
	printf("Enter your name\n");
	scanf("%s",c.name);
	printf("Enter your age\n");
	scanf("%d",&c.age);
		while(c.age<3){
		printf("Incorrect age! Please enter again\n");
		scanf("%d",&c.age);
	}
	printf("Enter your Phone number\n");
	scanf("%s",c.number);
	c.cno[0]=c.name[1];
	c.cno[1]=c.name[2];
	c.cno[2]=c.number[4];
	c.cno[3]=c.number[5];
	printf("Enter the amount you want to recharge\n");
	scanf("%d",&c.balance);
	printf("Enter your email-ID\n");
	scanf("%s",email);
	printf("CARD DETAILS\n");
	printf("Name:	%s\n",c.name);
	printf("Age:	%d\n",c.age);
	printf("Phone No.:	%s\n",c.number);
	printf("Card number:	%s\n",c.cno);
	printf("Balance:	%d\n",c.balance);
	if(c.age>=60)
		printf("Type:	Senior Card\n");
	else
		printf("Type:	Normal Card\n");
	printf("Card details successfully sent to your phone number and email");
	fwrite(&c, sizeof(card), 1, f);
	fclose(f);
	getchar();
}


void modify_card() {
	system("cls");
	char key[20],email[20];
	int flag=0, loc;
	card mc;
	FILE *f;
	f=fopen("cards.bin","rb+");
	printf("Enter the card number to be modified\n");
	scanf("%s",key);
	while(!feof(f)) {
		loc=ftell(f);
		fread(&mc, sizeof(card), 1, f);
		if(strcmp(mc.cno,key)==0) {
			flag=1;
			printf("Enter new details\n");
			printf("Enter your name\n");
			scanf("%s",mc.name);
			printf("Enter your age\n");
			scanf("%d",&mc.age);
			while(mc.age<3){
				printf("Incorrect age! Please enter again\n");
				scanf("%d",&mc.age);
			}
			printf("Enter your Phone number\n");
			scanf("%s",mc.number);
			printf("Enter email-ID\n");
			scanf("%s",email);
			mc.cno[0]=mc.name[1];
			mc.cno[1]=mc.name[2];
			mc.cno[2]=mc.number[4];
			mc.cno[3]=mc.number[5];
			printf("New Card number: %s\n",mc.cno);
			if(mc.age>=60)
				printf("Type:	Senior Card\n");
			else
				printf("Type:	Normal Card\n");
			fseek(f,loc,SEEK_SET);
			fwrite(&mc, sizeof(card), 1, f);
			printf("Details successfully modified!\n");
			break;
		}
	}
	if(flag==0)
		printf("Card not found!\n");
	fclose(f);
}


void pay_cash() {
	int tokno;
	printf("Please collect and submit the printed token number at the counter and pay your bill\n");
	tokno=rand();
	printf("%d",tokno);
	getchar();
}


void pay_card(int cost) {
	system("cls");
	char key[20];
	int flag=0, loc;
	card pc;
	FILE *f1;
	f1=fopen("cards.bin","rb+");
	printf("Enter your card number to pay\n");
	scanf("%s",key);
	while(!feof(f1)) {
		loc=ftell(f1);
		fread(&pc, sizeof(card), 1, f1);
		if(strcmp(pc.cno,key)==0) {
			flag=1;
			if(pc.balance<cost) {
				printf("Insufficient balance! Please pay via cash\n");
				pay_cash();
				break;
			}
			printf("Remaining Balance: %d\n",pc.balance);
			pc.balance-=cost;
			fseek(f1,loc,SEEK_SET);
			fwrite(&pc, sizeof(card), 1, f1);
			printf("Current Balance: %d\n",pc.balance);
			printf("Payment Successful! Enjoy your trip\n");
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Card not found!\n");
	fclose(f1);
}


void delete_card() {
	system("cls");
	char key[20];
	int flag=0;
	card d;
	FILE *f1,*f2;
	f1=fopen("cards.bin","rb+");
	f2=fopen("temp.bin","wb");
	printf("Cancellation charges = Rs.5\n");
	printf("Enter the card number to be deleted\n");
	scanf("%s",key);
	while(!feof(f1)) {
		fread(&d, sizeof(card), 1, f1);
		if(strcmp(d.cno,key)==0)
			flag=1;
		
		else
			fwrite(&d, sizeof(card), 1, f2);
	}
	fclose(f1);
	fclose(f2);
	remove("cards.bin");
	rename("temp.bin","cards.bin");	
	if(flag==0)
		printf("Card not found!\n");
	else {
		printf("Remaining Balance in the card = Rs.%d\n",d.balance);
		d.balance-=5;
		printf("Card deleted successfully! Please collect your cash of Rs.%d\n",d.balance);
	}		
}


metro *readcsv(metro train[80]) {
	FILE *file;
	file = fopen("Metro.txt","r");
	char *buf = malloc(80);
	char *item;
	int i=0;
	while (fgets(buf, MAX, file) != NULL) {
        if ((strlen(buf)>0) && (buf[strlen (buf) - 1] == '\n'))
            buf[strlen (buf) - 1] = '\0'; 
		item = strtok(buf, ",");
		train[i].num=atoi(item);
		
		item = strtok(NULL,",");
		strcpy(train[i].station,item);

		item = strtok(NULL,",");
		strcpy(train[i].line,item);
		
		item = strtok(NULL,",");
		train[i].intpt=atoi(item);
		
		item = strtok(NULL,",");
		train[i].status=atoi(item);
		
		i++;
	}
	fclose(file);
	return train;	
}


int main() {
	metro train[80];
	char ch;
	int c1,c2,cost;
	readcsv(train);
	do {
		system("cls");
		printf("NAMMA METRO\n");
		printf("Welcome to Metro booking system\n");
		printf("Please select the appropriate choice\n");
		printf("1.Display Stations\n2.Purchase Ticket\n3.Create Card\n4.Modify Card\n5.Delete Card\n6.Exit\n");
		scanf("%d",&c1);
		switch(c1) {
			case 1: { 
				system("cls");
				char line[10];
				printf("Enter the line whose stations you want to see (G/P/R/Y)\n");
				scanf("%s",line);
				while((strcmp(line,"Green")!=0)&&(strcmp(line,"Red")!=0)&&(strcmp(line,"Yellow")!=0)&&(strcmp(line,"Purple")!=0)){
					printf("Invalid Option! No such line exists\n");
					printf("Enter the line you want to travel(G/P/R/Y)\n");
					scanf("%s",line);		
				}
				dispStation(train,line);
				getchar();
				break; 
			}
			
			case 2: {
				system("cls");
				cost = tcost(train);
				getchar();
				printf("How would you like to pay?\n");
				printf("1.Metro Card\n2.Cash/e-Wallet/Credit or Debit Card\n");
				scanf("%d",&c2);
				while(c2<1||c2>2){
					printf("Invalid Option! Please choose again\n");
					scanf("%d",&c2);
				}
				if(c2==1){
					printf("Total cost of tickets = Rs.%d\n",cost);
					pay_card(cost);
					getchar();
				}
				else if(c2==2) {
					printf("Total cost of tickets = Rs.%d\n",cost);
					pay_cash();
					getchar();
				}
				else
					printf("Invalid Option!\n");
				break;
			}
			
			case 3: {
				system("cls");
				create_card();
				getchar();
				break;
			}
			
			case 4: {
				system("cls");
				modify_card();
				getchar();
				break;
			}
			
			case 5: {
				system("cls");
				delete_card();
				getchar();
				break;
			}		 
			
			case 6: {
				printf("Thank You! Visit again\n");
				getchar();
				exit(0);
				break;
			} 
			
			default: printf("Invalid choice!\n");						
		}
	printf("Would you like to continue?(y/n)\n");
	scanf("	%c",&ch);
	system("COLOR 7");
	}while(ch=='y'||ch=='Y');
	getchar();
	return 0;	
}
