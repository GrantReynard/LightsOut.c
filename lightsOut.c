#include <stdio.h>

#define HOUSE_WIDTH   69
#define HOUSE_HEIGHT  26
#define WINDOW_WIDTH  11
#define WINDOW_HEIGHT  3
/* Reads from the input buffer.
 *
 * This is necessary because scanf() misbehaves inside of
 * looping constructs.
 *
 * Parameters:
 *   val -- pointer to memory storing input value
 *
 * Returns:
 *   0 if input is more than one character or non-numeric.
 *     In this case, the data pointed to by val is invalid.
 *
 *   1 otherwise
 */
int get_input (int* val)
{
    do {
        if ( (*val = getchar()) == '\n')
            return 0;
    } while (getchar() != '\n');

    *val -= '0';

    if (*val >= 0 && *val <= 9)
        return 1;
    else
        return 0;
}


/* Prints the characters in the house array to the screen
 *
 * Parameters:
 *   house -- pointer characters representing the house
 *
 * Returns:
 *   Nothing
 */
void house_display (char* house)
{
    int i, j;

    for (j=0; j<HOUSE_HEIGHT; j++, printf("\n"))
        for (i=0; i<HOUSE_WIDTH; i++)
            printf ("%c", house[HOUSE_WIDTH*j+i]);
}


void house_change (char* house,int choice, int lightordark)
{
    char fill;
    if (lightordark==1){
    fill='#';
    }
    else if(lightordark==0){
    fill=' ';
    }
    
    char* window_start;
    switch(choice){
      case 0:
       window_start = house + 11+(HOUSE_WIDTH*8);
       break;
      case 1:
        window_start = house + 29+(HOUSE_WIDTH*8);
        break;
      case 2:
        window_start = house + 47+(HOUSE_WIDTH*8);
        break;
      case 3:
        window_start = house + 11+(HOUSE_WIDTH*14);
        break;
      case 4:
        window_start = house + 29+(HOUSE_WIDTH*14);
        break;
      case 5:
        window_start = house + 47+(HOUSE_WIDTH*14);
        break;
      case 6:
       window_start = house + 11+(HOUSE_WIDTH*20);
       break;
      case 7:
       window_start = house + 29+(HOUSE_WIDTH*20);
       break;
      case 8:
       window_start = house + 47+(HOUSE_WIDTH*20);
       break;
        
      }
        
    int i, j;
    
    for (j=0; j<WINDOW_HEIGHT; j++)
        for (i=0; i<WINDOW_WIDTH; i++)
           window_start[i+j*HOUSE_WIDTH]=fill;
    
    
}
//  row fisrt 8, second 14,  third 20,colum   first 11, second 29, third 47


void window_toggle(int*state,char* house, int choice){
if (choice==0){
   state[choice]=!state[choice];
   state[1]=!state[1];
   state[3]=!state[3];
   house_change(house,choice,state[choice]);
   house_change(house,1,state[1]);
   house_change(house,3,state[3]);
}
if (choice==1){
   state[choice]=!state[choice];
   state[0]=!state[0];
   state[2]=!state[2];
   state[4]=!state[4];
   house_change(house,choice,state[choice]);
   house_change(house,0,state[0]);
   house_change(house,2,state[2]);
   house_change(house,4,state[4]);
}
if (choice==2){
   state[choice]=!state[choice];
   state[1]=!state[1];
   state[5]=!state[5];
   house_change(house,choice,state[choice]);
   house_change(house,1,state[1]);
   house_change(house,5,state[5]);
}
if (choice==3){
   state[choice]=!state[choice];
   state[0]=!state[0];
   state[4]=!state[4];
   state[6]=!state[6];
   house_change(house,choice,state[choice]);
   house_change(house,0,state[0]);
   house_change(house,6,state[6]);
   house_change(house,4,state[4]);
}
if (choice==4){
   state[choice]=!state[choice];
   state[1]=!state[1];
   state[3]=!state[3];
   state[5]=!state[5];
   state[7]=!state[7];
   house_change(house,choice,state[choice]);
   house_change(house,1,state[1]);
   house_change(house,3,state[3]);
   house_change(house,5,state[5]);
   house_change(house,7,state[7]);
}
if (choice==5){
   state[choice]=!state[choice];
   state[2]=!state[2];
   state[4]=!state[4];
   state[8]=!state[8];
   house_change(house,choice,state[choice]);
   house_change(house,2,state[2]);
   house_change(house,4,state[4]);
   house_change(house,8,state[8]);
}
if (choice==6){
   state[choice]=!state[choice];
   state[3]=!state[3];
   state[7]=!state[7];
   house_change(house,choice,state[choice]);
   house_change(house,3,state[3]);
   house_change(house,7,state[7]);
}
if (choice==7){
   state[choice]=!state[choice];
   state[4]=!state[4];
   state[6]=!state[6];
   state[8]=!state[8];
   house_change(house,choice,state[choice]);
   house_change(house,4,state[4]);
   house_change(house,6,state[6]);
   house_change(house,8,state[8]);
}
if (choice==8){
   state[choice]=!state[choice];
   state[5]=!state[5];
   state[7]=!state[7];
   house_change(house,choice,state[choice]);
   house_change(house,5,state[5]);
   house_change(house,7,state[7]);
}
}

