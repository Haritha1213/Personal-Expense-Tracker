#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct type{
    double amount;
    string cat;
    string date;
};

class ExpenseTracker{
   
   	private:
    vector<type> expense;
    
    public:
	
    double totalSum=0;
	void addExpenses(double amount, string cat, string date){
	    type newExp = {amount, cat, date};
		expense.push_back(newExp);
		totalSum += amount;
		cout<<"New expense added successfully!"<<endl;
        
}

    void removeExpense(int index){
        
	if(index>0 && index<=expense.size()){
    double del=expense[index-1].amount;
	expense.erase(expense.begin() + (index-1));
	totalSum -= del; 
	cout<<"Expense removed successfully"<<endl;
    }
    else{
    	cout<<"Doesn't exist!!"<<endl;
	}
}
 
	
	void display(){
	    cout<<"\tS.No\t\tCategory\t\tAmount\t\tDate"<<endl;
		for(int i=0;i<expense.size();i++){
		    cout<<"\t"<<i+1<<"\t\t"<<expense[i].cat<<"\t\t"<<expense[i].amount<<"\t\t"<<expense[i].date<<endl;
        }
	}
	
		
};

	int main(){
		int choice=0,index=0;
		double sum;
		double amount=0;
		string date, category;		
		ExpenseTracker tracker;
		
		while(1){
		cout<<"***************************WELCOME TO PERSONAL EXPENSE TRACKER********************************"<<endl;
		cout<<" 1. Add Expense\n 2. Veiw Spendings\n 3. Remove Data\n 4. Total Expenditure\n 5. Exit\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice){
			
			case 1:
                cout<<"Type of spending: ";
				cin>>category;
				cout<<"Enter amount(Rs.): ";
				cin>>amount;
				cout<<"Enter date: ";
				cin>>date;
				tracker.addExpenses(amount, category,date);
				break;
				
			case 2:
			   tracker.display();
				break;
				
			case 3:
                cout<<"Enter the index of the expense to be removed: ";
			    cin>>index;
			    tracker.removeExpense(index);
				break;
				
			case 4:
			    sum = tracker.totalSum;
                cout<<"Total Expediture is: "<<sum<<endl;
				break;
				
			case 5:
				return 0;
				
				default:
				cout<<"Invalid Choice"<<endl;	

		}
		
	}
		return 0;
	}
	
