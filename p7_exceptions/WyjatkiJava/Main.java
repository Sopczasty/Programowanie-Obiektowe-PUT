import java.util.ArrayList;

import base.*;

public class Main {
    public static void main(String[] args) throws AccountNotFoundException {
        Customer customer = new Customer("Artur", "Arturowski", 97864542, "Ulica xyz");
        Customer customer2 = new Customer("Arkadiusz", "Arkowski", 645456, "Ulica phi");
        Account account = new Account(123, customer, 1234, "loginn");
        Bank bank = new Bank();
        bank.addAccount(account);
        try {
            ArrayList<Account> accounts = bank.findAllCustomerAccounts(customer2);
            for(Account a : accounts) {
                System.out.println(a.getCustomer().getName());
            }
        } catch (AccountNotFoundException e) {
            e.printStackTrace();
            e.fillInStackTrace();
            throw e;
        }
        
        try {
            bank.findByName("example");
        } catch (CustomerNotFoundException e) {
            System.out.println("Name: " + e.getName());
            //e.printStackTrace();
        }

        try {
            account.login("Arturito22", 123);
        } catch (AccountLoginFailedException e) {
            System.out.println("Password: " + e.getPassword());
            System.out.println("Login: " + e.getLogin());
            //e.printStackTrace();
        }
    }
} //stosujac interfejsy mozemy uzywac jednej definicji do wielu roznych zastosowan.
