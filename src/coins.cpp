#include "coins.hpp"
#include <iostream>

using namespace std;



Coins::Coins(int q, int d, int n, int p)
	:quarters(q), dimes(d), nickels(n), pennies(p) {
}


void Coins::deposit_coins(Coins& coins)
{
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;
	coins.quarters = 0;
    coins.dimes = 0;
    coins.nickels = 0;
    coins.pennies = 0;

}


bool Coins::has_exact_change_for_coins(Coins const& coins) const
{
    return (quarters >= coins.quarters) && (dimes >= coins.dimes) && (nickels>=coins.nickels) && (pennies>=coins.pennies);
}



Coins Coins::extract_exact_change(Coins const& coins)
{
    if(!has_exact_change_for_coins(coins))
    {
        return Coins(0, 0, 0, 0);
    }else{
        quarters -= coins.quarters;
        dimes -= coins.dimes;
        nickels -= coins.nickels;
        pennies -= coins.pennies;

        return coins;
    }
}



int Coins::total_value_in_cents() const
{
    return quarters*25 + dimes*10 + nickels*5 + pennies;
}



void Coins::print(ostream & out) const
{
    out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies";
}



void print_cents(int cents, ostream& out)
{
	out << "$" << cents/100 << "." << cents/10%10 << cents%10;
}



ostream& operator <<(ostream & out, Coins const& coins)
{
    coins.print(out);
    return out;
}



Coins coins_required_for_cents(int amount_in_cents)
{
     int q = amount_in_cents / 25;
     int d = (amount_in_cents % 25) / 10;
     int n = ((amount_in_cents % 25) % 10) / 5;
     int p = ((amount_in_cents % 25) % 10) % 5;
     return Coins(q, d, n, p);
}


Coins ask_for_coins(istream& in, ostream& out)
{
    int q, d, n, p;
    out << "Quarters? ";
    in >> q;
    out << "Dimes? ";
    in >> d;
    out << "Nickels? ";
    in >> n;
    out << "Pennies? ";
    in >> p;

    return Coins(q, d, n, p);
}




void coins_menu(istream& in, ostream& out) {
    Coins mycoin(0, 0, 0, 0);
    out << "Coins Menu" << endl;
    out << endl;

    int command = 0;
    while (command != 4) {
        out << "1. Deposit Change" << endl;
        out << "2. Extract Change" << endl;
        out << "3. Print Balance" << endl;
        out << "4. Exit" << endl << endl;
        out << "User Input: ";
        in >> command;

        if (command == 1) {
            out << endl;
            Coins input = ask_for_coins(in, out);
            mycoin.deposit_coins(input);
            out << endl;
            out << "Thank you!" << endl << endl;
            
        } 
		else if (command == 2) {
            out << endl;
            Coins input = ask_for_coins(in, out);
            out << endl;
            out << "Thank you!" << endl <<  endl;
           
            if (input.has_exact_change_for_coins(mycoin)) {
                mycoin.extract_exact_change(input);
            } else {
                out << "ERROR: Insufficient Funds" << endl << endl;
          
            }
        } 
		else if (command == 3) {
            out << endl;
            print_cents(mycoin.total_value_in_cents(), out);
			out << endl << endl;
            out << "Thank you!" << endl << endl;

        } 
		else if (command == 4) {
            out << endl;
            break;
        } 
		else {
            out << endl;
            out << "ERROR: Invalid Command" << endl << endl;
        }
    }
}




