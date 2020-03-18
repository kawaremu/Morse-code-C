void fromMorsetoSound(char* MorseCode);
char* fromTexttoMorse(char inputChar);
void DASHsound();
int hashIndex(char caractere);
void DOTsound();
void printMorse(char *code[]);
void Jump();
void Space();
void Test();
void StartConvertingTexttoMorse();
void goodbye();
char getOptionOfmenu();
void getInput(char *input);
void DOYOURWORK(char* UserInput);

typedef struct node{
    char morse[10];
    struct node *next;
} node;

typedef node* listMorse;

listMorse newNode(char input);
listMorse newList();
void printList(listMorse head);
listMorse toMorse(char* readable);

void addMorseCode(listMorse *head,char input);
listMorse newList();
