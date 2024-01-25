#include <iostream>
#include "coins.hpp"

using namespace std;


int main()
{
    Coins piggyBank = Coins(50, 50, 50, 50);
    Coins pocket = Coins(8, 3, 6, 8);

    cout << "Initial piggy bank: " << piggyBank << endl;
    cout << "Initial pocket: " << pocket << endl << endl;




	cout << "Bought chips using pocket" << endl;
    cout << "Coins required for chips: " << coins_required_for_cents(149) << endl;
    Coins chips = pocket.extract_exact_change(coins_required_for_cents(149));
    cout << "Pocket after paying for chips: " << pocket << endl;
    cout << endl;

    cout << "Transferring money to pocket" << endl;
    Coins transfer = piggyBank.extract_exact_change(coins_required_for_cents(405));
    cout << "Coins for transfer: " << transfer << endl;
    pocket.deposit_coins(transfer);
    cout << "Pocket: " << pocket << endl;
    cout << "Piggy bank: " << piggyBank << endl;
    cout << endl;



    cout << "Transferring sofa change to piggy bank" << endl;
    Coins sofa = Coins(10, 10, 10, 10);
    piggyBank.deposit_coins(sofa);
    cout << "Sofa: " << sofa << endl;
    cout << "Piggy bank: " << piggyBank << endl << endl;


    cout << "Piggy bank total: ";
    print_cents(piggyBank.total_value_in_cents(), cout);


}
