# DSA
Group Members: James Allen, Benjamin Corriveau, Grant Garcia, and Connor Stubbs

# Summary: 

This project is an interactive application, written in C++, that allows users to interact with sparse matrices to view information about advertisements that will be shown to them based on their previous online activity. In order to do this, sparse matrices are used to store data on how many times the user interacted with content in the given category, and is tracked across one week per sparse matrix.

# Planning: 

1.) Write the scaffolding for the application (Node.cpp, Node.h, Sparse_Matrix.cpp, Sparse_Matrix.h, and application.cpp).

	a.) Node.cpp and Node.h will be used to create the nodes that will be used to create the sparse matrices (our implementation utilizes linked lists to represent sparse matrices).
		
		i.) We will need three constructors for the Node class: one that has no parameters, one that takes in a row, column, and value, one that takes in a row, column, value, and pointer to the next node.
		
		ii.) We may need several get functions in order to access the private variables of the Node class within our application.cpp file.
	
	b.) Sparse_Matrix.cpp and Sparse_Matrix.h will be used to create the sparse matrices that will be used to store the data on the user's online activity.
		
		i.) We will need two constructors for the Sparse_Matrix class: one that has no parameters and one that takes in a vector of vectors containing integers.
		
		ii.) We need to implement methods that allow us to add and multiply two sparse matrices together.
		
		iii.) We need to implement methods that allow us to display the sparse matrices in a readable format.
		
		iv.) We need to implement a method that allows us to insert a new node into the sparse matrix.
		
		v.) We may need several get functions in order to access the private variables of the Sparse_Matrix class within our application.cpp file.
	
	c.) application.cpp will be used to create the application that will allow users to interact with the sparse matrices.
		
		i.) We will need to create functions that provide a user interface for the application.
		
		ii.) We will need to create functions that allow the user to interact with the sparse matrices.
		
		iii.) We will need to create functions that handle the user's input and output.

2.) Assign functions to group members.
	
	a.) James will be in charge of creating the Node class.
	
	b.) Benjamin will be in charge of creating the Sparse_Matrix class.
	
	c.) Grant will be in charge of creating the application class.
	
	d.) Connor will be in charge of creating the application class.

3.) Merge branches to the master branch as needed to ensure that the code is up to date.

4.) Test the application to ensure that it works as intended.

5.) Write compilation and runtime instructions.

# Code Explanation:

## Node Class:

![node_constructors.png](Code%20Snippets%2Fnode_constructors.png)

There are three constructors for the Node class. The first constructor is the default constructor, which sets the row, column, and value to 0 and the next pointer to NULL. The second constructor takes in a row, column, and value and sets the private variables to the values passed in as parameters. The third constructor takes in a row, column, value, and pointer to the next node and sets the private variables to the values passed in as parameters.

![node_helpers.png](..%2F..%2FDownloads%2Fnode_helpers.png)

There are also some small helper functions that simply return either the col, next pointer, or data of a node.

## Sparse Matrix Constructors:

<img width="391" alt="Screenshot 2023-04-18 144935" src="https://user-images.githubusercontent.com/123384354/232885569-aa874028-2921-4ec9-8ae4-7de0d724c2ee.png">

In order to provide the most flexibility with this data structure, we decided that we would implement an empty constructor and a constructor that takes in a 2D vector of ints as a parameter. For the empty constructor, it creates an empty sparse matrix that can then have values inserted into it, while the second constructor pulls all data values that are not 0 from the 2D vector and creates a sparse matrix using that data.

## Sparse Matrix Private Methods:

<img width="418" alt="Screenshot 2023-04-18 151627" src="https://user-images.githubusercontent.com/123384354/232888442-7944d1e7-c66c-4eb2-823c-b482c5211a62.png">

The get_max_row_col method accepts a sparse matrix as a parameter and finds the maximum row and column between the current sparse matrix and the one passed in as an argument. This data is then combined to form a pair, that is returned.

<img width="530" alt="Screenshot 2023-04-18 150654" src="https://user-images.githubusercontent.com/123384354/232889243-92480105-1db2-4fab-a011-c82a5ac5cef3.png">

The private add method creates an empty 2D vector of size max_row by max_col and fills it with 0s. Then, the two sparse matrices (the smaller of the two first) are then iterated through, taking the sum of the current value at the given row and column and the value held in the newly created 2D vector. A similar method is used for the private multiply method, however, the new matrix is created of size first matrix.rows by second matrix.columns. In addition to this, the multiply method multiplies the values in the two matrices if the row and column match, which is then added to the empty matrix.

## Sparse Matrix Public Methods:

<img width="412" alt="Screenshot 2023-04-18 151112" src="https://user-images.githubusercontent.com/123384354/232886242-33fe4f17-05a6-4a3a-8766-2299d820473e.png">

The add method accepts a second sparse matrix as a parameter and will take the sum of the two matrices. It does this by getting the max row and max column of the two sparse matrices (using the private get_max_row_col method), and then passing these values to the private add method, where all of the main logic is housed. This will return a 2D vector that is then used with the second constructor to create a new sparse matrix that is returned. The multiply method operates similarly, but does not find the max row and column of the two sparse matrices.

<img width="567" alt="Screenshot 2023-04-18 151354" src="https://user-images.githubusercontent.com/123384354/232887537-c8eaffd6-4004-4808-9d87-0b6133254ab6.png">

The insert method accepts a row, column, and value and inserts this value into the linked list representation of the sparse matrix based on the row and column of the value to be inserted. This is accomplished according to the way in which nodes are inserted into a linked list. After this is completed, the head and tail are reassigned to the inserted node (if necessary). The print_matrix method iterates through the current matrix and prints all values within the sparse matrix to the console.

