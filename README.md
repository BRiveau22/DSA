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
