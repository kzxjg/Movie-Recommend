#include <iostream>   
#include <string>       
#include <algorithm>  
#include "Database.h"
#include <fstream>


class Menu {
  public:
  void menu(){
  string A = "1. Add a movie\n";
  string B = "2. Delete a movie\n";
  string C = "3. Show the movies\n";
  string D = "4. Search for a movie\n";
  string E = "5. Quit\n";
  int data_choice;
  Database d;
  d.read_in();

  cout << A;
  cout << B;
  cout << C;
  cout << D;
  cout << E;

  cin >> data_choice;
  while(data_choice == 1 || data_choice == 2|| data_choice == 3|| data_choice == 4){
    
    if(data_choice == 1){
      d.add_record();
      cout << A;
      cout << B;
      cout << C;
      cout << D;
      cout << E;
      cin >> data_choice;
    }

    if(data_choice == 2){
      d.delete_record();
      cout << A;
      cout << B;
      cout << C;
      cout << D;
      cout << E;
      cin >> data_choice;
    }

    if(data_choice == 3){
      d.list_record();
      cout << A;
      cout << B;
      cout << C;
      cout << D;
      cout << E;
      cin >> data_choice;
    }

    if(data_choice == 4){
      d.search_movie();
      cout << A;
      cout << B;
      cout << C;
      cout << D;
      cout << E;
      cin >> data_choice;
    }

    if(data_choice == 5){
      d.handle_save();
    }
  }
}
};