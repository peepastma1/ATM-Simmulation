#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int idmain, choose = 5, t = 0,get_out=0;
float balance;
int login();
void register_account();
void deposit(int a, char b[100], char l[100]);
void withdraw(int a, char b[100], char l[100]);
void billing_sort_txt(float);
void billing(void);
void storage_data(char *, int, float);
void menu();
void admin();
void transaction();
void checkmoney();
void clear();
void receipt(void);
void receipt_deposit(int a);
void receipt_deposit_register(int a);
void receipt_withdraw(int a);
void receipt_trasfer(int a, float b);
void receipt_billing(char a[100], int b, float c);

struct account{
    int id, password;
    float bal;
} acc;

typedef struct{
    int id, pass;
    float money;
} record;

typedef struct{
    int num;
    char ba[50];
} well;

int main(){
    int haveaccount,start=0,out=0;
    FILE *cp;
    cp = fopen("receipt.txt", "w");
    do{fprintf(cp, "\n****************************************************");
    fprintf(cp, "\n                    Transaction");
    fprintf(cp, "\n****************************************************");
    fclose(cp);
    printf("--------------------------------------\n");
    printf("       Welcome To The Best ATM\n");
    printf("      The most security ATM ever\n");
    printf("--------------------------------------\n");
    printf("\n");
    printf("Do you have an account? (Choose 0-2)\n");
    printf("1.Yes\n2.No\n0.Quit\n");
    printf("\nChoosing (0-2) : ");
    scanf("%d", &haveaccount);
    clear();
    switch(haveaccount){
    case 0:
        start=1;
        printf("\n=== Thank you for using ATM ===");
        exit(0);
    case 1:
        start=1;
        login();
        break;
    case 2:
        start=1;
        register_account();
        break;
    default:
        printf("please choose only 0-2\n\n");
        break;
    }}while(start==0);
    while (choose != 0){
        menu();
    }
    int R;
    clear();
    do{printf("Do you want receipt?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Choosing: ");
    scanf("%d", &R);
    clear();
    if (R == 1){
        receipt();
        out++;
    }
    else if(R==2){
        printf("********************************\n");
        printf("\n=== Thank you for using ATM ===\n\n");
        printf("********************************\n\n");
        out++;

    }}while(out==0);
}

void menu(){
    clear();
    if (idmain != 000000){
        printf("\n************************************\n");
        printf("\n     What would you like to do?\n");
        printf("\n************************************\n");
        printf("\n[1] Deposit\t\t[2] Withdraw\n");
        printf("\n[3] Transfer Money\t[4] Billing\n");
        printf("\n[5] Account balance\t[0] Quit\n");
        printf("\nChoosing : ");
        scanf("%d", &choose);
        switch(choose){
        case 0:
            break;
        case 1:
            deposit(idmain, "account.txt", "bank.txt");
            break;
        case 2:
            withdraw(idmain, "account.txt", "bank.txt");
            break;
        case 3:
            transaction();
            break;
        case 4:
            billing();
            break;
        case 5:
            checkmoney();
            break;
        }
    }
    else if(idmain==0){
        admin();
    }
}

int login(){
    FILE *fp;
    int user_acc_id, user_acc_password, T = 0, i, c = 0, gc = 0;
    do{
        printf("------------ Login ------------\n");
        printf("\nEnter user id (6 integer): ");
        scanf("%d", &user_acc_id);
        printf("\nEnter your password (6 integer): ");
        scanf("%d", &user_acc_password);
        fp = fopen("account.txt", "r");
        while (!feof(fp) && T == 0){
            fscanf(fp, "%d %d %f", &acc.id, &acc.password, &acc.bal);
            if (user_acc_id == acc.id && user_acc_password == acc.password){
                T = 1;
                idmain = user_acc_id;
                c++;
            }
            else{
                T = 0;
            }
        }
        if (c == 0){
            printf("\n*** Id or Password is wrong ***\n\n*******************************\n\n");
            do{printf("Do you want to Register? (1-Yes 2-No) : ");
            scanf("%d", &gc);
            switch(gc)
            {
            case 1 :
                clear();
                register_account();
                T = 1;
                break;
            case 2 :
                T=1;
                printf("\nPress any key to try again...");
                getch();
                clear();
                login();
                break;
            default :
                printf("please enter only 1 or 2 : ");
                break;
            }
            clear();}while(T==0);
        }
    }while(T == 0);
    fclose(fp);
}

