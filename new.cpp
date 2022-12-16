#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

//__________________________________________PROTOTYPES_________________________________________________

void header(HANDLE h);
void clear_screen();
void gotoxy(int x, int y);

string main_page(HANDLE h, string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, int user_count, string u);
bool login();
string Admin(HANDLE h);
string director_1(HANDLE h, string rol);

int add_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol);
int remove_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol);
int update_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol);
int view_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol);

void sort(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[], int user_count, HANDLE h);
int func(int pay[], int position, int user_count);
void store(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[], int user_count);
int load(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[]);
string parse(string record, int field);

int drama_check(string drama[], string date[], int user_count, string serial[], string sdate[]);
int show_drama(string serial[], string sdate[], int dcount, HANDLE h);
void view_drama(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[], int user_count, HANDLE h, string serial[], string sdate[], int idx);
string user_page(HANDLE h, string rol, string user_name[], string role[], int pay[], int user_count, string u);
void user_role(HANDLE h, string rol, string user_name[], string role[], string dramas[], int pay[], int user_count, string u);
void user_profile(HANDLE h, string rol, string user_name[], string user_pass[], string cnic[], string contact[], string address[], string dramas[], string date[], string role[], int pay[], int user_count, string u);
void user_pay(HANDLE h, string rol, string user_name[], string role[], int pay[], int user_count, string u);

//_________________________________MAIN

