#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

//-------------------------------------------LINK LIST STRUCTURE

struct pro
{
    string user_name, user_pass, role, cnic, contact, address, dramas, date;
    int pay;
    pro *next;
};

pro *head = NULL;

//-------------------------------------------FIND LAST

pro *findLast()
{
    pro *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

//-------------------------------------------PARSE FUNTION

string parse(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount++;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}


void header(HANDLE h);
void gotoxy(int x, int y);
void clear_screen();
string parse(string record, int field);
void loadData();
void store();
void sort();
int drama_check(string serial[], string sdate[]);
string main_page(HANDLE h, string u);
string Admin(HANDLE h);
string director_1(HANDLE h, string rol);
void add_user(HANDLE h, string rol);
void remove_user(HANDLE h, string rol);
void update_user(HANDLE h, string rol);
void view_user(HANDLE h, string rol);
string user_page(HANDLE h, string rol, string u);
int show_drama(string serial[], string sdate[], int dcount, HANDLE h);
void view_drama(HANDLE h, string serial[], string sdate[], int idx);
void user_role(HANDLE h, string rol, string u);
void user_pay(HANDLE h, string rol, string u);
void user_profile(HANDLE h, string rol, string u);

main()
{

    loadData();
    

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string main;
    string serial[100], sdate[100];
    //sort();
    int dcount = drama_check(serial, sdate);
    string u;
    // while (main != "EXIT")
    // {
    //view_user(h, "ACTOR");
    
    main = main_page(h, u);

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
                        add_user(h, rol);
                    }
                    else if (op1 == "2")
                    {
                        remove_user(h, rol);
                    }
                    else if (op1 == "3")
                    {
                        update_user(h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort();
                        view_user(h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store();
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
                        add_user(h, rol);
                    }
                    else if (op1 == "2")
                    {
                        remove_user(h, rol);
                    }
                    else if (op1 == "3")
                    {
                        update_user(h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort();
                        view_user(h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
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
                        add_user(h, rol);
                    }
                    else if (op1 == "2")
                    {
                        remove_user(h, rol);
                    }
                    else if (op1 == "3")
                    {
                        update_user(h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort();
                        view_user(h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
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
                        add_user(h, rol);
                    }
                    else if (op1 == "2")
                    {
                        remove_user(h, rol);
                    }
                    else if (op1 == "3")
                    {
                        update_user(h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort();
                        view_user(h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
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
                        add_user(h, rol);
                    }
                    else if (op1 == "2")
                    {
                        remove_user(h, rol);
                    }
                    else if (op1 == "3")
                    {
                        update_user(h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort();
                        view_user(h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                }
            }
            else if (op == "6")
            {
                sort();
                int opt = show_drama(serial, sdate, dcount, h);
                pro *temp = head;

                for (int x = 0; x < dcount; x++)
                {
                    if (serial[opt - 1] == temp->dramas && sdate[opt - 1] == temp->date)
                    {
                        view_drama(h, serial, sdate, x);
                    }
                    temp = temp->next;
                }
            }
        }
    }

    if (main == "WRITER" || main == "PRODUCER" || main == "ACTOR" || main == "EMPLOYEE")
    {
        sort();
        string rol = main;
        string op2 = "1";

        while (op2 != "4")
        {
            op2 = user_page(h, rol, u);

            if (op2 == "1")
            {
                user_profile(h, rol, u);
            }
            else if (op2 == "2")
            {
                user_pay(h, rol, u);
            }
            else if (op2 == "3")
            {
                user_role(h, rol, u);
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
        sort();
        int opt = show_drama(serial, sdate, dcount, h);
        pro *temp = head;

        for (int x = 0; x < dcount; x++)
        {
            if (serial[opt - 1] == temp->dramas && sdate[opt - 1] == temp->date)
            {
                view_drama(h, serial, sdate, x);
            }
            temp = temp->next;
        }
    }
    //}
}





//_______________________________________________________FUNCTION______________________________________________________


//-------------------------------------------GOTOXY

void gotoxy(int x, int y)
{
    COORD coordinates; // coordinates is declared as COORD
    coordinates.X = x; // defining x-axis
    coordinates.Y = y; // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//-------------------------------------------HEADER

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

//-------------------------------------------CLEAR SCREEN

void clear_screen()
{
    cout << endl
         << " PRESS ANY KET TO CONTINUE ..... " << endl;
    getch();
    system("cls");
}

//-------------------------------------------LOAD

void loadData()
{
    fstream fileVariable;
    fileVariable.open("industry.txt", ios::in);
    string recorde;
    while (!(fileVariable.eof()))
    {
        getline(fileVariable, recorde);

        pro *record = new pro;

        record->user_name = parse(recorde, 1);
        record->user_pass = parse(recorde, 2);
        record->role = parse(recorde, 3);
        record->cnic = parse(recorde, 4);
        record->contact = parse(recorde, 5);
        record->address = parse(recorde, 6);
        record->pay = stoi(parse(recorde, 7));
        record->dramas = parse(recorde, 8);
        record->date = parse(recorde, 9);
        if (head == NULL)
        {
            head = record;
        }
        else
        {
            pro *temp = findLast();
            temp->next = record;
        }
        record->next = NULL;
    }
}
//-------------------------------------------STORE

void store()
{
    pro *temp;
    pro *record;
    fstream file;
    file.open("industry.txt", ios::out);
    while (temp->next->next != NULL)
    {
        file << record->user_name << "," << record->user_pass << "," << record->role << "," << record->cnic << "," << record->contact << "," << record->address << "," << record->pay << "," << record->dramas << "," << record->date << endl;
        temp = temp->next;
    }
    temp = temp->next;
    file << record->user_name << "," << record->user_pass << "," << record->role << "," << record->cnic << "," << record->contact << "," << record->address << "," << record->pay << "," << record->dramas << "," << record->date;
    file.close();
}
//-------------------------------------------SORTING

void sort()
{
    pro *current = head;
    pro *nextCurrent = current->next;
    while (current != NULL)
    {
        nextCurrent = current->next;
        while (nextCurrent != NULL)
        {
            if (current->pay > nextCurrent->pay)
            {
                string tempName = current->user_name;
                string tempPass = current->user_pass;
                int temppay = current->pay;
                string temprole = current->role;
                string tempcnic = current->cnic;
                string tempcontact = current->contact;
                string tempaddress = current->address;
                string tempdrama = current->dramas;
                string tempdate = current->date;

                current->user_name = nextCurrent->user_name;
                current->user_pass = nextCurrent->user_pass;
                current->pay = nextCurrent->pay;
                current->role = nextCurrent->role;
                current->cnic = nextCurrent->cnic;
                current->contact = nextCurrent->contact;
                current->address = nextCurrent->address;
                current->dramas = nextCurrent->dramas;
                current->date = nextCurrent->date;

                nextCurrent->user_name = tempName;
                nextCurrent->user_pass = tempPass;
                nextCurrent->pay = temppay;
                nextCurrent->role = temprole;
                nextCurrent->cnic = tempcnic;
                nextCurrent->contact = tempcontact;
                nextCurrent->address = tempaddress;
                nextCurrent->dramas = tempdrama;
                nextCurrent->date = tempdate;
            }
            nextCurrent = nextCurrent->next;
        }
        current = current->next;
    }
}

//-------------------------------------------DRAMA CHECK

int drama_check(string serial[], string sdate[])
{
    int count = 0;
    int idx = 0;
    pro *temp = head;
    while (temp->next != NULL)
    {
        for (int j = 0; j < 100; j++)
        {
            if (temp->dramas == serial[j])
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
            serial[idx] = temp->dramas;
            sdate[idx] = temp->date;
            idx++;
        }
        temp = temp->next;
    }
    return idx;
}
//-------------------------------------------MAIN PAGE

string main_page(HANDLE h, string u)
{
    string name;
    string user_pass;
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
        cout << "USER_PASSWARD";
        gotoxy(40, 12);
        // cout << "PRESS ESCAPE TO EXIT FROM THE PROGRAM";
        // if (GetAsyncKeyState(VK_ESCAPE))
        // {
        //     return "EXIT";
        // }
        gotoxy(50, 7);
        getline(cin, name);
        u = name;
        gotoxy(50, 9);
        getline(cin, user_pass);

        pro *temp = head;
        while (temp->next != NULL)
        {

            if (name == temp->user_name && user_pass == temp->user_pass)
            {

                flag = true;
                return temp->role;
            }
            temp = temp->next;
        }
        header(h);
        gotoxy(40, 5);
        cout << "ENTER THE VALID USERNAME OR user_passWARD" << endl;
        clear_screen();
    }
}

//-------------------------------------------ADMIN PAGE

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

//-------------------------------------------DIRECTOR PAGE

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

//-------------------------------------------ADD USER

void add_user(HANDLE h, string rol)
{
    pro *temp = findLast();

    header(h);
    gotoxy(50, 6);
    cout << "_______________ ADD " << rol << " _______________" << endl
         << endl;

    gotoxy(0, 7);
    cout << "USERNAME :";
    gotoxy(0, 8);
    cout << "user_passWARD :";
    gotoxy(0, 9);
    cout << "ROLE :";
    temp->role = rol;
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
    getline(cin, temp->user_name);
    gotoxy(30, 8);
    getline(cin, temp->user_pass);
    temp->role = rol;
    gotoxy(30, 9);
    cout << temp->role;
    gotoxy(30, 10);
    getline(cin, temp->cnic);
    gotoxy(30, 11);
    getline(cin, temp->contact);
    gotoxy(30, 12);
    getline(cin, temp->address);
    gotoxy(30, 13);
    cin >> temp->pay;
    cin.ignore();
    gotoxy(30, 14);
    getline(cin, temp->dramas);
    gotoxy(30, 15);
    getline(cin, temp->date);

    gotoxy(20, 18);
    cout << temp->role << " IS ADDED" << endl;

    clear_screen();
}
//-------------------------------------------REMOVE DIRECTOR

void remove_user(HANDLE h, string rol)
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
    pro *temp = head;
    while (temp->next != NULL)
    {

        if (nam == temp->user_name && temp->role == rol)
        {
            gotoxy(15, 10);
            cout << "PRESS Y TO DELETE THIS USER ";
            cin >> y;
            if (y == 'Y')
            {

                temp->user_name = temp->next->user_name;
                temp->user_pass = temp->next->user_pass;
                temp->role = temp->next->role;
                temp->cnic = temp->next->cnic;
                temp->contact = temp->next->contact;
                temp->address = temp->next->address;
                temp->pay = temp->next->pay;
                temp->dramas = temp->next->dramas;
                temp->date = temp->next->date;
            }
        }
        else
        {
            gotoxy(0, 10);
            cout << nam << " IS NOT A " << rol << endl;
            cout << "ENTER THE VALID USERNAME.......... ";
        }
        temp = temp->next;
    }
    if (y == 'Y')
    {
        gotoxy(0, 10);
        cout << nam << " IS REMOVED.......";
    }

    clear_screen();
}
//-------------------------------------------UPDATE USER

void update_user(HANDLE h, string rol)
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
    pro *temp = head;
    while (temp->next != NULL)
    {

        if (nam == temp->user_name && temp->role == rol)
        {

            header(h);
            gotoxy(40, 5);
            cout << "_______________ UPDATE " << rol << " _______________";

            gotoxy(0, 7);
            cout << "UPDATE USERNAME :";
            gotoxy(0, 8);
            cout << "UPDATE user_passWARD :";
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
            getline(cin, temp->user_name);
            gotoxy(30, 8);
            getline(cin, temp->user_pass);
            gotoxy(30, 9);
            getline(cin, temp->role);
            gotoxy(30, 10);
            getline(cin, temp->cnic);
            gotoxy(30, 11);
            getline(cin, temp->contact);
            gotoxy(30, 12);
            getline(cin, temp->address);
            gotoxy(30, 13);
            cin >> temp->pay;
            cin.ignore();
            gotoxy(30, 14);
            getline(cin, temp->dramas);
            gotoxy(30, 15);
            getline(cin, temp->date);
        }
        else
        {
            gotoxy(0, 10);
            cout << nam << " IS NOT A " << rol << endl;
            cout << "ENTER THE VALID USERNAME.......... ";
        }
        temp = temp->next;
    }
    if (y == 'Y')
    {
        gotoxy(0, 10);
        cout << nam << " IS UPDATED.......";
    }
    clear_screen();
}

//-------------------------------------------VIEW USERS

void view_user(HANDLE h, string rol)
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
    pro *temp = head;
    while (temp->next != NULL)
    {

        if (temp->role == rol)
        {

            gotoxy(0, y);
            cout << temp->user_name;
            gotoxy(30, y);
            cout << temp->role;
            gotoxy(40, y);
            cout << temp->cnic;
            gotoxy(60, y);
            cout << temp->contact;
            gotoxy(80, y);
            cout << temp->address;
            gotoxy(100, y);
            cout << temp->pay;
            gotoxy(110, y);
            cout << temp->dramas;
            gotoxy(120, y);
            cout << temp->date;
            y++;
        }
        temp = temp->next;
    }
    clear_screen();
}

//-------------------------------------------USER PAGE

string user_page(HANDLE h, string rol, string u)
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

//-------------------------------------------SHOW DRAMA

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

//-------------------------------------------VIEW DRAMA

void view_drama(HANDLE h, string serial[], string sdate[], int idx)
{
    pro *temp = head;

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
    while (temp->next != NULL)
    {

        if (temp->dramas == serial[idx] && temp->date == sdate[idx])
        {

            gotoxy(35, 9);
            cout << "DIRECTOR";

            if (temp->role == "DIRECTOR")
            {
                gotoxy(45, 9);
                cout << temp->user_name;
                d++;
            }

            gotoxy(35, 10);
            cout << "WRITER";

            if (temp->role == "WRITER")
            {
                gotoxy(45, 10);
                cout << temp->user_name;
                w++;
            }

            gotoxy(35, 11);
            cout << "PRODUCER";

            if (temp->role == "PRODUCER")
            {
                gotoxy(45, 11);
                cout << temp->user_name;
                p++;
            }

            gotoxy(35, 12);
            cout << "ACTOR";

            if (temp->role == "ACTOR")
            {
                gotoxy(45, 12);
                cout << temp->user_name;
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

    gotoxy(35, 14);
    clear_screen();
}

//-------------------------------------------USER PROFILE

void user_profile(HANDLE h, string rol, string u)
{
    header(h);
    gotoxy(40, 5);
    cout << "_______________ " << rol << " PROFILE _______________";
    gotoxy(0, 7);
    cout << "NAME ";
    gotoxy(20, 7);
    cout << "user_passWARD ";
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
    pro *temp = head;
    while (temp->next != NULL)
    {

        if (temp->role == rol)
        {
            gotoxy(0, y);
            cout << temp->user_name;
            gotoxy(20, y);
            cout << temp->user_pass;
            gotoxy(30, y);
            cout << temp->role;
            gotoxy(40, y);
            cout << temp->cnic;
            gotoxy(60, y);
            cout << temp->contact;
            gotoxy(80, y);
            cout << temp->address;
            gotoxy(100, y);
            cout << temp->pay;
            gotoxy(110, y);
            cout << temp->dramas;
            gotoxy(120, y);
            cout << temp->date;
            y++;
        }
        temp = temp->next;
    }
    clear_screen();
}

//-------------------------------------------USER PAY

void user_pay(HANDLE h, string rol, string u)
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

    pro *temp = head;
    while (temp->next != NULL)
    {

        if (rol == temp->role)
        {

            gotoxy(0, 9);
            cout << temp->user_name;
            gotoxy(20, 9);
            cout << temp->role;
            gotoxy(40, 9);
            cout << temp->pay;
            gotoxy(60, 9);
        }
        temp = temp->next;
    }
    clear_screen();
}

//-------------------------------------------USER ROLE

void user_role(HANDLE h, string rol, string u)
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

    pro *temp = head;
    while (temp->next != NULL)
    {
        if (rol == temp->role)
        {

            gotoxy(0, 9);
            cout << temp->user_name;
            gotoxy(20, 9);
            cout << temp->role;
            gotoxy(40, 9);
            cout << temp->dramas;
            gotoxy(60, 9);
        }
        temp = temp->next;
    }
    clear_screen();
}
