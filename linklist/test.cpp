#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

struct pro
{
    string user_name, user_pass, role, cnic, contact, address, dramas, date;
    int pay;
    pro *next;
};

pro *head = NULL;

pro *findLast()
{
    pro *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

// void addInList(string n, string p, int m)
// {
//     pro *record = new pro;
//     record->name = n;
//     record->user_pass = p;
//     record->marks = m;
//     record->next = NULL;

//     if (head == NULL)
//     {
//         head = record;
//     }
//     else
//     {
//         pro *temp = findLast();

//         temp->next = record;
//     }
// }

// void takeInput()
// {
//     string n;
//     string p;
//     int m;
//     cout << "Enter Name: ";
//     cin >> n;
//     cout << "Enter user_password: ";
//     cin >> p;
//     cout << "Enter Marks: ";
//     cin >> m;
//     addInList(n, p, m);
// }

// void printvalue(pro *record)
// {
//     cout << record->name << " " << record->user_pass << " " << record->marks << endl;
// }

void printAll()
{
    pro *temp = head;
    while (temp != NULL)
    {
        //printvalue(temp);
        temp = temp->next;
    }
}

bool search(string name)
{
    pro *temp = head;
    while (temp != NULL)
    {
        if (name == temp->user_name)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool deleteRecord(string name)
{
    pro *temp = head;
    pro *prev = head;
    while (temp != NULL)
    {
        if (temp->user_name == name)
        {
            // head = temp->next;
            prev->next = temp->next;
            delete temp;
            return 1;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}

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
    //             string user_name, user_pass, role, cnic, contact, address, dramas, date;
    // int pay;
                string tempName = current->user_name;
                string tempuser_pass = current->user_pass;
                int tempMarks = current->marks;

                current->name = nextCurrent->name;
                current->user_pass = nextCurrent->user_pass;
                current->marks = nextCurrent->marks;

                nextCurrent->name = tempName;
                nextCurrent->user_pass = tempuser_pass;
                nextCurrent->marks = tempMarks;
            }
            nextCurrent = nextCurrent->next;
        }
        current = current->next;
    }
}

string parseData(string record, int field)
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

void loadData()
{
    fstream fileVariable;
    fileVariable.open("data.txt", ios::in);
    string record;
    while (!(fileVariable.eof()))
    {
        getline(fileVariable, record);
        string name = parseData(record, 1);
        string user_password = parseData(record, 2);
        int marks = stoi(parseData(record, 3));
        addInList(name, user_password, marks);
    }
}

//-------------------------------------------STRUCTURE

//-------------------------------------------FUNCTION PROTOTYPE

void header(HANDLE h);

string main_page(HANDLE h, pro roli[], int user_count, string u);
bool login();
string Admin(HANDLE h);
string director_1(HANDLE h, string rol);
int add_user(pro roli[], int user_count, HANDLE h, string rol);
int remove_user(pro roli[], int user_count, HANDLE h, string rol);
int update_user(pro roli[], int user_count, HANDLE h, string rol);
int view_user(pro roli[], int user_count, HANDLE h, string rol);
void sort(pro roli[], int user_count, HANDLE h);
int func(pro roli[], int position, int user_count);
void store(pro roli[], int user_count);
string parse(string record, int field);
int drama_check(pro roli[], int user_count, string serial[], string sdate[]);
int show_drama(string serial[], string sdate[], int dcount, HANDLE h);
void view_drama(pro roli[], int user_count, HANDLE h, string serial[], string sdate[], int idx);
string user_page(HANDLE h, string rol, pro roli[], int user_count, string u);
void user_role(HANDLE h, string rol, pro roli[], int user_count, string u);
void user_profile(HANDLE h, string rol, pro roli[], int user_count, string u);
void user_pay(HANDLE h, string rol, pro roli[], int user_count, string u);

//---------------------------------------------------------------------------------------

void gotoxy(int x, int y);
void clear_screen();
int load(pro roli[100]);
string parse(string record, int field);

//-------------------------------------------MAIN

main()
{
    pro roli[100];
    int user_count = load(roli);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    string main;
    string serial[100], sdate[100];

    sort(roli, user_count, h);
    int dcount = drama_check(roli, user_count, serial, sdate);
    string u;
    // while (main != "EXIT")
    // {

    main = main_page(h, roli, user_count, u);

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
                        user_count = add_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(roli, user_count, h);
                        user_count = view_user(roli, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(roli, user_count);
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
                        user_count = add_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(roli, user_count, h);
                        user_count = view_user(roli, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(roli, user_count);
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
                        user_count = add_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(roli, user_count, h);
                        user_count = view_user(roli, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(roli, user_count);
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
                        user_count = add_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(roli, user_count, h);
                        user_count = view_user(roli, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(roli, user_count);
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
                        user_count = add_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "2")
                    {
                        user_count = remove_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "3")
                    {
                        user_count = update_user(roli, user_count, h, rol);
                    }
                    else if (op1 == "4")
                    {
                        sort(roli, user_count, h);
                        user_count = view_user(roli, user_count, h, rol);
                    }
                    else if (op1 != "5")
                    {
                        cout << "ENTER THE VALID OPTION" << endl;
                        clear_screen();
                    }
                    store(roli, user_count);
                }
            }
            else if (op == "6")
            {
                sort(roli, user_count, h);
                int opt = show_drama(serial, sdate, dcount, h);
                for (int x = 0; x < dcount; x++)
                {
                    if (serial[opt - 1] == roli[x].dramas && sdate[opt - 1] == roli[x].date)
                    {
                        view_drama(roli, user_count, h, serial, sdate, x);
                    }
                }
            }
        }
    }

    if (main == "WRITER" || main == "PRODUCER" || main == "ACTOR" || main == "EMPLOYEE")
    {
        sort(roli, user_count, h);
        string rol = main;
        string op2 = "1";

        while (op2 != "4")
        {
            op2 = user_page(h, rol, roli, user_count, u);

            if (op2 == "1")
            {
                user_profile(h, rol, roli, user_count, u);
            }
            else if (op2 == "2")
            {
                user_pay(h, rol, roli, user_count, u);
            }
            else if (op2 == "3")
            {
                user_role(h, rol, roli, user_count, u);
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
        sort(roli, user_count, h);
        int opt = show_drama(serial, sdate, dcount, h);
        for (int x = 0; x < dcount; x++)
        {
            if (serial[opt - 1] == roli[x].dramas && sdate[opt - 1] == roli[x].date)
            {
                view_drama(roli, user_count, h, serial, sdate, x);
            }
        }
    }
    //}
}

//-------------------------------------------LOAD

int load(pro roli[100])
{
    fstream file;
    string record;
    int idx = 0;
    file.open("industry.txt", ios::in);
    while (!(file.eof()))
    {
        getline(file, record);

        roli[idx].user_name = parse(record, 1);
        roli[idx].user_pass = parse(record, 2);
        roli[idx].role = parse(record, 3);
        roli[idx].cnic = parse(record, 4);
        roli[idx].contact = parse(record, 5);
        roli[idx].address = parse(record, 6);
        roli[idx].pay = stoi(parse(record, 7));
        roli[idx].dramas = parse(record, 8);
        roli[idx].date = parse(record, 9);

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

//-------------------------------------------GOTOXY

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

//__________________________MAIN PAGE

string main_page(HANDLE h, pro roli[], int user_count, string u)
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
        cout << "user_passWARD";
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

        for (int x = 0; x < user_count; x++)
        {

            if (name == roli[x].user_name && user_pass == roli[x].user_pass)
            {

                flag = true;
                return roli[x].role;
            }
        }
        header(h);
        gotoxy(40, 5);
        cout << "ENTER THE VALID USERNAME OR user_passWARD" << endl;
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

//-------------------------------------------ADMIN

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

int add_user(pro roli[], int user_count, HANDLE h, string rol)
{
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
    roli[user_count].role = rol;
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
    getline(cin, roli[user_count].user_name);
    gotoxy(30, 8);
    getline(cin, roli[user_count].user_pass);
    roli[user_count].role = rol;
    gotoxy(30, 9);
    cout << roli[user_count].role;
    gotoxy(30, 10);
    getline(cin, roli[user_count].cnic);
    gotoxy(30, 11);
    getline(cin, roli[user_count].contact);
    gotoxy(30, 12);
    getline(cin, roli[user_count].address);
    gotoxy(30, 13);
    cin >> roli[user_count].pay;
    cin.ignore();
    gotoxy(30, 14);
    getline(cin, roli[user_count].dramas);
    gotoxy(30, 15);
    getline(cin, roli[user_count].date);

    gotoxy(20, 18);
    cout << roli[user_count].role << " IS ADDED" << endl;
    user_count++;

    clear_screen();
    return user_count;
}

//-------------------------------------------REMOVE DIRECTOR

int remove_user(pro roli[], int user_count, HANDLE h, string rol)
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
    for (int x = 0; x < user_count; x++)
    {

        if (nam == roli[x].user_name && roli[x].role == rol)
        {
            gotoxy(15, 10);
            cout << "PRESS Y TO DELETE THIS USER ";
            cin >> y;
            if (y == 'Y')
            {
                for (int i = x; i < user_count; i++)
                {
                    roli[i].user_name = roli[i + 1].user_name;
                    roli[i].user_pass = roli[i + 1].user_pass;
                    roli[i].role = roli[i + 1].role;
                    roli[i].cnic = roli[i + 1].cnic;
                    roli[i].contact = roli[i + 1].contact;
                    roli[i].address = roli[i + 1].address;
                    roli[i].pay = roli[i + 1].pay;
                    roli[i].dramas = roli[i + 1].dramas;
                    roli[i].date = roli[i + 1].date;
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
    if (y == 'Y')
    {
        gotoxy(0, 10);
        cout << nam << " IS REMOVED.......";
    }

    clear_screen();
    return user_count;
}

//-------------------------------------------UPDATE USER

int update_user(pro roli[], int user_count, HANDLE h, string rol)
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

        if (nam == roli[x].user_name && roli[x].role == rol)
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
            getline(cin, roli[x].user_name);
            gotoxy(30, 8);
            getline(cin, roli[x].user_pass);
            gotoxy(30, 9);
            getline(cin, roli[x].role);
            gotoxy(30, 10);
            getline(cin, roli[x].cnic);
            gotoxy(30, 11);
            getline(cin, roli[x].contact);
            gotoxy(30, 12);
            getline(cin, roli[x].address);
            gotoxy(30, 13);
            cin >> roli[x].pay;
            cin.ignore();
            gotoxy(30, 14);
            getline(cin, roli[x].dramas);
            gotoxy(30, 15);
            getline(cin, roli[x].date);
        }
        else
        {
            gotoxy(0, 10);
            cout << nam << " IS NOT A " << rol << endl;
            cout << "ENTER THE VALID USERNAME.......... ";
        }
    }
    if (y == 'Y')
    {
        gotoxy(0, 10);
        cout << nam << " IS UPDATED.......";
    }
    clear_screen();
    return user_count;
}

//-------------------------------------------VIEW USERS

int view_user(pro roli[], int user_count, HANDLE h, string rol)
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
        if (roli[x].role == rol)
        {

            gotoxy(0, y);
            cout << roli[x].user_name;
            gotoxy(30, y);
            cout << roli[x].role;
            gotoxy(40, y);
            cout << roli[x].cnic;
            gotoxy(60, y);
            cout << roli[x].contact;
            gotoxy(80, y);
            cout << roli[x].address;
            gotoxy(100, y);
            cout << roli[x].pay;
            gotoxy(110, y);
            cout << roli[x].dramas;
            gotoxy(120, y);
            cout << roli[x].date;
            y++;
        }
    }
    clear_screen();
    return user_count;
}
//-------------------------------------------WRITER

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

//-------------------------------------------SORTING

void sort(pro roli[], int user_count, HANDLE h)
{
    int position = 0;
    int largest = roli[position].pay;

    for (int i = 0; i < user_count; i++)
    {
        position = i;
        int large = func(roli, position, user_count);

        int temp = roli[i].pay;
        roli[i].pay = roli[large].pay;
        roli[large].pay = temp;

        string temp_1;
        temp_1 = roli[i].user_name;
        roli[i].user_name = roli[large].user_name;
        roli[i].user_name = temp_1;

        temp_1 = roli[i].role;
        roli[i].role = roli[large].role;
        roli[i].role = temp_1;

        temp_1 = roli[i].cnic;
        roli[i].cnic = roli[i].cnic;
        roli[large].cnic = temp_1;

        temp_1 = roli[i].contact;
        roli[i].contact = roli[large].contact;
        roli[large].contact = temp_1;

        temp_1 = roli[i].address;
        roli[i].address = roli[large].address;
        roli[large].address = temp_1;

        temp_1 = roli[i].dramas;
        roli[i].dramas = roli[large].dramas;
        roli[large].dramas = temp_1;

        temp_1 = roli[i].date;
        roli[i].date = roli[large].date;
        roli[large].date = temp_1;
        // for (int i = 0; i < user_count; i++)
        // {
        //     cout << user_name[i] << " " << user_user_pass[i] << " " << role[i] << " " << cnic[i] << " " << contact[i] << " " << address[i] << " " << pay[i] << " " << dramas[i] << " " << date[i] << endl;
        // }
        // clear_screen();
    }
}

//-------------------------------------------FUNCTIOIN

int func(pro roli[], int position, int user_count)
{
    int largest = roli[position].pay;
    int idx = position;
    for (int i = position; i < user_count; i++)
    {
        if (largest <= roli[i].pay)
        {
            largest = roli[i].pay;

            idx = i;
        }
    }
    return idx;
}

//-------------------------------------------STORE

void store(pro roli[], int user_count)
{
    fstream file;
    file.open("industry.txt", ios::out);
    for (int i = 0; i < user_count - 1; i++)
    {
        file << roli[i].user_name << "," << roli[i].user_pass << "," << roli[i].role << "," << roli[i].cnic << "," << roli[i].contact << "," << roli[i].address << "," << roli[i].pay << "," << roli[i].dramas << "," << roli[i].date << endl;
    }
    file << roli[user_count - 1].user_name << "," << roli[user_count - 1].user_pass << "," << roli[user_count - 1].role << "," << roli[user_count - 1].cnic << "," << roli[user_count - 1].contact << "," << roli[user_count - 1].address << "," << roli[user_count - 1].pay << "," << roli[user_count - 1].dramas << "," << roli[user_count - 1].date;
    file.close();
}

//-------------------------------------------DRAMA CHECK

int drama_check(pro roli[], int user_count, string serial[], string sdate[])
{
    int idx = 0;
    for (int i = 0; i < user_count; i++)
    {
        int count = 0;
        for (int x = 0; x < user_count; x++)
        {

            if (roli[i].dramas == serial[x])
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
            serial[idx] = roli[i].dramas;
            sdate[idx] = roli[i].date;
            idx++;
        }
    }
    return idx;
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

void view_drama(pro roli[], int user_count, HANDLE h, string serial[], string sdate[], int idx)
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

            if (roli[x].dramas == serial[idx] && roli[x].date == sdate[idx])
            {

                gotoxy(35, 9);
                cout << "DIRECTOR";

                if (roli[x].role == "DIRECTOR")
                {
                    gotoxy(45, 9);
                    cout << roli[x].user_name;
                    d++;
                }

                gotoxy(35, 10);
                cout << "WRITER";

                if (roli[x].role == "WRITER")
                {
                    gotoxy(45, 10);
                    cout << roli[x].user_name;
                    w++;
                }

                gotoxy(35, 11);
                cout << "PRODUCER";

                if (roli[x].role == "PRODUCER")
                {
                    gotoxy(45, 11);
                    cout << roli[x].user_name;
                    p++;
                }

                gotoxy(35, 12);
                cout << "ACTOR";

                if (roli[x].role == "ACTOR")
                {
                    gotoxy(45, 12);
                    cout << roli[x].user_name;
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

//-------------------------------------------USER PAGE

string user_page(HANDLE h, string rol, pro roli[], int user_count, string u)
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

//-------------------------------------------USER PROFILE

void user_profile(HANDLE h, string rol, pro roli[], int user_count, string u)
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
    for (int x = 0; x < user_count; x++)
    {

        if (roli[x].role == rol)
        {
            gotoxy(0, y);
            cout << roli[x].user_name;
            gotoxy(20, y);
            cout << roli[x].user_pass;
            gotoxy(30, y);
            cout << roli[x].role;
            gotoxy(40, y);
            cout << roli[x].cnic;
            gotoxy(60, y);
            cout << roli[x].contact;
            gotoxy(80, y);
            cout << roli[x].address;
            gotoxy(100, y);
            cout << roli[x].pay;
            gotoxy(110, y);
            cout << roli[x].dramas;
            gotoxy(120, y);
            cout << roli[x].date;
            y++;
        }
    }
    clear_screen();
}

//-------------------------------------------USER PAY

void user_pay(HANDLE h, string rol, pro roli[], int user_count, string u)
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
        if (rol == roli[x].role)
        {

            gotoxy(0, 9);
            cout << roli[x].user_name;
            gotoxy(20, 9);
            cout << roli[x].role;
            gotoxy(40, 9);
            cout << roli[x].pay;
            gotoxy(60, 9);
        }
    }
    clear_screen();
}

//-------------------------------------------USER ROLE

void user_role(HANDLE h, string rol, pro roli[], int user_count, string u)
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
        if (rol == roli[x].role)
        {

            gotoxy(0, 9);
            cout << roli[x].user_name;
            gotoxy(20, 9);
            cout << roli[x].role;
            gotoxy(40, 9);
            cout << roli[x].dramas;
            gotoxy(60, 9);
        }
    }
    clear_screen();
}