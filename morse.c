#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "morse.h"
#define frequency 3654.85
#define DASH 536.75          //570
#define DOT 145.5        //170
#define dotSign '.'
#define dashSign '-'
#define rest 100



char *alphabet;

char *Morse[26] = {"·−" ,"−···","−·−·","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",
".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

void Jump(){
  printf("\n");
}
void Space(){
  printf("               ");
}

void Alphabet(){
  char c; int i = 0;
  alphabet = (char*)malloc(26*sizeof(char));
  for(c = 'A'; c <= 'Z';c++) alphabet[c] = c;
}

void printMorse(char *code[]){
  for(int i =0 ;i < 26 ;i++) printf(" %s |",code[i]);
}

void timePause(){
  Sleep(rest);
}

void DOTsound(){
Beep(frequency,DOT);
}

void DASHsound(){
Beep(frequency,DASH);
}


int hashIndex(char caractere){
  return toupper(caractere) - 65;
}

char* fromTexttoMorse(char inputChar)
{
char* empty = "  ";
if(inputChar == ' ') return empty;
else return Morse[hashIndex(inputChar)];
}

void fromMorsetoSound(char* MorseCode){
  while(*MorseCode != '\0'){
      if ( *MorseCode == dotSign) DOTsound();
      if ( *MorseCode == dashSign) DASHsound();
      else timePause();
      MorseCode++;
  }
}

typedef struct node{
    char morse[10];
    struct node *next;
} node;

typedef node* listMorse;

listMorse newNode(char input)
{
   listMorse newnode = (node*)malloc(sizeof(node));
   char *temp = fromTexttoMorse(input);
   strcpy(newnode->morse,temp);
   newnode->next = NULL;
   return newnode;
}

listMorse newList(){
  return NULL;
}

void addMorseCode(listMorse *head,char input){
  listMorse curr = *head;
  listMorse temp = newNode(input);

  if(*head == NULL) *head = temp;
  else
    {
            while(curr->next != NULL)
            {
              curr = curr->next;
            }
            curr->next = temp;
  }
}


listMorse toMorse(char* readable)
{
      listMorse L = newList();
      int length = strlen(readable);

      for(int i = 0;i < length;i++)
      {
       addMorseCode(&L,readable[i]);

      }
     return L;
}

void printList(listMorse head){
    Space();
    while(head){
      printf("%s",head->morse);
      head = head->next;
    }
}

void DOYOURWORK(char* UserInput){
  listMorse giveBack = newList(),copy;
  giveBack = toMorse(UserInput);
  Jump();Space();puts("Equivalent in morse code :");Jump();printList(giveBack);
  copy = giveBack;
  Space(); puts("Get ready to hear it in 3 seconds.");  Sleep(3000);
  while(copy != NULL){
    fromMorsetoSound(copy->morse);
    copy = copy->next;
  }

}

void getInput(char *input){
  gets(input);
}

char getOptionOfmenu()
{
    char c = 0;
    Space(); c = getchar();
    while(getchar() != '\n');
    return c;
}
void goodbye(){
Sleep(1000); Space(); puts("Thank you for testing the beta version of this simple converter."); Jump(); Sleep(1000);
Space(); puts("Ahlame.Not All Rights,reserved.");
Sleep(200); exit(0);
}

void StartConvertingTexttoMorse(){
char userInput[1000];
Space();getInput(userInput);
Space(); puts("System processing..."); Sleep(2000);
DOYOURWORK(userInput);
goodbye();

}


void Test(){
    printf("      ==========================================================\n");
    Jump();
    Jump();
    printf("                 **WELCOME TO THE MORSE-CODE CONVERTER**          \n");
    Jump();
    Jump();
    printf("            1.Convert from Text   -> Morse                        \n");
    //printf("            2.Convert from Morse  -> Text                         \n");
    printf("            2.Quit the converter                                  \n");
    printf("        ==========================================================\n");
    printf("        Please choose an option:                                  \n");

    char optionChosen;
    optionChosen = getOptionOfmenu();
    Space();puts("Please wait... System processing."); Jump();
    Sleep(3000);
    system("cls");

    switch(optionChosen)
    {
    case '1':
        Space();
        printf("You're converting from Text to Morse."); Jump(); system("cls"); Sleep(300);
        Space();puts("You are going to see your message converted into morse and hear it."); Jump();Sleep(2000);
        Space();puts("Make sure your speakers are on."); Sleep(100);Jump();
        Space(); puts("Enter the message you would like to convert to morse:"); Sleep(200);
        StartConvertingTexttoMorse();
        break;
    // case '2':
    //     Space();
    //     printf("You're converting from Morse to Text,this is still being developped."); Jump();
    //     exit(0);
    //     break;
    case '2':
        Space();
        printf("Thank you for trying my beta converter. Hope to see you soon.");
        exit(0);
    default:
        Space();
        printf("Thank you for trying my beta converter. Hope to see you soon.");
        exit(0);
    }
}