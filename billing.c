#include <stdio.h>

/* Prices (rupees) */
const double PRICE_TEA = 10.0;
const double PRICE_COFFEE = 15.0;
const double PRICE_BURGER = 60.0;
const double PRICE_PIZZA = 120.0;
const double PRICE_SANDWICH = 50.0;
const double PRICE_COLD_DRINK = 25.0;

/* Tax / discount */
const double GST_RATE = 0.18;             /* 18% */
const double DISCOUNT_RATE = 0.05;        /* 5% */
const double DISCOUNT_THRESHOLD = 1000.0; /* discount if subtotal > 1000 */

/* Global quantities */
int qty_tea = 0;
int qty_coffee = 0;
int qty_burger = 0;
int qty_pizza = 0;
int qty_sandwich = 0;
int qty_cold_drink = 0;

/* Function prototypes */
void show_main_menu(void);
void show_items_menu(void);
void add_item(void);
double calculate_subtotal(void);
void print_receipt(double subtotal);
void checkout(void);
void reset_order(void);
int read_int(void);
double read_double(void);

/* --- Menus and actions --- */

void show_main_menu(void)
{
    printf("\nMain Menu:\n");
    printf("1. Add Item\n");
    printf("2. Show Receipt\n");
    printf("3. Checkout / Pay\n");
    printf("4. Reset Order\n");
    printf("5. Exit\n");
}

void show_items_menu(void)
{
    printf("\nItems Menu:\n");
    printf("1. Tea        - Rs %.2f\n", PRICE_TEA);
    printf("2. Coffee     - Rs %.2f\n", PRICE_COFFEE);
    printf("3. Burger     - Rs %.2f\n", PRICE_BURGER);
    printf("4. Pizza      - Rs %.2f\n", PRICE_PIZZA);
    printf("5. Sandwich   - Rs %.2f\n", PRICE_SANDWICH);
    printf("6. Cold Drink - Rs %.2f\n", PRICE_COLD_DRINK);
    printf("0. Cancel\n");
}

void add_item(void)
{
    int choice, qty;

    show_items_menu();
    printf("Choose item number (0 to cancel): ");
    choice = read_int();

    if (choice == 0)
    {
        printf("Add cancelled.\n");
        return;
    }

    if (choice < 0 || choice > 6)
    {
        printf("Invalid item choice.\n");
        return;
    }

    printf("Enter quantity: ");
    qty = read_int();
    if (qty <= 0)
    {
        printf("Quantity must be positive.\n");
        return;
    }

    switch (choice)
    {
    case 1:
        qty_tea += qty;
        break;
    case 2:
        qty_coffee += qty;
        break;
    case 3:
        qty_burger += qty;
        break;
    case 4:
        qty_pizza += qty;
        break;
    case 5:
        qty_sandwich += qty;
        break;
    case 6:
        qty_cold_drink += qty;
        break;
    default:
        break;
    }

    printf("Added %d of item %d to the order.\n", qty, choice);
}

/* Compute subtotal from global quantities */
double calculate_subtotal(void)
{
    double subtotal = 0.0;

    double tea_cost = qty_tea * PRICE_TEA;
    double coffee_cost = qty_coffee * PRICE_COFFEE;
    double burger_cost = qty_burger * PRICE_BURGER;
    double pizza_cost = qty_pizza * PRICE_PIZZA;
    double sandwich_cost = qty_sandwich * PRICE_SANDWICH;
    double cold_drink_cost = qty_cold_drink * PRICE_COLD_DRINK;

    subtotal = tea_cost + coffee_cost + burger_cost + pizza_cost + sandwich_cost + cold_drink_cost;

    return subtotal;
}

