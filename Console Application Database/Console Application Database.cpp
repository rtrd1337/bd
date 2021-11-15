#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <iomanip>
#include <windows.h>
#include <math.h>

using namespace std;

ifstream inputstream1;
ofstream outputstream1;
int e, i, f, o, p = 0, except, counting, y = 0, d, h;
int takeinput(int);
long double j, k, l;
const char defaultusername[20] = "prepod", defaultpassword[20] = "avtomat";
char studentname[100][30], studentclass[100][30], studentrollno[100][30], studentphone[100][30], tempstudentname[30], tempstudentclass[30], tempstudentrollno[30], tempstudentphone[30];
char flag[5];
char tempbkname[30], tempstname[30];
char tempbkgenre[30], tempstclass[30];
char tempbkid[30], tempstrno[30];
char tempbkprice[30], tempstph[30];
char username[20], password[20], username2[20], password2[20];
char search[30];
char useless;
void changesecureke();
void librarymanagement();
void schoolmanagement();
void viewall_library();
void search_library();
void manage_library();
void viewall_school();
void search_school();
void manage_school();
void appmanager();
void appplybackground();
void error(int);
void security();
void welcome();
void area();
void perimeter();
void volume();
void start();
void shutdown(int);
void boot();
void newtask();
void settings();
void assistant();
void applauncher();
void calculator();
void math_table();
void unit_calculator();
void geometric_calculator();
void helper();
void projetinfo();
void processor(int);
void applydialoguebox(int, char[10][30]);
void applydialoguebox(int, char[50]);
void timer(int);
void onlyenter();
char string1[10][30] = { "Start","Shutdown Prepod" };
char string2[10][30] = { "New Task","Set up your system","Shutdown" };
char string3[10][30] = { "Shutdown","Reboot","Cancel" };
char string4[10][30] = { "App Launcher","Prepod assistant","Shutdown Prepod" };
char string5[10][30] = { "Change securekey","Shutdown Prepod" };
char string6[10][30] = { "Built-in apps","About Prepod","Shutdown Prepod" };
char string7[10][30] = { "General Calculator","Mathematic Tables","Unit Calculator","Geometry Calculation ","Shutdown Prepod" };
char string8[50] = { "Input user name" };
char string9[50] = { "Input password" };
char string10[10][30] = { "Calculate","Close" };
char string11[10][30] = { "Length Conversion","Temperature Conversion","Mass conversion","Time conversion","Currency conversion" };
char string12[10][30] = { "Library Management","School Management","Shutdown Prepod" };
char string13[10][30] = { "View all records","Search records","Manage Database","Exit" };
char string14[10][30] = { "Search by book ID","Search by book name","Search by book price","Search by book genre" };
char string15[10][30] = { "Add a record","Delete a record" };
char string16[10][30] = { "By roll no","By student name","By student phone  no","By student class" };
char string17[10][30] = { "Area ","Volume","Perimeter" };
char string18[10][30] = { "Triangle ","Square","Rectangle" };
char string19[10][30] = { "Cube ","Cuboid","Cylinder","Cone" };
char string20[10][30] = { "Triangle ","Square","Rectangle" };

//Classes
// Library
class library
{
public:
	char bookname[30];
	char bookgenre[30];
	char bkid[30];
	char bookprice[30];
}book[50];
// School
class school
{
public:
	char stname[30];
	char stclass[30];
	char strno[30];
	char stph[30];
}student[50];
// Shared functions
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;

	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}


