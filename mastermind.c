#include "master.h"

/**
 * main - main function, executes the game
 * Return: 1 if win 0 if lose
 */

int main(int argc, char **argv)
{
    size_t size = 4;
    int game = 1;
    char *arr[1024];
    int x = 0, a = 0;
    char *input = NULL;
    int idx = 0, n = 0;
    char hidden[4];
    char u_array[4];

    printf("\tWELCOME TO MIND MASTER\n");
    printf("\tPRESS \'Y\' TO START OR SOMETHING ELSE TO EXIT\n\n");

    printf(">> ");
    getline(&input, &size, stdin);
    if (*input == 'y' || *input == 'Y')
    {
        while (game)
        {
            printf("PLAYER 1 ENTER HIDDEN PATTERN:\n");
            getline(arr, &size, stdin);
            for(a = 0; arr[0][a] != 0; a++)
            {
                hidden[a] = arr[0][a];
            }
            printf("CONFIRM PATTERN?\n");
            getline(&input, &size, stdin);
            if (*input == 'y' || *input == 'Y')
                break;
        }
        
        while(game)
        {
            printf("\tPLAYER 2 TRY TO GUESS THE PATTERN\n");
            while (game)
            {
                printf(">> ");
                getline(&arr[idx], &size, stdin);
                for(a = 0; arr[idx][a] != 0; a++)
                {
                    u_array[a] = arr[0][a];
                }
                printf("CONFIRM PATTERN?\n");
                getline(&input, &size, stdin);
                if (*input == 'y' || *input == 'Y')
                {
                    system("clear");
                    break;
                }
            }
            //check_points();
            for(n = 0; n <= idx; n++)
            {
                for(x = 0; arr[n][x] != 0; x++)
                    if(arr[n][x] != '\n')
                        printf("\t[ %c ] ", arr[n][x]);
                printf("\n\n");
            }
            sw_enter_key(arr[idx]);
            idx++;
        }
    }
}
/**
 * sw_enter_key - function that changes enter key for end of line character
 * @buffer: pointer that stores the stdinput.
 * Return: buffer.
 */
char *sw_enter_key(char *buffer)
{
	int buff_size = 0;

	buff_size = strlen(buffer);
	buffer[buff_size - 1] = '\0';
	return (buffer);
}