main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int user_count;
    const int min = 100;
    string user_name[min], user_pass[min], role[min], cnic[min], contact[min], address[min];
    int pay[min];
    string dramas[min], date[min];

    string main;
    string serial[min], sdate[min];

    user_count = load(user_name, user_pass, role, cnic, contact, address, pay, dramas, date);
    sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);

    // for (int i = 0; i < user_count; i++)
    // {
    //     cout << user_name[i] << " " << user_pass[i] << " " << role[i] << " " << cnic[i] << " " << contact[i] << " " << address[i] << " " << pay[i] << " " << dramas[i] << " " << date[i] << endl;
    // }
    // clear_screen();

    int dcount = drama_check(dramas, date, user_count, serial, sdate);
    string u;
    main = main_page(h, user_name, user_pass, role, cnic, contact, address, pay, min, user_count, u);

    if (main == "DIRECTOR")
    {
        string op = "1";
        while (op != "7")
        {

            string rol;
            op = Admin(h);
            if (op == "1")
            {
                string op1 = "2";
                while (op1 != "5")
                {
                    rol = "DIRECTOR";
                    op1 = director_1(h, rol);
                    if (op1 == "1")
                    {
                        user_count = add_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
                        user_count = view_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count);
                }
            }
            else if (op == "2")
            {

                string op1 = "2";
                while (op1 != "5")
                {
                    rol = "WRITER";
                    op1 = director_1(h, rol);
                    if (op1 == "1")
                    {
                        user_count = add_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
                        user_count = view_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count);
                }
            }

            else if (op == "3")
            {

                string op1 = "2";
                while (op1 != "5")
                {
                    rol = "PRODUCER";
                    op1 = director_1(h, rol);
                    if (op1 == "1")
                    {
                        user_count = add_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
                        user_count = view_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {

                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count);
                }
            }
            else if (op == "4")
            {

                string op1 = "2";
                while (op1 != "5")
                {
                    rol = "ACTOR";
                    op1 = director_1(h, rol);
                    if (op1 == "1")
                    {
                        user_count = add_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
                        user_count = view_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count);
                }
            }
            else if (op == "5")
            {

                string op1 = "2";
                while (op1 != "5")
                {
                    rol = "EMPLOYEE";
                    op1 = director_1(h, rol);
                    if (op1 == "1")
                    {
                        user_count = add_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
                        user_count = view_user(user_name, user_pass, role, cnic, contact, address, pay, min, dramas, date, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count);
                }
            }
            else if (op == "6")
            {
                sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
                int opt = show_drama(serial, sdate, dcount, h);
                for (int x = 0; x < dcount; x++)
                {
                    if (serial[opt - 1] == dramas[x] && sdate[opt - 1] == date[x])
                    {
                        view_drama(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h, serial, sdate, x);
                    }
                }
            }
        }
    }

    if (main == "WRITER" || main == "PRODUCER" || main == "ACTOR" || main == "EMPLOYEE")
    {
        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
        string rol = main;
        string op2 = "1";

        while (op2 != "4")
        {
            op2 = user_page(h, rol, user_name, role, pay, user_count, u);

            if (op2 == "1")
            {
                user_profile(h, rol, user_name, user_pass, cnic, contact, address, dramas, date, role, pay, user_count, u);
            }
            else if (op2 == "2")
            {
                user_pay(h, rol, user_name, role, pay, user_count, u);
            }
            else if (op2 == "3")
            {
                user_role(h, rol, user_name, role, dramas, pay, user_count, u);
            }
            else if (op2 != "4")
            {
                cout << "ENTER THE VALID OPTION" << endl;
                clear_screen();
            }
        }
    }

    if (main == "USER")
    {
        sort(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h);
        int opt = show_drama(serial, sdate, dcount, h);
        for (int x = 0; x < dcount; x++)
        {
            if (serial[opt - 1] == dramas[x] && sdate[opt - 1] == date[x])
            {
                view_drama(user_name, user_pass, role, cnic, contact, address, pay, dramas, date, user_count, h, serial, sdate, x);
            }
        }
    }
}

//__________________________MAIN PAGE

string main_page(HANDLE h, string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, int user_count, string u)
{
    string name;
    string pass;
    bool flag = false;
    while (flag == false)
    {
        header(h);
        gotoxy(50, 5);
        cout << "_______________ SIGN IN _______________" << endl
             << endl;
        gotoxy(30, 7);
        cout << "USER NAME ";
        gotoxy(30, 9);
        cout << "PASSWARD";
        gotoxy(50, 7);
        getline(cin, name);
        u = name;
        gotoxy(50, 9);
        getline(cin, pass);

        for (int x = 0; x < user_count; x++)
        {

            if (name == user_name[x] && pass == user_pass[x])
            {

                flag = true;
                return role[x];
            }
        }
        header(h);
        gotoxy(40, 5);
        cout << "ENTER THE VALID USERNAME OR PASSWARD" << endl;
        clear_screen();
    }
}

//__________________________DIRECTOR PAGE

string Admin(HANDLE h)
{
    string op = "0";
    header(h);
    gotoxy(40, 6);
    cout << "_______________ ADMIN MENU _______________" << endl
         << endl;
    cout << "1. DIRECTOR    " << endl;
    cout << "2. WRITER      " << endl;
    cout << "3. PRODUCER    " << endl;
    cout << "4. ACTOR       " << endl;
    cout << "5. EMPLOYEE    " << endl;
    cout << "6. DRAMAS    " << endl;
    cout << "7. EXIT    " << endl;
    cin >> op;
    return op;
}

//__________________________ADMIN=====>>DIRECTOR
string director_1(HANDLE h, string rol)
{
    header(h);
    string op1 = "0";
    gotoxy(40, 6);
    cout << "_______________" << rol << "_______________" << endl
         << endl;
    cout << "1. ADD " << rol << endl;
    cout << "2. REMOVE  " << rol << endl;
    cout << "3. UPDATE " << rol << endl;
    cout << "4. VIEW ALL " << rol << endl;
    cout << "5. EXIT " << endl;
    cin >> op1;
    return op1;
}

//__________________________ADD USER
int add_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol)
{
    header(h);
    gotoxy(50, 6);
    cout << "_______________ ADD " << rol << " _______________" << endl
         << endl;

    gotoxy(0, 7);
    cout << "USERNAME :";
    gotoxy(0, 8);
    cout << "PASSWARD :";
    gotoxy(0, 9);
    cout << "ROLE :";
    role[user_count] = rol;
    gotoxy(0, 10);
    cout << "CNIC :";
    gotoxy(0, 11);
    cout << "CONTACT NO / EMAIL :";
    gotoxy(0, 12);
    cout << "ADRESS :";
    gotoxy(0, 13);
    cout << "PAY :";
    gotoxy(0, 14);
    cout << "DRAMA :";
    gotoxy(0, 15);
    cout << "RELEASING DATE :";

    gotoxy(30, 7);
    cin.ignore();
    getline(cin, user_name[user_count]);
    gotoxy(30, 8);
    getline(cin, user_pass[user_count]);
    role[user_count] = rol;
    gotoxy(30, 9);
    cout << role[user_count];
    gotoxy(30, 10);
    getline(cin, cnic[user_count]);
    gotoxy(30, 11);
    getline(cin, contact[user_count]);
    gotoxy(30, 12);
    getline(cin, address[user_count]);
    gotoxy(30, 13);
    cin >> pay[user_count];
    cin.ignore();
    gotoxy(30, 14);
    getline(cin, dramas[user_count]);
    gotoxy(30, 15);
    getline(cin, date[user_count]);

    gotoxy(20, 18);
    cout << role[user_count] << " IS ADDED" << endl;
    user_count++;

    clear_screen();
    return user_count;
}