// Display lock Function
void showlock(int a)
{
	if (a == 0)
	{
		i = 5;
	}
	else if (a == 1)
	{
		i = 4;
	}
	gotoxy(42, i);
	cout << "	   ###############";
	i = i + 1;
	gotoxy(42, i);
	cout << "	   ##           ##";
	if (a == 0)
	{
		i = i + 1;
		gotoxy(42, i);
		cout << "	   ##           ##";
		i = i + 1;
		gotoxy(42, i);
		cout << "	   ##           ##";
		i = i + 1;
		gotoxy(42, i);
		cout << "	   ##           ##";
	}
	else if (a == 1)
	{
		i = i + 1;
		gotoxy(42, i);
		cout << "	                ##";
		i = i + 1;
		gotoxy(42, i);
		cout << "	                ##";
		i = i + 1;
		gotoxy(42, i);
		cout << "	                ##";
		i = i + 1;
		gotoxy(42, i);
		cout << "	                ##";
	}
	i = i + 1;
	gotoxy(42, i);
	cout << "	   ##           ##";
	i = i + 1;
	gotoxy(48, i);
	cout << "######################";
	i = i + 1;
	gotoxy(48, i);
	cout << "##########  ##########";
	i = i + 1;
	gotoxy(48, i);
	cout << "#########    #########";
	i = i + 1;
	gotoxy(48, i);
	cout << "##########  ##########";
	i = i + 1;
	gotoxy(48, i);
	cout << "##########  ##########";
	i = i + 1;
	gotoxy(48, i);
	cout << "##########  ##########";
	i = i + 1;
	gotoxy(48, i);
	cout << "##########  ##########";
	i = i + 1;
	gotoxy(48, i);
	cout << "######################";
	gotoxy(20, 8);
}
// Apply BackGround Function
void applybackground()
{
	for (i = 1; i < 80; i++)
	{
		gotoxy(i, 1);
		cout << "X";
		gotoxy(i, 2);
		cout << "X";
		gotoxy(i, 24);
		cout << "X";
		gotoxy(i, 25);
		cout << "X";
	}
	for (i = 3; i <= 23; i++)
	{
		gotoxy(1, i);
		cout << "XXX";
		gotoxy(77, i);
		cout << "XXX";
	}
	i = 15;
	gotoxy(60, i);
	cout << "0000000000000000X";
	i = i + 1;
	gotoxy(60, i);
	cout << "oooooooooooooooXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "00000000000000XXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "ooooooooooooXXXXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "0000000000XXXXXXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "ooooooooXXXXXXXXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "000000XXXXXXXXXXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "ooooXXXXXXXXXXXXX";
	i = i + 1;
	gotoxy(60, i);
	cout << "00XXXXXXXXXXXXXXX";
}
// Apply Dialogue Box Function
void applydialoguebox(char string[50])
{
	int a = strlen(string);
	gotoxy(6, 4);
	cout << " OOOOOXXXXXXXXXXXXXXXXXXXXXXXXXOOOOO";
	gotoxy(6, 5);
	cout << " OO     " << string << setw((28 - a)) << "OO";
	gotoxy(6, 6);
	cout << " OOOOOXXXXXXXXXXXXXXXXXXXXXXXXXOOOOO";
}
// Apply Dialogue Box Function
void applydialoguebox(int l, char stringf[10][30])
{
	int b;
	char c[50];
	for (i = 0; i < l; i++)
	{
		c[i] = strlen(stringf[i]);
	}
	f = 0;
	gotoxy(12, 6);
	cout << "OOOOOXXXXXXXXXXXXX-(';')-XXXXXXXXXXXXXOOOOO";
	gotoxy(12, 7);
	cout << "OO                                       OO";
	gotoxy(12, 8);
	for (i = 0; i < l; i++)
	{
		b = 36 - c[i];
		gotoxy(12, (8 + f));
		cout << "OO  " << (i + 1) << ". " << stringf[i] << setw(b) << "OO";
		f = f + 2;
	}
	f = 0;
	for (i = 0; i < l; i++)
	{
		gotoxy(12, (9 + f));
		cout << "OO                                       OO";
		f = f + 2;
	}
	gotoxy(12, 8 + f);
	cout << "OOOOOXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXOOOOO";

}
// Timer Function
void timer(int a)
{
	unsigned long i;
	unsigned long int c;
	c = a * 10000000;
	for (i = 0; i <= c; i++)
	{
	}
}
// Only Enter
void onlyenter()
{
	for (i = 0; i < 2; i++)
	{
		useless = _getch();
		if (useless == 13)
		{
			break;
		}
		else
		{
			i = 0;
		}
	}
}
// Take Input Function
int takeinput(int limit)
{
	f = 8;
	//gotoxy(50, 10);
	//cout << "\b\b\b\b\b\b\b\b\b\b";
	//gotoxy(40, 8);
	//cout << "->>(';')~*";
	gotoxy(45, 8);
	for (i = 0; i < 2; i++)
	{
		useless = _getch();
		if (useless == 119)
		{
			f = f - 2;
			if (f >= 8)
			{
				//gotoxy(50, (f + 2)); cout << "\b\b\b\b\b\b\b\b\b\b";
				//gotoxy(40, f);
				//cout << "->>(';')~*";
				gotoxy(45, f);
				i = 0;
			}
			else
			{
				f = (limit + 8);
				//gotoxy(50, 8); cout << "\b\b\b\b\b\b\b\b\b\b";
				//gotoxy(40, f);
				//cout << "->>(';')~*";
				gotoxy(45, f);

			}
		}
		else if (useless == 115)
		{
			f = f + 2;
			if (f <= (limit + 8))
			{
				//gotoxy(50, (f - 2));
				//cout << "\b\b\b\b\b\b\b\b\b\b";
				//gotoxy(40, f);
				//cout << "->>(';')~*";
				gotoxy(45, f);
				i = 0;
			}
			else
			{
				f = 8;
				//gotoxy(50, (f + limit));
				//cout << "\b\b\b\b\b\b\b\b\b\b";

				//gotoxy(40, f);
				//cout << "->>(';')~*";
				gotoxy(45, f);
			}
		}
		else if (useless == 13)
		{
			break;
		}
		else if (useless == 27)
		{
			break;
		}
		i = 0;
	}

	return(f);
}
// Processor Function
void processor(int p)
{
	switch (p)
	{
	case 2:
	{cout << "\n\t\tProcessing"; }
	break;
	case 3:  gotoxy(20, 10);
	{cout << "Loading"; }
	break;
	}
	cout << ".";
	cout << ".";
	cout << ".";
	cout << ".";
	cout << ".";
	cout << ".";
	cout << ".";
	cout << ".";
	cout << ".";
	gotoxy(36, 10);
	cout << "\\";
	gotoxy(36, 10);
	timer(2);
	cout << "/";
	gotoxy(36, 10);
	timer(2);
	cout << "\\";
	gotoxy(36, 10);
	timer(2);
	cout << "/";
	gotoxy(36, 10);
	timer(2);
	cout << "\\";
	gotoxy(36, 10);
	timer(2);
	cout << "/";
	gotoxy(36, 10);
	timer(2);
	cout << "\\";
	gotoxy(36, 10);
	timer(2);
	cout << "/";
	gotoxy(36, 10);
	timer(2);
	cout << "\\";
	gotoxy(36, 10);
	timer(2);
	cout << "/-";
	timer(2);
}
//Starter functions
// Shutdown  Fuction
void shutdown(int a)
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(2, string3);
	f = takeinput(2);
	if (useless == 27)
	{
		if (a == 1)
		{
			welcome();
		}
		else if (a == 2)
		{
			start();
		}
		else if (a == 3)
		{
			newtask();
		}
		else if (a == 4)
		{
			settings();
		}
		else if (a == 5)
		{
			assistant();
		}
		else if (a == 6)
		{
			helper();
		}
		else if (a == 7)
		{
			applauncher();
		}
	}
	gotoxy(7, 16);
	cout << "Press Enter key to confirm and proceed";
	gotoxy(7, 17);
	cout << "or Esc to cancel the action";
	gotoxy(46, 17);
	for (i = 0; i < 2; i++)
	{
		useless = _getch();
		if (useless == 13)
		{
			break;
		}
		else if (useless == 27)
		{
			break;
		}
		else
		{
			i = 0;
		}
	}
	switch (useless)
	{
	case 27:
		shutdown(a);
		break;
	default:
	{switch (f)
	{
	case 8:
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t";

		cout << "\n\n\n\t\t                 Shutting down...";
		gotoxy(48, 25);
		cout << "You can now safely close Prepod ";
		exit(0);
		break;
	case 10:boot();
	}}
	break;
	}
}
// Boot Function
void boot()
{
	system("cls");
	e = 1;
	timer(1);
	cout << "\n\n   XXXXOOOOOOOOO";
	timer(1);
	cout << "\n   XXXXOOOOOOOOO";
	timer(1);
	cout << "\n   XXXX      OOO";
	timer(1);
	cout << "\n   XXXX      OOO";
	timer(1);
	cout << "\n   XXXXOOOOOOOOO";
	timer(1);
	cout << "\n   XXXXOOOOOOOOO";
	timer(1);
	cout << "\n   XXXX           ";
	timer(1);
	cout << "\n   XXXX   R E P O D";
	timer(1);
	cout << "\n   XXXX        ";
	timer(1);
	cout << "\n   XXXX        ";
	timer(1);
	cout << "\n\n\n\t\C++ Database with console interface";
	timer(1);
	cout << "\n\nLaunch Succesfull\n\nPress Enter key to proceed\t";
	onlyenter();
	security();
}
// Start Function
void start()
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(3, string2);
	f = takeinput(4);
	if (useless == 27)
	{
		welcome();
	}
	switch (f)
	{
	case 8:newtask();
		break;
	case 10:settings();
		break;
	case 12:shutdown(2);
		break;
	}
}
// Security Function
void security()
{
	inputstream1.open("secureke.dat");
	inputstream1.seekg(0);
	if (inputstream1.eof() || (!inputstream1))
	{
		for (i = 0; i < 20; i++)
		{
			username[i] = defaultusername[i];
			password[i] = defaultpassword[i];
		}
	}
	else
	{
		inputstream1.getline(username, 20);
		inputstream1.getline(password, 20);
		inputstream1.seekg(0);
	}
	inputstream1.close();
recheck:
	system("cls");
	applydialoguebox(string8);
	showlock(0);
	gotoxy(17, 8);
	cin >> username2;
	processor(2);
	for (int d = 0; d < 8; d++)
	{
		if (username2[d] == username[d] && strlen(username2) == strlen(username))
		{
			o = 0;
		}
		else
		{
			o = 1;
			goto last;

		}
	}
	system("cls");
	applydialoguebox(string9);
	showlock(0);
	gotoxy(17, 8);
	for (d = 0; d < 20; d++)
	{
		password2[d] = _getch();
		cout << "*";
		if (password2[d] == 8)
		{
			cout << "\b\b";
			if (d == 0)
			{
				gotoxy(18, 8);
			}
			if (d != 0)
			{
				d = d - 2;
			}
		}
		else if (password2[d] == 13)
		{
			cout << "\b";
			password2[d] = '\0';
			break;
		}
	}
	gotoxy(17, 9);
	processor(2);
	for (d = 0; d < 20; d++)
	{
		if (password2[d] == password[d] && strlen(password2) == strlen(password))
		{
			o = 0;
		}
		else
		{
			o = 1;
			goto last;

		}
	}
last:
	if (o == 1)
	{
		cout << "\n\n\t\aAccess Denied";
		timer(3);
		if (e < 3 && e >= 0)
		{
			e = e + 1;
			goto recheck;
		}
		else
		{
			cout << "\n\n\a\a\a\aSystem Halted";
			timer(4); exit(0);
		}
	}
	else
	{
		showlock(1);
		gotoxy(10, 20);
		cout << "Access Granted";
		gotoxy(10, 24);
		cout << "Press Enter key to continue";
		gotoxy(44, 24);
		onlyenter();
		welcome();
	}
}
//Welcome Fuction
void welcome()
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(2, string1);
	f = takeinput(2);
