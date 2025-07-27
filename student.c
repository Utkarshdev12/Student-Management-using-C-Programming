#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[40];
    char guardian[40];
    char branch[10];
    char usn[20];
    char gender[7];
    int year;
    char phone[15];
    char add[20];
    char dob[10];
} STUDENT;

int main() {
    STUDENT s;
    int choice, recsize, id, choice1, y;
    FILE *fp, *ft;
    char q, another, name[40], search_usn[20];

    fp = fopen("studentdata.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("studentdata.dat", "wb+");
        if (fp == NULL) {
            printf("File cannot be accessed");
            getch();
            exit(1);
        }
    }

    recsize = sizeof(s);

    printf("\t\t  ***********************     \n");
    printf("\t\t**      STUDENT DATABASE     **\n");
    printf("\t\t  ***********************     \n\n");

    while (1) {
        printf("\n\n");
        printf("\t|=================|\n");
        printf("\t|___MAIN___MENU___|\n");
        printf("\t|=================|\n\n");
        printf("\t _____________________\n");
        printf("\t| [1]. List Records    |\n");
        printf("\t| [2]. Add Records     |\n");
        printf("\t| [3]. Delete Records  |\n");
        printf("\t| [4]. Modify Records  |\n");
        printf("\t| [5]. Search Records  |\n");
        printf("\t| [6]. Exit            |\n");
        printf("\t|_____________________|\n");

        printf("\n\n\tEnter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
            case 1:
                rewind(fp);
                printf("\n\t\t\t     |==================|\n");
                printf("\t\t\t     | LIST of STUDENTS |\n");
                printf("\t\t\t     |==================|\n\n");
                printf("%-20s %-15s %-20s %-15s %-10s %-4s\n", "NAME", "USN", "ADDRESS", "PHONE", "BRANCH", "YEAR");


                while ((fread(&s, recsize, 1, fp)) == 1) {
                    printf("%-20s %-15s %-20s %-15s %-10s %-4d\n", s.name, s.usn, s.add, s.phone, s.branch, s.year);

                }
                printf("\n\n");
                break;

            case 2:
                fseek(fp, 0, SEEK_END);
                another = 'Y';

                printf("\n\t\t\t     |======================|\n");
                printf("\t\t\t     | ADD STUDENT'S RECORD |\n");
                printf("\t\t\t     |======================|\n\n");

                while ((another == 'Y') || (another == 'y')) {
                    printf("Enter the student's name	: ");
                    fflush(stdin);
                    fgets(s.name, sizeof(s.name), stdin);
                    s.name[strcspn(s.name, "\n")] = '\0';

                    printf("Enter the USN			: ");
                    scanf("%s", s.usn);

                    printf("Enter the branch		: ");
                    scanf("%s", s.branch);

                    printf("Enter the Address		: ");
                    scanf("%s", s.add);

                    printf("Enter the phone no.		: ");
                    scanf("%s", s.phone);

                    printf("Enter the year joined		: ");
                    scanf("%d", &s.year);

                    fflush(stdin);
                    printf("Enter the Guardian's name	: ");
                    fgets(s.guardian, sizeof(s.guardian), stdin);
                    s.guardian[strcspn(s.guardian, "\n")] = '\0';

                    printf("Enter the Date of Birth		: ");
                    scanf("%s", s.dob);

                    printf("Enter the Gender		: ");
                    scanf("%s", s.gender);

                    fwrite(&s, recsize, 1, fp);
                    printf("Add another Record (Y/N): ");
                    fflush(stdin);
                    another = getchar();
                    printf("\n");
                }
                break;

            case 3:
                another = 'Y';
                printf("\n\t\t\t     |=========================|\n");
                printf("\t\t\t     | DELETE STUDENT'S RECORD |\n");
                printf("\t\t\t     |=========================|\n\n");

                while ((another == 'Y') || (another == 'y')) {
                    printf("Enter the name of the student to be deleted: ");
                    fflush(stdin);
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';

                    rewind(fp);
                    int found = 0;

                    ft = fopen("TEMP.dat", "wb");

                    while (fread(&s, recsize, 1, fp) == 1) {
                        if (strcmp(s.name, name) == 0) {
                            found = 1;
                            printf("\nName: %s\n", s.name);
                            printf("Gender: %s\nDOB: %s\n", s.gender, s.dob);
                            printf("Guardian: %s\n", s.guardian);
                            printf("Branch: %s\nUSN: %s\nYear: %d\nAddress: %s\nPhone: %s\n",
                                   s.branch, s.usn, s.year, s.add, s.phone);
                            printf("Confirm Data Delete (Y/N): ");
                            fflush(stdin);
                            q = getchar();
                            if (q == 'y' || q == 'Y') continue;
                        }
                        fwrite(&s, recsize, 1, ft);
                    }

                    fclose(fp);
                    fclose(ft);
                    remove("studentdata.dat");
                    rename("TEMP.dat", "studentdata.dat");
                    fp = fopen("studentdata.dat", "rb+");

                    if (!found) {
                        printf("Sorry!! No match Found\n\n");
                    }

                    printf("Do you want to Delete another Record (Y/N): ");
                    fflush(stdin);
                    another = getchar();
                }
                break;

            case 4:
                another = 'Y';
                printf("\n\t\t\t     |=========================|\n");
                printf("\t\t\t     | MODIFY STUDENT'S RECORD |\n");
                printf("\t\t\t     |=========================|\n\n");

                while ((another == 'Y') || (another == 'y')) {
                    printf("Enter name of student to modify : ");
                    fflush(stdin);
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0';

                    rewind(fp);

                    while (fread(&s, recsize, 1, fp) == 1) {
                        if (strcmp(s.name, name) == 0) {
                            printf("Current Record: %s, %s\n", s.name, s.usn);

                            printf("Enter new name			: ");
                            fflush(stdin);
                            fgets(s.name, sizeof(s.name), stdin);
                            s.name[strcspn(s.name, "\n")] = '\0';

                            printf("Enter new USN			: ");
                            scanf("%s", s.usn);

                            printf("Enter new branch		: ");
                            scanf("%s", s.branch);

                            printf("Enter new address		: ");
                            scanf("%s", s.add);

                            printf("Enter new phone no.		: ");
                            scanf("%s", s.phone);

                            printf("Enter new year joined	: ");
                            scanf("%d", &s.year);

                            fflush(stdin);
                            printf("Enter new guardian name	: ");
                            fgets(s.guardian, sizeof(s.guardian), stdin);
                            s.guardian[strcspn(s.guardian, "\n")] = '\0';

                            printf("Enter new DOB			: ");
                            scanf("%s", s.dob);

                            printf("Enter new gender		: ");
                            scanf("%s", s.gender);

                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&s, recsize, 1, fp);
                            break;
                        }
                    }

                    printf("Do you want to Modify another record (Y/N): ");
                    fflush(stdin);
                    another = getchar();
                }
                break;

            case 5:
                another = 'Y';
                printf("\n\t\t\t     |=========================|\n");
                printf("\t\t\t     | SEARCH STUDENT'S RECORD |\n");
                printf("\t\t\t     |=========================|\n\n");

                while ((another == 'Y') || (another == 'y')) {
                    rewind(fp);
                    printf("Search By:\n[1] Name\n[2] USN\nEnter your choice: ");
                    scanf("%d", &choice1);

                    if (choice1 == 1) {
                        printf("Enter name	: ");
                        fflush(stdin);
                        fgets(name, sizeof(name), stdin);
                        name[strcspn(name, "\n")] = '\0';

                        int found = 0;
                        rewind(fp);
                        while (fread(&s, recsize, 1, fp) == 1) {
                            if (strcmp(s.name, name) == 0) {
                                found = 1;
                                printf("Name: %s\nDOB: %s\nGender: %s\nGuardian: %s\nBranch: %s\nUSN: %s\nYear: %d\nAddress: %s\nPhone: %s\n\n",
                                       s.name, s.dob, s.gender, s.guardian, s.branch, s.usn, s.year, s.add, s.phone);
                                break;
                            }
                        }

                        if (!found) {
                            printf("No match found!\n");
                        }
                    } else if (choice1 == 2) {
                        printf("Enter USN          : "); scanf("%s", search_usn);
                        printf("Enter Year joined  : "); scanf("%d", &y);

                        int found = 0;
                        rewind(fp);
                        while (fread(&s, recsize, 1, fp) == 1) {
                            if ((strcmp(s.usn, search_usn) == 0) && s.year == y) {
                                found = 1;
                                printf("Name: %s\nDOB: %s\nGender: %s\nGuardian: %s\nBranch: %s\nUSN: %s\nYear: %d\nAddress: %s\nPhone: %s\n\n",
                                       s.name, s.dob, s.gender, s.guardian, s.branch, s.usn, s.year, s.add, s.phone);
                                break;
                            }
                        }

                        if (!found) {
                            printf("No match found!\n");
                        }
                    } else {
                        printf("INVALID CHOICE\n");
                    }

                    printf("Do you want to Search another record (Y/N): ");
                    fflush(stdin);
                    another = getchar();
                }
                break;

            case 6:
                fclose(fp);
                printf("\nThank You for using our program... :)\n");
                getch();
                exit(0);
                break;

            default:
                printf("INVALID CHOICE\n");
                getch();
        }
    }

    fclose(fp);
    return 0;
}