//__________________________REMOVE DIRECTOR
int remove_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol)
{
    string nam;
    header(h);
    gotoxy(40, 5);
    cout << "_______________ REMOVE " << rol << " _______________" << endl
         << endl;
    cin.ignore();
    gotoxy(0, 7);
    cout << "USERNAME :";
    gotoxy(30, 7);
    getline(cin, nam);

    char y = ' ';
    for (int x = 0; x < min; x++)
    {

        if (nam == user_name[x] && role[x] == rol)
        {
            gotoxy(15, 10);
            cout << "PRESS Y TO DELETE THIS USER ";
            cin >> y;
            if (y == 'Y')
            {
                for (int i = x; i < user_count; i++)
                {
                    user_name[i] = user_name[i + 1];
                    user_pass[i] = user_pass[i + 1];
                    role[i] = role[i + 1];
                    cnic[i] = cnic[i + 1];
                    contact[i] = contact[i + 1];
                    address[i] = address[i + 1];
                    pay[i] = pay[i + 1];
                    dramas[i] = dramas[i + 1];
                    date[i] = date[i + 1];
                }
                user_count--;
            }
        }
        else
        {
            gotoxy(0, 10);
            cout << nam << " IS NOT A " << rol << endl;
            cout << "ENTER THE VALID USERNAME.......... ";
        }
    }
    if (y == 'y')
    {
        gotoxy(0, 10);
        cout << nam << " IS REMOVED.......";
    }

    clear_screen();
    return user_count;
}

int update_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[], string date[], int user_count, HANDLE h, string rol)
{
    string nam;
    header(h);
    gotoxy(40, 5);
    cout << "_______________ UPDATE " << rol << "_______________" << endl
         << endl;
    cin.ignore();
    gotoxy(0, 7);
    cout << "USERNAME :";
    gotoxy(30, 7);
    getline(cin, nam);

    char y = ' ';
    for (int x = 0; x < user_count; x++)
    {

        if (nam == user_name[x] && role[x] == rol)
        {

            header(h);
            gotoxy(40, 5);
            cout << "_______________ UPDATE " << rol << " _______________";

            gotoxy(0, 7);
            cout << "UPDATE USERNAME :";
            gotoxy(0, 8);
            cout << "UPDATE PASSWARD :";
            gotoxy(0, 9);
            cout << "UPDATE ROLE :";

            gotoxy(0, 10);
            cout << "UPDATE CNIC :";
            gotoxy(0, 11);
            cout << "UPDATE CONTACT NO / EMAIL :";
            gotoxy(0, 12);
            cout << "UPDATE ADRESS :";
            gotoxy(0, 13);
            cout << "UPDATE PAY :";
            gotoxy(0, 14);
            cout << "UPDATE DRAMA :";
            gotoxy(0, 15);
            cout << "UPDATE RELEASING DATE :";

            cin.ignore();
            gotoxy(30, 7);
            cin.ignore();
            getline(cin, user_name[x]);
            gotoxy(30, 8);
            getline(cin, user_pass[x]);
            gotoxy(30, 9);
            getline(cin, role[x]);
            gotoxy(30, 10);
            getline(cin, cnic[x]);
            gotoxy(30, 11);
            getline(cin, contact[x]);
            gotoxy(30, 12);
            getline(cin, address[x]);
            gotoxy(30, 13);
            cin >> pay[x];
            cin.ignore();
            gotoxy(30, 14);
            getline(cin, dramas[x]);
            gotoxy(30, 15);
            getline(cin, date[x]);
        }
        else
        {
            gotoxy(0, 10);
            cout << nam << " IS NOT A " << rol << endl;
            cout << "ENTER THE VALID USERNAME.......... ";
        }
    }
    if (y == 'y')
    {
        gotoxy(0, 10);
        cout << nam << " IS UPDATED.......";
    }
    clear_screen();
    return user_count;
}