again:
	if (useless == 27)
	{
		f = takeinput(2);
		goto again;
	}
	switch (f)
	{
	case 8:start();
		break;
	case 10:shutdown(1);
		break;
	}
}
// Functions

// Library management
void librarymanagement()
{
	system("cls"); gotoxy(15, 6);
	cout << "\n   xxxx";
	cout << "\n   xxxx";
	cout << "\n   xxxx ";
	cout << "\n   xxxx ";
	cout << "\n   xxxx                 >>( ' Prepod ' )<<";
	cout << "\n   xxxx";
	cout << "\n   xxxx";
	cout << "\n   xxxx";
	cout << "\n   xxxx";
	cout << "\n   xxxxxxxxxxxxxxxxxxxx";
	cout << "\n   xxxxxxxxxxxxxxxxxxxx    I B R A R Y     M A N A G E M E N T";
	inputstream1.open("libdata.dat");
	inputstream1.seekg(0);
	inputstream1.getline(flag, 5);
	if (inputstream1.eof() || (!inputstream1) || flag[0] == '0')
	{
		o = 1; counting = 0;
	}
	else
	{
		o = 0; i = 0, counting = 0;
		while (!inputstream1.eof())
		{
			counting++;
			inputstream1.getline(book[i].bkid, 30);
			inputstream1.getline(book[i].bookname, 30);
			inputstream1.getline(book[i].bookprice, 30);
			inputstream1.getline(book[i].bookgenre, 30);
			i++;
		}
	}
	inputstream1.close();
	cout << " \n\n   Press Enter key to proceed:  ";
	onlyenter();
recheck:
	system("cls");
	applybackground();
	applydialoguebox(4, string13);
	f = takeinput(6);
	for (i = 0; i < 2; i++)
	{
		if (useless == 27)
		{
			goto recheck;
		}
		else { break; }
	}
	switch (f)
	{
	case 8: viewall_library();
		break;
	case 10: search_library();
		break;
	case 12:manage_library();
		break;
	case 14:
		for (i = 0; i < 2500; i++)
		{
			cout << "\"(';')\"";
		}system("cls"); gotoxy(15, 6);
		applauncher();
		break;
	}

}
// view full library
void viewall_library()
{
	system("cls");
	applybackground();
	if (o == 1)
	{
		gotoxy(12, 8);
		cout << "Cannot access the database."; gotoxy(12, 9); cout << "The database is empty or has been corrupted or deleted."; gotoxy(12, 10); cout << "Press Enter key to rerun the application and scan again   "; onlyenter();
		librarymanagement();
	}
	else
	{
		system("cls");
		cout << "------------------------------------------------------------ ";
		for (i = 0; i < counting; i++)
		{
			cout << "\n------------------------------------------------------------ ";
			cout << "\nItem  ID    :     " << book[i].bkid;
			cout << "\nTitle       :     " << book[i].bookname;
			cout << "\nGenre       :     " << book[i].bookprice;
			cout << "\nPrice       :     " << book[i].bookgenre;
			cout << "\n------------------------------------------------------------ ";
		}
		cout << "\n\nPress Enter key to go back:    "; onlyenter(); librarymanagement();
	}
}
// search library
void search_library()
{
	system("cls");
	applybackground();
	if (o == 1)
	{
		gotoxy(12, 8);
		cout << "Cannot access the database."; gotoxy(12, 9); cout << "The database is empty or has been corrupted or deleted."; gotoxy(12, 10); cout << "Press Enter key to rerun the application and scan again   "; onlyenter();
		librarymanagement();
	}
	else
	{
		applydialoguebox(4, string14);
		f = takeinput(6);
		if (useless == 27)
		{
			librarymanagement();
		}
		switch (f)
		{
		case  8: system("cls");
			cout << "\nEnter ID of the book to be searched :  ";
			cin >> search;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == book[i].bkid[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) { break; }
			}
			if (e == 1)
			{
				cout << "------------------------------------------------------------ ";
				cout << "\nItem  ID :    " << book[i].bkid;
				cout << "\nTitle :    " << book[i].bookname;
				cout << "\nGenre :    " << book[i].bookprice;
				cout << "\nPrice :     " << book[i].bookgenre;
			}
			if (e == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); librarymanagement();
			break;
		case 10: system("cls");
			cout << "\nEnter name of the book to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == book[i].bookname[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "Item  ID :    " << book[i].bkid;
					cout << "\nTitle :    " << book[i].bookname;
					cout << "\nGenre :    " << book[i].bookprice;
					cout << "\nPrice :     " << book[i].bookgenre;
				}
			}
			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); librarymanagement();
			break;
		case 12: system("cls");
			cout << "\nEnter price of the book to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == book[i].bookprice[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "Item  ID :    " << book[i].bkid;
					cout << "\nTitle :    " << book[i].bookname;
					cout << "\nGenre :    " << book[i].bookprice;
					cout << "\nPrice :     " << book[i].bookgenre;
				}
			}
			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); librarymanagement();
			break;
		case 14: system("cls");
			cout << "\nEnter genre of the book to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == book[i].bookgenre[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "Item  ID :    " << book[i].bkid;
					cout << "\nTitle :    " << book[i].bookname;
					cout << "\nGenre :    " << book[i].bookprice;
					cout << "\nPrice :     " << book[i].bookgenre;

				}
			}

			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); librarymanagement();
			break;
		}
	}
}
// Manage Library
void manage_library()
{
	system("cls");
	applybackground();
	applydialoguebox(2, string15);
	f = takeinput(2);
	if (useless == 27)
	{
		librarymanagement();
	}
	switch (f)
	{
	case 8:
		system("cls");
		cout << "\nEnter book ID:   ";
		cin >> (tempbkid);
		cout << "\nEnter book name:   ";
		cin >> (tempbkname);
		cout << "\nEnter book price:   ";
		cin >> (tempbkprice);
		cout << "\nEnter book genre:   ";
		cin >> (tempbkgenre);
		cout << "\nConfirm details(y/n)";
	rerun:
		useless = _getch();
		switch (useless)
		{
		case  'y':

			if (counting == 0)
			{
				outputstream1.open("libdata.dat");
				outputstream1 << "1";
				outputstream1.close();
			}
			outputstream1.open("libdata.dat", ios::app);
			outputstream1 << "\n" << tempbkid << "\n" << tempbkname << "\n" << tempbkprice << "\n" << tempbkgenre;
			outputstream1.close(); cout << "\n\n task succesfull"; timer(2); librarymanagement();

			break;
		case   'Y':

			if (counting == 0)
			{
				outputstream1.open("libdata.dat");
				outputstream1 << "1";
				outputstream1.close();
			}
			outputstream1.open("libdata.dat", ios::app);
			outputstream1 << "\n" << tempbkid << "\n" << tempbkname << "\n" << tempbkprice << "\n" << tempbkgenre;
			outputstream1.close(); cout << "\n\n task succesfull"; timer(2); librarymanagement();
			break;
		case   'n':      librarymanagement();
			break;
		case 'N':       librarymanagement();
			break;
		default: goto rerun;
		}
		break;
	case  10:
		system("cls");
		cout << "Enter book ID to be deleted (0 to go back):     ";
		cin >> (search);
		if (search[0] == '0' && search[1] == '\0')
		{
			librarymanagement();
		}
		else
		{
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == book[i].bkid[f])
					{
						y = 1;
					}
					else
					{
						y = 0;  break;
					}

				}
				if (y == 1)
				{
					goto skip;
				}

			}
		skip:
			if (counting == 1 && y == 1)
			{
				outputstream1.open("libdata.dat");
				outputstream1 << "0";
				outputstream1.close();
				librarymanagement();
			}
			else if (y == 1)
			{
				except = i;
				outputstream1.open("libdata.dat");
				for (i = 0; i < counting; i++)
				{
					if (except == i)
					{
					}
					else
					{

						outputstream1 << "\n" << book[i].bkid << "\n" << book[i].bookname << "\n" << book[i].bookgenre << "\n" << book[i].bookprice;


					}

				}
				outputstream1.close();
			}
			else
			{
				librarymanagement();
			}
		}librarymanagement();
		break;
	}
}
// School management
void schoolmanagement()
{
	system("cls");
	gotoxy(15, 6);
	cout << "\n   xxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << "\n   xxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << "\n   xxxx                     ";
	cout << "\n   xxxx                     ";
	cout << "\n   xxxxxxxxxxxxxxxxxxxxxxxxx                 >>( ' Prepod ' )<<";
	cout << "\n   xxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << "\n                        xxxx";
	cout << "\n                        xxxx";
	cout << "\n   xxxxxxxxxxxxxxxxxxxxxxxxx";
	cout << "\n   xxxxxxxxxxxxxxxxxxxxxxxxx    C H O O L     M A N A G E M E N T";
	inputstream1.open("schooldata.dat");
	inputstream1.seekg(0);
	inputstream1.getline(flag, 5);
	if (inputstream1.eof() || (!inputstream1) || flag[0] == '0')
	{
		o = 1; counting = 0;
	}
	else
	{
		o = 0; i = 0, counting = 0;
		while (!inputstream1.eof())
		{
			counting++;
			inputstream1.getline(student[i].strno, 30);
			inputstream1.getline(student[i].stname, 30);
			inputstream1.getline(student[i].stclass, 30);
			inputstream1.getline(student[i].stph, 30);
			i++;
		}
	}
	inputstream1.close();
	cout << "\n\n   Press Enter key to proceed:  ";
	onlyenter();
recheck:
	system("cls");
	applybackground();
	applydialoguebox(4, string13);
	f = takeinput(6);
	for (i = 0; i < 2; i++)
	{
		if (useless == 27)
		{
			goto recheck;
		}
		else { break; }
	}
	switch (f)
	{
	case 8: viewall_school();
		break;
	case 10: search_school();
		break;
	case 12:manage_school();
		break;
	case 14:
		for (i = 0; i < 2500; i++)
		{
			cout << "\"(';')\"";
		}system("cls"); gotoxy(15, 6);
		applauncher();
		break;
	}


}
// View full school
void viewall_school()
{
	system("cls");
	applybackground();
	if (o == 1)
	{
		gotoxy(12, 8);
		cout << "Cannot access the database."; gotoxy(12, 9); cout << "The database is empty or has been corrupted or deleted."; gotoxy(12, 10); cout << "Press Enter key to rerun the application and scan again   "; onlyenter();
		schoolmanagement();
	}
	else
	{
		system("cls");
		cout << "------------------------------------------------------------ ";
		for (i = 0; i < counting; i++)
		{
			cout << "\n------------------------------------------------------------ ";
			cout << "\nRoll  no :    " << student[i].strno;
			cout << "\nName     :    " << student[i].stname;
			cout << "\nClass    :    " << student[i].stclass;
			cout << "\nPhone    :    " << student[i].stph;
			cout << "\n------------------------------------------------------------ ";
		}
		cout << "\n\nPress Enter key to go back:    "; onlyenter(); schoolmanagement();
	}
}
// Search school
void search_school()
{
	system("cls");
	applybackground();
	if (o == 1)
	{
		gotoxy(12, 8);
		cout << "Cannot access the database."; gotoxy(12, 9); cout << "The database is empty or has been corrupted or deleted."; gotoxy(12, 10); cout << "Press Enter key to rerun the application and scan again   "; onlyenter();
		schoolmanagement();
	}
	else
	{
		applydialoguebox(4, string16);
		f = takeinput(6);
		if (useless == 27)
		{
			schoolmanagement();
		}
		switch (f)
		{
		case  8: system("cls");
			cout << "\nEnter Roll no of the student to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == student[i].strno[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "\nRoll  no :    " << student[i].strno;
					cout << "\nName     :    " << student[i].stname;
					cout << "\nClass    :    " << student[i].stclass;
					cout << "\nPhone    :    " << student[i].stph;
				}
			}
			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); schoolmanagement();
			break;
		case 10: system("cls");
			cout << "\nEnter name of the student to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == student[i].stname[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "\nRoll  no :    " << student[i].strno;
					cout << "\nName     :    " << student[i].stname;
					cout << "\nClass    :    " << student[i].stclass;
					cout << "\nPhone    :    " << student[i].stph;
				}
			}
			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); schoolmanagement();
			break;
		case 12: system("cls");
			cout << "\nEnter Phone no of the student to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == student[i].stph[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "\nRoll  no :    " << student[i].strno;
					cout << "\nName     :    " << student[i].stname;
					cout << "\nClass    :    " << student[i].stclass;
					cout << "\nPhone    :    " << student[i].stph;
				}
			}
			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); schoolmanagement();
			break;
		case 14: system("cls");
			cout << "\nEnter class of the student to be searched :  ";
			cin >> (search);
			p = 0;
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == student[i].stclass[f])
					{
						e = 1;
					}
					else { e = 0; break; }
				}
				if (e == 1) {
					p = 1;
					cout << "------------------------------------------------------------ ";
					cout << "\nRoll  no :    " << student[i].strno;
					cout << "\nName     :    " << student[i].stname;
					cout << "\nClass    :    " << student[i].stclass;
					cout << "\nPhone    :    " << student[i].stph;
				}
			}
			if (p == 0) { cout << "No match for your search"; }
			cout << "\nPress Enter key to go back:    "; onlyenter(); schoolmanagement();
			break;
		}
	}
}
// Manage school
void manage_school()
{
	system("cls");
	applybackground();
	applydialoguebox(2, string15);
	f = takeinput(2);
	if (useless == 27)
	{
		schoolmanagement();
	}
	switch (f)
	{
	case 8:
		system("cls");
		cout << "\nEnter student roll no:   ";
		cin >> (tempstrno);
		cout << "\nEnter student  name:   ";
		cin >> (tempstname);
		cout << "\nEnter student class:   ";
		cin >> (tempstclass);
		cout << "\nEnter student phone no:   ";
		cin >> (tempstph);
		cout << "\nConfirm details(y/n)";
	rerun:
		useless = _getch();
		switch (useless)
		{
		case  'y':

			if (counting == 0)
			{
				outputstream1.open("schooldata.dat");
				outputstream1 << "1";
				outputstream1.close();
			}
			outputstream1.open("schooldata.dat", ios::app);
			outputstream1 << "\n" << tempstrno << "\n" << tempstname << "\n" << tempstclass << "\n" << tempstph;
			outputstream1.close(); cout << "\n\n task succesfull"; timer(2); schoolmanagement();

			break;
		case   'Y':

			if (counting == 0)
			{
				outputstream1.open("schooldata.dat");
				outputstream1 << "1";
				outputstream1.close();
			}
			outputstream1.open("schooldata.dat", ios::app);
			outputstream1 << "\n" << tempstrno << "\n" << tempstname << "\n" << tempstclass << "\n" << tempstph;
			outputstream1.close(); cout << "\n\n task succesfull"; timer(2); schoolmanagement();
			break;
		case   'n':      schoolmanagement();
			break;
		case 'N':       schoolmanagement();
			break;
		default: goto rerun;
		}
		break;
	case  10:
		system("cls");
		cout << "Enter student roll no  to be deleted (0 to go back):     ";
		cin >> (search);
		if (search[0] == '0' && search[1] == '\0')
		{
			schoolmanagement();
		}
		else
		{
			for (i = 0; i < counting; i++)
			{
				for (f = 0; f < 30; f++)
				{
					if (search[f] == student[i].strno[f])
					{
						y = 1;
					}
					else
					{
						y = 0;  break;
					}

				}
				if (y == 1)
				{
					goto skip;
				}

			}
		skip:
			if (counting == 1 && y == 1)
			{
				outputstream1.open("schooldata.dat");
				outputstream1 << "0";
				outputstream1.close();
				librarymanagement();
			}
			else if (y == 1)
			{
				except = i;
				outputstream1.open("schooldata.dat");
				for (i = 0; i < counting; i++)
				{
					if (except == i)
					{
					}
					else
					{

						outputstream1 << "\n" << student[i].strno << "\n" << student[i].stname << "\n" << student[i].stclass << "\n" << student[i].stph;


					}

				}
				outputstream1.close();
			}
			else
			{
				schoolmanagement();
			}
		}schoolmanagement();
		break;
	}

}
// New Task Function
void newtask()
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(3, string4);
	f = takeinput(4);
	if (useless == 27)
	{
		start();
	}
	switch (f)
	{
	case 8: applauncher();
		break;
	case 10:assistant();
		break;
	case 12:shutdown(3);
		break;
	}
}
// Applauncher Function
void applauncher()
{
	system("cls");
	applybackground();
	applydialoguebox(3, string12);
	f = takeinput(4);
	if (useless == 27)
	{
		start();
	}
	switch (f)
	{
	case 8: for (i = 0; i < 2500; i++)
	{
		cout << "\"(';')\"";
	}
		  librarymanagement();
		  break;
	case 10: for (i = 0; i < 2500; i++)
	{
		cout << "\"(';')\"";
	}
		   schoolmanagement();
		   break;
	case 12:shutdown(7);
		break;
	}

}
// Assistant Function
void assistant()
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(3, string6);
	f = takeinput(4);

	if (useless == 27)
	{
		start();
	}
	switch (f)
	{
	case 8: helper();
		break;
	case 10:projetinfo();
		break;
	case 12:shutdown(5);
		break;
	}
}
// Calculator Function
void calculator()
{
	f, i; loading: system("cls");
	applybackground();
	applydialoguebox(2, string10);
	f = takeinput(2);
	if (useless == 27)
	{
		goto loading;
	}
	switch (f)
	{
	case 8:
	{
	rerun:
		system("cls");
		applybackground();
		p = 0;
		long double  number1 = 0, number2 = 0, result;
		gotoxy(15, 9);
		char data[31], storage1[31], storage2[31];
		char o;
		for (i = 0; i < 31; i++)
		{
			data[i] = _getch();
			if (data[i] == '1' || data[i] == '2' || data[i] == '3' || data[i] == '4' || data[i] == '5' || data[i] == '6' || data[i] == '7' || data[i] == '8' || data[i] == '9' || data[i] == '0' || data[i] == '+' || data[i] == '-' || data[i] == '/' || data[i] == '*' || data[i] == '.' || data[i] == 27 || data[i] == 8)
			{
				if (data[i] == 27)
				{
					goto rerun;
				}
				else if (data[i] == 8)
				{
					if (i != 0)
					{
						cout << "\b";
						i = i - 2;
					}
					else
					{
						i = -1;
					}
				}
				else if (data[i] == '+' || data[i] == '-' || data[i] == '/' || data[i] == '*')
				{
					o = data[i];
					data[i] = '\0';
					goto next;
				}
				else
				{
					cout << data[i];
				}

			}

			else
			{
				if (i != 0)
				{
					i = i - 1;
				}
				else
				{
					i = -1;
				}
			}
		}
	next:
		int a;
		a = strlen(data);
		gotoxy(14 + a, 10);
		cout << o;
		for (i = 0; i <= a; i++)
		{
			storage1[i] = data[i];
		}
		gotoxy(15, 11);
		for (int h = i; h < 31; h++)
		{
			data[h] = _getch();
			if (data[h] == '1' || data[h] == '2' || data[h] == '3' || data[h] == '4' || data[h] == '5' || data[h] == '6' || data[h] == '7' || data[h] == '8' || data[h] == '9' || data[h] == '0' || data[h] == '.' || data[h] == 27 || data[h] == 8 || data[h] == 13)
			{
				storage2[p] = data[h];
				if (data[h] == 27)
				{
					goto rerun;
				}
				else if (data[h] == 8)
				{
					if (h != i + 1 && p != 0)
					{
						cout << "\b";
						h = h - 2;
						p = p - 2;
					}
					else
					{
						h = i + 1;
						p = 1;
					}
				}
				else if (data[h] == 13)
				{
					storage2[p] = '\0';
					goto last;
				}
				else
				{
					cout << data[h];
				}

			}

			else
			{
				if (h != i + 1)
				{
					h = h - 1;
				}
				else
				{
					h = i;
				}
			}
			p++;

		}

	last:
		cout << "\b\b\b\b\b\b\b\b";
		gotoxy(15 + strlen(storage1) - strlen(storage2), 11);
		cout << storage2;

		int u = 10, x = 0;
		int d = strlen(storage1) - 1;
		for (h = 0; h < strlen(storage1); h++)
		{
			if (storage1[h] == '0')
			{
				number1 = number1;
			}
			else if (storage1[h] == '1')
			{
				number1 = number1 + (1 * (pow(10, d)));
			}
			else if (storage1[h] == '2')
			{
				number1 = number1 + (2 * (pow(10, d)));
			}
			else if (storage1[h] == '3')
			{
				number1 = number1 + (3 * (pow(10, d)));
			}
			else if (storage1[h] == '4')
			{
				number1 = number1 + (4 * (pow(10, d)));
			}
			else if (storage1[h] == '5')
			{
				number1 = number1 + (5 * (pow(10, d)));
			}
			else if (storage1[h] == '6')
			{
				number1 = number1 + (6 * (pow(10, d)));
			}
			else if (storage1[h] == '7')
			{
				number1 = number1 + (7 * (pow(10, d)));
			}
			else if (storage1[h] == '8')
			{
				number1 = number1 + (8 * (pow(10, d)));
			}
			else if (storage1[h] == '9')
			{
				number1 = number1 + (9 * (pow(10, d)));
			}
			else if (storage1[h] == '.')
			{
				if (x == 0)
				{
					x = 1;
					f = d;
				}
			}

			d--;
		}

		d = strlen(storage2) - 1;
		for (h = 0; h < strlen(storage2); h++)
		{
			if (storage2[h] == '0')
			{
				number2 = number2;
			}
			else if (storage2[h] == '1')
			{
				number2 = number2 + (1 * (pow(10, d)));
			}
			else if (storage2[h] == '2')
			{
				number2 = number2 + (2 * (pow(10, d)));
			}
			else if (storage2[h] == '3')
			{
				number2 = number2 + (3 * (pow(10, d)));
			}
			else if (storage2[h] == '4')
			{
				number2 = number2 + (4 * (pow(10, d)));
			}
			else if (storage2[h] == '5')
			{
				number2 = number2 + (5 * (pow(10, d)));
			}
			else if (storage2[h] == '6')
			{
				number2 = number2 + (6 * (pow(10, d)));
			}
			else if (storage2[h] == '7')
			{
				number2 = number2 + (7 * (pow(10, d)));
			}
			else if (storage2[h] == '8')
			{
				number2 = number2 + (8 * (pow(10, d)));
			}
			else if (storage2[h] == '9')
			{
				number2 = number2 + (9 * (pow(10, d)));
			}


			d--;
		}
		gotoxy(16 + strlen(storage1) - 8, 12);
		cout << "--------------";
		switch (o)
		{
		case '+': result = number1 + number2;
			break;
		case '-': result = number1 - number2;
			break;
		case '/': result = number1 / number2;
			break;
		case '*': result = number1 * number2;
			break;
		}
		gotoxy(15, 13);
		cout << result;

		gotoxy(16 + strlen(storage1) - 8, 14);
		cout << "--------------";
	fault:
		gotoxy(20, 16);
		useless = _getch();
		switch (useless)
		{
		case 27: goto loading;
		case 13: goto rerun;
		default: goto fault;
		}

	}
	case 10:helper();
		break;
	}
}
//Mathematic Tables
void math_table()
{
loading:
	system("cls");
	cout << "Input a number whose multiplication table you want to see\n\nInput 0(zero) to close this application\n\n\t\t\t";
	cin >> j;
	if (j == 0)
	{
		helper();
	}
	system("cls");
	cout << "\n   The table of " << j << "\n\n";
	for (i = 0; i < 10; i++)
	{
		cout << "         " << j << " * " << (i + 1) << " =  " << j * (i + 1) << "\n\n";
		timer(1);
	}
	cout << "Input Enter key to go back\t";
	onlyenter();
	goto loading;
}
// Unit Calculator
void unit_calculator()
{
	system("cls");
	applybackground();
}
// Area Calulator
void area()
{
	applybackground();
	applydialoguebox(3, string18);
	f = takeinput(4);
	if (useless == 27)
	{
		assistant();
	}
	switch (f)
	{
	case 8:  system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter base of your Triangle : ";
		cin >> j;
		gotoxy(15, 7);
		cout << "Enter height of your Triangle : ";
		cin >> k;
		j = 0.5 * j * k;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The area is : " << j;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	case 10:
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter side of the square : ";
		cin >> j;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The area is : " << j * j;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	case 12:
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter length of the rectangle : ";
		cin >> j;
		cout << "Enter breadth of the rectangle : ";
		cin >> k;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The area is : " << j * k;
		gotoxy(15, 6);
		cout << "The area is : " << j * j;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();


		break;
	}



}


