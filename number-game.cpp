#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;
void print_guess(int, vector <int>);
int main()
{
    vector <int> hist_vect, int_vect, user_vect, user_arr_temp, int_arr_temp;
    int start_count = 0, digit = 0, user_int, place_count, occ_count;
    int num;
    char yorn;
    cout << "Logic based number placement game\n\n";
    init:
    hist_vect.clear(); int_vect.clear(); user_vect.clear(); user_arr_temp.clear(); int_arr_temp.clear();
    start_count = digit = user_int = place_count = occ_count = num = 0;
    yorn = '\0';

    cout << "Enter the number of digits : ";
    cin >> num;
    srand(time(0));
    for(int i=0; i<num; i++)
    {  
        int push = rand() % 10;
        if(push == 0)
        {
            push += 2;
        }
        int_vect.push_back(push);
        //cout << int_vect[i] ;
    }
    start:
    start_count++;
    cout << "\n\nEnter " << num << " digit number : ";
    cin >> user_int;
    int temp1 = user_int, temp2 = user_int;
    digit = 0;
    while(temp1)
    {
        digit++;
        temp1 = temp1/10;
    }
    if(digit == num)
    {
        hist_vect.push_back(user_int);
    }
    else
    {
        cout << " x x x -- Enter "<< num <<" digit  -- x x x \n";
        goto start;
    }
    //change to vector
    {
        int temp = user_int;
        for(int i=0; i < num; i++)
        {
            user_vect.push_back(i);
        }
        for(int i=(num - 1); i>=0; --i)
        {
            user_vect[i] = temp % 10;
            temp = temp / 10;
        }

    }
    place_count = 0; occ_count = 0;
    //check count of places
    {
        for(int i=0; i < num; i++)
        {
            if(int_vect[i] == user_vect[i])
            {
                place_count++;
            }
        }
    }
    hist_vect.push_back(place_count);

    //check for occurances
    {
        for(int i = 0; i < num ;i++)
        {
            for(int j = 0; j < num ;j++)
            {
                if(int_vect[i] == user_vect[j])
                {
                    occ_count++;
                    user_vect[j] = 0;
                    break;
                }
            }
        }
    }
    hist_vect.push_back(occ_count);
    if(place_count == num)
    {
        print_guess(start_count, hist_vect);
        cout << "\nCorrect\n";
        cout << "Want to play again (y/n)? ";
        cin >> yorn;
        if (yorn == 'y')
        {
            goto init;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        print_guess(start_count, hist_vect);
        goto start;
    }
    return 0;
}

void print_guess(int start_count, vector <int> hist_vect)
{
    if(start_count)
    {
        cout << "\n  Guess  Correct Placement - Digits present";
        for (auto i = hist_vect.begin(); i != hist_vect.end(); ++i) 
        {
            cout << "\n   " << *i;
            ++i;
            cout << "       " << *i;
            ++i;
            cout << " - " << *i;
        }
    }
}