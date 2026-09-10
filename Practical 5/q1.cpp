#include <iostream>
using namespace std;

// Maximum number of library items
const int MAX_ITEMS = 100;


class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:

    // Constructor
    LibraryItem(string t = "", string a = "", string d = "")
    {
        title = t;
        author = a;
        dueDate = d;
    }

    // Virtual Destructor
    virtual ~LibraryItem() {}

    // Getters
    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    // Setters
    void setTitle(string newTitle)
    {
        if (newTitle.empty())
            throw invalid_argument("Title cannot be empty.");

        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        if (newAuthor.empty())
            throw invalid_argument("Author cannot be empty.");

        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    // Pure virtual functions
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};


class Book : public LibraryItem
{
private:
    string isbn;
    int quantity;
    bool checkedOut;

public:

    Book(string title, string author, string dueDate,
         string isbn, int quantity)
        : LibraryItem(title, author, dueDate)
    {
        // Validate quantity
        if (quantity < 0)
            throw invalid_argument("Quantity cannot be negative.");

        // Validate ISBN
        if (isbn.length() != 13)
            throw invalid_argument("ISBN must contain exactly 13 digits.");

        for (char c : isbn)
        {
            if (!isdigit(c))
                throw invalid_argument("ISBN must contain only digits.");
        }

        this->isbn = isbn;
        this->quantity = quantity;
        checkedOut = false;
    }

    // Checkout book
    void checkOut() override
    {
        if (quantity <= 0)
        {
            cout << "Book is not available.\n";
            return;
        }

        quantity--;
        checkedOut = true;

        cout << "Book checked out successfully.\n";
    }

    // Return book
    void returnItem() override
    {
        quantity++;
        checkedOut = false;

        cout << "Book returned successfully.\n";
    }

