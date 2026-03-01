#include <stdio.h>

// conversion functions => all theses formulas werer given to us in the lab pdf all i did was make them
// into functions so its easier to reuse them for this program also my main will look simpler / less confusing for me in the long run
float celsius_to_fahrenheit(float tempC) { return (9.0f / 5.0f) * tempC + 32.0f; }
float fahrenheit_to_celsius(float tempF) { return (5.0f / 9.0f) * (tempF - 32.0f); }
float celsius_to_kelvin(float tempC) { return tempC + 273.15f; }
float kelvin_to_celsius(float tempK) { return tempK - 273.15f; }

// This void is just about category based on Celsius
// What it will do is print out a certain messaged all depending on how hot or cold ths user input is
// I used celsius becausae in the pdf everything was getting converted into cel first so yea
// We hadent gone over loops yet so i just did if and else statments which still works but loop would of been faster
void categorize_temperature(float tempC)
{
    if (tempC < 0)
        printf("Freezing - Wear a jacket.\n");
    else if (tempC < 10)
        printf("Cold - Bundle up.\n");
    else if (tempC < 25)
        printf("Comfortable - Nice outside.\n");
    else if (tempC <= 35)
        printf("Hot - Drink water.\n");
    else
        printf("Extreme Heat - Stay indoors.\n");
}

int main()
{ // just simple variable name that will store user info/input + make it into converstions
    float inputTemp, tempC, outputTemp;
    char scaleFrom, scaleTo;

    int valid = 0; // loop flag so program keeps asking until input is good we finnaly learned how to do them in lecture so now my program wont just end

    while (!valid) // while its not valid
    {
        printf("Enter temperature value: "); // ask user for temp #
        scanf("%f", &inputTemp);

        printf("From scale (C/F/K): ");
        scanf(" %c", &scaleFrom); // notice the spave before %c very helpfult to aviod user input erros

        printf("To scale (C/F/K): ");
        scanf(" %c", &scaleTo);

        // This just make lowercase work too because C is case sensitive and my program just kept ending so ima just do it this way so it wont
        // just end and not bring user back because they might of accdenily used lower case cfk instead of CFK. i dont know if theses is need but it makes sense to me
        if (scaleFrom == 'c')
            scaleFrom = 'C';
        if (scaleFrom == 'f')
            scaleFrom = 'F';
        if (scaleFrom == 'k')
            scaleFrom = 'K';

        if (scaleTo == 'c')
            scaleTo = 'C';
        if (scaleTo == 'f')
            scaleTo = 'F';
        if (scaleTo == 'k')
            scaleTo = 'K';

        // quick check to make sure they actually typed C/F/K
        if ((scaleFrom != 'C' && scaleFrom != 'F' && scaleFrom != 'K') ||
            (scaleTo != 'C' && scaleTo != 'F' && scaleTo != 'K'))
        {
            printf("Invalid input scale.\n");
            continue;
        }

        // Just quick error check making sure it cannot convert to the same scale
        if (scaleFrom == scaleTo)
        {
            printf("Invalid choice: same scale.\n");
            continue;
        }

        // k temp cant be negative
        if (scaleFrom == 'K' && inputTemp < 0)
        {
            printf("Invalid Kelvin (cannot be negative).\n");
            continue;
        }

        valid = 1; // if we reach here input is valid so exit loop
    }

    // just convert input to Cel first just makes it ova easier to understand
    if (scaleFrom == 'C')
        tempC = inputTemp;
    else if (scaleFrom == 'F')
        tempC = fahrenheit_to_celsius(inputTemp);
    else // scaleFrom must be 'K' here
        tempC = kelvin_to_celsius(inputTemp);

    // once the program has cel it contrvertes it to what the user wants it to be
    if (scaleTo == 'C')
        outputTemp = tempC;
    else if (scaleTo == 'F')
        outputTemp = celsius_to_fahrenheit(tempC);
    else // scaleTo must be 'K' here
        outputTemp = celsius_to_kelvin(tempC);

    categorize_temperature(tempC);

    printf("Converted: %.2f %c\n", outputTemp, scaleTo);

    return 0; // program ran smoothly
}