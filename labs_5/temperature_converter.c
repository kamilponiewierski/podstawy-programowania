
// author: Kamil Poniewierski
#include <stdio.h>
#include <stdlib.h>


double kelvinToCelsius(double kelvin)
{
    return kelvin - 273.15;
}

double celsiusToKelvin(double celsius)
{
    return celsius + 273.15;
}


double kelvinToFahr(double kelvin)
{
    return kelvin * 9 / 5 - 459.67;
}

double celsiusToFahr(double celsius)
{
    return kelvinToFahr(celsiusToKelvin(celsius));
}

double fahrToKelvin(double fahr)
{
    return (fahr + 459.67) * 5 / 9;
}

double fahrToCelsius(double fahr)
{
    return kelvinToCelsius(fahrToKelvin(fahr));
}


void printConversionsFromCelsius(double celsius)
{
    printf("%.2lfC = %.2lfF = %.2lfK\n", celsius, celsiusToFahr(celsius), celsiusToKelvin(celsius));
}

void printConversionsFromKelvin(double kelvin)
{
    printf("%.2lfK = %.2lfC = %.2lfF\n", kelvin, kelvinToCelsius(kelvin), kelvinToFahr(kelvin));
}


void printConversionsFromFahr(double fahr)
{
    printf("%.2lfF= %.2lfC = %.2lfK\n", fahr, fahrToCelsius(fahr), fahrToKelvin(fahr));

}

int main()
{
    double temperature;

    int parsedNumbers = scanf("%lf", &temperature);
    if (parsedNumbers == 0) {
        printf("Input error");
        exit(0);
    }

    printConversionsFromCelsius(temperature);
    printConversionsFromFahr(temperature);
    printConversionsFromKelvin(temperature);

    return 0;
}