    // Display book details
    void displayDetails() const override
    {
        cout << "\n----- BOOK DETAILS -----\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Author     : " << getAuthor() << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "ISBN       : " << isbn << endl;
        cout << "Available  : " << quantity << endl;
        cout << "Status     : "
             << (checkedOut ? "Checked Out" : "Available") << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;
    bool checkedOut;

public:

    DVD(string title, string author, string dueDate, int duration)
        : LibraryItem(title, author, dueDate)
    {
        if (duration <= 0)
            throw invalid_argument("Duration must be greater than 0.");

        this->duration = duration;
        checkedOut = false;
    }

    // Checkout DVD
    void checkOut() override
    {
        if (checkedOut)
        {
            cout << "DVD is already checked out.\n";
            return;
        }

        checkedOut = true;

        cout << "DVD checked out successfully.\n";
    }

    // Return DVD
    void returnItem() override
    {
        if (!checkedOut)
        {
            cout << "DVD is already available.\n";
            return;
        }

        checkedOut = false;

        cout << "DVD returned successfully.\n";
    }

    // Display DVD details
    void displayDetails() const override
    {
        cout << "\n----- DVD DETAILS -----\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Director   : " << getAuthor() << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Duration   : " << duration << " minutes" << endl;
        cout << "Status     : "
             << (checkedOut ? "Checked Out" : "Available") << endl;
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;
    bool checkedOut;

public:

    Magazine(string title, string author, string dueDate,
             int issueNumber)
        : LibraryItem(title, author, dueDate)
    {
        if (issueNumber <= 0)
            throw invalid_argument("Issue number must be greater than 0.");

        this->issueNumber = issueNumber;
        checkedOut = false;
    }

    // Checkout magazine
    void checkOut() override
    {
        if (checkedOut)
        {
            cout << "Magazine is already checked out.\n";
            return;
        }

        checkedOut = true;

        cout << "Magazine checked out successfully.\n";
    }

    // Return magazine
    void returnItem() override
    {
        if (!checkedOut)
        {
            cout << "Magazine is already available.\n";
            return;
        }

        checkedOut = false;

        cout << "Magazine returned successfully.\n";
    }

    // Display magazine details
    void displayDetails() const override
    {
        cout << "\n----- MAGAZINE DETAILS -----\n";
        cout << "Title       : " << getTitle() << endl;
        cout << "Publisher   : " << getAuthor() << endl;
        cout << "Due Date    : " << getDueDate() << endl;
        cout << "Issue No.   : " << issueNumber << endl;
        cout << "Status      : "
             << (checkedOut ? "Checked Out" : "Available") << endl;
    }
};

class Library
{
private:
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount;

public:

    // Constructor
    Library()
    {
        itemCount = 0;

        for (int i = 0; i < MAX_ITEMS; i++)
        {
            libraryItems[i] = nullptr;
        }
    }

    // Destructor
    ~Library()
    {
        for (int i = 0; i < itemCount; i++)
        {
            delete libraryItems[i];
        }
    }

    // Add item
    void addItem(LibraryItem* item)
    {
        if (itemCount >= MAX_ITEMS)
        {
            delete item;
            throw runtime_error("Library is full.");
        }

        libraryItems[itemCount] = item;
        itemCount++;

        cout << "\nItem added successfully.\n";
    }

    // Display all items
    void displayAllItems()
    {
        if (itemCount == 0)
        {
            cout << "\nNo items in the library.\n";
            return;
        }

        cout << "\n====================================\n";
        cout << "       ALL LIBRARY ITEMS\n";
        cout << "====================================\n";

        for (int i = 0; i < itemCount; i++)
        {
            cout << "\nItem Number: " << i + 1;
            libraryItems[i]->displayDetails();
        }
    }

    // Search item
    int searchItem(string title)
    {
        for (int i = 0; i < itemCount; i++)
        {
            if (libraryItems[i]->getTitle() == title)
            {
                return i;
            }
        }

        return -1;
    }

    // Search and display
    void search()
    {
        string title;

        cout << "\nEnter title to search: ";
        cin.ignore();
        getline(cin, title);

        int index = searchItem(title);

        if (index == -1)
        {
            cout << "\nItem not found.\n";
        }
        else
        {
            cout << "\nItem found!\n";
            libraryItems[index]->displayDetails();
        }
    }

    // Checkout item
    void checkoutItem()
    {
        string title;

        cout << "\nEnter title to checkout: ";
        cin.ignore();
        getline(cin, title);

        int index = searchItem(title);

        if (index == -1)
        {
            cout << "\nItem not found.\n";
            return;
        }

        // Polymorphism
        libraryItems[index]->checkOut();
    }

    // Return item
    void returnItem()
    {
        string title;

        cout << "\nEnter title to return: ";
        cin.ignore();
        getline(cin, title);

        int index = searchItem(title);

        if (index == -1)
        {
            cout << "\nItem not found.\n";
            return;
        }

        // Polymorphism
        libraryItems[index]->returnItem();
    }
};

int main()
{
    Library library;

    int choice;

    do
    {
        cout << "\n\n========================================\n";
        cout << "       LIBRARY MANAGEMENT SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Search Item\n";
        cout << "6. Check Out Item\n";
        cout << "7. Return Item\n";
        cout << "8. Exit\n";

        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try
        {

            if (choice == 1)
            {
                string title, author, dueDate, isbn;
                int quantity;

                cin.ignore();

                cout << "\nEnter Book Title: ";
                getline(cin, title);

                cout << "Enter Author Name: ";
                getline(cin, author);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter ISBN (13 digits): ";
                getline(cin, isbn);

                cout << "Enter Quantity: ";
                cin >> quantity;

                Book* book = new Book(
                    title,
                    author,
                    dueDate,
                    isbn,
                    quantity
                );

                library.addItem(book);
            }

            else if (choice == 2)
            {
                string title, director, dueDate;
                int duration;

                cin.ignore();

                cout << "\nEnter DVD Title: ";
                getline(cin, title);

                cout << "Enter Director Name: ";
                getline(cin, director);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Duration (minutes): ";
                cin >> duration;

                DVD* dvd = new DVD(
                    title,
                    director,
                    dueDate,
                    duration
                );

                library.addItem(dvd);
            }

            else if (choice == 3)
            {
                string title, publisher, dueDate;
                int issueNumber;

                cin.ignore();

                cout << "\nEnter Magazine Title: ";
                getline(cin, title);

                cout << "Enter Publisher Name: ";
                getline(cin, publisher);

                cout << "Enter Due Date: ";
                getline(cin, dueDate);

                cout << "Enter Issue Number: ";
                cin >> issueNumber;

                Magazine* magazine = new Magazine(
                    title,
                    publisher,
                    dueDate,
                    issueNumber
                );

                library.addItem(magazine);
            }

            else if (choice == 4)
            {
                library.displayAllItems();
            }

            else if (choice == 5)
            {
                library.search();
            }

            else if (choice == 6)
            {
                library.checkoutItem();
            }

            else if (choice == 7)
            {
                library.returnItem();
            }

            else if (choice == 8)
            {
                cout << "\nThank you for using Library Management System!\n";
            }

            else
            {
                cout << "\nInvalid choice. Please try again.\n";
            }
        }

        catch (const exception& e)
        {
            // General exception handling
            cout << "\nException: " << e.what() << endl;
        }

    } while (choice != 8);

    return 0;
}