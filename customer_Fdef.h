void customer1()
{   
    gotoxy(10,3);//slowmo
    char d[25] = " Customer Login Portal " ;
    int j;

    gotoxy(10,1);
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0;j<strlen(d);j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    customer();
}

void customer()
{   
    gotoxy(30,3);
    printf("You are in Customer Mode.");
    gotoxy(10,5);
    printf("1. Sign up");
    gotoxy(10,6);
    printf("2. Log in");
    gotoxy(10,7);
    printf("3. Browse movies");
    gotoxy(10,8);
    printf("4. Exit");

    gotoxy(10,10);
    printf("Enter your choice: ");
    scanf("%d",&choice);
    fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); signup(); break;

        case 2: system("cls"); login(); break;

        case 3:
        {   
            system("cls");
            browse_movies();
            printf("Press ENTER to go back to Customer panel...");
            getch();
            system("cls");
            customer();
            break;
        }

        case 4: system("cls"); welcome(); break;

        case 5: system("cls"); TestRead(); break;

        case 6: system("cls"); testRead(); break;
    }
}

void signup()
{
    fsu = fopen("userinfo.txt","a+");
    if(getSignup()==1)
    {
        fseek(fsu,0,SEEK_END);
        fwrite(&b,sizeof(b),1,fsu);
        fclose(fsu);
    }

    fli = fopen("logininfo.txt","a+");
    if(getLogin()==1)
    {
        fseek(fli,0,SEEK_END);
        fwrite(&c,sizeof(c),1,fli);
        fclose(fli);

        gotoxy(10,9);
        printf("You've succesfully created an account.");
        gotoxy(10,10);
        printf("Press ENTER to Log in...");
    }
    getch(); //customer();
    system("cls");
    login();
}

int getSignup()
{   
    gotoxy(10,4);
    printf("Enter First Name: ");
    gets(b.Fname);
    fflush(stdin);
    gotoxy(10,5);
    printf("Enter  Last Name: ");
    gets(b.Lname);
    fflush(stdin);

    return 1;
}

int getLogin()
{   
    gotoxy(10,6);
    printf("Enter   Username: ");
    gets(c.username);
    fflush(stdin);
    gotoxy(10,7);
    printf("Enter   Password: ");
    gets(c.password);
    fflush(stdin);

    return 1;
}

void login()
{
    char u_name[20], p_word[17];

    gotoxy(10,4);
    printf("Enter Username: ");
    gets(u_name); fflush(stdin); //printf("%s\n",u_name);
    gotoxy(10,5);
    printf("Enter Password: ");
    gets(p_word); fflush(stdin); //printf("%s\n",p_word);

    fli = fopen("logininfo.txt","r");
    //rewind(fli);
    while(fread(&c,sizeof(c),1,fli)==1)
    {   
        count=0;
        //printf("in while loop %s %s\n",c.username,c.password);
        if(((strcmp(c.username,u_name)==0)) && ((strcmp(c.password,p_word)==0)))
        {
            system("cls");
            fclose(fli); count++;
            strcpy(uname,c.username);
            in_login();
        }
        /*printf("%s ",c.username);
        printf("%s ",c.password);*/
    }
    if(count==0)
    {
            
        system("cls"); 
        fclose(fli);
        gotoxy(10,8);
        printf("You've entered invalid log in information.");
        gotoxy(10,9);
        printf("Please, enter your username and password again.");
        login();
    }
}

void in_login()
{   
    gotoxy(18,4);
    printf("MY ACCOUNT");
    gotoxy(10,6);
    printf("1. Browse Movies to buy");
    gotoxy(10,7);
    printf("2. Your Movie list");
    gotoxy(10,8);
    printf("3. Log out");

    gotoxy(10,10);
    printf("Enter your choice: ");
    scanf("%d",&choice);
    fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); browseMovToB(); break;

        case 2: system("cls"); ur_movies(); break;

        case 3: system("cls"); customer(); break;

        default: system("cls"); gotoxy(13,2); printf("Invalid choice. Try again."); in_login(); break;
    }
}