int solved(int state[]){
int doneGame[]={1,1,1,1,1,1,1,1,1};
int size=9;
int i;
	for(i=0;i<size;i++){
		if(state[i]!=doneGame[i])
			return 0;
	}
	return 1;
}

int main (int argc, char** argv)
{
    int choice;

    char house[] =
    "                                             ______________          "
    "                                            |______________|         "
    "      _______________________________________|            |_____     "
    "     '                                       |____________|     `    "
    "    |                                                           |    "
    "    '-----------------------------------------------------------'    "
    "    |           1                 2                 3           |    "
    "    |     +-----------+     +-----------+     +-----------+     |    "
    "    |     |           |     |           |     |           |     |    "
    "    |     |           |     |           |     |           |     |    "
    "    |     |           |     |           |     |           |     |    "
    "    |     +-----------+     +-----------+     +-----------+     |    "
    "    |           4                 5                 6           |    "
    "    |     +-----------+     +-----------+     +-----------+     |    "
    "    |     |           |     |           |     |           |     |    "
    "    |     |           |     |           |     |           |     |    "
    "  _ |     |           |     |           |     |           |     |    "
    " |#||     +-----------+     +-----------+     +-----------+     |    "
    " |_||           7                 8                 9           |    "
    "  `-|     +-----------+     +-----------+     +-----------+     |    "
    "    -     |           |     |           |     |           |     |    "
    "    '     |           |     |           |     |           |     |    "
    "    '     |           |     |           |     |           |     |    "
    "   o'     +-----------+     +-----------+     +-----------+     |    "
    "    '                                                           |    "
    "____'___________________________________________________________'____";

    



    /* NOTE:
     * this will be our initial window state, do not change this!
     *   1 = Light is ON  -- fill with '#' character
     *   0 = Light is OFF -- fill with ' ' character (i.e. a space) */
    int state[] = { 1, 1, 0,
                    1, 1, 0,
                    1, 0, 0 };
                    
    house_change(house,0,1);
    house_change(house,1,1);
    house_change(house,3,1);
    house_change(house,4,1);
    house_change(house,6,1);
    
    /* TODO: house[] needs to be updated to reflect initial
     *       values held in state[] */
/*
    house_init (house, state)
*/

    /* Infinite game loop.
     * (We will exit using 'break' when certain conditions are met) */
    while (1) {
        house_display (house);

        

        if (solved(state)) {
            printf ("Congratulations!  You won!\n");
            break;
        }

        printf ("Choose a Window (0 to exit): ");
       
        if (!get_input (&choice)) {
            printf ("INVALID SELECTION!\n");
            printf ("please enter again\n");
            continue;
        }

        if (!choice)
            break;
        
       

        choice--;
        window_toggle (state, house, choice);

    }

    printf ("Goodbye!\n");

    return 0;
}