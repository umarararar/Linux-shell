#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{

    char exitC[] = "exit";

    do
    {
        char arguments[200];

        cout << "Enter your arguments: ";
        cin.getline(arguments, 200,'\n');

        cout << "\nEntered command is: " << arguments << endl;

        if (strcmp(arguments, exitC) == 0)           //exiting if user enter exit
        {
            cout << "---Exited---";
            // break;
            return 0;
        }

        char *array[10];
        int i = 0;
        array[i] = strtok(arguments, " ");             //tokenizing the string entered by user

        while (array[i] != NULL)
        {

            array[++i] = strtok(NULL, " ");                //tokenize on spaces
        }
      //  cout << "\n\nAfter tokenization:\n";
        for (int j = 0; j < j; j++)
        {

            cout << array[j] << endl;
        }
       // array[9] = NULL;

        int pid = fork();
      //  cout << "\n\nPID: " << pid << endl;
        if (pid == 0)
        {
            execvp(array[0], array);                  //running execvp in child process
            exit(0);
        }
        else if (pid == -1)             //if fork fails
        {

            cout << "\nFork failed!\n";
        }
        if (pid > 0)                //parent process
        {
           wait(NULL);
        }
    } while (1);
}
