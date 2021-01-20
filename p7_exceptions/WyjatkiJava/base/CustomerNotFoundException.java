package base;

public class CustomerNotFoundException extends Exception {
    static final long serialVersionUID = 1L;
    String name;

    CustomerNotFoundException() {
        super();
    }

    CustomerNotFoundException(String errorMsg, String name) {
        super(errorMsg);
        this.name = name; 
    }

    public String getName() {
        return name;
    }
}
