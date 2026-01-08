#include <stdio.h>
#include <string.h>


void print_header(void)
{
    printf(
" /$$$$$$                 /$$                            /$$$$$$   /$$                                  \n"
"|_  $$_/                | $$                           /$$__  $$ | $$                                  \n"
"  | $$   /$$$$$$$   /$$$$$$$  /$$$$$$  /$$   /$$      | $$  \\__//$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$ \n"
"  | $$  | $$__  $$ /$$__  $$ /$$__  $$|  $$ /$$/      |  $$$$$$|_  $$_/   /$$__  $$ /$$__  $$ /$$__  $$\n"
"  | $$  | $$  \\ $$| $$  | $$| $$$$$$$$ \\  $$$$/        \\____  $$ | $$    | $$  \\ $$| $$  \\__/| $$$$$$$$\n"
"  | $$  | $$  | $$| $$  | $$| $$_____/  >$$  $$        /$$  \\ $$ | $$ /$$| $$  | $$| $$      | $$_____/\n"
" /$$$$$$| $$  | $$|  $$$$$$$|  $$$$$$$ /$$/\\  $$      |  $$$$$$/ |  $$$$/|  $$$$$$/| $$      |  $$$$$$$\n"
"|______/|__/  |__/ \\_______/ \\_______/|__/  \\__/       \\______/   \\___/   \\______/ |__/       \\_______/\n"
"                                                                                                       \n"
"                                                                                                       \n"
"                                                                                                       \n");
}
void print_menu(void)
{
    printf("Input Command:  Insert  |  Find  |  Update  |  Delete  |  List  |  Exit\n\n");
}

//switch case, but with words
void cmd_insert()
{
    printf("input is insert\n");
}
void cmd_find()
{
    printf("input is find\n");
}
void cmd_update()
{
    printf("input is update\n");
}
void cmd_delete()
{
    printf("input is delete\n");
}
void cmd_list()
{
    printf("input is list\n");
}

struct command
{
    const char *name;
    void (*function)();
};

struct command commands[] ={
    {"insert", cmd_insert},
    {"find", cmd_find},
    {"update", cmd_update},
    {"delete", cmd_delete},
    {"list", cmd_list},
};







int main()
{
    print_header();
    print_menu();

    while(1)
    {
    char buffer[20];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    if (strcmp(buffer, "exit") == 0)
    {
        break;
    }

    for (int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++)
    {
        if (strcmp(buffer, commands[i].name) == 0)
        {
            commands[i].function();
            break;
        }
    }
    }


    return 0;
}