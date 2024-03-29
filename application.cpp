#include "Sparse_Matrix.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

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
void generate_home_ui(){
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "1. Find my most targeted ad for the week" << std::endl;
    std::cout << "2. Find my most targeted ad for multiple weeks" << std::endl;
    std::cout << "3. Find percent chance of receiving an ad of a given category" << std::endl;
    std::cout << "4. Display file requirements" << std::endl;
    std::cout << "5. Exit Application" << std::endl;
}

//Displays requirements of input matrix file
void file_reqs(){

std::cout << "Each row is a new day (7 rows for days in a week per file)\nEach column is an ad category(12 in total)\nCol 1: News\nCol 2: Music\nCol 3: Art\nCol 4: Sports\nCol 5: Medical\nCol 6: Food\nCol 7: Cars\nCol 8: Video Games\nCol 9: Technology\nCol 10: Politics\nCol 11: Movies/Shows\nCol 12: Vacations\n\nHere is an example matrix:\n0 1 0 0 5 0 3 0 0 0 1 0\n1 1 0 0 4 0 1 0 0 0 0 0\n0 0 0 1 2 0 0 1 1 0 0 0\n1 0 0 2 0 0 4 0 0 0 0 0\n0 0 0 0 2 0 1 0 0 1 0 1\n0 2 0 1 0 3 0 0 0 4 0 0\n3 0 0 0 1 1 0 0 0 0 3 0\n\n";

}

// Returns a 2d vector of all the file data
std::vector<std::vector<int>> fto2d(std::string fname){
    std::ifstream in_file(fname);

    while (!in_file) {
        std::cout << "File does not exist. Please enter a valid file name." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> fname;
        in_file.open(fname);
    }

    std::vector<std::vector<int>> data_vector(7, std::vector<int>(12, 0));

    for(int row = 0; row<7; row++){
        for(int col=0; col<12; col++){
            in_file >> data_vector[row][col];
        }
    }

    in_file.close();

    return data_vector;
}


//Displays ads that will be most commonly displayed from a week of data
void week_target() {
    std::cout << "Enter the file name that stores your 7x12 matrix of visited site categories" << std::endl;

    //Gets file name from user
    std::string fname;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> fname;

    //Converts file data to a 2d vector
    std::vector<std::vector<int>> data = fto2d(fname);

    //Creates sparse matrix from the data
    Sparse_Matrix week(data);


    // Categories vector
    std::vector<std::string> cats = {"News","Music","Art","Sports","Medical","Food","Cars","Video Games","Technology","Politics","Movies/Shows","Vacations"};

    // Empty vector to hold cumulative scores for each category
    std::vector<int> visits = std::vector<int>(12, 0);

    //Starts at the head node
    Node* current_node = week.get_head();

    //Adds all values to the visits vector
    while(current_node != nullptr){
        visits[current_node->get_col()] += current_node->get_val();
        current_node = current_node->get_next();
    }

    //Finds category with most visits
    int most_index=0;
    for(int i=0; i<visits.size(); i++){
        if(visits[i]>visits[most_index]){
            most_index = i;
        }
    }

    //Displays results
    std::cout << "You would be most commonly targeted with ads related to " << cats[most_index] << " this week.\n\n";

}

//Displays ads that will be most commonly displayed from a week of data
void mult_weeks_target(){

    //Gets amount of weeks to be added together from user
    std::cout << "Enter the amount of weeks you would like to analyze:" << std::endl;
    int num_weeks = 0;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> num_weeks;

    //Creates initial empty sparse matrix of zeros
    Sparse_Matrix result_matrix =  Sparse_Matrix();



    for(int i=0; i<num_weeks; i++){
        std::cout << "\nEnter the file name that stores your 7x12 matrix of visited site categories" << std::endl;

        //Gets file name from user
        std::string fname;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> fname;

        //Converts file data to a 2d vector
        std::vector<std::vector<int>> data = fto2d(fname);

        //Creates sparse matrix from the data
        Sparse_Matrix week = Sparse_Matrix(data);

        //Adds current week data to result matrix using matrix division
        result_matrix = week.add(result_matrix);
    }

    // Categories vector
    std::vector<std::string> cats = {"News","Music","Art","Sports","Medical","Food","Cars","Video Games","Technology","Politics","Movies/Shows","Vacations"};

    // Empty vector to hold cumulative scores for each category
    std::vector<int> visits = std::vector<int>(12, 0);

    //Starts at the head node
    Node* current_node = result_matrix.get_head();

    //Adds all values to the visits vector
    while(current_node != nullptr){
        visits[current_node->get_col()] += current_node->get_val();
        current_node = current_node->get_next();
    }

    //Finds category with most visits
    int most_index=0;
    for(int i=0; i<visits.size(); i++){
        if(visits[i]>visits[most_index]){
            most_index = i;
        }
    }

    //Displays results
    std::cout << "You would be most commonly targeted with ads related to " << cats[most_index] << " over these " << num_weeks << " weeks.\n\n";

}

//Create Method to determine relative frequency of each category
void weighted_target(){

//Gets amount of weeks to be averaged to find the frequency
    std::cout << "Enter the amount of weeks you would like to analyze:" << std::endl;
    int num_weeks = 0;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> num_weeks;
    float total = 0.0;
    //empty vector for each of the ad categories
    std::vector<int> VCount = std::vector<int>(12, 0);

    //loops through each week given
    for(int i=0; i<num_weeks; i++){

        std::cout << "\nInput the name of the file that stores your 7x12 matrix of visited ad site categories" << std::endl;

        //Gets file name from user
        std::string fname;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> fname;

        //turns file data into a 2d vector
        std::vector<std::vector<int>> data = fto2d(fname);

        //uses the data to create a sparse matrix
        Sparse_Matrix week = Sparse_Matrix(data);

        Node* temp_node = week.get_head();

        while(temp_node != nullptr){
            VCount[temp_node->get_col()] += temp_node->get_val();
            total += temp_node->get_val();
            temp_node = temp_node->get_next();
        }
    }

    for(int j = 0; j < 12; j++){
        VCount[j] = floor((VCount[j] / total)*100);
    }

    //display results
    std::cout << "\nThe percent chance of each subject appearing is as follows:" << std::endl;

    std::cout << "\nNews: " << VCount[0] << "\nMusic: " << VCount[1] << "\nArt: " << VCount[2]
              << "\nSports: " << VCount[3] << "\nMedical: " << VCount[4] << "\nFood: " << VCount[5]
              << "\nCars: " << VCount[6] << "\nVideo Games: " << VCount[7] << "\nTechnology: " << VCount[8]
              << "\nPolitics: " << VCount[9] << "\nMovies/Shows: " << VCount[10] << "\nVacations: " << VCount[11] << "\n\n" << std::endl;

};

//Handles the users choice from the home menu
void home_input_handler(int choice){
    if(choice == 1){
        week_target();
    }
    else if(choice == 2){
        mult_weeks_target();
    }
    else if(choice == 3){
        weighted_target();
    }
    else if(choice == 4){
        file_reqs();
    }
    else if (choice == 5) {
		return;
	}
    else{
        std::cout << "Invalid choice, try again.\n" << std::endl;
    }

}


int main(int argc, char* argv[]) {
    std::cout << "Welcome to our ad targeting application!\n";

    int choice = -1;
    while(choice != 5){
        generate_home_ui();
        std::cin >> choice;
        home_input_handler(choice);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Thank you for trying our application!";
}