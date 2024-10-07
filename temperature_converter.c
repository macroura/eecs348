#include <stdio.h>

float celsius_to_fahrenheit(float num) {
    return (num*9/5) + 32;
}

float fahrenheit_to_celsius(float num) {
    return (num-32)*5/9;
}

float celsius_to_kelvin(float num) {
    return num+273.15;
}

float kelvin_to_celsius(float num) {
    return num-273.15;
}

float fahrenheit_to_kelvin(float num) {
    return ((num*9/5) + 32)+273.15;
}

float kelvin_to_fahrenheit(float num) {
    return (((num-273.15)*9/5) + 32);
}

void categorize_temperature(float num){
    
    if (num < 0){
        printf("Don't go outside, it's freezing\n");
    } else if (num <= 10) {
        printf("Wear a jacket, it's cold.\n");
    } else if (num <= 25) {
        printf("It's comfortable, wear a t-shirt.\n");
    } else if (num <= 35) {
        printf("It's hot, go swimming.\n");
    } else {
        printf("Extreme heat. Stay indoors.\n");
    }
        
    
    
}

int main() {
    char input_type[10];
    printf("What temperature are you converting from? (k,f,c): ");
    scanf("%s", input_type);

    char target_type[10];
    printf("What temperature are you converting to? (k,f,c): ");
    scanf("%s", target_type);

    float number;
    printf("What temperature are you converting?: ");
    scanf("%f", &number);

    float converted_number;
    int valid = 0;

    if (input_type[0] == 'c' && target_type[0] == 'f') {
        converted_number = celsius_to_fahrenheit(number);
        valid = 1;
        categorize_temperature(number);
    } else if (input_type[0] == 'f' && target_type[0] == 'c') {
        converted_number = fahrenheit_to_celsius(number);
        valid = 1;
        categorize_temperature(converted_number);
    } else if (input_type[0] == 'c' && target_type[0] == 'k') {
        converted_number = celsius_to_kelvin(number);
        valid = 1;
        categorize_temperature(number);
    } else if (input_type[0] == 'k' && target_type[0] == 'c') {
        converted_number = kelvin_to_celsius(number);
        valid = 1;
        categorize_temperature(converted_number);
    } else if (input_type[0] == 'k' && target_type[0] == 'f') {
        converted_number = kelvin_to_fahrenheit(number);
        valid = 1;
        categorize_temperature(number-273.15);
    } else if (input_type[0] == 'f' && target_type[0] == 'k') {
        converted_number = fahrenheit_to_kelvin(number);
        valid = 1;
        categorize_temperature(number+273.15);
    }

    if (valid == 1) {
        printf("%f degrees %s is %f degrees %s\n", number, input_type, converted_number, target_type);
    
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
