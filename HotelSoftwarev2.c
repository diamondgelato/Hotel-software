/**
Changes I have made from the original website code (make sure this documentation
doesnt get into submitted code nai to lavde lagenge)

- Commented all instances of 'getch()', 'clrscr()' (future me nikaalne ka plan
  hai)
- Replaces all instances of 'cputs()' with simple 'printf()'
- Changed most the function names
  - 'intro()' -> 'startPage()'
  - 'cancel()' -> 'cancellation()'
  - 'getavail()' -> 'getAvailablity()'
  - 'putavail()' -> 'printAvailablity()'
  - 'features()' -> 'printRoomFeature()'
  - 'allocate()' -> 'checkIn()'
  - 'deallocate()' -> 'checkOut()'
  - 'putcust()' -> 'printCustInfo()'
  - I think I'll spare 'restaurant()'
- Changed the hotel address (Punjab ka address is not feasible guys)

*/

#include <stdio.h>
//#include<conio.h>
#include <string.h>
//#include<process.h>

//Global variables............
//int advance[5]={750,500,400,500,750};
int  r_no[5]={1,2,3,4,5};
int room;
int tot[5]={0,0,0,0,0};
int g_tot=0;
int  r_charge[5];
char r_type[5][7];  //type of room
char r_cust[5][20]={"N.A","N.A","N.A","N.A","N.A"};  //name of customer
//char c_city[5][20];  //city customer is from
char temp[30];
int  c_mem[5];  //number of members in room
char c_nat[5][20];  //customer nationality
char r_avail[5];  //
int  r_per[5];  //duration of stay
//int  no[5];
//int year[5];
//int month[5];
//int day[5];

//ignore the bad bois above this, these are the new GLOBAL VARIABLES
struct customer {
  char name [20];  //(set by checkIn)
  //char city [20];
  char nationality [20];  //(set by checkIn)
  int id;  //the position of its struct in the array CUST (set by checkIn)
  int members;  //(set by checkIn)
  int roomId = 0;  //(set by checkIn)
};

struct room {
  char type [7];
  int available;  //1 - available and 0 - not available (set by checkIn, reset by checkOut)
  int id;  //is the position of its struct in the array (set by main)
  int rate;  //rate of the room (set by getAvailablity)
  int stayCharge;  //(recorded and reset by checkOut)
  int foodCharge = 0;  //(recorded by restaurant check with Prachi, reset by checkOut)
  int grandTotal;  //(set in checkOut)
  int duration;  //duration of stay in days (set by checkIn, reset by checkOut)
  int custId = 0;  //(set by checkIn, reset by checkOut)
};

struct customer CUST [20];
struct room hotel [5];
int newCustomer = 0;
int i;

//Function prototypes.........
void getAvailablity();
void printAvailablity();
void printRoomFeature();
void checkIn();
void printCustInfo();
void restaurant();
void checkOut();
//void cancellation();
void startPage();
void screenheader();

//Function definitions..........
/*void screenheader()
 {
   printf("\n                       :::::::::::::::::::::::::::::::::::::");
   printf("\n                       ::                                 ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @      WELCOME TO     @     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @    Lovely  Coding   @     ::");
   printf("\n                       ::     @                     @     ::");
   printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
   printf("\n                       ::                                 ::");
   printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
 }*/

/*
    This function is there to display the features of the hotal and serves as an introduction to the program
 */
void startPage()    //prints the first page, which has info about hotel
 {
   printf("\n\tNear BSF Chowk, Netaji Subhash Chandra Bose Road, Lonavala City,\n\t\t\t\t Maharashtra 436772, INDIA");
   printf("\n\n                              Ph. No.:022-28537229");
   //printf("\n\n\n                             WELCOMES YOU..............");
   printf("\n\n\n\tHotel Rosemund Inn is one of the newest Hotel in Lonavala. The Hotel is \t\tequipped with with all the general amenities and facilities that go \t\talong with memorable stay. Set amidst beautifully landscaped gardens, \t\tit proves to be a ideal dream destination for perceptive traveller.");
   printf("\n\n\tThe Hotel have well furnished rooms along with rooms providing pleasent \tviews of the city. The hotel satisfies the needs of business as well \t\tas the leisure traveller. All the rooms at the thotel are furnished \t\tbeautifully. All the rooms are fitted with amenities.");
   printf("\n\n                             AMENITIES .......\n");
   printf("\n\t\t\t1. 100%% Power backup.\n");
   printf("\t\t\t2. Automatic lift.\n");
   printf("\t\t\t3. Ample parking space.\n");
   printf("\t\t\t4. Round the clock security.\n");
   printf("\t\t\t5. Running hot and cold water.\n");
   printf("\t\t\t6. Free internet service.\n");
   printf("\t\t\t7. 24 hours room service.\n");
   printf("\t\t\t8. Laundary service.\n");
   printf("\nPress any character to continue:");
   //getch();
 }

