#include<iostream>
#include<fstream>
#include<vector>
#include<windows.h>
#include<ctime>
#pragma warning (disable : 4996)//this is for visual studio to disable time error

using namespace std;


struct cofelst {
    int ID;
    string Cname;
    float Cprice;
    int Ccaffine;

};
struct coffeeAdmin
{
    int ID;
    string Coffeename;
    float Coffeeprice;
    int Coffeecaffine;
};
struct logHisto {
    int totalOrder;
    double totalPrices;
    int day;
    int  year;

    string DayName;
    string MonthName;
    string time;
}std1;

void timee();
void clear();
void coffeeImage() {

    cout << R"(______________¶¶¶1___¶¶¶____¶¶¶1_______________
_____________¶¶¶____¶¶¶1___¶¶¶1___________________
______________¶¶¶¶___1¶¶¶___1¶¶¶__________________
_______________1¶¶¶1___¶¶¶1___¶¶¶¶________________
_________________1¶¶1____¶¶¶____¶¶¶_______________
___________________¶¶1____¶¶1____¶¶1______________
___________________¶¶¶____¶¶¶____¶¶¶______________
__________________1¶¶1___1¶¶1____¶¶1______________
_________________¶¶¶____¶¶¶1___1¶¶1_______________
________________11_____111_____11_________________
__________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
1¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
1¶¶¶¶¶¶¶¶¶¶¶__1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
1¶¶_______¶¶__1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
1¶¶_______¶¶__1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
1¶¶_______¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
1¶¶_______¶¶__1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
_¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
_¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶________
__________¶¶___1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1________
__________1¶¶___¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_________
____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶11__________
11_____________________________________________111
1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1
__¶¶111111111¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶111111111¶__)" << endl;

    Sleep(2000);
    for (int i = 15; i <= 100; i += 5) {

        clear();



        cout << "\t" << "...System Loading...";
        cout << "\n\n\t\t" << i << "%";
        cout << "";


        Sleep(100);
        if (i == 90 || i == 50 || i == 96 || i == 83) {
            Sleep(100);
        }

    }
}

void user();
void admin();

//user
double coffeorder(int order, double price);//for order calculate
void saveCheckOut(double Tprice, int Torder);//stroing total price in to log
//user






bool systemrun = true;
void main() {
    if (systemrun == true) {
        coffeeImage();
        systemrun = false;
    }clear();
    string users;

    cout << "\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 MAIN \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n\n\t\t  User Type\n\n";
    cout << "\t\t  1-User\n\n";
    cout << "\t\t  2-Admin\n\n";
    cout << "\t\t  3-Exit\n\n";
    string password;
    do
    {
        cin >> users;
        if (users == "1") {
            clear();
            user();
        }
        else if (users == "2") {
            do {
                clear();
                cout << "Enter Your pass Word:\n";
                cin >> password;
                if (password == "Holan") {
                    admin();
                }

            } while (password != "Holan");
        }
        else if (users == "3") { exit(0); }
        else { cout << "please type correctly !\n"; }



    } while (users != "3");
}




//user
void user() {

    ifstream coffeeList("coffee.txt", ios::in);
    cofelst list;
    vector<cofelst> coffee;

    string sizecheck;
    int  idorder;
    float price;
    if (coffeeList.is_open()) {
        while (coffeeList >> list.ID >> list.Cname >> list.Cprice >> list.Ccaffine) {
            coffee.push_back(list);
        }
        cout << "Welcome User Hope you doing well\n\n";
        timee();
        Sleep(3500);



        do {
            clear();
            cout << "press 0 to go back main\t\t\t"; timee(); cout << endl << endl;
            cout << "\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 MENU \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl << endl;
            cout << "\t.:ID:.\t .:Name:.   .:Price:.   .:Caffeine:.\n\n";

            for (int i = 0; i < coffee.size(); i++) {
                sizecheck = coffee[i].Cname;
                cout << "\t   " << coffee[i].ID << "\t" << coffee[i].Cname;
                for (int i = sizecheck.size(); i < 15; i++) {
                    cout << " ";

                }
                cout << "\t" << coffee[i].Cprice << "$" << "\t    " << coffee[i].Ccaffine << "%" << endl << endl;
            }
            cout << "\nWhat type of coffee do you like ?\n";
            int BuyOrder, Checking = 0;//cheacking for ID in list to define it ,:: BuyOrder is for calculating
            char checkout;
            do {
                cin >> idorder;
                for (int i = 0; i < coffee.size(); i++) {
                    if (idorder == coffee[i].ID) {
                        Checking = coffee[i].ID;
                        cout << "How many do you want to order  " << coffee[i].Cname << " coffee!\n";
                        cin >> BuyOrder;
                        while (BuyOrder > 20) {
                            cout << "!!This is too much coffee!!\nplease be sure about it and Enter again the amount order\n";
                            cin >> BuyOrder;
                        }
                        if (BuyOrder == 0) {
                            break;
                        }
                        coffeorder(BuyOrder, coffee[i].Cprice);
                        cout << "\nIt is cost you " << coffeorder(BuyOrder, coffee[i].Cprice) << "$";
                        double TotalPrice = coffeorder(BuyOrder, coffee[i].Cprice);
                        cout << "\nDo you want me to CheckOut? if yes press (y or Y) or any to cancel it\n";
                        cin >> checkout;
                        if (checkout == 'y' || checkout == 'Y') {
                            saveCheckOut(TotalPrice, BuyOrder);
                            cout << "Thank you for Buying coffee from us\nHave a great day";
                            Sleep(3000);
                        }
                        else {
                            break;
                        }

                    }


                }
                if (Checking != idorder) {
                    cout << "\ncoffee not found please insert by list ID\n";
                }
                else
                {
                    break;
                }

            } while (true);



            if (idorder == 0) {
                clear();
                main();
            }
        } while (idorder != 0);

    }
    else {//color RED
        cout << "\ncoffee DataBase not found\n";
    }


}

