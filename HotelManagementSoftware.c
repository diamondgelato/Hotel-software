#include <stdio.h>
#include <string.h>

//GLOBAL VARIABLES
struct customer {
  char name [20];
  char nationality [20];
  int id;
  int members;
  int roomId;
};

struct room {
  char type [7];
  int available;
  int id;
  int rate;
  int stayCharge;
  int foodCharge;
  int grandTotal;
  int duration;
  int custId;
};

struct customer CUST [20];
struct room hotel [5];
int newCustomer = 1;
int i;
int room;

//FUNCTION PROTOTYPES
void getAvailablity();
void printAvailablity();
void printRoomFeature();
void checkIn();
void printCustInfo();
void restaurant();
void checkOut();
void startPage();


/*
    This function is there to display the features of the hotal and serves as an introduction to the program
 */
void startPage()
 {
   printf("\n\tNear BSF Chowk, Netaji Subhash Chandra Bose Road, Lonavala City,\n\t\t\t\t Maharashtra 436772, INDIA");
   printf("\n\n                              Ph. No.:022-28537229");
   printf("\n\n\n\nHotel Rosemund Inn is one of the newest Hotel in Lonavala. The Hotel is \nequipped with with all the general amenities and facilities that go \nalong with memorable stay. Set amidst beautifully landscaped gardens, \nit proves to be a ideal dream destination for perceptive traveller.");
   printf("\n\n\nThe Hotel have well furnished rooms along with rooms providing pleasent \nviews of the city. The hotel satisfies the needs of business as well \nas the leisure traveller. All the rooms at the thotel are furnished \nbeautifully. All the rooms are fitted with amenities.");
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
  printf("\n                          ROOM AVAILABILITY");
  printf("\n                         -------------------");
  printf("\n Room No \tType \tCharge \tAvailability \tCust_Name \tPeriod \n");
  for(i=0;i<5;i++)
  {
    printf("\n%d\t\t", (hotel[i].id+1));
    printf("%s\t", hotel[i].type);
    printf("%d\t", hotel[i].rate);

    if (hotel[i].available == 0)
      printf("     N\t\t");
    else if (hotel[i].available == 1)
      printf("     Y\t\t");

    if (hotel[i].custId == 0)
      printf("NA\t\t");
    else
      printf("%s\t", CUST[hotel[i].custId-1].name);

    printf("%d\t", hotel[i].duration);
  }
}


