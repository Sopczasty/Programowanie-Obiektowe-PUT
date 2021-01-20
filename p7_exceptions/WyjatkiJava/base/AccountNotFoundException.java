package base;

public class AccountNotFoundException extends Exception {
    static final long serialVersionUID = 1L;
    private int number;
    private Customer customer;

    public AccountNotFoundException() {
        super();
    }

    AccountNotFoundException(String errorMsg, int number) {
        super(errorMsg);
        this.number = number;
    }

    AccountNotFoundException(String errorMsg, Customer cust) {
        super(errorMsg);
        this.customer = cust;
    }

    public Customer getCustomer() {
        return customer;
    }

    public int getNumber() {
        return number;
    }
}
