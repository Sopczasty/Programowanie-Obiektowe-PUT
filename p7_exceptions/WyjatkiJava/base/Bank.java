package base;

import java.util.ArrayList;

public class Bank implements SearchAccounts, SearchCustomers {
    ArrayList<Customer> customers = new ArrayList<Customer>();
    ArrayList<Account> accounts = new ArrayList<Account>();

    public void addCustomer(Customer cust) {
        if(!customers.contains(cust))
            customers.add(cust);
        else System.out.println("Customer is already registered in this bank!");    
    }

    public void addAccount(Account a) {
        if(!customers.contains(a.getCustomer()))
            customers.add(a.getCustomer());
        if(!accounts.contains(a))
            accounts.add(a);
        else System.out.println("Account is already registered in this bank!");
    }

    public void removeAccount(Account a) {
        if(accounts.contains(a))
            accounts.remove(a);
    }

    public void removeCustomer(Customer cust) {
        if(customers.contains(cust))
            customers.remove(cust);
    }

    public ArrayList<Account> getAccounts() {
        return accounts;
    }

    public ArrayList<Customer> getCustomers() {
        return customers;
    }
    @Override
    public Customer findByName(String name)
        throws CustomerNotFoundException {
            for(Customer c : customers) 
                if(c.getName().equals(name))
                    return c;
            throw new CustomerNotFoundException("There is no Customer registered with that name", name);
    } 

    @Override
    public Account findByNumber(int number)
        throws AccountNotFoundException {
            for(Account a : accounts) 
                if(a.getNumber() == number)
                    return a;
            throw new AccountNotFoundException("There is no Account with that number", number);
    }

    @Override
    public ArrayList<Account> findAllCustomerAccounts(Customer cust)
        throws AccountNotFoundException {
            ArrayList<Account> ret = new ArrayList<Account>();
            for(Account a : accounts)
                if(a.getCustomer().equals(cust))
                    ret.add(a);
            if(!ret.isEmpty()) return ret;
            else throw new AccountNotFoundException("There is no Account of that Customer!", cust);
    }
}

