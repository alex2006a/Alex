#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY 10
#define DEFAULT_PIN "1234"

typedef struct {
    char name[50];
    char lastName[50];
    int accountID;
    float balance;
    char pin[5];
    int isActive;
    char transactionHistory[MAX_HISTORY][100];
    int historyCount;
    int transactionCounter;
} BankAccount;

BankAccount account;
int accountExists = 0;

void initializeAccount() {
    account.accountID = 0;
    account.balance = 0;
    strcpy(account.pin, DEFAULT_PIN);
    account.isActive = 0;
    account.historyCount = 0;
    account.transactionCounter = 0;
    for (int i = 0; i < MAX_HISTORY; i++) {
        strcpy(account.transactionHistory[i], "");
    }
}

int verifyPin() {
    char enteredPin[5];
    int attempts = 3;
    
    while (attempts > 0) {
        printf("Lotfan PIN ra vared konid: ");
        scanf("%s", enteredPin);
        
        if (strcmp(enteredPin, account.pin) == 0) {
            return 1;
        } else {
            attempts--;
            if (attempts > 0) {
                printf("PIN eshtebah ast. %d talash mande.\n", attempts);
            }
        }
    }
    
    printf("3 bar PIN eshtebah vared shod. Barname khatemeh miyabad.\n");
    exit(0);
    return 0;
}

void addTransaction(char type[], float amount) {
    char transaction[100];
    
    account.transactionCounter++;
    
    if (strcmp(type, "Deposit") == 0) {
        sprintf(transaction, "Deposit: +%.2f, mojoodi: %.2f", amount, account.balance);
    } else if (strcmp(type, "Withdraw") == 0) {
        sprintf(transaction, "Withdraw: -%.2f, mojoodi: %.2f", amount, account.balance);
    } else if (strcmp(type, "Create") == 0) {
        sprintf(transaction, "Hesab ijad shod, mojoodi: %.2f", account.balance);
    }
    
    if (account.historyCount < MAX_HISTORY) {
        strcpy(account.transactionHistory[account.historyCount], transaction);
        account.historyCount++;
    } else {
        for (int i = 0; i < MAX_HISTORY - 1; i++) {
            strcpy(account.transactionHistory[i], account.transactionHistory[i + 1]);
        }
        strcpy(account.transactionHistory[MAX_HISTORY - 1], transaction);
    }
}

void createAccount() {
    if (accountExists) {
        printf("Ghablan hesabi ijad shode ast!\n");
        return;
    }
    
    printf("\n*** Ijade Hesab Jadid *\n");
    
    printf("Name: ");
    scanf("%s", account.name);
    
    printf("Name Khanevadegi: ");
    scanf("%s", account.lastName);
    
    account.accountID = 100000 + (rand() % 900000);
    
    printf("mojoodi avalie: ");
    float initialBalance;
    scanf("%f", &initialBalance);
    
    if (initialBalance < 0) {
        printf(" bayad mojoodi mosbat bashad!\n");
        return;
    }
    
    account.balance = initialBalance;
    account.isActive = 1;
    accountExists = 1;
    
    printf("\nHesab ba movafaghiat ijad shod!\n");
    printf("Account ID: %d\n", account.accountID);
    printf("Name: %s %s\n", account.name, account.lastName);
    printf("mojoodi avalie: %.2f\n", account.balance);
    
    addTransaction("Create", 0);
}

void deposit() {
    if (!accountExists) {
        printf("Hich hesabi vojoud nadarad!\n");
        return;
    }
    
    printf("\n* Variz ***\n");
    
    if (!verifyPin()) {
        return;
    }
    
    float amount;
    printf("Mablegh variz: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Mablegh bayad bozorgtar az 0 bashad!\n");
        return;
    }
    
    account.balance += amount;
    addTransaction("Deposit", amount);
    
    printf("Variz ba movafaghiat anjam shod.\n");
    printf("mojoodi jadid: %.2f\n", account.balance);
}

