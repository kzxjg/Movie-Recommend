#include <iostream>   
#include <string>       
#include "movie.h"
#include <fstream>
#include <sstream>

using namespace std;

class Database{
  private:
  movie* data;
  int size;
  int cap;

  public:
  Database(){
    size = 0;
    cap = 100;
    data = new movie[cap];
  }
  ~Database(){delete[] data;}

  void handle_save(){
    ofstream fout("database.txt");
    int empty = 0;
    for(int i = 0; i<size; i++){
      if (data[i].name == ""){
        empty++;
      } 
      else {
        fout << data[i].name  << "," << data[i].genre << "," << data[i].year << "\n";
        cout << data[i].name  << "," << data[i].genre << "," << data[i].year << "\n";
      }
    }
    size = size - empty;
  }



  void read_in(){
    ifstream fin("database.txt");
    string name; 
    string genre;
    int year;
    string new_data;
    while(getline(fin,new_data)){
      stringstream ss(new_data);
      string name, genre;
      string year;
      getline(ss,name,',');
      getline(ss,genre,',');
      getline(ss,year,',');
      movie m = movie(name, genre, stoi(year));
      data[size] = m;
      size++;
      }
  }

  //Add record 
  void add_record(){
    string name; string genre; int year;
    cout << "Enter a name\n";
    cin.ignore();
    getline(cin, name);
    cout << "Enter a genre\n";
    getline(cin, genre);
    cout << "Enter a year\n";
    cin >> year;

    while(year < 1900 || year>2022 || isdigit(year)){
      cin.clear();
      cin.ignore();
      cin >> year;
    }

    for(int i = 0; i<size; i++){
      if(data[i].name == name && data[i].genre == genre && data[i].year == year){
        cout << "That Movie is Already in the database";
        break;
      }
      else{
        movie m = movie(name, genre, year);
        data[size] = m;
        cout << "Added to the database\n";
        size = size + 1;
        break;
      }
    }
  }

  //Deletes a movie
  void delete_record(){
    cout << "Enter the movie you want to delete\n";
    string moviename;
    cin.ignore();
    getline(cin, moviename);
    cout << "Are you sure you want to delete this movie (y/n)\n";
    string reply; 
    cin >> reply;
    int found = 0;
    if(reply == "y" || reply == "Y"){
      for(int i = 0; i<size; i++){
        if(data[i].name == moviename){
          data[i].name = "";
          found++;
        }
        else if(!(data[i].name.find(moviename))){
          data[i].name = "";
          found++;
        }    
      }
      //Wasnt clear on what the other two instruction were asking me to do 
      if(found == 0){
        cout << "Sorry, that movie was not in our database\n";
      } 
    }
  }


  //Searches for a movie
  void search_movie(){
    string name; string genre; int year;
    string reply;
    cout << "(N)ame of the movie\n";
    cout << "(G)enre of the movie\n";
    cout << "(Y)ear that the movie was released\n";
    cout << "(R)eturn to menu\n";
    cin >> reply;

    while(reply == "R" || reply == "r"){
      cout << "(N)ame of the movie\n";
      cout << "(G)enre of the movie\n";
      cout << "(Y)ear that the movie was released\n";
      cout << "(R)eturn to menu\n";
      cin >> reply;
    }
    if(reply == "N" || reply == "n"){
      cout << "Enter a name\n";
      cin.ignore();
      getline(cin, name);
      for(int i = 0; i< size; i++){
        if(data[i].name == name || !(data[i].name.find(name))){ 
          string new_mov;
          new_mov += data[i].name;
			    new_mov += ",";
			    new_mov += data[i].genre;
			    new_mov += ",";
			    new_mov += to_string(data[i].year);
          cout << new_mov << "\n";
        }
      }
    }

    else if(reply == "G" || reply == "g"){
      cout << "Enter a Genre\n";
      cin.ignore();
      getline(cin, genre);
      for(int i = 0; i< size; i++){
        if(data[i].genre == genre){ 
          string new_mov;
          new_mov += data[i].name;
			    new_mov += ",";
			    new_mov += data[i].genre;
			    new_mov += ",";
			    new_mov += to_string(data[i].year);
          cout << new_mov << "\n";
        }
      }
    }

    else if(reply == "Y" || reply == "y"){
      cout << "Enter the year\n";
      cin >> year;
      for(int i = 0; i<size; i++){
        if(data[i].year == year){
          string new_mov;
          new_mov += data[i].name;
			    new_mov += ",";
			    new_mov += data[i].genre;
			    new_mov += ",";
			    new_mov += to_string(data[i].year);
          cout << new_mov << "\n";
        }
      }
    }
    else{
      cout << "Sorry, we could not find that movie int the database";
    }
  }


  
  //Sorting movies
  void list_record(){
    cout << "1.List the record in ascending order\n";
    cout << "2.List the record in decending order\n";
    cout << "3.List the record in alphabetical order\n";
    cout << "4.List the record in descending alphabetical order\n";
    int reply;
    cin >> reply;
    if(reply == 1){
      string temp;
      string temp2;
      int temp3;
      for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
          if(data[i].year < data[j].year){
            temp = data[i].name;
            data[i].name = data[j].name;
            data[j].name = temp;
            temp2 = data[i].genre;
            data[i].genre = data[j].genre;
            data[j].genre = temp2;
            temp3 = data[i].year;
            data[i].year = data[j].year;
            data[j].year = temp3;
          }        
        }
      }
      for(int i = 0; i<size; i++){
        cout << data[i].name << "," << data[i].genre << "," << data[i].year<<"\n";
      }
    }
    if(reply == 2){
      string temp;
      string temp2;
      int temp3;
      for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
          if(data[i].year > data[j].year){
            temp = data[i].name;
            data[i].name = data[j].name;
            data[j].name = temp;
            temp2 = data[i].genre;
            data[i].genre = data[j].genre;
            data[j].genre = temp2;
            temp3 = data[i].year;
            data[i].year = data[j].year;
            data[j].year = temp3;
          }        
        }
      }
      for(int i = 0; i<size; i++){
        cout << data[i].name << "," << data[i].genre << "," << data[i].year<<"\n";
      }
    }
    if(reply == 3){
      string temp;
      string temp2;
      int temp3;
      for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
          if(data[i].name < data[j].name){
            temp = data[i].name;
            data[i].name = data[j].name;
            data[j].name = temp;
            temp2 = data[i].genre;
            data[i].genre = data[j].genre;
            data[j].genre = temp2;
            temp3 = data[i].year;
            data[i].year = data[j].year;
            data[j].year = temp3;
          }        
        }
      }
      for(int i = 0; i<size; i++){
        cout << data[i].name << "," << data[i].genre << "," << data[i].year<<"\n";
      }
    }
    if(reply == 4){
      string temp;
      string temp2;
      int temp3;
      for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
          if(data[i].name > data[j].name){
            temp = data[i].name;
            data[i].name = data[j].name;
            data[j].name = temp;
            temp2 = data[i].genre;
            data[i].genre = data[j].genre;
            data[j].genre = temp2;
            temp3 = data[i].year;
            data[i].year = data[j].year;
            data[j].year = temp3;
          }        
        }
      }
      for(int i = 0; i<size; i++){
        cout << data[i].name << "," << data[i].genre << "," << data[i].year<<"\n";
      }
    }
  }
};

//Citation 
//https://www.geeksforgeeks.org/bubble-sort/
//https://stackoverflow.com/questions/35974402/reading-getline-from-cin-into-a-stringstream-c