int view_user(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], const int min, string dramas[1000], string date[1000], int user_count, HANDLE h, string rol)
{
    header(h);
    gotoxy(40, 5);
    cout << "_______________ VIEW ALL " << rol << " _______________";
    gotoxy(0, 7);
    cout << "NAME ";
    gotoxy(30, 7);
    cout << "ROLE ";
    gotoxy(40, 7);
    cout << "CNIC ";
    gotoxy(60, 7);
    cout << "CONTACT ";
    gotoxy(80, 7);
    cout << "ADDRESS ";
    gotoxy(100, 7);
    cout << "PAY ";
    gotoxy(110, 7);
    cout << "DRAMA ";
    gotoxy(120, 7);
    cout << "RELEASE DATE ";
    int y = 9;
    for (int x = 0; x < user_count; x++)
    {
        if (role[x] == rol)
        {

            gotoxy(0, y);
            cout << user_name[x];
            gotoxy(30, y);
            cout << role[x];
            gotoxy(40, y);
            cout << cnic[x];
            gotoxy(60, y);
            cout << contact[x];
            gotoxy(80, y);
            cout << address[x];
            gotoxy(100, y);
            cout << pay[x];
            gotoxy(110, y);
            cout << dramas[x];
            gotoxy(120, y);
            cout << date[x];
            y++;
        }
    }
    clear_screen();
    return user_count;
}
//-------------------------WRITER

string writer_1(HANDLE h, string rol)
{
    header(h);
    string op1 = "0";
    gotoxy(40, 6);
    cout << "_______________" << rol << "_______________" << endl
         << endl;
    cout << "1. ADD " << rol << endl;
    cout << "2. REMOVE  " << rol << endl;
    cout << "3. UPDATE " << rol << endl;
    cout << "4. VIEW ALL " << rol << endl;
    cout << "5. EXIT " << endl;
    cin >> op1;
    return op1;
}

//__________________________HEADER

void header(HANDLE h)
{
    SetConsoleTextAttribute(h, 1);
    system("cls");
    gotoxy(30, 0);
    cout << "*************************************************************************" << endl;
    gotoxy(30, 1);
    cout << "*                       INDUSTRY MANAGMENT SYSTEM                       *" << endl;
    gotoxy(30, 2);
    cout << "*************************************************************************" << endl;
    SetConsoleTextAttribute(h, 5);
}

//__________________________GOTOXY FUNCTION

