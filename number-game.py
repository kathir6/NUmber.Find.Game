
using namespace std;

int main()
{
    vector <int> hist_vect, int_vect, user_vect, user_arr_temp, int_arr_temp;
    int start_count = 0, digit = 0, user_int, place_count, occ_count;
    int num;
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
    //cout <<  "\n\n\n\n\n\n\n\n\n\n\n";
    start:
    if(start_count)
    {
        for (auto i = hist_vect.begin(); i != hist_vect.end(); ++i) 
        {
            cout << "\n   " << *i;
            ++i;
            cout << "   " << *i;
            ++i;
            cout << "-" << *i;
        }
    }

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
        cout << " x x x -- Enter four digit  -- x x x \n";
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
    //cout << "Place count : " << place_count << "\n";
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
                   // cout << "\n" << i << "--"<< int_vect[i] << " "<< j << "--" << user_vect[j] << "\n";
                    user_vect[j] = 0;
                    break;
                }
            }
        }
   // cout << "Occurance count : " << occ_count << "\n";
    }
    hist_vect.push_back(occ_count);
    if(place_count == num)
    {
        cout << "Correct\n";
    }
    else
    {
        goto start;
    }
    return 0;
}
