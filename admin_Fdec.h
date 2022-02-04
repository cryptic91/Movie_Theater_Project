int choice;
char findMovies;
FILE *fp, *ft, *fs;
struct movies
{
    int id;
    char movName[25];
    char date[12];
    char time[8];
    int price;
} a;

COORD coord = {0, 0};
int J=0;

void welcome();

void adminLogin();
void adminlogin1();
void admin();
void add_movie();
void delete_movie();
void browse_movies();
void deleteMovies();

int getMovie();
int checkid();

int EXIT();

void gotoxy (int x, int y);