void register_account(){
    FILE *fp1,*fp2,*fp3,*fp4;
    int n1=0,n2=0,start=100000,bank100,bank500,bank1000, c = 0;
    float nm;
    well bank;
    struct register_acc{
        int id, password, id_temp, password_temp;
        float bala, balance_temp;
    }acc;
    fp2=fopen("account.txt", "r");
    if (fp2 == NULL){
        acc.id = start;
    }
    else{
        while (!feof(fp2)){
            fscanf(fp2, "%d %d %f", &acc.id_temp, &acc.password_temp, &acc.balance_temp);
            acc.id = acc.id_temp + 1;
        }
        idmain = acc.id;
    }
    fp1 = fopen("account.txt", "a");
    printf("--- Register an account ---\n\n");
    do{
        printf("Password (6-digits) : ");
        scanf("%d", &acc.password);
        if (acc.password < 100000 || acc.password >= 1000000){
            printf("\n***Please enter 6-digits password***\n");
        }
        else{
            n1 = 1;
        }
    }while(n1!=1);

    do{
        int am=0,u;
        do{
        printf("\nPlease deposit your money to open your account\n");
        printf("\nDeposit money (At least 500 Baht) : ");
        scanf("%f", &acc.bala);
        u = acc.bala / 100;
        u = u * 100;
        if(acc.bala < 500 || acc.bala != u){
            printf("**** Please deposit at least 500 Baht and please deposit amount that banknote can contain ****\n\n");
            printf("Press any key to return...");
            getch();
            clear();
        }
        else{
            am=1;
        }
        }while(am!=1);
        printf("\n---- Please give information ----\n\n");
        printf("Banknote 100 : ");
        scanf("%d", &bank100);
        printf("Banknote 500 : ");
        scanf("%d", &bank500);
        printf("Banknote 1000 : ");
        scanf("%d", &bank1000);
        nm = ((100 * bank100) + (500 * bank500) + (1000 * bank1000));
        if (acc.bala != nm){
            printf("**** It will be illegal for cheating ****\n");
            printf("\nPress any key to give information again...");
            getch();
            clear();
        }
        else{
            n2 = 1;
        }
    }while(n2!=1);
    fprintf(fp1, "\n%d ", acc.id);
    idmain = acc.id;
    fprintf(fp1, "%d ", acc.password);
    fprintf(fp1, "%.2f", acc.bala);
    clear();
    printf("\n---- Register an account successfully ----\n\n");
    printf("------------------------------------------\n");
    printf("Your Information :\n");
    printf("ID : %d\n", acc.id);
    printf("Password : %d\n", acc.password);
    printf("Balance : %.2f\n", acc.bala);
    printf("------------------------------------------\n");
    receipt_deposit_register(acc.bala);

    fclose(fp1);
    fclose(fp2);

    fp3 = fopen("bank.txt", "r+");
    fp4 = fopen("bank.txt", "r+");
    while (!feof(fp3)){
        fscanf(fp3, "%s %d", bank.ba, &bank.num);
        if (c == 0){
            bank.num = bank.num + bank1000;
            c++;
        }
        else if (c == 1){
            bank.num = bank.num + bank500;
            c++;
        }
        else if (c == 2){
            bank.num = bank.num + bank100;
            c++;
        }
        fprintf(fp4, "\n%s %d", bank.ba, bank.num);
    }
    fclose(fp3);
    fclose(fp4);
    printf("Press any key to go to menu... ");
    getch();
    clear();
}