// Perimeter Calulator

void perimeter()
{

	applybackground();
	applydialoguebox(3, string20);
	f = takeinput(4);
	if (useless == 27)
	{
		assistant();
	}
	switch (f)
	{
	case 8:  system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter side 1 of your Triangle : ";
		cin >> j;
		gotoxy(15, 7);
		cout << "Enter side 2 of your Triangle : ";
		cin >> k;
		gotoxy(15, 7);
		cout << "Enter side 3 of your Triangle : ";
		cin >> l;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The perimeter is : " << (j + k + l);
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	case 10:
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter side of the square : ";
		cin >> j;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The perimeter is : " << 4 * j;
		gotoxy(15, 7);
		cout << "Press Enter key to go back  ";
		onlyenter();
		geometric_calculator();

		break;
	case 12:
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter length of the rectangle : ";
		cin >> j;
		cout << "Enter breadth of the rectangle : ";
		cin >> k;
		system("cls");
		gotoxy(15, 6);
		cout << "The perimeter is : " << 2 * (j + k);
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	}




}

// Volume Calulator

void volume()
{
	applybackground();
	applydialoguebox(4, string19);
	f = takeinput(6);
	if (useless == 27)
	{
		assistant();
	}
	switch (f)
	{
	case 8:  system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter side of your cube : ";
		cin >> j;
		system("cls");
		gotoxy(15, 6);
		cout << "The volume is : " << j * j * j;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	case 10:
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter length of the cuboid : ";
		cin >> j;
		gotoxy(15, 7);

		cout << "Enter breadth of the cuboid : ";
		cin >> k;
		gotoxy(15, 8);
		cout << "Enter height of the cuboid : ";
		cin >> l;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The volume is : " << j * k * l;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	case 12:
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter radius of your cylinder : ";
		cin >> j;
		gotoxy(15, 7);
		cout << "Enter height of your cylinder : ";
		cin >> k;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The volume is : " << 3.14 * j * j * k;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();
		break;
	case 14:
		system("cls");
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "Enter radius of your cone : ";
		cin >> j;
		gotoxy(15, 7);
		cout << "Enter height of your cone : ";
		cin >> k;
		system("cls");
		applybackground();
		gotoxy(15, 6);
		cout << "The volume is : " << 3.14 * j * j * k * 0.33;
		gotoxy(15, 7);
		cout << "Press Enter key to go back : ";
		onlyenter();
		geometric_calculator();

		break;
	}



}

