#include <stdio.h>
#include <stdbool.h>

void print_combo(int combo[], int length) {
    int amounts[5] = {0, 0, 0, 0, 0};  
    for (int i = 0; i < length; i++) {
        if (combo[i] == 2) amounts[0]++;
        else if (combo[i] == 3) amounts[1]++;
        else if (combo[i] == 6) amounts[2]++;
        else if (combo[i] == 7) amounts[3]++;
        else if (combo[i] == 8) amounts[4]++;
    }
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", amounts[4], amounts[3], amounts[2], amounts[1], amounts[0]);
}

bool arrays_equal(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
bool combo_exists(int combos[][100], int combo[], int combo_count, int length) {
    for (int i = 0; i < combo_count; i++) {
        if (arrays_equal(combos[i], combo, length)) return true;
    }
    return false;
}
void find_combos(int n, int combo[], int length, int combos[][100], int *combo_count) {
    if (n == 0) {
        if (!combo_exists(combos, combo, *combo_count, length)) {
            for (int i = 0; i < length; i++) {
                combos[*combo_count][i] = combo[i];
            }
            (*combo_count)++;
            print_combo(combo, length);
        }
    } else if (n > 0) {
        int new_combo[100];
        for (int i = 0; i < length; i++) {
            new_combo[i] = combo[i];
        }
        new_combo[length] = 2; find_combos(n - 2, new_combo, length + 1, combos, combo_count);
        new_combo[length] = 3; find_combos(n - 3, new_combo, length + 1, combos, combo_count);
        new_combo[length] = 6; find_combos(n - 6, new_combo, length + 1, combos, combo_count);
        new_combo[length] = 7; find_combos(n - 7, new_combo, length + 1, combos, combo_count);
        new_combo[length] = 8; find_combos(n - 8, new_combo, length + 1, combos, combo_count);
    }
}
int main() {
    int target;
    printf("What Number?\n");
    scanf("%d", &target);
    if (target>2){
    int combos[100][100];  
    int combo[100];        
    int combo_count = 0;   
    find_combos(target, combo, 0, combos, &combo_count);} else {printf("Number too small.");}
    return 0;
}