void deposit(int a, char b[100], char l[100]){
    clear();
    FILE *fp, *r, *b1, *b2;
    record account;
    well bank;
    int ex = 0, i = 0, nm, bank100, bank500, bank1000, c = 0, z = 0, u;
    float money;
    fp = fopen(b, "r+");
    r = fopen(b, "r+");

    while (!feof(fp)){
        fscanf(fp, "%d %d %f", &account.id, &account.pass, &account.money);
        if (account.id == a){
            for (i = 0; i < 5 && c == 0; i++){
                printf("***************************************************************");
                printf("\n\n\t\t            Deposit\n\n");
                printf("***************************************************************\n");
                printf("\nHow much money do you want to deposit (At least 100 Baht) : ");
                scanf("%f", &money);
                u = money / 100;
                u = u * 100;
                if (money != u){
                    printf("\n                    **** Can't deposit ****");
                    printf("\n\n    ==== Please enter amount that banknote can contain ====");
                    ex = 1;
                    printf("\n\n***************************************************************\n");
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                    break;
                }
                if(money < 100){
                    printf("**** Can't deposit (Please deposit more that 100 Baht) ****");
                    ex = 1;
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                    break;
                }
                printf("\n               ---- Please give information ----\n\n");
                printf("Banknote 100 : ");
                scanf("%d", &bank100);
                printf("Banknote 500 : ");
                scanf("%d", &bank500);
                printf("Banknote 1000 : ");
                scanf("%d", &bank1000);
                nm = ((100 * bank100) + (500 * bank500) + (1000 * bank1000));
                if (nm == money && c == 0){
                    printf("\n\n                    -----Successful-----\n\n");
                    account.money = account.money + nm;
                    printf("Now money in your account is %.2f\n", account.money);
                    printf("\n***************************************************************\n");
                    c++;
                    receipt_deposit(nm);
                    printf("\nPress any key to return menu...");
                    getch();
                }
                if (c == 0){
                    printf("**** It will be illegal for cheating ****\n");
                    printf("\nPress any key to give information again...");
                    getch();
                }
                clear();
            }
        }
        fprintf(r, "\n%d %d %.2f", account.id, account.pass, account.money);
    }
    fclose(fp);
    fclose(r);
    b1 = fopen(l, "r+");
    b2 = fopen(l, "r+");
    while (!feof(b1) && ex != 1){
        fscanf(b1, "%s %d", bank.ba, &bank.num);

        if (z == 0){
            bank.num = bank.num + bank1000;
            z++;
        }
        else if (z == 1){
            bank.num = bank.num + bank500;
            z++;
        }
        else if (z == 2){
            bank.num = bank.num + bank100;
            z++;
        }
        fprintf(b2, "\n%s %d", bank.ba, bank.num);
    }
    fclose(b1);
    fclose(b2);
}

void withdraw(int a, char b[100], char l[100]){
    clear();
    FILE *fp, *r, *b1, *b3, *b4;
    record account;
    well bank;
    int i = 0, nm, c = 0, z = 0, out = 0;
    int money, q100, q500, q1000, w100, w500, w1000, p, o1, o2, o3, ee = 0;
    fp = fopen(b, "r+");
    r = fopen(b, "r+");
    b1 = fopen(l, "r+");
    b3 = fopen(l, "r+");
    b4 = fopen(l, "r+");
    while (!feof(fp)){
        fscanf(fp, "%d %d %f", &account.id, &account.pass, &account.money);
        if (account.id == a){
            printf("***************************************************************");
            printf("\n\n\t\t            Withdraw\n\n");
            printf("***************************************************************\n");
            printf("\nHow much money do you want to withdraw (Baht && only integer) : ");
            scanf("%d", &money);
            if (money > account.money){
                printf("**** Don't have enough money ****");
                out = 1;
                printf("\nPress any key to return...");
                getch();
                clear();
                break;
            }
            else if (money % 100 != 0||money<=0){
                printf("\n                    **** Can't withdraw ****");
                printf("\n\n    ==== Please enter amount that banknote can contain ====\n\n");
                printf("***************************************************************\n");
                out = 1;
                printf("\nPress any key to return...");
                getch();
                clear();
                break;
            }
            else{
                q100 = ((money % 1000) % 500);
                q500 = ((money - q100) % 1000);
                q1000 = ((money - q100) - q500);
                q100 = q100 / 100;
                q500 = q500 / 500;
                q1000 = q1000 / 1000;
                while (!feof(b1)){
                    fscanf(b1, "%s %d", bank.ba, &bank.num);
                    if (z == 0){
                        if (q1000 > bank.num){
                            w1000 = q1000 - bank.num;
                            p = w1000 * 2;
                            q500 = p + q500;
                            o1 = bank.num;
                            bank.num = 0;
                        }
                        else{
                            bank.num = bank.num - q1000;
                            o1 = q1000;
                        }
                        z++;
                    }
                    else if (z == 1){
                        if(q500 > bank.num){
                            w500 = q500 - bank.num;
                            p = w500 * 5;
                            q100 = p + q100;
                            o2 = bank.num;
                            bank.num = 0;
                        }
                        else{
                            bank.num = bank.num - q500;
                            o2 = q500;
                        }
                        z++;
                    }
                    else if(z == 2){
                        if(q100 > bank.num){
                            ee = 1;
                        }
                        else{
                            bank.num = bank.num - q100;
                            o3 = q100;
                        }
                        z++;
                    }
                }
            }
        }
    }
    if(ee == 1 ){
        out = 1;
        printf("\t\t\t**** ERROR ****\n");
        printf("Don't have enough banknote!! Please try again later or contact staff immediately");
    }
    else if(out == 1){
        printf("***********************************************************************************\n\n");
        printf("                              --- Let's turn back ---\n                            check money in you account\n       check money that you want to withdraw can be paid by BANK100/500/1000");
        printf("\n\n***********************************************************************************\n");
    }
    else{
        printf("\n                      --- You will get ---\n\n banknote100 : %d \n banknote500 : %d\n banknote1000 : %d", o3, o2, o1);
    }
    i = 0;
    while(!feof(b3) && out != 1){
        fscanf(b3, "%s %d", bank.ba, &bank.num);
        if(i == 0){
            bank.num = bank.num - o1;
        }
        else if(i == 1){
            bank.num = bank.num - o2;
        }
        else if(i == 2){
            bank.num = bank.num - o3;
        }
        fprintf(b4, "\n%s %d", bank.ba, bank.num);
        i++;
    }
    fclose(b3);
    fclose(b4);

    fclose(fp);
    fclose(r);
    fclose(b1);

    fp = fopen(b, "r+");
    r = fopen(b, "r+");
    while(!feof(fp) && ee == 0 && out != 1){
        fscanf(fp, "%d %d %f", &account.id, &account.pass, &account.money);
        if (account.id == a){
            printf("\n\n                     -----Successful-----\n\n");
            printf("***************************************************************\n");
            account.money = account.money - money;
            printf("Now money in your account is %.2f\n", account.money);
            printf("***************************************************************\n");
            receipt_withdraw(money);
        }
        fprintf(r,"\n%d %d %.2f", account.id, account.pass, account.money);
    }
    fclose(fp);
    fclose(r);
    printf("\nPress any key to return menu...");
    getch();
}