void printRoomFeature()
 {
   int typ;

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
       case 1:
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

       case 2:
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

       case 3:
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

       case 4:
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

       case 5:
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

  getAvailablity();
  printAvailablity();

  printf("\n Enter the room number in which you want to stay:");
  scanf("%d", &room);

  if (hotel[room-1].available == 1)
  {
    fflush(stdin);

    CUST[newCustomer-1].id = newCustomer;
    tempId = newCustomer - 1;
    hotel[room-1].custId = newCustomer;
    CUST[newCustomer-1].roomId = hotel[room-1].id;

    printf("\n Enter Name of customer :");
    gets (CUST[tempId].name);
    printf("\n Enter nationality :");
    gets(CUST[tempId].nationality);
    printf("\n Enter duration of stay(in days) :");
    scanf("%d", &hotel[room-1].duration);
    printf("\n Enter number of member staying in the room :");
    scanf("%d", &CUST[tempId].members);

    if ((room == 1) || (room == 2) || (room == 3))
    {
      if((CUST[tempId].members < 1)||(CUST[tempId].members>5))
      {
        printf("\n %d members cannot be allocated this room.Allowed members are between 1-5.", CUST[tempId].members);
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

    printf("\n Room is allocated to %s for %d days.", CUST[hotel[i].custId].name, hotel[room-1].duration);
    hotel[room-1].available = 0;
    newCustomer++;
  }
  else
  {
    printf("\n ERROR : Room cannot be allocated ...");
    printf("\n Room is not available...");
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

  printf("\nEnter the room number:");
  scanf("%d",&room);
  a = room - 1;

  if(hotel[a].custId == 0)
  {
    printf("\nThe room is empty........");
  }
  else
  {
    printf("Are you sure you want to deallocate this room? (1 for yes/0 for no) : ");
    scanf("%d", &ch);

    if (ch == 1)
    {
      printf("\nRoom number %d is deallocated......",room);
      hotel[a].custId = 0;
    }

    else
    {
      printf("\nOk cool!");
    }
  }

  hotel[a].stayCharge = hotel[a].rate * hotel[a].duration;
  hotel[a].grandTotal = hotel[a].stayCharge + hotel[a].foodCharge;
  printf("\n\nYour total bill is %d", hotel[a].grandTotal);
  printf("\n\n\nThanks for staying in this hotel!");
}

void printCustInfo()
 {
   int i;
   printf("\nEnter the room number :");
   scanf("%d",&room);
   i = room - 1;

   if(hotel[i].custId==0)
     {
       printf("\n Data not available ");
     }
   else
     {
       printf("\n Room No        :%d", (hotel[i].id+1));
       printf("\n Customer Name  :%s", CUST[hotel[i].custId-1].name);
       printf("\n Customer Id    :%d", hotel[i].custId);
       printf("\n Period         :%d", hotel[i].duration);
       printf("\n Nationality    :%s", CUST[hotel[i].custId-1].nationality);
       printf("\n No of members   :%d", CUST[hotel[i].custId].members);
     }
 }


void restaurant()
 {
   int count=0,z=0,fc[113],answ,p,i;
   char ans,rname[20], name[20];
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

   printf("\n                        *********");
   printf("\n                        MENU CARD");
   printf("\n                        *********");
   printf("\n\n                        VEGETARIAN\n");
   for(i=0;i<103;count++,i++)
     {
       printf("\t%d\t\t",i+1);
       printf("%s\t\t", food[i]);
       printf("%d\n",price[i]);

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
   printf("\n\nPRESS 0 TO GO BACK TO MENU CARD\nPRESS 1 TO CONTINUE ");
   scanf("%d",&answ);
   switch(answ)
     {
       case 0:restaurant();
       break;

       case 1 :
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
         if(CUST[i].roomId==(room-1))
         {
           strcpy(rname,CUST[i].name);
           p=i;
           break;
         }
       }
        if(strcmpi(name,rname)!=0)
   {
     printf("\nWrong name...:");
     restaurant();
   }
        for(i=0;i<z;i++)
   {
     printf("%s", food[fc[i]-1]);
     printf("\t\t\t%d\n",price[fc[i]-1]);
     hotel[p].foodCharge +=price[fc[i]-1];
   }
        printf("TOTAL\t\t\t\t%d",hotel[p].foodCharge);
        break;

       default:printf("\nWrong choice entered!!!");
        restaurant();
     }
 }


int main()
 {
   char ans;
   int ch, j;
   for (j = 0; j < 5; j++)
   {
     hotel[j].id = j;
     hotel[i].foodCharge = 0;
     hotel[i].custId = 0;
   }

   startPage();
   do
     {
       printf("\n\n\n        Choose a category:\n");
       printf("    1. Get availability\n");
       printf("    2. Features of room\n");
       printf("    3. Room allocation\n");
       printf("    4. Show customer details\n");
       printf("    5. Restaurant\n");
       printf("    6. Room Deallocation\n");
       printf("    7. Exit\n");
       printf("\n\nEnter your choice: ");
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
     case 6:checkOut();
     break;
     case 7:return 0;
     default:printf("\n\n\nWrong choice!!!!\n\nPlease choose 1-7");
   }
 printf("\n\nDo you want to continue:");
 fflush(stdin);
 scanf("%c",&ans);
     }while(ans=='y'||ans=='Y');
 }
