#include "master.h"

/**
 * main - main function, executes the game
 * Return: 1 if win 0 if lose
 */

int main(int argc, char **argv)
{
    size_t size = 4;
    int game = 1, i = 0;
    char *arr[1024];
    int x = 0, a = 0;
    char *input = NULL;
    int idx = 0, n = 0;
    char hidden[4];
    char u_array[4];
    int *result[10];

    system("clear");
    printf("\tWELCOME TO MIND MASTER\n");
    printf("\tThe main objective is that player 2 tries to guess the pattern of colors that the player 1 types in.\n");
    printf("\tPlayer 2 has 10 attempts. Only uppercase letters can be used.\n");
    printf("\tInput should be a string of four letters. For example: YBRO");
    printf("\n\n");
    printf("\tResult session meaning:\n\n");
    printf("\t\t-1 -> there is a color that does not match with the player 1 pattern\n");
    printf("\t\t 0 -> there is a color that matches with the player 1 pattern but is not in the correct place\n");
    printf("\t\t 1 -> there is a color that matches with the player 1 pattern and is in the correct place\n\n\n");
    printf("\tPRESS \'Y\' TO START OR SOMETHING ELSE TO EXIT\n\n");

    printf(">> ");
    getline(&input, &size, stdin);
    if (*input == 'y' || *input == 'Y')
    {
        while (game)
        {
            printf("PLAYER 1 ENTER HIDDEN PATTERN:\n");
            printf("COLORS: Blue(B), Green(G), Orange(O), Purple(P), Red(R), Yellow(Y)\n");
            printf(">> ");
            getline(arr, &size, stdin);
            for(a = 0; arr[0][a] != 0; a++)
            {
                hidden[a] = arr[0][a];
            }
            printf("CONFIRM PATTERN? yes(Y), no(anything else)\n");
            printf(">> ");
            getline(&input, &size, stdin);
            if (*input == 'y' || *input == 'Y')
            {
                system("clear");
                break;
            }
        }
        
        while(game)
        {
            printf("\tPLAYER 2 TRY TO GUESS THE PATTERN\n");
            printf("COLORS: Blue(B), Green(G), Orange(O), Purple(P), Red(R), Yellow(Y)\n");
            while (game)
            {
                printf(">> ");
                getline(&arr[idx], &size, stdin);
                for(a = 0; arr[idx][a] != 0; a++)
                {
                    u_array[a] = arr[idx][a];
                }
                printf("CONFIRM PATTERN?, yes(Y), no(anything else)\n");
                printf(">> ");
                getline(&input, &size, stdin);
                if (*input == 'y' || *input == 'Y')
                {
                    system("clear");
                    break;
                }
            }
            result[idx] = check_points(hidden, u_array);
            for(n = 0; n <= idx; n++)
            {
                printf("Attempt #%d ", n + 1);
                for(x = 0; arr[n][x] != 0; x++)
                    if(arr[n][x] != '\n')
                        printf("\t[ %c ] ", arr[n][x]);
                printf("       ||       ");
                for(x = 0; x < 4; x++)
                {
                    printf("[ %d ]", result[n][x]);
                }
                printf("\n\n");
            }
            sw_enter_key(arr[idx]);
            for(i = 0; i <= 3; i++)
            {
                if (result[idx][i] != 1)
                    break;
                if (i + 1 == 4)
                {
                    printf("CONGRATS! PLAYER 2 WON\n");
                    exit(0);
                }
            }
            if(idx == 9)
            {
                printf("CONGRATS! PLAYER 1 WON\n");
                exit(0);
            }
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