void billing(void){
    clear();
    int n0, n1, n2, n3, n4, n5, n6, exit[6] = {0, 0, 0, 0, 0, 0}, temp;
    char type[30];
    float money;
    do{
        printf("-----------------------\n");
        printf("--- Billing Payment ---\n");
        printf("1.Utility bills\n");
        printf("2.Phone bills\n");
        printf("3.Credit Card bills\n");
        printf("4.Insurance bills\n");
        printf("0.Return\n");
        printf("-----------------------\n");
        printf("Please choose menu (0-4) : ");
        scanf("%d", &n0);
        clear();
        switch (n0){
        case 0:
            exit[0] = 1;
            break;
        case 1:
            while (exit[1] != 1){
                printf("---------------------\n");
                printf("--- Utility bills ---\n");
                printf("1.Electric bills\n");
                printf("2.Water bills\n");
                printf("0.Return\n");
                printf("---------------------\n");
                printf("Please choose menu (0-2) : ");
                scanf("%d", &n1);
                clear();
                switch (n1){
                case 0:
                    exit[1] = 1;
                    break;
                case 1:
                    printf("--Electric bills--\n");
                    printf("Please enter bar code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("electric_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("electric_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;

                case 2:
                    printf("--Water bills--\n");
                    printf("Please enter bar code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("water_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("water_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                default:
                    printf("\n *** Please enter (0-2) *** \n");
                    break;
                }
            }
            exit[1] = 0;
            break;

        case 2:
            while (exit[2] != 1){
                printf("-------------------\n");
                printf("--- Phone bills ---\n");
                printf("1.TRUE bills\n");
                printf("2.AIS bills\n");
                printf("3.dtac bills\n");
                printf("4.CAT bills\n");
                printf("5.TOT bills\n");
                printf("0.Return\n");
                printf("-------------------\n");
                printf("Please choose menu (0-5) : ");
                scanf("%d", &n2);
                clear();
                switch (n2){
                case 0:
                    exit[2] = 1;
                    break;
                case 1:
                    printf("--TRUE bills--\n");
                    printf("Please enter Phone number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("true_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("true_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;

                case 2:
                    printf("--AIS bills--\n");
                    printf("Please enter Phone number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("ais_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("ais_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 3:
                    printf("--dtac bills--\n");
                    printf("Please enter Phone number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("dtac_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("dtac_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 4:
                    printf("--CAT bills--\n");
                    printf("Please enter Phone number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("cat_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("cat_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 5:
                    printf("--TOT bills--\n");
                    printf("Please enter Phone number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("tot_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("tot_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                default:
                    printf("\n*** Please enter (0-2) ***\n");
                    break;
                }
            }
            exit[2] = 0;
            break;
        case 3:
            while (exit[3] != 1)
            {
                printf("-------------------------\n");
                printf("--- Credit Card bills ---\n");
                printf("1.Citibank\n");
                printf("2.KTC\n");
                printf("3.AEON\n");
                printf("4.GHB\n");
                printf("5.First Choice\n");
                printf("0.Return\n");
                printf("-------------------------\n");
                printf("Please choose menu (0-5) : ");
                scanf("%d", &n3);
                clear();
                switch (n3)
                {
                case 0:
                    exit[3] = 1;
                    break;

                case 1:
                    printf("--Citibank--\n");
                    printf("Please enter card number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("citibank_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("citibank_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;

                case 2:
                    printf("--KTC--\n");
                    printf("Please enter card number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("ktc_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("ktc_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 3:
                    printf("--AEON--\n");
                    printf("Please enter card number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("aeon_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("aeon_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 4:
                    printf("--GHB--\n");
                    printf("Please enter card number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("ghb_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("ghb_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 5:
                    printf("--First Choice--\n");
                    printf("Please enter card number : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("first_choice_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("first_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                default:
                    printf("\n*** Please enter (0-5) ***\n");
                    break;
                }
            }
            exit[3] = 0;
            break;

        case 4:
            while (exit[4] != 1)
            {
                printf("------------------------------\n");
                printf("    --- Insurance bills ---\n");
                printf("1.AIA\n");
                printf("2.Muang Thai Life Premium\n");
                printf("3.Thai Life Insurance Premium\n");
                printf("4.Allianz Ayudhya\n");
                printf("5.Bangkok Insurance Premium\n");
                printf("0.Return\n");
                printf("------------------------------\n");
                printf("Please choose menu (0-5) : ");
                scanf("%d", &n4);
                clear();
                switch (n4)
                {
                case 0:
                    exit[4] = 1;
                    break;
                case 1:
                    printf("--AIA--\n");
                    printf("Please enter bill code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("aia_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("aia_bill", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;

                case 2:
                    printf("--Muang Thai Life Premium--\n");
                    printf("Please enter bill code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("muang_thai_life_premium_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("muang_thai", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 3:
                    printf("--Thai Life Insurance Premium--\n");
                    printf("Please enter bill code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("thai_life_insurance_premium_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("thai_life", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 4:
                    printf("--Allianz Ayudhya--\n");
                    printf("Please enter bill code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("allianz_ayudhya_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("allianz_a", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                case 5:
                    printf("--Bangkok Insurance Premium--\n");
                    printf("Please enter bill code : ");
                    scanf("%d", &temp);
                    printf("Please enter price : ");
                    scanf("%f", &money);
                    billing_sort_txt(money);
                    storage_data("bangkok_insurance_premium_bill", temp, money);
                    if(get_out == 0 ){
                        receipt_billing("bangkok_i", temp, money);
                    }
                    printf("\nPress any key to return...");
                    getch();
                    clear();
                    break;
                default:
                    printf("\n*** Please enter (0-4) ***\n");
                    break;
                }
            }
            exit[4]=0;
            break;

        default:
            printf("\n *** Please enter (0-4) *** \n");
            break;
        }
    }while(exit[0] != 1);
}

void billing_sort_txt(float n){
    struct sort_account{
        int id, password;
        float bal;
    }sort_acc;

    FILE *fp1, *fp2;
    fp1 = fopen("account.txt", "r+");
    fp2 = fopen("account.txt", "r+");

    while (!feof(fp1)){
        fscanf(fp1, "%d %d %f", &sort_acc.id, &sort_acc.password, &sort_acc.bal);
        if (idmain == sort_acc.id){
            if(n<0)
            {
                printf("\nCan't pay\n");
                get_out = 1;
                sort_acc.bal = sort_acc.bal;
            }
            else if (sort_acc.bal >= n){
                sort_acc.bal -= n;
                get_out = 0;
            }
            else{
                printf("\nNot enough money\n");
                get_out = 1;
                sort_acc.bal = sort_acc.bal;
            }
            printf("Yours account balance : %.2f\n", sort_acc.bal);
        }
        fprintf(fp2, "\n%d %d %.2f", sort_acc.id, sort_acc.password, sort_acc.bal);
    }
    fclose(fp1);
    fclose(fp2);
}

void storage_data(char str[], int code, float n){
    FILE *fp;
    fp = fopen("billing_data.txt", "a");
    fprintf(fp, "\n%s : %d ; %d ; %.2f", str, idmain, code, n);
    fclose(fp);
}

void admin(){
    clear();
    FILE *b1, *b2;
    well bank;
    int count=0,ch,doing, bank100, bank500, bank1000, nm, yn = 0, z = 0, sum, t1, t2, t3,err100,err500,err1000;
    printf("***************************************************************");
    printf("\n\n\t\t             Admin\n\n");
    printf("***************************************************************\n\n");
    printf("What do you want to do?\n");
    printf("1. Add money\n");
    printf("2. Take money\n");
    printf("3. Check banknote\n");
    printf("0. Exit\n");
    printf("\n***************************************************************\n");
    printf("Enter (0-3):");
    scanf("%d", &doing);
    switch (doing){
    case 0:
        printf("\n---- Good day,sir ----\n");
        exit(0);
    case 1:
        z=0;
        nm=0;
        clear();
        do{
            printf("***************************************************************");
            printf("\n\n\t\t           Add money\n\n");
            printf("***************************************************************\n\n");
            printf("--- Please give banknote ---\n");
            printf("Banknote 100 : ");
            scanf("%d", &bank100);
            printf("Banknote 500 : ");
            scanf("%d", &bank500);
            printf("Banknote 1000 : ");
            scanf("%d", &bank1000);
            nm = ((100 * bank100) + (500 * bank500) + (1000 * bank1000));
            clear();
            printf("--- Confirm? ---\n");
            printf("1.Yes \n2.No");
            printf("\nChoose (1-2) : ");
            scanf("%d", &yn);
            clear();
            if(yn == 1){
                b1 = fopen("bank.txt", "r+");
                b2 = fopen("bank.txt", "r+");
                while (!feof(b1)){
                    fscanf(b1, "%s %d", bank.ba, &bank.num);

                    if(z == 0){
                        bank.num = bank.num + bank1000;
                        t3 = bank.num;
                        z++;
                    }
                    else if(z == 1){
                        bank.num = bank.num + bank500;
                        t2 = bank.num;
                        z++;
                    }
                    else if(z == 2){
                        bank.num = bank.num + bank100;
                        t1 = bank.num;
                        z++;
                    }
                    fprintf(b2, "\n%s %d", bank.ba, bank.num);
                }
                fclose(b1);
                fclose(b2);
                printf("----------------------------------\n");
                printf("Please wait and check the money...\n");
                printf("Banknote100 : %d\n", t1);
                printf("Banknote500 : %d\n", t2);
                printf("Banknote1000 : %d\n", t3);
                printf("------------Successful------------");
            }
            else{
                yn = 0;
            }
        }while(yn == 0);
        printf("\nPress any key to return to menu...");
        getch();
        break;
    case 2:
        clear();
        nm=0;
            printf("***************************************************************");
            printf("\n\n\t\t           Take money\n\n");
            printf("***************************************************************\n\n");
            z = 0;
            printf("---------------------------------------------------------------\n");
            printf("\n                   Banknote in ATM right now\n\n");
            b1 = fopen("bank.txt", "r+");
            while(!feof(b1)){
                fscanf(b1,"%s %d",bank.ba,&bank.num);
                printf("%s : %d\n",bank.ba,bank.num);
            }
        printf("\n---------------------------------------------------------------\n");
           do{ printf("\n\n[1.] All\t\t [2.] Specific\n");
            printf("\nChoose : ");
            scanf("%d",&ch);
            clear();
            switch(ch)
            {
            case 1:
                b1 = fopen("bank.txt", "r");
                while (!feof(b1)){
                z++;
                fscanf(b1,"%s %d",bank.ba,&bank.num);
                if(z==1)
                {
                    t3=bank.num;
                    err1000=t3*1000;
                    bank.num=0;
                }
                else if(z==2)
                {
                    t2=bank.num;
                    err500=t2*500;
                    bank.num=0;
                }
                else if(z==3)
                {
                    t1=bank.num;
                    err100=t1*100;
                    bank.num=0;
                }
                }
                fclose(b1);
                b2 = fopen("bank.txt", "w");
            fprintf(b2,"\nBANKNOTE1000 %d",0);
            fprintf(b2,"\nBANKNOTE500 %d",0);
            fprintf(b2,"\nBANKNOTE100 %d",0);
            fclose(b2);

            printf("\n---- Please wait and check the money ----\n");
            printf("Left-Banknote100 : %d\n", 0);
            printf("Left-Banknote500 : %d\n", 0);
            printf("Left-Banknote1000 : %d\n", 0);
            printf("-----------------------------------------\n");
            nm = err1000+err500+err100;
            printf("\nYou will take %d Baht\n", nm);
            printf("---- Successful ----\n");
            z=0;
            count=1;
            printf("\nPress any key to return to menu...");
            getch();
            break;

            case 2:
                printf("\n---------------------------------------------------------------\n");
            printf("\n                        Give information\n");
            printf("\n---------------------------------------------------------------\n");
            fclose(b1);
            printf("Banknote 100 : ");
            scanf("%d", &bank100);
            printf("Banknote 500 : ");
            scanf("%d", &bank500);
            printf("Banknote 1000 : ");
            scanf("%d", &bank1000);
            clear();

            b1 = fopen("bank.txt", "r");
            while (!feof(b1)){
                z++;
                fscanf(b1,"%s %d",bank.ba,&bank.num);
                if (z == 1){
                    if(bank.num >= bank1000){
                    bank.num = bank.num - bank1000;
                    err1000 = bank1000*1000;
                    }
                    else{
                        printf("\n***Insufficient Banknote 1000***\n");
                        err1000 = 0;
                    }
                    t3 = bank.num;
                }
                else if (z == 2){
                    if(bank.num >= bank500){
                    bank.num = bank.num - bank500;
                    err500 = bank500*500;
                    }
                    else{
                        printf("\n***Insufficient Banknote 500***\n");
                        err500 = 0;
                    }
                    t2 = bank.num;
                }
                else if (z == 3){
                    if(bank.num >= bank100){
                    bank.num = bank.num - bank100;
                    err100 = bank100*100;
                    }
                    else{
                        printf("\n***Insufficient Banknote 100***\n");
                        err100 = 0;
                    }
                    t1 = bank.num;
                }
            }
            fclose(b1);
            b2 = fopen("bank.txt", "w");
            fprintf(b2,"\nBANKNOTE1000 %d",t3);
            fprintf(b2,"\nBANKNOTE500 %d",t2);
            fprintf(b2,"\nBANKNOTE100 %d",t1);
            fclose(b2);

            printf("\n---- Please wait and check the money ----\n");
            printf("Left-Banknote100 : %d\n", t1);
            printf("Left-Banknote500 : %d\n", t2);
            printf("Left-Banknote1000 : %d\n", t3);
            printf("-----------------------------------------\n");
            nm = err1000+err500+err100;
            printf("\nYou will take %d Baht\n", nm);
            printf("---- Successful ----\n");
            z=0;
            count=1;
        printf("\nPress any key to return to menu...");
        getch();
        break;
            default :
                printf("please choose only 1 or 2 :");
                count=0;
                break;
            }
            }while(count==0);
            break;

    case 3:
        clear();
        b1 = fopen("bank.txt", "r+");
        while (!feof(b1)){
            fscanf(b1, "%s %d", bank.ba, &bank.num);
            printf("Left-%s\t:\t%d \n", bank.ba, bank.num);
        }
        fclose(b1);
        printf("\nPress any key to return to menu...");
        getch();
        break;
    }
}

void transaction(void){
    clear();
    FILE *fp1, *fp2;
    int ac2, money2 = 0, m = 0, ex = 0;
    float tran;
    record account;
    fp1 = fopen("account.txt", "r+");
    fp2 = fopen("account.txt", "r+");
    printf("*********************************************************************");
    printf("\n\n\t\t            Transfer money\n\n");
    printf("*********************************************************************\n");
    printf("\nPlease enter destination account (6-digits): ");
    scanf("%d", &ac2);
    while (m == 0 && ex == 0){
        printf("\nPlease enter amount of money for transfer (At least 100 Baht) : ");
        scanf("%f", &tran);
        printf("\n");

        while (!feof(fp1) && ex != 1){
            fscanf(fp1, "%d %d %f", &account.id, &account.pass, &account.money);
            if (idmain == account.id){
                if (account.money < tran){
                    printf("Insufficient balance.");
                    printf("\n\n*********************************************************************\n");
                    ex = 1;
                }
                else if (tran < 100){
                    printf("At least 100.00 Baht.\n\n");
                    printf("*********************************************************************\n");
                    ex = 1;
                }
                else{
                    m++;
                }
            }
        }
    }
    fclose(fp1);
    fp1 = fopen("account.txt", "r+");
    while (!feof(fp1) && ex != 1){
        fscanf(fp1, "%d %d %f", &account.id, &account.pass, &account.money);

        if (ac2 == account.id){
            account.money = account.money + tran;
        }
        else if (idmain == account.id){
            account.money = account.money - tran;
        }
        fprintf(fp2, "\n%d %d %.2f", account.id, account.pass, account.money);
    }

    fclose(fp2);
    fclose(fp1);

    fp1 = fopen("account.txt", "r+");
    while (!feof(fp1) && ex != 1){
        fscanf(fp1, "%d %d %f", &account.id, &account.pass, &account.money);
        if (idmain == account.id){
            printf("ID : %d has %.2f Baht left", account.id, account.money);
            printf("\n\n*********************************************************************\n");
            receipt_trasfer(ac2, tran);
        }
    }
    fclose(fp1);
    printf("\nPress any key to return to menu...");
    getch();
    clear();
}

void checkmoney(){
    clear();
    FILE *fp1;
    fp1 = fopen("account.txt", "r+");
    record account;
    while (!feof(fp1)){
        fscanf(fp1, "%d %d %f", &account.id, &account.pass, &account.money);
        if (idmain == account.id){
            printf("***************************************************************");
            printf("\n\n\t\t        Account balance\n\n");
            printf("***************************************************************\n\n");
            printf("You account has %.2f baht\n", account.money);
            printf("\n***************************************************************\n");
        }
    }
    printf("\nPress any key to return to menu...");
    getch();
    clear();
}

void clear(){
    system("cls");
}

void receipt(void){
    FILE *read,*fp;
    read = fopen("receipt.txt", "r");
    time_t result = time(NULL);
    fp = fopen("account.txt","r");
    char ch[100];
    record acc;
    while (!feof(read)){
        fgets(ch, 100, read);
        printf("%s", ch);
    }
    while(!feof(fp)){
        fscanf(fp,"%d %d %f",&acc.id,&acc.pass,&acc.money);
        if(acc.id == idmain){
            balance = acc.money;
        }
    }

    printf("\n");
    fprintf(read, "Balance \t\t\t %.2f", balance);
    printf("\nId : %d\n",idmain);
    printf("Balance \t\t\t %.2f BAHT",balance);
    printf("\nDate/Time: %s", ctime(&result));
    printf("\n\n****************************************************\n");
    printf("\n\n           === Thank you for using ATM ===");
}
void receipt_deposit(int a){
    FILE *write;
    write = fopen("receipt.txt", "a");
    fprintf(write, "\nDeposit \t\t\t %d BAHT", a);
    fclose(write);
}
void receipt_deposit_register(int a){
    FILE *write;
    write = fopen("receipt.txt", "a");
    fprintf(write, "\nDeposit_at_register \t\t %d BAHT", a);
    fclose(write);
}
void receipt_withdraw(int a){
    FILE *write;
    write = fopen("receipt.txt", "a");
    fprintf(write, "\nWithdraw \t\t\t %d BAHT", a);
    fclose(write);
}
void receipt_trasfer(int a, float b){
    FILE *write;
    write = fopen("receipt.txt", "a");
    fprintf(write, "\nTrasfer to %d \t\t %.2f BAHT", a, b);
    fclose(write);
}
void receipt_billing(char a[100], int b, float c){
    FILE *write;
    write = fopen("receipt.txt", "a");
    fprintf(write, "\n%s:%d \t\t %.2f BAHT", a, b, c);
    fclose(write);
}
