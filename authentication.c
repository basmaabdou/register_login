#include <stdio.h>
#include <string.h>

struct User 
{
    char userName[500];
    char password[500];
    union {
        char flag[4];
    };
};

struct User users[100];
int count = 0;

void Register() 
{
    struct User userRegister;
    printf("Enter userName: ");
    scanf("%s", userRegister.userName);
    
    printf("Enter Password: ");
    scanf("%s", userRegister.password);

    printf("Enter Flag (true or false): ");
    scanf("%s", userRegister.flag);
    
    users[count++] = userRegister;
    printf("Successfully registered\n");
}

void Login() 
{
    char userName[500];
    char password[500];
    
    printf("Enter UserName: ");
    scanf("%s", userName);
    
    printf("Enter Password: ");
    scanf("%s", password);
    
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(userName, users[i].userName) == 0 && strcmp(password, users[i].password) == 0) 
        {
            if ( strcmp(users[i].flag, "true") == 0) 
            {
                printf("Login successful, Hello %s\n", users[i].userName);
                return;
            } 
            else 
            {
                printf("User account is not active\n");
                return;
            }
        }
    }
    
    printf("Invalid username or password\n");
}

int main(void) 
{
    printf("Register a new User\n");
    Register();
    printf("Login with your User\n");
    Login();
    return 0;
}