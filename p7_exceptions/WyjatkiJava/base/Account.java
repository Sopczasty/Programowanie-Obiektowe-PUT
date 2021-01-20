package base;

public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account() {
        this.accountNumber = 0;
        this.balance = 0;
        this.login = null;
        this.owner = null;
        this.password = 0;
    }
    
    public Account(int n, Customer c, int p, String l) {
        this.accountNumber = n;
        this.owner = c;
        this.password = p;
        this.login = l;
    }

    public void login(String l, int passwd) 
        throws AccountLoginFailedException {
            if(this.login.equals(l) && this.password == passwd)
                System.out.println("Login Successful");
            else throw new AccountLoginFailedException("Nie poprawne dane logowania", l, passwd);
    }

    public Customer getCustomer() {
        return this.owner;
    }

    public int getNumber() {
        return this.accountNumber;
    }

    public double getBalance() {
        return this.balance;
    }

    public int getPassword() {
        return this.password;
    }

    public String getLogin() {
        return this.login;
    }

    public double withdraw(double amount) {
        if(amount > this.balance) { 
            this.balance -= amount;
            return amount;
        } else return 0;
    }
}
