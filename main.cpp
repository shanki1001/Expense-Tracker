#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<limits>


using namespace std;

struct Expense{
    string date;
    double amount;
    string category;
    string description;
};

vector<Expense> ExpenseList;

void AddExpense(){

    Expense NewExpense;

    cout<<"Enter date in format(DD-MM-YYYY):";
    getline(cin, NewExpense.date);

    do{
    cout<<"Enter amount of the expense:";
    cin>>NewExpense.amount;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(NewExpense.amount<=0) cout<<"Enter a positive amount of the Expense!!\n";
    }while(NewExpense.amount<=0);

    do{
    cout<<"Enter Category of the expense(Food/Travel/Shopping/Miscellaneous):";
    getline(cin,NewExpense.category);
    for(int i=0 ; i<NewExpense.category.size(); i++)
        NewExpense.category[i] = tolower(NewExpense.category[i]);
    }while( NewExpense.category!="food" &&
            NewExpense.category!="travel" &&
            NewExpense.category!="shopping" &&
            NewExpense.category!="miscellaneous"
           );

    cout<<"Enter Description (Optional):";
    getline(cin,NewExpense.description);

    ExpenseList.push_back(NewExpense);

}

void AllExpenses(){
    if(ExpenseList.empty()){
        cout<<"No expeses in Record!!!!\n";
        return;
    }
    cout<<"\n     Expenses Record:-\n";
    for(int i=0 ; i<ExpenseList.size() ; i++){
        cout<<" "<<i+1<<".\n";
        cout<<" Date        :-"<<ExpenseList[i].date<<"\n";
        cout<<" Amount      :-"<<ExpenseList[i].amount<<"\n";
        cout<<" Category    :-"<<ExpenseList[i].category<<"\n";
        cout<<" Description :-"<<ExpenseList[i].description<<"\n";
    }
    cout<<"\n\n";
}

string trim(string str){

    size_t first = str.find_first_not_of(" \t\n\r");
    if(first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first,(last-first+1));
}

void FilterByCategory(){

    if(ExpenseList.empty()){
        cout<<"No Expenses in the List!!!\n";
        return;
    }
    string FilterCategory;

    do{
        cout<<"Enter a category to filter the Records:";
        getline(cin,FilterCategory);
        FilterCategory = trim(FilterCategory);
        for(int i=0 ; i<FilterCategory.size();i++) FilterCategory[i]=tolower(FilterCategory[i]);
        if( FilterCategory!="food" &&
            FilterCategory!="travel"&&
            FilterCategory!="shopping"&&
            FilterCategory!="miscellaneous")
        cout<<"Enter Valid Category!!!\n";
    }while(FilterCategory!="food" &&
            FilterCategory!="travel"&&
            FilterCategory!="shopping"&&
            FilterCategory!="miscellaneous"
           );

    cout<<"     Filtered List By Category:-"<<FilterCategory<<"\n";
    int indexRecord=1;
    for(int i=0 ; i<ExpenseList.size(); i++){
        if(ExpenseList[i].category == FilterCategory){
            cout<<indexRecord<<".\n";
            cout<<" Date        :-"<<ExpenseList[i].date<<"\n";
            cout<<" Amount      :-"<<ExpenseList[i].amount<<"\n";
            cout<<" Category    :-"<<ExpenseList[i].category<<"\n";
            cout<<" Description :-"<<ExpenseList[i].description<<"\n";
            indexRecord++;
        }
    }
    if(indexRecord==1) cout<<"No Expenses by such category in the List Right now!!!\n";
}

void DeleteExpense(){
    if(ExpenseList.empty()) {
        cout<<"No Expenses in Expense List\n";
        return;
    }
    AllExpenses();
    int indexToDelete;
    cout<<"Enter the index of the Expense to delete:";
    cin>>indexToDelete;
    if(indexToDelete<1 || indexToDelete>ExpenseList.size()){
        cout<<"Index to delete is out of bound!!!";
        return;
    }
    ExpenseList.erase(ExpenseList.begin()+indexToDelete-1);
    cout<<"Expense Deleted successfully!!!!\n";

}
void SaveExpenses(){
    ofstream file("expenses.csv");
    if(!file.is_open()){
        cout<<"Error opening in the file!!\n";
        return;
    }
    for(int i=0 ; i<ExpenseList.size(); i++){
        file<<ExpenseList[i].date<<",";
        file<<ExpenseList[i].amount<<",";
        file<<ExpenseList[i].category<<",\"";
        file<<ExpenseList[i].description<<"\""<<"\n";
    }
    file.close();
    cout<<"Expenses saved successfully!!!\n";
}
void LoadExpenses(){
    ifstream file("expenses.csv");
    if(!file.is_open()) {
        cout<<"Error opening in the file!!\n";
        return;
    }
    ExpenseList.clear();
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string date, amountStr,category, description;
        getline(ss,date,',');
        getline(ss,amountStr,',');
        getline(ss,category,',');
        getline(ss,description);

        Expense e;
        e.date = date;
        e.amount = stod(amountStr);
        e.category= category;

        if(!description.empty() && description.front()=='"' && description.back()=='"'){
            description = description.substr(1,description.length()-2);
        }
        e.description = description;

        ExpenseList.push_back(e);

    }
    file.close();
    cout<<"Expenses loaded successfully.\n";
}


int main(){
    LoadExpenses();
    int choice;

    do{
        cout<<"                ------Menu------\n";
        cout<<"         1.Add a expense\n";
        cout<<"         2.Show all Expenses\n";
        cout<<"         3.Filter the expenses by category\n";
        cout<<"         4.Delete an Expense\n";
        cout<<"         5.Save Expenses and exit\n";
        cout<<"         Enter a choice:-";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1: AddExpense(); break;
            case 2: AllExpenses(); break;
            case 3: FilterByCategory(); break;
            case 4: DeleteExpense();    break;
            case 5: SaveExpenses(); break;
            default: cout<<"Invalid choice\n";break;
        }
    }while(choice!=5);



    return 0;
}
