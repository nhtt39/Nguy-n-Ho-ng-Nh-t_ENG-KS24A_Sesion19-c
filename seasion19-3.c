#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

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

void addStudent(struct Student students[], int *currentLength) {
    if (*currentLength >= 5) {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    
    struct Student newStudent;
    printf("Nhap ID sinh vien: ");
    scanf("%d", &newStudent.id);
    getchar();
    printf("Nhap ten sinh vien: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0;
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newStudent.age);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", newStudent.phoneNumber);
    
    students[*currentLength] = newStudent;
    (*currentLength)++;
    printf("Sinh vien da duoc them.\n");
}

void editStudent(struct Student students[], int currentLength) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            getchar();
            printf("Nhap ten moi sinh vien: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;
            printf("Nhap tuoi moi sinh vien: ");
            scanf("%d", &students[i].age);
            printf("Nhap so dien thoai moi sinh vien: ");
            scanf("%s", students[i].phoneNumber);
            printf("Thong tin sinh vien da duoc cap nhat.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void deleteStudent(struct Student students[], int *currentLength) {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--;  // Gi?m currentLength di 1
            printf("Sinh vien co ID %d da duoc xoa.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void searchStudent(struct Student students[], int currentLength) {
    int id;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("Sinh vien tim thay: ID: %d, Name: %s, Age: %d, Phone: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

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
    printf("Danh sach sinh vien da duoc sap xep.\n");
}

void showMenu() {
    printf("\nMENU\n");
    printf("1. Hien thi danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Tim kiem sinh vien\n");
    printf("6. Sap xep danh sach sinh vien\n");
    printf("7. Thoat\n");
    printf("Lua chon cua ban: ");
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
    
    int choice;
    do {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(students, currentLength);
                break;
            case 2:
                addStudent(students, &currentLength);
                break;
            case 3:
                editStudent(students, currentLength);
                break;
            case 4:
                deleteStudent(students, &currentLength);
                break;
            case 5:
                searchStudent(students, currentLength);
                break;
            case 6:
                sortStudentsByName(students, currentLength);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