/* Print a neat receipt */
void print_receipt(double subtotal)
{
    double gst = subtotal * GST_RATE;
    double discount = 0.0;

    if (subtotal > DISCOUNT_THRESHOLD)
        discount = subtotal * DISCOUNT_RATE;

    double grand_total = subtotal + gst - discount;

    printf("\n===== RECEIPT =====\n");
    printf("Item        Qty   Amount\n");
    printf("-------------------------------\n");

    if (qty_tea)
        printf("Tea         %d    %.2f\n", qty_tea, qty_tea * PRICE_TEA);

    if (qty_coffee)
        printf("Coffee      %d    %.2f\n", qty_coffee, qty_coffee * PRICE_COFFEE);

    if (qty_burger)
        printf("Burger      %d    %.2f\n", qty_burger, qty_burger * PRICE_BURGER);

    if (qty_pizza)
        printf("Pizza       %d    %.2f\n", qty_pizza, qty_pizza * PRICE_PIZZA);

    if (qty_sandwich)
        printf("Sandwich    %d    %.2f\n", qty_sandwich, qty_sandwich * PRICE_SANDWICH);

    if (qty_cold_drink)
        printf("Cold Drink  %d    %.2f\n", qty_cold_drink, qty_cold_drink * PRICE_COLD_DRINK);

    printf("-------------------------------\n");

    printf("Subtotal:          %.2f\n", subtotal);
    printf("GST (18%%):         %.2f\n", gst);

    if (discount > 0)
        printf("Discount:         -%.2f\n", discount);

    printf("Grand Total:       %.2f\n", grand_total);
    printf("===============================\n");
}

/* Checkout: show receipt, accept payment, handle change or insufficient */
void checkout(void)
{
    double subtotal = calculate_subtotal();

    if (subtotal == 0.0)
    {
        printf("No items to checkout.\n");
        return;
    }

    print_receipt(subtotal);

    double gst = subtotal * GST_RATE;
    double discount = 0.0;
    if (subtotal > DISCOUNT_THRESHOLD)
    {
        discount = subtotal * DISCOUNT_RATE;
    }
    double grand_total = subtotal + gst - discount;

    printf("\nGrand Total: Rs %.2f\n", grand_total);
    printf("Enter amount paid: ");
    double paid = read_double();

    if (paid > grand_total)
    {
        printf("Payment accepted. Change: Rs %.2f\n", paid - grand_total);
        printf("Thank you!\n");
        reset_order(); /* start fresh after successful payment */
    }

    else if (paid == grand_total)
    {
        printf("Payment accepted.");
        printf("Thank you!\n");
        reset_order(); /* start fresh after successful payment */
    }

    else
    {
        printf("Insufficient payment. Rs %.2f outstanding.\n", grand_total - paid);
        printf("You can either pay remaining amount or reset the order from main menu.\n");
    }
}

/* Reset global quantities */
void reset_order(void)
{
    qty_tea = 0;
    qty_coffee = 0;
    qty_burger = 0;
    qty_pizza = 0;
    qty_sandwich = 0;
    qty_cold_drink = 0;
}

/* --- Simple input helpers --- */

int read_int(void)
{
    int x;
    while (1)
    {
        if (scanf("%d", &x) == 1)
        {
            return x;
        }
        else
        {
            printf("Invalid input. Please enter an integer: ");
            while (getchar() != '\n')
                ; // clear buffer
        }
    }
}

double read_double(void)
{
    double x;
    while (1)
    {
        if (scanf("%lf", &x) == 1)
            return x;
        else
        {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n')
                ;
        }
    }
}

int main(void)
{
    int running = 1;
    int choice;

    printf("=== Simple Billing System ===\n");

    while (running)
    {
        show_main_menu();
        printf("Enter choice: ");
        choice = read_int();

        switch (choice)
        {
        case 1:
            add_item();
            break;

        case 2:
        {
            double subtotal = calculate_subtotal();
            if (subtotal == 0.0)
                printf("No items in the order yet.\n");
            else
                print_receipt(subtotal);
            break;
        }

        case 3:
            checkout();
            break;

        case 4:
            reset_order();
            printf("Order has been reset. New bill started.\n");
            break;

        case 5:
            running = 0;
            printf("Exiting. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter 1-5.\n");
        }
    }

    return 0;
}
