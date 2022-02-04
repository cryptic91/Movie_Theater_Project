struct signup
{
    char Fname[20];
    char Lname[20];
}b;
struct login
{
    char username[20];
    char password[17];
}c;
struct buy_ticket
{   
    int quatity;
    char username[20];
    int id;
    char movName[25];
    char date[12];
    char time[8];
    int price;
}d;

char uname[20];

FILE *fsu, *fli, *urm;
int count=0;

void customer1();
void customer();
void signup();
void login();
int getSignup();
int getLogin();
void ur_movies();
void in_login();
void browseMovToB();
void buyTicket();

void TestRead();
void testRead();