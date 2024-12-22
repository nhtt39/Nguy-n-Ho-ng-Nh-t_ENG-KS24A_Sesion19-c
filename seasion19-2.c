#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void sortStudentsByName(struct Student students[], int currentLength) {
    struct Student temp;
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(struct Student students[], int currentLength) {
    if (currentLength == 0) {
        printf("Khong co sinh vien trong danh sach.\n");
        return;
    }
    
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Minh C", 22, "0912345678"},
        {4, "Pham Mai D", 23, "0934567890"},
        {5, "Hoang Son E", 24, "0945678901"}
    };
    int currentLength = 5; 

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);

    sortStudentsByName(students, currentLength);
    
    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, currentLength);

    return 0;
}

