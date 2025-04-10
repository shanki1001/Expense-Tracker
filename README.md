💰 Expense Tracker CLI
A simple and efficient command-line Expense Tracker built using C++.
Track your daily expenses by category, filter them, and save/load from CSV files.

💡 Features
➕ Add a new expense (Date, Amount, Category, Description)

📋 View all recorded expenses

🔍 Filter expenses by category

❌ Delete an expense by index

💾 Load expenses from a CSV file on startup

📂 Save expenses to a CSV file on exit

🧪 Sample Run
pgsql
Copy
Edit
            ------Menu------
        1. Add an expense
        2. Show all expenses
        3. Filter expenses by category
        4. Delete an expense
        5. Save expenses and exit
🛠️ How It Works
Uses vector to store expenses in memory

Each expense includes: Date, Amount, Category, Description

Stores data in expenses.csv using a simple comma-separated format

Uses fstream and sstream for file operations

Supports proper parsing of fields including multi-word descriptions (e.g. "pizza,bread")

Entire logic written using standard C++ (no external libraries)

📁 File Structure
less
Copy
Edit
ExpenseTracker.cpp     // Main application code
expenses.csv           // Auto-generated CSV data file
README.md              // This file
🚀 How to Run

Open the code in any C++ IDE or text editor (e.g., VSCode, CodeBlocks, Dev C++)

Compile and run ExpenseTracker.cpp

Interact using the provided menu options

Upon exit, your data is saved in expenses.csv

📝 CSV Format Example
arduino
Copy
Edit
09-04-2025,100,food,"pizza,bread"
09-04-2025,60,food,kachauri
The description is wrapped in quotes to support commas within it.

👨‍💻 Author
Shashank Rai
GitHub: @shanki1001
