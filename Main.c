/*************************************************************************************
* Name: Nur Liyana Binti Zaiman
* Course: CISB134 (Structured Programming with C)
* Date: 30/12/2020
* Question: Phase 4 (Individual Assignment)
* Brief Description: Read the electrcity & water usage. Then, calculate the 
electricity & water charge.
Calculate and display the Monthly Savings, Monthly 
Expenses, Expenses for a Year, Monthly Balance, Savings for a Year for Nazwa Latifah. 
The program should allow her to select and print the total expenses of a particular month.
*************************************************************************************/
#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define month 12
float readE_usage(void);
float readW_usage(void);
void totalExpenses(float);
void totalSavings(float);

void main()
{
    //Put all the identifiers needed
    int i, income;
    char x[10];
    float EPF, house_rent, internet, expenses_yearly = 0, savings_yearly = 0;
    float savings_monthly[month], expenses_monthly[month], e_charge[month], 
    water_charge[month], balance_monthly[month];//Arrays

    for (i = 0; i < month; i++)//Loop for 12 months
    {
        //Read savings monthly 
        printf("Enter amount that you want to save on month %d: ", i + 1);
        scanf_s("%f", &savings_monthly[i]);
        
        //Read and calc electric & water charge
        e_charge[i] = readE_usage();
        water_charge[i] = readW_usage();

        //Define income, house rent, internet & EPF values
        income = 2450;
        house_rent = 300;
        internet = 75;
        EPF = 0.07 * income;
        
        //Calculations
        expenses_monthly[i] = house_rent + internet + e_charge[i] + water_charge[i];// monthly expenses
        balance_monthly[i] = income - expenses_monthly[i] - EPF - savings_monthly[i];//balance monthly
        expenses_yearly = expenses_yearly + expenses_monthly[i];//yearly expenses
        savings_yearly = savings_yearly + EPF + savings_monthly[i];//savings yearly
        
        //print the monthly expenses & balance 
        printf("\nYour expenses for month %d: %.2f\n", i + 1, expenses_monthly[i]);
        printf("Your amount of money left for month %d: %.2f\n", i + 1, balance_monthly[i]);
        printf("--------------------------------------------------\n");
    }
    
    //print yearly expenses & savings
    totalExpenses(expenses_yearly);
    totalSavings(savings_yearly);

    //get particular month
    printf("\nSelect Month: ");
    scanf_s("%s", &x);

    //using string compare
    if (strcmp(x, "January") == 0) {
        i = 0;
    }
    else if (strcmp(x, "February") == 0) {
        i = 1;
    }
    else if (strcmp(x, "Mac") == 0) {
        i = 2;
    }
    else if (strcmp(x, "April") == 0) {
        i = 3;
    }
    else if (strcmp(x, "May") == 0) {
        i = 4;
    }
    else if (strcmp(x, "June") == 0) {
        i = 5;
    }
    else if (strcmp(x, "July") == 0) {
        i = 6;
    }
    else if (strcmp(x, "August") == 0) {
        i = 7;
    }
    else if (strcmp(x, "September") == 0) {
        i = 8;
    }
    else if (strcmp(x, "October") == 0) {
        i = 9;
    }
    else if (strcmp(x, "November") == 0) {
        i = 10;
    }
    else if (strcmp(x, "December") == 0) {
        i = 11;
    }
    else {
        printf("Invalid months");
    }

    printf("Electricity charge: RM%.2f\n", e_charge[i]);
    printf("Water charge: RM%.2f\n", water_charge[i]);
    printf("Internet: RM%.2f\n", internet);
    printf("House rent: RM%.2f\n", house_rent);
    printf("Savings: RM%.2f\n", savings_monthly[i]);
    }

    float readE_usage(void)//function electricity usage
    {
        int elec_usage;
        float e_charge;

        do {
            //Get electricity usage
                printf("Please enter your electricity usage a month : ");
                scanf_s("%d", &elec_usage);

            //if else condition for electricity usage
            if (elec_usage > 0 && elec_usage <= 200)
            {
                e_charge = (elec_usage * 0.218);
            if (e_charge < 3)
                e_charge = 3;
            else
                e_charge = e_charge;
            }
            else if (elec_usage > 200 && elec_usage <= 300)
            {
                e_charge = 43.6 + ((elec_usage - 200) * 0.334);
            }
            else if (elec_usage > 300 && elec_usage <= 400)
            {
                e_charge = 77 + ((elec_usage - 300) * 0.400);
            }
            else if (elec_usage > 400 && elec_usage <= 501)
            {
                e_charge = 117 + ((elec_usage - 400) * 0.402);
            }
            else if (elec_usage > 500 && elec_usage <= 600)
            {
                e_charge = 157.2 + ((elec_usage - 500) * 0.416);
            }
            else if (elec_usage > 600 && elec_usage <= 700)
            {
                e_charge = 198.8 + ((elec_usage - 600) * 0.426);
            }
            else if (elec_usage > 700 && elec_usage <= 800)
            {
                e_charge = 241.4 + ((elec_usage - 700) * 0.437);
            }
            else if (elec_usage > 800 && elec_usage <= 900)
            {
                e_charge = 285.1 + ((elec_usage - 800) * 0.453);
            }
            else if (elec_usage > 900)
            {
                e_charge = 330.4 + ((elec_usage - 900) * 0.454);
            }
            else {
                printf("Invalid number. Electricity usage must be bigger than 
            0.");
            }
        } while (elec_usage < 0); //loop if electricity usage is negative value
            return e_charge;
    }

    float readW_usage(void)//function water usage
    {
        int water_usage;
        float water_charge;

        //Get water consumption usage
        do {
        printf("Please enter your water consumption a month : ");
        scanf_s("%d", &water_usage);

        //if else condition for water consumption
        if (water_usage > 0 && water_usage <= 20)
        {
            water_charge = (water_usage * 0.57);
        if (water_charge < 6)
            water_charge = 6;
        else
            water_charge = water_charge;
        }
        else if (water_usage > 20 && water_usage <= 35)
        {
            water_charge = 6 + 11.4 + ((water_usage - 20) * 1.03);
        }
        else if (water_usage > 35)
        {
            water_charge = 6 + 26.85 + ((water_usage - 35) * 2.00);
        }
        else {
            printf("Invalid number. Water consumption must be bigger than 0.");
        }
        } while (water_usage < 0);//loop if water usage is negative value
            return water_charge;
    }

    void totalExpenses(float expenses_yearly)//function to print yearly expenses
    {
        printf("\nYour yearly expenses is : %.2f\n", expenses_yearly);
    }

    void totalSavings(float savings_yearly)//function to print the yearly expenses
    {
        printf("Your total amount of savings for a year: %.2f\n", savings_yearly);
    }