# DSA
Group Members: James Allen, Benjamin Corriveau, Grant Garcia, and Connor Stubbs

Summary: This project is an interactive application, written in C++, that allows users to interact with sparse matrices to view information about advertisements that will be shown to them based on their previous online activity. In order to do this, sparse matrices are used to store data on how many times the user interacted with content in the given category, and is tracked across one week per sparse matrix.

Planning: 
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

Compilation Instructions:
In order to compile the program, you must have the GNU C++ compiler installed on your machine. If you do not have it installed, you can download it here: https://gcc.gnu.org/install/binaries.html

1.) Download the repository to your machine.

2.) Open a terminal window and navigate to the directory where you downloaded the repository.

3.) Type "g++ application.cpp Sparse_Matrix.cpp -o application.out" into the terminal window and press enter. This will create a file called "application.out" that can be run from the terminal to access the application.

4.) Type "application.out" into the terminal window and press enter.

Runtime Instructions:
1.) Once you have properly compiled and launched the program from the terminal, you are ready to interact with the application to view information about advertisements that will be shown to you based on your previous online activity. You will be presented with a menu where you can enter an integer from 1-__ to choose an option. The options are as follows:
	1: Displays the user's most targeted advertisement of the week.
	2: Displays the user's most targeted advertisement across several (number determined by user) weeks.
	3: Displays the requirements that input files must meet in order to be used by the application.
	4: Displays the likelihood that the user will be presented an advertisement of each category.
	5: Exits the application