double coffeorder(int order, double price) {
    double total = order * price;
    return total;
}
void saveCheckOut(double Tprice, int Torder) {
    time_t timo;
    time(&timo);

    ofstream log;
    log.open("logDATA.txt", ios::app);
    log << Torder << "\t" << Tprice << "\t" << ctime(&timo);

    log.close();



}

void timee() {
    time_t timo;
    time(&timo);
    cout << "Date & Time :" << ctime(&timo);
}

void clear() {
    system("cls");
}
//user


void admin() {

    fstream coffeeDB("coffee.txt", ios::in | ios::out);


    coffeeAdmin list;
    vector<coffeeAdmin> coffee;
    vector<int> IDs, Cofeecaffine;
    vector<string> Cofeename;
    vector<double>Cofeeprice;
    string sizecheck;
    int lID, lcaffeine;
    string nameC;
    float price;
    if (coffeeDB.is_open()) {
        clear();

        while (coffeeDB >> list.ID >> list.Coffeename >> list.Coffeeprice >> list.Coffeecaffine) {
            coffee.push_back(list);


        }//This is for record erase at this moment my brain just got this thing to go Do not mind me!
        //this is only solution at 5:30am morning 4/1/2022
        coffeeDB.close();
        coffeeDB.open("coffee.txt", ios::in);
        while (coffeeDB >> lID >> nameC >> price >> lcaffeine) {
            IDs.push_back(lID);
            Cofeename.push_back(nameC);
            Cofeeprice.push_back(price);
            Cofeecaffine.push_back(lcaffeine);
        }
        coffeeDB.close();
        string chose;




        do {
            clear();
            cout << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 Admin Page \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << "\t";  timee(); cout << endl << endl;
            cout << "\t1-Add New Coffee\n\n" << "\t2-Remove Coffee on menu\n\n" << "\t3-Update Coffee on menu\n\n" << "\t4-Log Hitory Data\n\n" << "\t0-To LogOut\n\n";
            cin >> chose;
            //add new coffee
            if (chose == "1") {

                cout << "Type ID of the coffee:\n";
                int count = 0;
                do {
                    count = 0;
                    cin >> list.ID;

                    for (int i = 0; i < coffee.size(); i++) {
                        if (list.ID == coffee[i].ID) {

                            cout << "The ID already Exist!\nType new ID\n";
                        }
                        else if (list.ID == 0) {
                            cout << "\nZero ID is not an ID please enter again!\n";
                            i = coffee.size() - 1;
                        }
                        else { count++; }
                    }

                } while (count != coffee.size());//work by limit of the list id
                cout << "Enter Coffee name:\n";
                cin >> list.Coffeename;
                cout << "Enter the price\n";
                do {
                    cin >> list.Coffeeprice;
                    if (list.Coffeeprice > 8.99) {
                        cout << "this high price coffee not accept\n";
                    }
                    else if (list.Coffeeprice < 0.5) {
                        cout << "this low price coffee not accept\n";
                    }

                } while (list.Coffeeprice >= 9 || list.Coffeeprice < 0.5);
                cout << "Enter the percentage caffeine  in coffee\n";
                do {
                    cin >> list.Coffeecaffine;
                    if (list.Coffeecaffine > 100) {
                        cout << "This High caffeine  not exist\n";
                    }
                    else if (list.Coffeecaffine < 5) {
                        cout << "This low caffeine   not exist\n";
                    }

                } while (list.Coffeecaffine > 100 || list.Coffeecaffine < 5);
                cout << "ID:" << list.ID << "\tName: " << list.Coffeename << "\tPrice: " << list.Coffeeprice << "$" << "\tcaffeine " << list.Coffeecaffine << "%" << endl;
                cout << "\nDo you want to Save if yes Press (Y or y) or any key to go back Admin main\n";
                string saving;
                cin >> saving;
                if (saving == "y" || saving == "Y") {
                    coffee.push_back(list);
                    coffeeDB.open("coffee.txt", ios::app);
                    coffeeDB << list.ID << "\t" << list.Coffeename << "\t" << list.Coffeeprice << "\t" << list.Coffeecaffine << endl;
                    coffeeDB.close();

                }
                clear();

                cout << "\n\n\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 MENU \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl << endl;
                cout << "\t.:ID:.\t .:Name:.   .:price:.   .:caffine:.\n\n";

                for (int i = 0; i < coffee.size(); i++) {
                    sizecheck = coffee[i].Coffeename;
                    cout << "\t   " << coffee[i].ID << "\t" << coffee[i].Coffeename;
                    for (int i = sizecheck.size(); i < 15; i++) {
                        cout << " ";

                    }
                    cout << "\t" << coffee[i].Coffeeprice << "$" << "\t    " << coffee[i].Coffeecaffine << "%" << endl << endl;
                }
                Sleep(5000);

            }
            //remove
            else if (chose == "2") {

                clear();
                cout << "\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 MENU \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl << endl;
                cout << "\t.:ID:.\t .:Name:.   .:price:.   .:caffine:.\n\n";

                for (int i = 0; i < IDs.size(); i++) {
                    sizecheck = Cofeename[i];
                    cout << "\t   " << IDs[i] << "\t" << Cofeename[i];
                    for (int i = sizecheck.size(); i < 15; i++) {
                        cout << " ";

                    }
                    cout << "\t" << Cofeeprice[i] << "$" << "\t    " << Cofeecaffine[i] << "%" << endl << endl;
                }
                int id;


                do {

                    cout << "\nWhich record do you want to delete Type ID ? or press 0 to cancel\n";
                    int Checking = 0;//cheacking for ID in list to define it ,:: BuyOrder is for calculating
                    char deleting;
                    do {
                        cin >> id;
                        for (int i = 0; i < IDs.size(); i++) {
                            if (id == IDs[i]) {
                                Checking = IDs[i];
                                cout << "This Coffee: " << Cofeename[i] << " coffee!\n";


                                cout << "\nDo you want to delete This Record? if yes press (y or Y) or any to cancel it\n";
                                cin >> deleting;
                                if (deleting == 'y' || deleting == 'Y') {
                                    IDs.erase(IDs.begin() + i);
                                    Cofeename.erase(Cofeename.begin() + i);
                                    Cofeeprice.erase(Cofeeprice.begin() + i);
                                    Cofeecaffine.erase(Cofeecaffine.begin() + i);
                                    coffeeDB.open("coffee.txt", ios::out);
                                    for (int i = 0; i < IDs.size(); i++) {
                                        coffeeDB << IDs[i] << "\t" << Cofeename[i] << "\t" << Cofeeprice[i] << "\t" << Cofeecaffine[i] << endl;
                                    }
                                    coffeeDB.close();
                                }
                                else {
                                    break;
                                }

                            }


                        }
                        if (Checking != id) {
                            cout << "\ncoffee record not found please insert by list ID\n";
                        }
                        else
                        {
                            break;
                        }

                    } while (true);



                    if (id == 0) {
                        clear();
                        admin();
                    }
                } while (id != 0);

            }









            else if (chose == "3") {
                clear();
                //displaymenu(sizeOfVec,IDs,Coffeename)
                cout << "\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 MENU \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl << endl;
                cout << "\t.:ID:.\t .:Name:.   .:price:.   .:caffine:.\n\n";

                for (int i = 0; i < IDs.size(); i++) {
                    sizecheck = Cofeename[i];
                    cout << "\t   " << IDs[i] << "\t" << Cofeename[i];
                    for (int i = sizecheck.size(); i < 15; i++) {
                        cout << " ";

                    }
                    cout << "\t" << Cofeeprice[i] << "$" << "\t    " << Cofeecaffine[i] << "%" << endl << endl;
                }

                int id;


                do {

                    cout << "\nWhich record do you want to Update Type ID ? or press 0 to cancel\n";
                    int Checking = 0, chosen, newcaffeine;//cheacking for ID in list to define it ,:: BuyOrder is for calculating
                    char updating;
                    string newname;
                    float newPrice;
                    do {
                        cin >> id;
                        for (int i = 0; i < IDs.size(); i++) {
                            if (id == IDs[i]) {
                                Checking = IDs[i];
                                cout << "1-Name\t2-Price\t3-Caffeine\t4-All";
                                cin >> chosen;
                                switch (chosen)
                                {
                                case 1:cout << "\nName: "; cin >> newname; Cofeename.insert(Cofeename.begin() + i, newname);
                                    break;
                                case 2:cout << "\nPrice: "; 
                                        do {
                                            cin >> newPrice;
                                            if (newPrice > 8.99) {
                                                cout << "this high price coffee not accept\n";
                                            }
                                            else if (newPrice < 0.5) {
                                                cout << "this low price coffee not accept\n";
                                            }

                                        } while (newPrice >= 9 || newPrice < 0.5);
                                        Cofeeprice.insert(Cofeeprice.begin() + i, newPrice);
                                    
                                    
                                    break;
                                case 3:cout << "\nCaffeine: "; cin >> newcaffeine; Cofeecaffine.insert(Cofeecaffine.begin() + i, newcaffeine);
                                    break;
                                case 4:cout << "Name: "; cin >> newname; Cofeename.insert(Cofeename.begin() + i, newname);
                                    cout << "\nPrice: "; newPrice; Cofeeprice.insert(Cofeeprice.begin() + i, newPrice);
                                    cout << "\nCaffeine: "; newcaffeine; Cofeecaffine.insert(Cofeecaffine.begin() + i, newcaffeine);
                                    break;
                                default:
                                    break;
                                }

                                cout << "\nDo you want to Update This Record? if yes press (y or Y) or any to cancel it\n";
                                cin >> updating;
                                if (updating == 'y' || updating == 'Y') {

                                    coffeeDB.open("coffee.txt", ios::out);
                                    for (int i = 0; i < IDs.size(); i++) {
                                        coffeeDB << IDs[i] << "\t" << Cofeename[i] << "\t" << Cofeeprice[i] << "\t" << Cofeecaffine[i] << endl;
                                    }
                                    coffeeDB.close();
                                }
                                else {
                                    break;
                                }

                            }


                        }
                        if (Checking != id) {
                            cout << "\ncoffee record not found please insert by list ID\n";
                        }
                        else
                        {
                            break;
                        }

                    } while (true);



                    if (id == 0) {
                        clear();
                        admin();
                    }
                } while (id != 0);

            }
            else if (chose == "4") {
                clear();
                ifstream coffeeLOG("logDATA.txt");
                logHisto log;
                vector<logHisto> all;


                if (coffeeLOG.is_open()) {

                    while (coffeeLOG >> log.totalOrder >> log.totalPrices >> log.DayName >> log.MonthName >> log.day >> log.time >> log.year) {
                        all.push_back(log);
                    }


                    cout << "\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 DATA LOG \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl << endl;
                    cout << "\tTotal order" << "\tTotal Price" << "\t  Date" << "\t\tTime\n";
                    for (int i = 0; i < all.size(); i++) {
                        cout << "\n\t " << all[i].totalOrder << "\t\t" << all[i].totalPrices << "$\t\t" << all[i].MonthName << "/" << all[i].day << "/" << all[i].year << "\t" << all[i].time << endl;
                    }
                    int chosen;
                    cout << "\n\t1-For TOTAL Orders:" << "\n\t2-For TOTAL Profit:\n" << "\n\tpress 0 to quit..\n\n";
                    do {

                        cin >> chosen;


                        float sumOrder = 0, sumProfit = 0;

                        switch (chosen) {
                        case 1:for (int i = 0; i < all.size(); i++) {
                            sumOrder += all[i].totalOrder;
                        }cout << "\nTotal Orders: " << sumOrder << endl;
                            break;
                        case 2:for (int i = 0; i < all.size(); i++) {
                            sumProfit += all[i].totalPrices;
                        }cout << "\nTotal Profits: " << sumProfit << "$" << endl;
                            break;
                        default:
                            break;
                        }
                    } while (chosen != 0);
                    coffeeLOG.close();
                }
                else { cout << "file not found"; }
            }






            else if (chose == "0") { clear(); main(); }
            else { cout << "\n\nPlease Admin Take coffee to know what you type!!\n"; Sleep(2000); }


        } while (chose != "0");








        cout << "\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9 MENU \xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl << endl;
        cout << "\t.:ID:.\t .:Name:.   .:price:.   .:caffine:.\n\n";

        for (int i = 0; i < coffee.size(); i++) {
            sizecheck = coffee[i].Coffeename;
            cout << "\t   " << coffee[i].ID << "\t" << coffee[i].Coffeename;
            for (int i = sizecheck.size(); i < 15; i++) {
                cout << " ";

            }
            cout << "\t" << coffee[i].Coffeeprice << "$" << "\t    " << coffee[i].Coffeecaffine << "%" << endl;
        }

    }
    else {
        cout << "\ncoffee DataBase not found\n";
    }

}