/*
    This function goes through all the room in the hotel and checks whether they are empty or not
 */
void getAvailablity()
{
  for(i=0;i<5;i++)
  {
    if(hotel[i].id == 0)
    {
      strcpy(hotel[i].type, "Sp Dlx");
      hotel[i].rate = 1500;

      if(hotel[i].custId == 0)
      {
        hotel[i].available = 1;
        hotel[i].duration = 0;
      }
    }

    else if(hotel[i].id == 1)
    {
      strcpy(hotel[i].type, "Dlx");
      hotel[i].rate = 1000;

      if(hotel[i].custId == 0)
      {
        hotel[i].available = 1;
        hotel[i].duration = 0;
      }
    }

    else if(hotel[i].id == 2)
    {
      strcpy(hotel[i].type, "Gen");
      hotel[i].rate = 750;

      if(hotel[i].custId == 0)
      {
        hotel[i].available = 1;
        hotel[i].duration = 0;
      }
    }

    else if(hotel[i].id == 3)
    {
      strcpy(hotel[i].type, "Couple");
      hotel[i].rate = 1000;

      if(hotel[i].custId == 0)
      {
        hotel[i].available = 1;
        hotel[i].duration = 0;
      }
    }

    else if(hotel[i].id == 4)
    {
      strcpy(hotel[i].type, "C Dlx");
      hotel[i].rate = 1500;

      if(hotel[i].custId == 0)
      {
        hotel[i].available = 1;
        hotel[i].duration = 0;
      }
    }
  }
}

/*
    This function prints the list of the room, its type, availability and the
    customer details if the room is occupied
 */
void printAvailablity()
{
  //clrscr();
  //screenheader();
  printf("\n                          ROOM AVAILABILITY");
  printf("\n                         -------------------");
  printf("\n Room No |\tType |\tCharge |\tAvailability |\tCust_Name |\tPeriod |\n");
  for(i=0;i<5;i++)
  {
    printf("\n%d\t", (hotel[i].id+1));
    printf("%s\t", hotel[i].type);  //cputs(r_type[i]);
    printf("%d\t", hotel[i].rate);

    if (hotel[i].available == 0)
      printf("N\t");
    else if (hotel[i].available == 1)
      printf("Y\t");

    /*if(i==0)
      printf("    %d\t%c\t     ",r_charge[i],r_avail[i]);
    if((i==1) || (i==2))
      printf("       %d\t   %c\t        ",r_charge[i],r_avail[i]);
    if(i==3 || i==4)
      printf("     %d\t %c\t      ",r_charge[i],r_avail[i]);*/

    if (hotel[i].custId == 0)
      printf("NA\t");
    else
      printf("%s\t", CUST[hotel[i].custId].name);

    //printf("%s", r_cust[i]);   //cputs(r_cust[i]);

    printf("%d\t", hotel[i].duration);
    /*if((i==1) || (i==2))
      printf("\t %d",r_per[i]);
    else if((i==3) || (i==4))
      printf("\t       %d",r_per[i]);
    else
      printf("\t      %d",r_per[i]);*/
  }
}