//Geometric Calculator
void geometric_calculator()
{
	system("cls");
	applybackground();
	applydialoguebox(3, string17);
	f = takeinput(4);
	if (useless == 27)
	{
		assistant();
	}
	switch (f)
	{
	case 8: area();
		break;
	case 10:volume();
		break;
	case 12:perimeter();
		break;
	}

}
// Helper Function
void helper()
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(5, string7);
	f = takeinput(8);
	if (useless == 27)
	{
		assistant();
	}
	switch (f)
	{
	case 8: calculator();
		break;
	case 10:math_table();
		break;
	case 12:unit_calculator();
		break;
	case 14:geometric_calculator();
		break;
	case 16:shutdown(6);
		break;
	}
}
// Prepod info Function
void projetinfo()
{
	system("cls");
	applybackground();
	gotoxy(10, 4);
	cout << "   XXXXOOOOOOOOO";
	gotoxy(10, 5);
	cout << "   XXXXOOOOOOOOO";
	gotoxy(10, 6);
	cout << "   XXXX      OOO";
	gotoxy(10, 7);
	cout << "   XXXX      OOO";
	gotoxy(10, 8);
	cout << "   XXXXOOOOOOOOO";
	gotoxy(10, 9);
	cout << "   XXXXOOOOOOOOO";
	gotoxy(10, 10);
	cout << "   XXXX              ";
	gotoxy(10, 11);
	cout << "   XXXX                 R O J E C T";
	gotoxy(10, 12);
	cout << "   XXXX             ";
	gotoxy(10, 13);
	cout << "   XXXX        ";
	gotoxy(10, 16);
	gotoxy(10, 17);
	cout << "Postav'te 5 pojaluista, 2000 strok vse taki.";
	gotoxy(10, 19);
	cout << "Input Enter key to go back\t";
	onlyenter();
	assistant();
}
// Settings Function
void settings()
{
loading:
	system("cls");
	applybackground();
	applydialoguebox(2, string5);
	f = takeinput(4);
	if (useless == 27)
	{
		start();
	}
	switch (f)
	{
	case 8: changesecureke();
		break;
	case 12:shutdown(4);
		break;
	}
}
// Change securekey
void changesecureke()
{
	system("cls");
	applybackground();
	gotoxy(15, 8);
	cout << "Enter new username:   ";
	cin >> (username2);
	gotoxy(15, 10);
	cout << "Enter new password:   ";
	for (int d = 0; d < 20; d++)
	{
		password2[d] = _getch();
		cout << "*";
		if (password2[d] == 8)
		{
			cout << "\b\b";
			if (d == 0)
			{
				gotoxy(18, 8);
			}
			if (d != 0)
			{
				d = d - 2;
			}
		}
		else if (password2[d] == 13)
		{
			cout << "\b";
			password2[d] = '\0';
			break;
		}
	}

	system("cls");
	applybackground();
	gotoxy(15, 8);
	cout << "Confirm new username:   ";
	cin >> (username);
	gotoxy(15, 11);
	cout << "Confirm new password:   ";
	for (d = 0; d < 20; d++)
	{
		password[d] = _getch();
		cout << "*";
		if (password[d] == 8)
		{
			cout << "\b\b";
			if (d == 0)
			{
				gotoxy(18, 8);
			}
			if (d != 0)
			{
				d = d - 2;
			}
		}
		else if (password[d] == 13)
		{
			cout << "\b";
			password[d] = '\0';
			break;
		}
	}

	for (d = 0; d < 8; d++)
	{
		if (username[d] == username2[d] && strlen(username) == strlen(username2))
		{
			o = 0;
		}
		else
		{
			o = 1;
			goto last;

		}
	}
	for (d = 0; d < 20; d++)
	{
		if (password[d] == password2[d] && strlen(password) == strlen(password2))
		{
			o = 0;
		}
		else
		{
			o = 1;
			goto last;

		}
	}
last:
	if (o == 1)
	{
		cout << "  \aIncorrect data";
		timer(3);
		changesecureke();
	}
	else
	{
		gotoxy(15, 13); cout << "Confirm request  (Enter or Esc)  ";
	reinput:
		useless = _getch();
		switch (useless)
		{
		case 13:
			outputstream1.open("secureke.dat", ios::out);
			outputstream1 << username2 << "\n" << password2 << "\n";
			outputstream1.close(); gotoxy(15, 16);
			cout << "Task completed successfully";
			timer(3); boot();
			break;
		case 27: settings();
			break;
		default: goto reinput;
		}

	}

}


// Application Manager Function
void appmanager()
{
	system("cls");
	applybackground();
}
// Main
void main()
{
	boot();
}