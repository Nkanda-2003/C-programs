#include <stdio.h>      // Standard input/output functions
#include <string.h>     // String handling functions

// Define a structure called Book
struct Book
{
    int bookID;             // Stores book ID
    char title[50];         // Stores book title
    char author[50];        // Stores author name
    int quantity;           // Stores number of copies
};

// Create an array of structures to store books
struct Book library[100];

// Variable to count total books
int count = 0;

// Function to add a new book
void addBook()
{
    // Ask user to enter Book ID
    printf("\nEnter Book ID: ");
    scanf("%d", &library[count].bookID);

    // Ask user to enter Book Title
    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[count].title);

    // Ask user to enter Author Name
    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[count].author);

    // Ask user to enter Quantity
    printf("Enter Quantity: ");
    scanf("%d", &library[count].quantity);

    // Increase book counter
    count++;

    // Display success message
    printf("\nBook Added Successfully!\n");
}

// Function to display all books
void displayBooks()
{
    int i;  // Loop variable

    // Check if no books exist
    if(count == 0)
    {
        printf("\nNo books available.\n");
        return;
    }

    // Display heading
    printf("\n===== BOOK LIST =====\n");

    // Loop through all stored books
    for(i = 0; i < count; i++)
    {
        printf("\nBook ID: %d", library[i].bookID);
        printf("\nTitle: %s", library[i].title);
        printf("\nAuthor: %s", library[i].author);
        printf("\nQuantity: %d\n", library[i].quantity);
    }
}

// Function to search a book by ID
void searchBook()
{
    int id;         // Stores entered ID
    int i;          // Loop variable
    int found = 0; // Flag variable

    // Ask user for Book ID
    printf("Enter Book ID to Search: ");
    scanf("%d", &id);

    // Search through all books
    for(i = 0; i < count; i++)
    {
        // Check if ID matches
        if(library[i].bookID == id)
        {
            printf("\nBook Found!\n");
            printf("Book ID: %d\n", library[i].bookID);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Quantity: %d\n", library[i].quantity);

            found = 1; // Mark as found
            break;     // Stop searching
        }
    }

    // If not found
    if(found == 0)
    {
        printf("\nBook Not Found!\n");
    }
}

// Function to issue a book
void issueBook()
{
    int id; // Book ID
    int i;  // Loop variable

    // Ask user for Book ID
    printf("Enter Book ID: ");
    scanf("%d", &id);

    // Search book
    for(i = 0; i < count; i++)
    {
        // Check matching ID
        if(library[i].bookID == id)
        {
            // Check availability
            if(library[i].quantity > 0)
            {
                // Reduce quantity by one
                library[i].quantity--;

                printf("\nBook Issued Successfully!\n");
            }
            else
            {
                printf("\nBook Out of Stock!\n");
            }

            return; // Exit function
        }
    }

    // If book not found
    printf("\nBook Not Found!\n");
}

// Main function starts here
int main()
{
    int choice; // Stores menu choice

    do
    {
        // Display menu
        printf("\n\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Exit");

        // Ask user for choice
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        // Execute selected option
        switch(choice)
        {
            case 1:
                addBook();      // Call Add Book function
                break;

            case 2:
                displayBooks(); // Call Display Books function
                break;

            case 3:
                searchBook();   // Call Search Book function
                break;

            case 4:
                issueBook();    // Call Issue Book function
                break;

            case 5:
                printf("\nThank You For Using The System!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    }
    while(choice != 5); // Continue until user chooses Exit

    return 0; // End program successfully
}