void gotoxy(int x, int y)
{
    COORD coordinates; // coordinates is declared as COORD
    coordinates.X = x; // defining x-axis
    coordinates.Y = y; // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

//__________________________CLEAR SCREEN

void clear_screen()
{
    cout << endl
         << " PRESS ANY KET TO CONTINUE ..... " << endl;
    getch();
    system("cls");
}

//__________________________SORTING

void sort(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[], int user_count, HANDLE h)
{
    int position = 0;
    int largest = pay[position];

    for (int i = 0; i < user_count; i++)
    {
        position = i;
        int large = func(pay, position, user_count);

        int temp = pay[i];
        pay[i] = pay[large];
        pay[large] = temp;

        string temp_1;
        temp_1 = user_name[i];
        user_name[i] = user_name[large];
        user_name[large] = temp_1;

        temp_1 = role[i];
        role[i] = role[large];
        role[large] = temp_1;

        temp_1 = cnic[i];
        cnic[i] = cnic[large];
        cnic[large] = temp_1;

        temp_1 = contact[i];
        contact[i] = contact[large];
        contact[large] = temp_1;

        temp_1 = address[i];
        address[i] = address[large];
        address[large] = temp_1;

        temp_1 = dramas[i];
        dramas[i] = dramas[large];
        dramas[large] = temp_1;

        temp_1 = date[i];
        date[i] = date[large];
        date[large] = temp_1;
        // for (int i = 0; i < user_count; i++)
        // {
        //     cout << user_name[i] << " " << user_pass[i] << " " << role[i] << " " << cnic[i] << " " << contact[i] << " " << address[i] << " " << pay[i] << " " << dramas[i] << " " << date[i] << endl;
        // }
        // clear_screen();
    }
}

int func(int pay[], int position, int user_count)
{
    int largest = pay[position];
    int idx = position;
    for (int i = position; i < user_count; i++)
    {
        if (largest <= pay[i])
        {
            largest = pay[i];

            idx = i;
        }
    }
    return idx;
}

void store(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[], int user_count)
{
    fstream file;
    file.open("industry.txt", ios::out);
    for (int i = 0; i < user_count - 1; i++)
    {
        file << user_name[i] << "," << user_pass[i] << "," << role[i] << "," << cnic[i] << "," << contact[i] << "," << address[i] << "," << pay[i] << "," << dramas[i] << "," << date[i] << endl;
    }

    file << user_name[user_count - 1] << "," << user_pass[user_count - 1] << "," << role[user_count - 1] << "," << cnic[user_count - 1] << "," << contact[user_count - 1] << "," << address[user_count - 1] << "," << pay[user_count - 1] << "," << dramas[user_count - 1] << "," << date[user_count - 1];
    file.close();
}

int load(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[])
{
    fstream file;
    string record;
    int idx = 0;
    file.open("industry.txt", ios::in);
    while (!(file.eof()))
    {
        getline(file, record);

        user_name[idx] = parse(record, 1);
        user_pass[idx] = parse(record, 2);
        role[idx] = parse(record, 3);
        cnic[idx] = parse(record, 4);
        contact[idx] = parse(record, 5);
        address[idx] = parse(record, 6);
        pay[idx] = stoi(parse(record, 7));
        dramas[idx] = parse(record, 8);
        date[idx] = parse(record, 9);

        idx++;
    }
    return idx;
}
string parse(string record, int field)
{
    string term;
    int comma = 1;
    for (int i = 0; i < record.length(); i++)
    {
        if (record[i] == ',')
        {
            comma++;
        }
        else if (comma == field)
        {
            term = term + record[i];
        }
    }
    return term;
}

int drama_check(string drama[], string date[], int user_count, string serial[], string sdate[])
{
    int idx = 0;
    for (int i = 0; i < user_count; i++)
    {
        int count = 0;
        for (int x = 0; x < user_count; x++)
        {

            if (drama[i] == serial[x])
            {
                count++;
                if (count >= 1)
                {
                    break;
                }
            }
        }
        if (count <= 0)
        {
            serial[idx] = drama[i];
            sdate[idx] = date[i];
            idx++;
        }
    }
    return idx;
}

int show_drama(string serial[], string sdate[], int dcount, HANDLE h)
{
    header(h);
    gotoxy(50, 5);
    cout << "_______________ DRAMAS _______________" << endl
         << endl;
    gotoxy(30, 7);
    cout << "DRAMA ";
    gotoxy(50, 7);
    cout << "RELEASE DATE";
    int y = 9;
    int x = 1;

    for (int i = 0; i < dcount; i++)
    {
        gotoxy(20, y);
        cout << x;
        gotoxy(30, y);
        cout << serial[i];
        gotoxy(50, y);
        cout << sdate[i];
        y++;
        x++;
    }

    int point;
    y++;
    gotoxy(30, y);
    cout << "ENTER THE NUMBER OF DRAMA : ";
    gotoxy(60, y);
    cin >> point;

    return point;
}

void view_drama(string user_name[], string user_pass[], string role[], string cnic[], string contact[], string address[], int pay[], string dramas[], string date[], int user_count, HANDLE h, string serial[], string sdate[], int idx)
{
    for (int i = 0; i < user_count; i++)
    {
        header(h);
        gotoxy(50, 5);
        cout << "_______________ DRAMA DETAILS_______________" << endl
             << endl;
        gotoxy(30, 7);
        cout << "DRAMA :";
        gotoxy(30, 8);
        cout << "RELEASE DATE :";

        gotoxy(60, 7);
        cout << serial[idx];
        gotoxy(60, 8);
        cout << sdate[idx];
        int d = 0, p = 0, w = 0, a = 0;
        for (int x = 0; x < user_count; x++)
        {

            if (dramas[x] == serial[idx] && date[x] == sdate[idx])
            {

                gotoxy(35, 9);
                cout << "DIRECTOR";

                if (role[x] == "DIRECTOR")
                {
                    gotoxy(45, 9);
                    cout << user_name[x];
                    d++;
                }

                gotoxy(35, 10);
                cout << "WRITER";

                if (role[x] == "WRITER")
                {
                    gotoxy(45, 10);
                    cout << user_name[x];
                    w++;
                }

                gotoxy(35, 11);
                cout << "PRODUCER";

                if (role[x] == "PRODUCER")
                {
                    gotoxy(45, 11);
                    cout << user_name[x];
                    p++;
                }

                gotoxy(35, 12);
                cout << "ACTOR";

                if (role[x] == "ACTOR")
                {
                    gotoxy(45, 12);
                    cout << user_name[x];
                    a++;
                }
            }
        }
        if (d == 0)
        {
            gotoxy(45, 9);
            cout << "NEED DIRECTOR";
        }
        if (w == 0)
        {
            gotoxy(45, 10);
            cout << "NEED WRITER";
        }
        if (p == 0)
        {
            gotoxy(45, 11);
            cout << "NEED PRODUCER";
        }
        if (a == 0)
        {
            gotoxy(45, 12);
            cout << "NEED ACTORS";
        }
    }
    gotoxy(35, 14);
    clear_screen();
}
string user_page(HANDLE h, string rol, string user_name[], string role[], int pay[], int user_count, string u)
{
    header(h);
    string op = "0";
    gotoxy(50, 5);
    cout << "_______________ " << rol << " PAGE _______________" << endl
         << endl;
    gotoxy(0, 7);
    cout << "1.PROFILE ";
    gotoxy(0, 8);
    cout << "2.PAY";
    gotoxy(0, 9);
    cout << "3.MY DRAMAS";
    gotoxy(0, 10);
    cout << "4.EXIT";

    gotoxy(0, 11);
    cin >> op;
    return op;
}

void user_profile(HANDLE h, string rol, string user_name[], string user_pass[], string cnic[], string contact[], string address[], string dramas[], string date[], string role[], int pay[], int user_count, string u)
{
    header(h);
    gotoxy(40, 5);
    cout << "_______________ " << rol << " PROFILE _______________";
    gotoxy(0, 7);
    cout << "NAME ";
    gotoxy(20, 7);
    cout << "PASSWARD ";
    gotoxy(30, 7);
    cout << "ROLE ";
    gotoxy(40, 7);
    cout << "CNIC ";
    gotoxy(60, 7);
    cout << "CONTACT ";
    gotoxy(80, 7);
    cout << "ADDRESS ";
    gotoxy(100, 7);
    cout << "PAY ";
    gotoxy(110, 7);
    cout << "DRAMA ";
    gotoxy(120, 7);
    cout << "RELEASE DATE ";
    int y = 9;
    for (int x = 0; x < user_count; x++)
    {

        if (role[x] == rol)
        {
            gotoxy(0, y);
            cout << user_name[x];
            gotoxy(20, y);
            cout << user_pass[x];
            gotoxy(30, y);
            cout << role[x];
            gotoxy(40, y);
            cout << cnic[x];
            gotoxy(60, y);
            cout << contact[x];
            gotoxy(80, y);
            cout << address[x];
            gotoxy(100, y);
            cout << pay[x];
            gotoxy(110, y);
            cout << dramas[x];
            gotoxy(120, y);
            cout << date[x];
            y++;
        }
    }
    clear_screen();
}

void user_pay(HANDLE h, string rol, string user_name[], string role[], int pay[], int user_count, string u)
{
    header(h);
    gotoxy(40, 5);
    cout << "_______________ " << rol << " PAY _______________";
    gotoxy(0, 7);
    cout << "NAME ";
    gotoxy(20, 7);
    cout << "ROLE ";
    gotoxy(40, 7);
    cout << "PAY ";
    gotoxy(60, 7);

    for (int x = 0; x < user_count; x++)
    {
        if (rol == role[x])
        {

            gotoxy(0, 9);
            cout << user_name[x];
            gotoxy(20, 9);
            cout << role[x];
            gotoxy(40, 9);
            cout << pay[x];
            gotoxy(60, 9);
        }
    }
    clear_screen();
}

void user_role(HANDLE h, string rol, string user_name[], string role[], string dramas[], int pay[], int user_count, string u)
{
    header(h);
    gotoxy(40, 5);
    cout << "_______________ " << rol << " ROLE _______________";
    gotoxy(0, 7);
    cout << "NAME ";
    gotoxy(20, 7);
    cout << "ROLE ";
    gotoxy(40, 7);
    cout << "DRAMA ";
    gotoxy(60, 7);

    for (int x = 0; x < user_count; x++)
    {
        if (rol == role[x])
        {

            gotoxy(0, 9);
            cout << user_name[x];
            gotoxy(20, 9);
            cout << role[x];
            gotoxy(40, 9);
            cout << dramas[x];
            gotoxy(60, 9);
        }
    }
    clear_screen();
}