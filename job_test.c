
#include <stdio.h>
#include <string.h>//for manipulating strings 
#include <ctype.h> // imported for isdigit() method
#include <stdlib.h> //imported for the exit() function

#define SIZE 100

//Question 3: function to test if user selected a delimiter or not.
int check_delimiter(char *sd) {
  if(sd[0] == '/' && sd[1]== '/' ) {
  //printf("User selected a delimiter\n"); disregard, used to test if the *sd pointer works fine
      return 1;
      } else if(isdigit(sd[0]) || isdigit(sd[1]) || isalpha(sd[0]) || isalpha(sd[1])) {
        printf("Wrong deli format, program closed. Start Again...\n");
        exit(1);
      } else {
        printf("No selected deli, Default delis will be used!\n");
      return 0;
      }
  }

int add(char *numbers, char *sd) {
   int sum = 0;
   char *token;
   char delim[] = "$();'@#,.[]+:{}\\n"; //list of all the default delimiter characters
   char *selected_delim; //the user selected delimiter
   char *selected_delim_holder; ///placeholder for the user selected delimiter
   int input_strlen = strlen(numbers)-2; //gets the length of the input string without '/0'
   char negative_numbers[100] = ""; // string to store the negative numbers for question 4
   int is_negative = 0; // flag to check if there are negative numbers
    
   if(isdigit(numbers[input_strlen])) {
     if(check_delimiter(sd)) { 
      //printf("from add func %c, %c, %c\n", sd[0], sd[1], sd[2]);
      selected_delim = &sd[2];
      selected_delim_holder = &sd[2];
      //printf("from add-function, user selected %c \n", selected_delim[0]);//disregard, for testing purposes
      memset(delim, selected_delim_holder[0], sizeof(delim)); //replaces all delim characters with user selected character
        token = strtok(numbers, selected_delim);
    } 
      else {
        token = strtok(numbers, delim); 
        //printf("Default Delim will be used!!\n"); //disregard, this is for testing purposes
      }
    while (token != NULL) { 
        int number = atoi(token);
        if (number < 0) { 
            is_negative = 1;
            strcat(negative_numbers, token);
            strcat(negative_numbers, ","); 
        } else if (number <= 1000) { 
            sum += number; 
        }
      
      token = strtok(NULL, delim); 
    }
    if (is_negative) {
        negative_numbers[strlen(negative_numbers)-1] = '\0'; 
        printf("Negatives not allowed: %s\n", negative_numbers);
        return 0;
    } 
  }
    else {
      printf("ERROR! Last input is not a number!\n"); 
  }
    return sum;
}

int main() {
    char numbers[SIZE];
    char sd[SIZE];
  
    printf("Format for deli is //[deli]\\n or Just \\n:\n");
    fgets(sd, sizeof(sd), stdin); 
    fgets(numbers, sizeof(numbers), stdin); 
  
    int sum = add(numbers, sd);
    printf("Sum: %d\n", sum); 
    return 0; 
  } 

/*
-------------------------comments--------------------------
1. If no delimiter is inputed on the first line, it uses the list of default delimiters specified on the delim[] string array to sum up all the digits in the second line(second input string)
2. The format for delimiters from my understanding of the question paper is //[delimiter]\n. If this format is not properly followed on the firstline, the default delimiters will also be used.
3. This program also checks to make sure that the last input on the second line is a digit or throws an error message  returning 0 as output.
4. This program meets specification 3 because it allows a user to select a delimiter and also allows the first line to be optional for the user.
5. It meets specification 4 because when a negetive number is included in the string, it rejects and prints the list of negetive numbers with 0 as the sum
6. It also meets specification 5 because when a number is bigger than 1000, it rejects the number and sums only smaller numbers.
7. it meets specification 6. Delimiters of any length.
8. It meets specification 7 and 8. Multiple Delimiters and multiple delimeters of any length are supported but this works only when a specific delimiter is not selected by user. 

*/