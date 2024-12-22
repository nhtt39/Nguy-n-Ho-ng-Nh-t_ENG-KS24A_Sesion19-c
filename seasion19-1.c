#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void deleteStudent(int id, struct Student students[], int *currentLength) {
    int i, j;
    int found = 0;

    for (i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;
            printf("Sinh vien co id %d da duoc xoa.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi id %d.\n", id);
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

    int idToDelete;
    printf("\nNhap id sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    deleteStudent(idToDelete, students, &currentLength);

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    printStudents(students, currentLength);

    return 0;
}

