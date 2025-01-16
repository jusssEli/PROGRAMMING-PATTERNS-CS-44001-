# PROGRAMMING-PATTERNS-CS-44001-

All of my CS3 Lab work

STL

Lab1:
      Implements a program that compares two text files character-by-character. The program should output the line numbers that contain different characters and          the place where the two lines start to differ. The difference is denoted by ^ (caret) character. If both files are identical, the program should output             nothing.
      
Lab2:
      Implements a program that reads in a text file, counts how many times each word occurs in the file and outputs the words (and counts) in the increasing order       of occurrence, i.e. the counts need to be output in sorted order: rare words first. If the two words have the same number of occurences, the words should be        sorted in alphabetical order.
      
Lab3: 
      Implements add() -- takes an item as the argument and adds it to the collection, does not check for duplicates.
      remove() -- takes an item as the argument and removes all instances of this item from the collection. The removed nodes should be properly deallocated.
      last() -- returns the last item in the collection.
      print() -- prints all items in the collection. The printout does not have to be in order.
      bool equal(const Collection&, const Collection&) : compares two collections for equality. Implemented as a friend function.

Lab4: 
      Lists the classes each student is enrolled in.
      Each student has exactly two names: first and last (no middle names). The course name is the file name without the extension.
      
Lab5:
      Part 1: Same as Lab 4 but implemented with maps and sets
      Part 2: Recoded the roster example so that it prints all the students currently enrolled in at least one course. That is, enrolled in a course and are not in       dropout list
      
Lab6:
      Lemons: use the priority queue container adapter instead of a hand-written loop
      Oranges: uses a multimap instead of vector to store fruit as well as upper_bound(), lower_bound() functions and emplace() to populate the multimap.
      Apples: uses algorithms for_each(), count_if(), accumulate(), transform(), remove_if()
      Peaches: uses algorithms for_each(), count_if(), generate(), transform(), remove_copy_if() with back_inserter(), bind(), accumulate()
      
DESIGN PATTERNS

Lab8: 
      Part 1: Implements inserting text into a file using Singleton design pattern
      Part 2: Add a game of Dice where two players try to get the higher score by rolling five dice up to three times. A single dice roll should be a random number       from 1-6. Thus, the minimum score is 5 and the maximum is 30. The first player is the computer. The computer randomly selects whether to roll again or pass         and keep the score. The second player is human. The program should print the round number, the outcome of the round (for both human and computer) and ask           whether the human wants to roll again or pass. The game ends either after three moves (rounds) or when both players decide to pass and keep the score.
      
Lab9:
      Part 1: The car buyers may now request a particular model as well as the make of a car (randomly selected). The dealer lot may hold up to 8 cars on his car           lot. Initially, the lot contains 8 random cars. The buyer tries cars until he finds the one he likes (Ford or Toyota of particular model). The buyer then           buys this car. If the buyer does not find the car he likes, he goes away (the function terminates). The dealer requests another car from a random factory           to replace the one purchased.
      Part 2: The border and the inside of the figure can be painted with two different characters. Specifically, base class Fill should contain two characters:            one for border paint, one for internal paint. The constructor for this class should now accept two characters to be assigned to the two member variables.

Lab10:
      Part 1: Added the following functions to LegacyRectangle class:
        void move(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) //implements generic repositioning and resizing of the figure;
        getTopLeftX(), getTopLeftY(), getBottomRightX(), getBottomRightY() //return the respective corner coordinates.
        int size() //returns the current square size;
        void resize(int newSize) //changes the size of the figure by moving its bottom right corner.
      Part 2: Using State Design Pattern, implements Process class that provides an interface to the three state process model of operating system scheduler                implementation. If the transition is not in the appropriate state, for example if Dispatch is invoked on a process that is in running state, no action              should be taken (no state transition should occur).
      Part 3: Uses Prototype Design Pattern to create a new process. That is, the new process should be cloned from the prototype. The prototype should be in ready         state of the three state process model above.
        Implements a process ready and blocked queue as follows. Uses STL queue of processes. The first process in the queue is in running state, the rest are in           ready. Randomly (with probability of 33% for each case), the running process may either exit, be suspended, or be blocked
        In case of exiting, the process is destroyed.
        In case of suspension, the process becomes ready and moves to the tail of the ready queue.
        In case of blocking, the process moves to the tail of blocked queue and becomes blocked. With a certain probability, the head process from the blocked              queue moves to the ready queue and becomes ready again.