void withdraw() {
    if (!accountExists) {
        printf("Hich hesabi vojoud nadarad!\n");
        return;
    }
    printf("\n*** Bardasht *\n");
    
    if (!verifyPin()) {
        return;
    }
    
    float amount;
    printf("Mablegh bardasht: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Mablegh bayad bozorgtar az 0 bashad!\n");
        return;
    }
    
    if (amount > account.balance) {
        printf("mojoodi kafi nist!\n");
        printf("mojoodi mojoud: %.2f\n", account.balance);
        return;
    }
    
    account.balance -= amount;
    addTransaction("Withdraw", amount);
    
    printf("Bardasht ba movafaghiat anjam shod.\n");
    printf("mojoodi jadid: %.2f\n", account.balance);
}

void checkBalance() {
    if (!accountExists) {
        printf("Hich hesabi vojoud nadarad!\n");
        return;
    }
    
    printf("\n* Etelaat Hesab *\n");
    
    int enteredID;
    printf("Account ID ra vared konid: ");
    scanf("%d", &enteredID);
    
    if (enteredID != account.accountID) {
        printf("Account ID eshtebah ast!\n");
        return;
    }
    
    printf("\n========== Etelaat Hesab ==========\n");
    printf("Name: %s %s\n", account.name, account.lastName);
    printf("Account ID: %d\n", account.accountID);
    printf("mojoodi: %.2f\n", account.balance);
    printf("Vaziyat: %s\n", account.isActive ? "Faal" : "Gheyr Faal");
    printf("\nTarikhche 10 Tarakonesh Akhar:\n");
    
    if (account.historyCount == 0) {
        printf("Hich tarakoneshi vojoud nadarad.\n");
    } else {
        int start = account.historyCount - 1;
        int count = 0;
        
        for (int i = start; i >= 0 && count < 10; i--) {
            printf("%d. %s\n", count + 1, account.transactionHistory[i]);
            count++;
        }
    }
    printf("===================================\n");
}

void changePIN() {
    if (!accountExists) {
        printf("Hich hesabi vojoud nadarad!\n");
        return;
    }
    
    printf("\n* Taghir PIN *\n");
    
    char currentPin[5];
    printf("PIN feli: ");
    scanf("%s", currentPin);
    
    if (strcmp(currentPin, account.pin) != 0) {
        printf("PIN feli eshtebah ast!\n");
        return;
    }
    
    char newPin[5];
    printf("PIN jadid (4 ragham): ");
    scanf("%s", newPin);
    
    if (strlen(newPin) != 4) {
        printf("PIN bayad 4 ragham bashad!\n");
        return;
    }
    
    char confirmPin[5];
    printf("Taeed PIN jadid: ");
    scanf("%s", confirmPin);
    
    if (strcmp(newPin, confirmPin) != 0) {
        printf("PIN haye jadid motabeghat nadarand!\n");
        return;
    }
    
    strcpy(account.pin, newPin);
    printf("PIN ba movafaghiat taghir yaft!\n");
}

void showMenu() {
    printf("\n");
    printf("******** Systeme Bankdari Sade ******\n");
    printf("1. Ijade Hesab\n");
    printf("2. Variz\n");
    printf("3. Bardasht\n");
    printf("4. Moshahdeh mojoodi\n");
    printf("5. Taghir PIN\n");
    printf("6. Khoroj\n");
    printf("*******************************************\n");
}

int main() {
    printf("Be Systeme Bankdari Sade khosh amadid!\n");
    initializeAccount();
    
    int choice;
    
    while (1) {
        showMenu();
        printf("Entekhab khod ra vared konid: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                changePIN();
                break;
            case 6:
                printf("Khoroj az system. Khoda hafez!\n");
                return 0;
            default:
                printf("Entekhab namotabar! Lotfan adad beyne 1 ta 6 vared konid.\n");
        }
    }
    
    return 0;
}