## Application Methods:
<img width="504" alt="Screen Shot 2023-04-20 at 5 31 40 PM" src="https://user-images.githubusercontent.com/123471864/233492341-f127a635-6d51-4a3a-a4e3-fcb0d804e38a.png">

<img width="455" alt="home_ui" src="https://user-images.githubusercontent.com/123471864/233492091-91cf7e22-e699-4598-8941-f16e1dd11241.png">

The application begins with the main function which welcomes the user to the application and then starts a while loop that runs until the user inputs 5 to exit the application. Inside of this while loop our generate_home_ui function is called. This function simply outputs the 5 options that the user has to choose from which are finding their most targeted ad for the week, finding their most targeted ad over multiple weeks, finding their most targeted ad in a week based on weights for each category, displaying the file requirements for the sparse matrix input file, and finally to exit the application.

<img width="538" alt="Screen Shot 2023-04-20 at 5 32 55 PM" src="https://user-images.githubusercontent.com/123471864/233492551-28229c15-d314-4b0a-86d2-2dbeef6d6e0e.png">

Next, the user inputs their choice which is passed into our home_input_handler which calls the function that corresponds with the user's choice or prompts the user to try again if they input an option other than 1-5.

<img width="489" alt="fqs" src="https://user-images.githubusercontent.com/123471864/233492789-9e89ab54-7e80-47e1-bc18-394ac60b61a7.png">

A great option for the user to use before using our application is the file requirements choice which calls out function file_reqs. This function prints out the requirements for the users input file which simply states the file must be a 7x12 matrix where the rows are days(7 for a week) and the columns are the 12 categories of websites that we chose for our basic application (Col 1: News, Col 2: Music, Col 3: Art, Col 4: Sports, Col 5: Medical, Col 6: Food, Col 7: Cars, Col 8: Video Games, Col 9: Technology, Col 10: Politics, Col 11: Movies/Shows, and Col 12: Vacations).

<img width="698" alt="fto2d" src="https://user-images.githubusercontent.com/123471864/233492936-c4b13727-c2ca-48af-b4df-c0c06556672a.png">

The function fto2d is a helper function that takes the input file name as a parameter, puts the matrix data into a 2-dimensional vector, and then returns the 2-dimensional vector. This function operates by creating a 7x12 2-dimensional vector filled with zeroes, opening a file stream using the file name, and then adding every corresponding value from the input file to the 2-dimensional vector in a nested for loop. After the entire file is iterated through the 2-dimensional vector is returned. This function is very convenient because it allows for a 2-dimensional vector of the file data to be passed into the Sparse_Matrix constructor.

<img width="1259" alt="Screen Shot 2023-04-20 at 5 38 20 PM" src="https://user-images.githubusercontent.com/123471864/233493366-a6ade3f1-dbbb-4fec-ae96-e380ba2fe9c2.png">

If the user selects choice 1, the week_target function is called. This function begins by asking the user to input the file name that stores their data and then gets a 2-dimensional vector of the data by calling the fto2d helper function. Next, a sparse matrix using linked lists for the week's data is created by passing in the 2-dimensional vector and a vector of the 12 categories named cats is declared. Afterwards, an empty vector with integers set to 0 is declared to hold the number of visits per category and a node pointer is declared to point to the head of our linked list that represents the sparse matrix. A for loop then iterates throughout the entire linked list and adds the values of that pertain to each category to the visits vector. Finally, the greatest number of visits index is found and the ad category that the user would most likely be targeted with due to frequency of visits is printed to the console. 

<img width="1257" alt="Screen Shot 2023-04-20 at 5 40 22 PM" src="https://user-images.githubusercontent.com/123471864/233493618-7a754015-675a-498c-a57e-bc9e070a4f3f.png">
<img width="1230" alt="Screen Shot 2023-04-20 at 5 41 05 PM" src="https://user-images.githubusercontent.com/123471864/233493709-21df1685-b8b4-4fdd-8214-efd7bdf66c55.png">

Similar to the week_target function, is the mult_weeks_target function. This function does practically the same thing as the week_target function except it prompts the user for the number of weeks to be analyzed and then asks the user for the name of input files for however many weeks were previously indicated. All of these values are added to a result matrix and then the most likely to be targeted ad category among all of the weeks is printed to the console. 


# Compilation Instructions:

In order to compile the program, you must have the GNU C++ compiler installed on your machine. If you do not have it installed, you can download it here: https://gcc.gnu.org/install/binaries.html

1.) Download the repository to your machine.

2.) Open a terminal window and navigate to the directory where you downloaded the repository.

3.) Type "g++ application.cpp Sparse_Matrix.cpp Node.cpp -o application.out" into the terminal window and press enter. This will create a file called "application.out" that can be run from the terminal to access the application.

4.) Type "application.out" into the terminal window and press enter.

#Runtime Instructions:

1.) Once you have properly compiled and launched the program from the terminal, you are ready to interact with the application to view information about advertisements that will be shown to you based on your previous online activity. You will be presented with a menu where you can enter an integer from 1-5 to choose an option. The options are as follows:
	
	1: Displays the user's most targeted advertisement of the week.
	
	2: Displays the user's most targeted advertisement across several (number determined by user) weeks.
	
	3: Displays the requirements that input files must meet in order to be used by the application.
	
	4: Displays the likelihood that the user will be presented an advertisement of each category.
	
	5: Exits the application