void printRoomFeature()
 {
   int typ;
   //clrscr();
   //screenheader();
   printf("\nChoose the room type:\n1. Sp. Delux\n2. Delux");
   printf("\n3. General\n4. Couple\n5. C. Delux\n");
   scanf("%d",&typ);
   if(typ>5)
     {
       printf("\nWrong choice!! Choose a number between 1-5:");
       printRoomFeature();
     }
   switch(typ)
     {
       case 1://clrscr();
       //screenheader();
       printf("\n Room number            >>>1");
       printf("\n Advance                >>>750\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Sp.delux");
       printf("\n\n Room charges         >>> Rs.1500 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n\n 3.Balcony available     ");
       printf("\n------------------------------------------------------------------");
       printf("\n                     ADDITIONAL FEATURES                        ");
       printf("\n------------------------------------------------------------------");
       printf("\n\n 1.A/C  available ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       printf("\n------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
       case 2://clrscr();
       //screenheader();
       printf("\n Room number            >>>2\n\n");
       printf("\n Advance                >>>500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Delux                                      ");
       printf("\n\n Room charges         >>>Rs.1000 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.A/C available   ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
       case 3://clrscr();
       //screenheader();
       printf("\n Room number            >>>3\n\n");
       printf("\n Advance                >>>400\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> General                                    ");
       printf("\n\n Room charges         >>>Rs.750 per day");
       printf("\n\n 1. Bed               >>>      2");
       printf("\n\n 2.Capacity           >>>      5");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.Geyser available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
       case 4://clrscr();
       //screenheader();
       printf("\n Room number            >>>4\n\n");
       printf("\n Advance                >>>500\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Couple                                     ");
       printf("\n\n Room charges         >>>Rs.1000 per day");
       printf("\n\n 1. Bed               >>>      1");
       printf("\n\n 2.Capacity           >>>      2");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.Geyser available");
       printf("\n\n 2.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
       case 5://clrscr();
       //screenheader();
       printf("\n Room number            >>>5\n\n");
       printf("\n Advance                >>>750\n\n");
       printf("\n                      FEATURES OF THIS ROOM                       ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n Room Type            >>> Couple Delux                                    ");
       printf("\n\n Room charges         >>>Rs.1500 per day");
       printf("\n\n 1. Bed               >>>      1");
       printf("\n\n 2.Capacity           >>>      2");
       printf("\n-------------------------------------------------------------------");
       printf("\n                    ADDITIONAL FEATURES                        ");
       printf("\n-------------------------------------------------------------------");
       printf("\n\n 1.A/C available   ");
       printf("\n\n 2.Geyser available");
       printf("\n\n 3.TV available      ");
       printf("\n-------------------------------------------------------------------");
       printf("\n NOTE :- Extra bed will cost Rs.50 per bed ");
       break;
      }
 }

/*
    This function registers a new customer who wishes to stay in the hotel
 */
void checkIn()
{
  int room, tempId;

  //clrscr();
  //screenheader();
  getAvailablity();
  printAvailablity();

  printf("\n Enter the room number in which you want to stay:");
  scanf("%d", &room);

  if (hotel[room-1].available == 1)
  {
    fflush(stdin);

    CUST[newCustomer].id = newCustomer;
    tempId = newCustomer;
    hotel[room-1].custId = newCustomer;
    CUST[newCustomer].roomId = hotel[room-1].id;

    printf("\n Enter Name of cust living :");
    gets (CUST[tempId].name);      //gets(r_cust[room-1]);
    //printf("\n Enter city name :");
    //gets (CUST[tempId].city);      //gets(c_city[room-1]);
    printf("\n Enter nationality :");
    gets(CUST[tempId].nationality);
    printf("\n For how many days cust want the room :");
    scanf("%d", &hotel[room-1].duration);
    printf("\n Enter no. of member in your group :");
    scanf("%d", &CUST[tempId].members);

    if ((room == 1) || (room == 2) || (room == 3))
    {
      if((CUST[tempId].members < 1)||(CUST[tempId].members>5))
      {
        printf("\n %d members cannot be allocated this room.Allowed members are between 1-5.", CUST[tempId].members);
        //getch();
        checkIn();
      }
    }
    else if ((room == 4) || (room == 5))
    {
      if((CUST[tempId].members < 1) || (CUST[tempId].members > 2))
      {
        printf("\n %d members cannot be allocated this room.Allowed members are between 1-2.", CUST[tempId].members);
        //getch();
        checkIn();
      }
    }
       /*printf("\n Enter the date of arrival :");
       printf("\n------------------------------");
       printf("\n Year : ");
       scanf("%d",&year[room-1]);
       printf("\n Month :");
       scanf("%d",&month[room-1]);
       printf("\n Day :");
       scanf("%d",&day[room-1]);
       if((year[room-1]>9999)||(month[room-1]>12)||(month[room-1]<1)||(day[room-1]<1)||(((month[room-1]==1)||(month[room-1]==3)||(month[room-1]==5)||(month[room-1]==7)||(month[room-1]==8)||(month[room-1]==10)||(month[room-1]==12))&&(day[room-1]>31))||(((month[room-1]==4)||(month[room-1]==6)||(month[room-1]==9)||(month[room-1]==11))&&(day[room-1]>30))||((month[room-1]==2)&&((year[room-1]%400==0)||((year[room-1]%4==0)&&(year[room-1]%100!=0)))&&(day[room-1]>29))||((month[room-1]==2)&&(year[room-1]%4!=0)&&(day[room-1]>28)))
  {
    //delay(200);
    printf("\n\n!!!!!INVALID DATE........");
    //getch();
    checkIn();
  }*/
       //else
    //{
    printf("\n Room is allocated to %s for %d days.", CUST[hotel[i].custId].name, hotel[room-1].duration);
    //cputs(r_cust[room-1]);
    hotel[room-1].available = 0;
    newCustomer++;
    //getch();
    //}
  }
  else
  {
    printf("\n ERROR : Room cannot be allocated ...");
    printf("\n Room is not available...");
    //getch();
  }
}

/*
    Checklist:
    - Calculate the food and stay totals
    - reset type, foodCharge. stayCharge, grandTotal, duration, custId for the given room
 */
void checkOut()
{
  int room, ch, a;

  //clrscr();
  //screenheader();
  printf("\nEnter the room number:");
  scanf("%d",&room);
  a = room - 1;

  if(hotel[a].custId == 0)  //r_cust[room-1]=="N.A"
  {
    printf("\nThe room is empty........");
    //getch();
  }
  else
  {
    /*printf("\nEnter the name of the person staying in the room:");
    fflush(stdin);
    gets(name);
    if(strcmpi(name,r_cust[room-1])==0)
    {*/

    printf("Are you sure you want to deallocate this room? (1 for yes/0 for no) : ");
    scanf("%d\n", &ch);

    if (ch == 1)
    {
      printf("\nRoom number %d is deallocated......",room);
      hotel[a].custId = 0;
      //getch();
    }

    //}
    else
    {
      printf("\nOk cool!");
      //getch();
      //checkOut();
    }
  }

  hotel[a].stayCharge = hotel[a].rate * hotel[a];
  hotel[a].grandTotal = hotel[a].stayCharge + hotel[a].foodCharge;
  printf("\n\nYour total bill is %d", hotel[a].grandTotal);
  printf("\n\n\nThanks for staying in this hotel!");
}


/*void cancellation()
 {
   //clrscr();
   //screenheader();
   printf("\nEnter the room number:");
   scanf("%d",&room);
   if(strcmp(r_cust[room-1],"N.A")==0)  //r_cust[room-1]=="N.A"
     {
       printf("\nThe room is empty........");
       //getch();
     }
   else
     {
       printf("\nEnter the name of the person staying in the room:");
       fflush(stdin);
       gets(name);
       if(strcmpi(name,r_cust[room-1])==0)
  {
    printf("\nReservation for room number %d is cancelled......",room);
    strcpy(r_cust[room-1],"N.A");
    //getch();
  }
       else
  {
    printf("\nInvalid name........");
    //getch();
    cancellation();
  }
     }
   g_tot=advance[room-1];
   printf("\n\nYour total bill is %d",g_tot);
 }*/


void printCustInfo()
 {
   int j;
   //clrscr();
   //screenheader();
   printf("\nEnter the room number :");
   scanf("%d",&room);
   j=strcmp(CUST[i],"N.A");
   if(j==0)
     {
       printf("\n Data not available ");
       //getch();
     }
   else
     {
       printf("\n Room No        :%d", hotel[i].id);
       printf("\n Customer Name  :%s", CUST[i].name);
       printf("\n Customer Id    :%d", CUST[i].id);
       //cputs(r_cust[room-1]);
       printf("\n Period         :%d", hotel[i].duration);
       //printf("\n City           :%s", c_city[room-1]);
       //cputs(c_city[room-1]);
       printf("\n Nationality    :%s", CUST[i].nationality);
       //cputs(c_nat[room-1]);
       printf("\n No of members   :%d", CUST[i].members);
       //printf("\n Arrival Date   :%d/%d/%d",day[room-1],month[room-1],year[room-1]);
       //getch();
     }
 }


void restaurant()
 {
   int count=0,z=0,fc[113],answ,p,i;
   char ans,rname[20];
   int price[103]={245,245,245,245,240,240,240,240,235,250,235,235,220,
   215,230,
   250,250,250,250,250,250,250,255,245,245,245,245,240,
                   
   240,360,290,360,295,360,290,360,290,250,360,250,370,
   290,360,290,250,250,280,245,290,235,265,
   
   240,290,300,256,240,265,270,255,
   255,240,240,235,220,
                   
   25,30,25,30,35,35,25,30,35,25,35,25,25,30,100,105,105,
   100,105,
                   
   100,105,125,105,105,100,105,110,115,
                   
   100,100,100,105,105,105,105,
   125,105,120,120};
   char food[103][30]={"SHAHI PANEER","KADAI PANEER","CHEESE KORMA",
   "MALAI KOFTA","MATAR PANEER","PALAK PANEER","MIX VEG.","ALOO GOBI",
   "CHANA MASALA","MATAR MUSHROOM","RAJMA MAKHANI","DAL MAKHANI",
   "MIXED RAITA","BUNDI RAITA","PINEAPPLE RAITA","MUSHROOM PANEER",
                   
   "MUTTON MASALA","MUTTON MUGHLAI","MUTTON KORMA",
   "MUTTON DO PYAZA","MUTTON SAGH","MUTTON DAHI","MUTTON ROGAN JOSH",
   "MUTTON CURRY","KADAI MUTTON","KEEMA LEVER","KEEMA MATAR","KEEMA EGG",
   "EGG CURRY",
                   
   "BUTTER CHICKEN","BUTTER CHICKEN(1/2)",
   "KADAI CHICKEN","KADAI CHICKEN(1/2)",
   "CHICKEN MUGHLAI","CHICKEN MUGHLAI(1/2)",
   "CHICKEN MASALA","CHICKEN MASALA(1/2)","CHICKEN MASALA(1/4)",
   "CHICKEN SAGH","CHICKEN SAGH(1/2)",
   "CHICKEN KORMA","CHICKEN KORMA(1/2)",
   "CHICKEN DO PYAZA","CHICKEN DO PYAZA(1/2)","FISH CURRY","CHICKEN CURRY",
   "CHICKEN CURRY(1/2)","CHICKEN CURRY(1/4)","CHILLI CHICKEN","TANDOORI ALOO",
   
                       
   "CHICKEN TIKKA","SEEKH KABAB",
   "FISH TIKKA","CHICKEN TANDOORI",
   "CHICKEN TANDOORI(1/2)","PANEER TIKKA","CHICKEN SEEKH KABAB",
   "CHICKEN HARA KABAB","CHICKEN BIRYANI","MUTTON BIRYANI","PANEER PULAO",
   "VEG.PULAO","JEERA RICE","STEAMED RICE",
                   
   "RUMALI ROTI","ROTI","NAN",
   "ALOO NAN","PANEER NAN","KEEMA NAN","PARANTHA","ALOO PARANTHA",
   "PANEER PARANTHA","PUDINA PARANTHA","BUTTER NAN","LACHCHA PARANTHA",
   "MISSI ROTI","KHASTA ROTI","VEG.BURGER","PANEER BURGER","CHEESE SANDWICH",
   "VEG.PATTI","CHICKEN PATTI",
                 
   "TEA","COFFEE","COLD COFFEE","PINEAPPLE",
   "STRAWBERRY","CHOCOLATE","BLACK FOREST","DOUBLE STORIED","TRIPLE STORIED",
   
   "SOFT CONE","VANILLA","STRAWBERRY","CHOCOLATE","CHOCO CHIPS","MANGO",
   "TUTTI FRUITY","LICHI","PISTA BADAM","CHOCOLATE PISTA BADAM","CHOCO DIP",
   };
   //clrscr();
   //screenheader();
   printf("\n                        *********");
   printf("\n                        MENU CARD");
   printf("\n                        *********");
   printf("\n\n                        VEGETARIAN\n");
   for(i=0;i<113;count++,i++)
     {
       //gotoxy(17,count+20);
       printf("\t%d\t\t",i+1);
       //gotoxy(30,count+20);
       printf("%s\t\t", food[i]);  //cputs(food[i]);
       //gotoxy(55,count+20);
       printf("%d",price[i]);
       /*if(count==17)
  {
    count=0;
    printf("\n                              PRESS ANY KEY TO CONTINUE");
    //getch();
    //clrscr();
    //screenheader();
  }*/
       if(i==15)
  {
    printf("\n\n                     MUTTON\n");
    count +=3;
  }
       if(i==28)
  {
    printf("\n\n                     CHICKEN\n");
    count +=3;
  }
       if(i==48)
  {
    printf("\n\n                     BAR-BE-QUE\n");
    count +=3;
  }
       if(i==64)
  {
    printf("\n\n                   ROTI-NAN-PARANTHA\n");
    count +=3;
  }
       if(i==82)
  {
    printf("\n\n                   BEVERAGES\n");
    count +=3;
  }
       if(i==91)
  {
    printf("\n\n                   ICE-CREAMS\n");
    count +=3;
  }
     }
   //getch();
   //clrscr();
   //screenheader();
   printf("\n\nPRESS 0 TO GO BACK TO MENU CARD\nPRESS 1 TO CONTINUE ");
   scanf("%d",&answ);
   switch(answ)
     {
       case 0:restaurant();
       break;

       case 1 ://clrscr();
        do
   {
     printf("ENTER THE FOOD CODE YOU WANT TO HAVE :: ");
     scanf("%d",&fc[z]);
     z++;
     puts("DO YOU WANT MORE(Y/N) ::");
     fflush(stdin);
     scanf("%c",&ans);
   }while ((ans=='y')||(ans=='Y'));
        printf("\nEnter your room number:");
        scanf("%d",&room);
        printf("\nEnter your name:");
        fflush(stdin);
        gets(name);
       for(i=0;i<5;i++)
       {
         if(CUST[i].roomId==room)
         {
           strcpy(rname,CUSR[i].name);
           p=i;
           break;
         }
       }
        if(strcmpi(name,rnamr)!=0)
   {
     printf("\nWrong name...:");
     //getch();
     restaurant();
   }
        //getch();
        //clrscr();
        //screenheader();
        for(i=0;i<z;i++)
   {
     printf("%s", food[fc[i]-1]);    //cputs(food[fc[i]-1]);
     printf("\t\t\t%d\n",price[fc[i]-1]);
     hotel[p].foodCharge +=price[fc[i]-1];
   }
        printf("TOTAL\t\t\t\t%d",hotel[p].foodChrge);
        break;

       default:printf("\nWrong choice entered!!!");
        //getch();
        restaurant();
     }
 }


int main()
 {
   char ans;
   int ch, j;
   //clrscr();
   //screenheader();
   for (j = 0; j < 5; j++)
   {
     hotel[j].id = j;
   }

   startPage();
   do
     {
       //clrscr();
       //screenheader();
       printf("\n\n\n        Choose a category:\n");
       printf("    1. Get availability\n");
       printf("    2. Features of room\n");
       printf("    3. Room allocation\n");
       printf("    4. Show customer details\n");
       printf("    5. Restaurant\n");
       //printf("    6. Cancellation\n");
       printf("    6. Room Deallocation\n");
       printf("    7. Exit\n");
       scanf("%d",&ch);
       switch(ch)
   {
     case 1:getAvailablity();
     printAvailablity();
     break;
     case 2:printRoomFeature();
     break;
     case 3:checkIn();
     break;
     case 4:printCustInfo();
     break;
     case 5:restaurant();
     break;
     //case 6:cancellation();
     //break;
     case 6:checkOut();
     break;
     case 7:return 0;  //exit(0);
     default:printf("\n\n\nWrong choice!!!!\n\nPlease choose 1-7");
      //getch();
   }
 printf("\n\nDo you want to continue:");
 fflush(stdin);
 scanf("%c",&ans);
     }while(ans=='y'||ans=='Y');
 }
