# Banker's Algorithim
Bankers Algorithim implementation for Operating Systems Class.
11/20/2022
Chris

#Implementation
A file, data.txt, holds the data to be analyzed in the form:
Process count, Resource count
required allocation count for each resource of each process
max count for each resource of each process
available count for each resource
These are entered in the form P0(ABC) P1(ABC) etc.
These are then read into the programs matrices.
The program then tests every possible combination, terminating its attempt when the required memory would no longer be present. 
Once it tries every combination, it checks if it was unsuccessful then prints out the order of the most recently attempted sequence if it succeeded.
If no sequences are found, it informs you that no safe sequences exist.

# Usage
In the code, the debug boolean can be turned on / off to show some functions as they execute.
data.txt must be in the same directory as the cpp file.
Compile with g++ BankerAlgorithim.cpp -o banker
Run with ./banker

# Output Example
Ran with numbers from assingment document with debug enabled:
![image](https://user-images.githubusercontent.com/84880331/202955659-e698c666-936e-46fb-9f70-e0b5260d0ba5.png)

Displays process count, resource count, imported matrices, the safe sequence checker, and finally the result.
Running with debug off [default] only displays the safe sequence, like this:
![image](https://user-images.githubusercontent.com/84880331/202959770-83bdd589-6c23-4fa1-abbb-957feb2a0b2a.png)

