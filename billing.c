void check_out(struct customer c1)
{
	printf("The sparkle Hotel and Spa\n");
	printf("\t Your total bill");
	bill(c1);
}
void bill(struct customer c1)
{
	printf("Your room charges are:");
}
struct customer{
	char name[30];
	int cust_id;
	char mob_no[10];
	char type_room[10];
	char room_service_status;
	char check_in_date[10];
}