void browseMovToB()
{   
    int ticket;
    count=0;
    browse_movies();

    fp = fopen("movies.txt","r");

    // rewind(fp);
    // while(fread(&a,sizeof(a),1,fp)==1)
    // {
    //     printf("%d ",a.id);
    //     printf("%s ",a.movName);
    //     printf("%s ",a.date);
    //     printf("%s ",a.time);

    //     printf("\n");
    // }
    // //fclose(fp);

    
    // printf("\n");
    printf("Enter movie id to buy ticket: ");
    scanf("%d",&ticket);
    fflush(stdin);

    rewind(fp);

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(ticket==a.id)
        {   
            system("cls");
            gotoxy(10,2);
            printf("Movie id = %d is avilable.",ticket);
            gotoxy(10,3);
            printf("Movie name is \"%s\"",a.movName);

            //storing movie information in another struct to show them in ur_movies() function
            d.id = a.id;
            d.price = a.price;
            strcpy(d.username,uname);
            strcpy(d.movName,a.movName);
            strcpy(d.date,a.date);
            strcpy(d.time,a.time);

            fclose(fp);
            count++;
            break;
        }
    }
    if(count==0)
    {   
        system("cls");
        gotoxy(10,2);
        printf("Movie id = %d is not avilable.",ticket);
        fclose(fp);
        gotoxy(10,3);
        printf("Press ENTER to search again...");
        getch();
        browseMovToB();
    }
    else if(count>0)
    {
        gotoxy(10,5);
        printf("Do you want to buy ticket for this movie? (Y/N): ");
        if(getch()=='y')
        {   
            system("cls");
            buyTicket();
        }
        else
        {   
            gotoxy(10,6);
            printf("Press \"Y\" to search for another movie to buy or press \"ENTER\" to go back to MY ACCOUNT: ");

            if(getch()=='y')
            {
                system("cls");
                browseMovToB();
            }
            else 
            {
                system("cls");
                in_login();
            }
        }
    }
   

}

void buyTicket()
{
    gotoxy(10,3);
    printf("Enter how many tickets you want to buy for movie \"%s\": ",d.movName);
    scanf("%d",&d.quatity); fflush(stdin);
    gotoxy(10,4);
    printf("You have bought %d tickets of \"%s\" movie.",d.quatity,d.movName);

    /*
    printf("Quantity = %d\n",d.quatity);
    printf("username = %s\n",d.username);
    printf("id = %d\n",d.id);
    printf("movname = %s\n",d.movName);
    printf("date = %s\n",d.date);
    printf("time = %s\n",d.time);
    */

    urm = fopen("ur_movies.txt","a+");
    fseek(urm,0,SEEK_END);
    fwrite(&d,sizeof(d),1,urm);
    fclose(urm);

    gotoxy(10,6);
    printf("Do you want to buy another movie ticket (Y/N): ");
        if(getch()=='y')
        {   
            system("cls");
            browseMovToB();
        }
        else
        {   
            gotoxy(10,7);
             printf("Press \"Y\" to see your movie list or press \"ENTER\" to go back to MY ACCOUNT: ");

            if(getch()=='y')
            {
                system("cls");
                ur_movies();
            }
            else 
            {
                system("cls");
                customer();
            }
        }
}

void ur_movies()
{
    /*
    urm = fopen("ur_movies.txt","r");
    
    while(fread(&d,sizeof(d),1,urm)==1)
    {
        if((!(strcmp(d.username,uname))))
        {
            printf("Quantity = %d\n",d.quatity);
            printf("username = %s\n",d.username);
            printf("id = %d\n",d.id);
            printf("movname = %s\n",d.movName);
            printf("date = %s\n",d.date);
            printf("time = %s\n",d.time);
        }
        printf("\n");
    }
    fclose(urm);

    printf("Y to return to customer mode: ");
    getch(); login();
    */

    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("************************** MOVIE LIST ****************************");
    gotoxy(2,3);
    printf("  ID      MOVIE NAME        DATE       TIME       PRICE   QUANTITY");
    //printf("  ID  MOVIE NAME      DATE      TIME     PRICE   QUANTITY");
    gotoxy(1,4);
    printf("--------------------------------------------------------------------");
    j=6;

    urm = fopen("ur_movies.txt","r");
    rewind(urm);

    while(fread(&d,sizeof(d),1,urm)==1)
    {   
        if((!(strcmp(d.username,uname))))
        {
            gotoxy(3,j);
            printf("%d",d.id);
            gotoxy(12,j);
            printf("%s",d.movName);
            gotoxy(29,j);
            printf("%s",d.date);
            gotoxy(41,j);
            printf("%s",d.time);
            gotoxy(54,j);
            printf("%d",d.price);
            gotoxy(63,j);
            printf("%d",d.quatity);
            printf("\n\n");
            j++;
        }

    }
    fclose(urm);
    
    gotoxy(1,j+1);
    printf("Press ENTER to return to MY ACCOUNT...");
    getch(); system("cls"); in_login();
}

void TestRead()
{
    fsu = fopen("userinfo.txt","r");

    while(fread(&b,sizeof(b),1,fsu)==1)
    {
        printf("%s ",b.Fname);
        printf("%s ",b.Lname);
    }

    fclose(fsu);

    gotoxy(10,4);
    printf("Enter any key to return to Customer panel... ");
    getch();
    system("cls");
    customer();
}

void testRead()
{
    fli = fopen("logininfo.txt","r");
    while(fread(&c,sizeof(c),1,fli)==1)
    {
        printf("%s ",c.username);
        printf("%s ",c.password);
    }
    fclose(fli);

    gotoxy(10,4);
    printf("Enter any key to return to Customer panel... ");
    getch();
    system("cls");
    customer();
}