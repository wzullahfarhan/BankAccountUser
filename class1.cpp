#include<iostream>
using namespace std;
class Account{
    private:
    string AccountName;
    int AccountNO;
    double Balance;
    string AccountType;
    public:
    Account(){
        cout<<"User Details is Empty"<<endl;
    }
    Account(string name,int no,double bal,string type){
        AccountName=name;
        AccountNO=no;
        Balance=bal;
        AccountType=type;
    }
    void SetName(string name){
        AccountName=name;
    }
    string GetName(){
        return AccountName;
    }
    void SetNO(int no){
        AccountNO=no;
    }
    int GetNO(){
        return AccountNO;
    }
    void SetBal(double bl){
        Balance=bl;
    }
    double GetBal(){
        return Balance;
    }
    void SetTy(string ty){
        AccountType=ty;
    }
    string GetTy(){
        return AccountType;
    }
    void SetDeposite(double balance){
        Balance+=balance;
    }
    void SetWithdrow(double bala){
        Balance-=bala;
    }
    void Transfer(int receiId,double am){
        AccountNO=receiId;
        Balance+=am;
    }
    void Trans(double a){
        Balance -=a;
    }
    void Recie(double b){
        Balance +=b;
    }
    double Mainbal(){
        return Balance;
    }
    void ShowAllinfo(){
        cout<<"\t\t\t\t The Profile of User \n\n"<<endl;
        cout<<"\tAccount Name Is: "<<AccountName<<"\n"<<endl;
        cout<<"\tAccount Number Is: "<<AccountNO<<"\n"<<endl;
        cout<<"\tAccount Type: "<<AccountType<<"\n"<<endl;
        cout<<"\tAccount Balance : "<<Balance<<"\n"<<endl;
    }
    ~Account(){
        cout<<"Delete"<<endl;
    }
};
int main(){
    
    int i,a,c,d;
    cout<<"How Many User Account Want to Input: ";
    cin>>a;
    cout<<endl;
    Account b[a];
    string name,type;
    int no;
    double bal;
    int AcNo;
    for (i = 0; i < a; i++)
    {
        cout<<"Enter "<<1+i<<" Account Name: ";
        cin>>name;
        cout<<"Enter "<<1+i<<" Account Number: ";
        cin>>no;
        cout<<"Enter "<<1+i<<" Account Type: ";
        cin>>type;
        cout<<"Enter "<<1+i<<" Balance: ";
        cin>>bal;
        b[i].SetName(name);
        b[i].SetNO(no);
        b[i].SetBal(bal);
        b[i].SetTy(type);
        cout<<endl;
    }
    char ch;
    double e,f;
    cout<<"Do you want to Deposite or Withdrow For any user???\n"<<endl;
    cout<<"If   'YES' 'Press' == y "<<endl;
    cout<<"If   'NO' 'Press' == n "<<endl;
    cout<<"' -------- ' = ";
    cin>>ch;
    if(ch=='y'){
        cout<<"How many User want to Deposite Or WithDrow:: ";
        cin>>c;
        cout<<endl;
        for (int j = 0; j < c ;j++)
        {
            cout<<"\tWhich User Want to Deposite Or Withdrow: ";
            cin>>d;
            cout<<"\t\t Deposite ammount is: ";
            cin>>e;
            if(0<= b[d-1].Mainbal()){
            cout<<"\t\t Withdrow Ammount is: ";
            cin>>f;
            }
            b[d-1].SetDeposite(e);
            b[d-1].SetWithdrow(f);
            cout<<"Welcome to our Family"<<endl;
            cout<<endl;
        }
    }else if(ch=='n'){
        cout<<"Welcome to our Family"<<endl;
        cout<<endl;
    }
    else{
        cout<<"User input Error"<<endl;
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;

    char ta;
    double tra,re;
    cout<<"\t\tDo you Want yo Transfer Or Receive Money???\n"<<endl;
    cout<<"If   'YES' 'Press' == y "<<endl;
    cout<<"If   'NO' 'Press' == n "<<endl;
    cout<<"' -------- ' = ";
    cin>>ta;
        
        if (ta=='y')
        {
            cout<<"Enter Account Number: ";
            cin>>AcNo;
                
                for (int m = 0; m < a; m++)
                {
                    if (AcNo==b[m].GetNO()){
                    cout<<"Enter Transfer Amount: ";
                    cin>>tra;
                    b[m].Trans(tra);
                    cout<<"Enter Receiver Account Number: ";
                    cin>>re;
                    for (int o = 0; o < a; o++)
                    {
                        if (re==b[o].GetNO())
                        {
                            b[o].Transfer(b[o].GetNO(),tra);
                        }
                    }
                    break;
                    }
                    continue;
                        cout<<"User Input error"<<endl;
                        
                }
        }
        else if (ta=='n')
        {
            cout<<"Thanks For Using Our Bank Account"<<endl;
            
        }
        else
        {
            cout<<"----User Input Error----"<<endl;
            cout<<"--Thank you--"<<endl;
        }

    for (int k = 0; k < a; k++)
    {
        cout<<k+1<<" user Profile:::::---"<<endl;
        b[k].ShowAllinfo();
    }
    return 0;
}
