#include <stdio.h>
#include <string.h>

struct User 
{
    char userName[500];
    char password[500];
};


struct User users[200];
int count = 0;

void Register() 
{
    struct User userRegister;
    printf("Enter userName: ");
    scanf("%s", userRegister.userName);
    
    printf("Enter Password: ");
    scanf("%s", userRegister.password);
    
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
           
                printf("Login successful, Hello %s\n", users[i].userName);
                return;
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