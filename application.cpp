#include "application.h"
#include "Sparse_Matrix.h"

//This application replicates an ad targeting algorithm
/*
 Each row is a new day
 Each column is an add category
 Col 1: News
 Col 2: Music
 Col 3: Art
 Col 4: Sports
 Col 5: Medical
 Col 6: Food
 Col 7: Cars
 Col 8: Video Games
 Col 9: Technology
 Col 10: Politics
 Col 11: Movies/Shows
 Col 12: Vacations

 0 1 0 0 5 0 3 0 0 0 1 0
 1 1 0 0 4 0 1 0 0 0 0 0
 0 0 0 1 2 0 0 1 1 0 0 0
 1 0 0 2 0 0 4 0 0 0 0 0
 0 0 0 0 2 0 1 0 0 1 0 1
 0 2 0 1 0 3 0 0 0 4 0 0
 3 0 0 0 1 1 0 0 0 0 3 0



 */

// Displays the home user interface
void Generate_HomeUI(){
    std::cout << "What would you like to do?\n1. Find my most targeted ad for the week\n2. Display file requirements\n6. Exit Application\n";
}

//Displays requirements of input matrix file
void file_reqs(){

std::cout << "Each row is a new day (7 rows for days in a week per file)\nEach column is an ad category(12 in total)\nCol 1: News\nCol 2: Music\nCol 3: Art\nCol 4: Sports\nCol 5: Medical\nCol 6: Food\nCol 7: Cars\nCol 8: Video Games\nCol 9: Technology\nCol 10: Politics\nCol 11: Movies/Shows\nCol 12: Vacations\n\nHere is an example matrix:\n0 1 0 0 5 0 3 0 0 0 1 0\n1 1 0 0 4 0 1 0 0 0 0 0\n0 0 0 1 2 0 0 1 1 0 0 0\n1 0 0 2 0 0 4 0 0 0 0 0\n0 0 0 0 2 0 1 0 0 1 0 1\n0 2 0 1 0 3 0 0 0 4 0 0\n3 0 0 0 1 1 0 0 0 0 3 0\n\n";

}
// Returns a 2d vector of all the file data
std::vector<std::vector<int>> fto2d(std::string fname){
    std::ifstream in_file(fname);
    std::vector<std::vector<int>> data_vector(7, std::vector<int>(12, 0));

    for(int row = 0; row<7; row++){
        for(int col=0; col<12; col++){
            in_file >> data_vector[row][col];
        }
    }

    return data_vector;
}


//Displays ads that will be most commonly displayed from a week of data
void week_target(){
    std::cout << "Enter the file name that stores your 7x12 matrix of visited site categories" << std::endl;

    //Gets file name from user
    std::string fname;
    std::cin >> fname;

    //Converts file data to a 2d vector
    std::vector<std::vector<int>> data = fto2d(fname);

    //Creates sparse matrix from the data
    Sparse_Matrix week = Sparse_Matrix(data);

    // Categories vector
    std::vector<std::string> cats = {"News","Music","Art","Sports","Medical","Food","Cars","Video Games","Technology","Politics","Movies/Shows","Vacations"};

    // Empty vector to hold cumulative scores for each category
    std::vector<int> visits = std::vector<int>(12, 0);

    //Starts at the head node
    Node* current_node = week.getHead();

    //Adds all values to the visits vector
    while(current_node != nullptr){
        visits[current_node->getCol()] += current_node->getVal();
        current_node = current_node->getNext();
    }

    //Finds category with most visits
    int most_index=0;
    for(int i=0; i<visits.size(); i++){
        if(visits[i]>visits[most_index]){
            most_index = i;
        }
    }

    //Displays results
    std::cout << "You would be most commonly targeted with ads related to " << cats[most_index-1] << "\n\n";

}

//Handles the users choice from the home menu
void Home_Input_Handler(int choice){
    if(choice == 1){
        week_target();
    }
    else if(choice == 2){
        file_reqs();
    }

}




int main(int argc, char* argv[]) {
    std::cout << "Welcome to our ad targeting application!\n";

    int choice;
    while(choice != 6){
        Generate_HomeUI();
        std::cin >> choice;
        Home_Input_Handler(choice);
    }
    std::cout << "Thank you for trying our application!";
}