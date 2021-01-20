package base;

public class AccountLoginFailedException extends Exception {
    static final long serialVersionUID = 1L;
    private int password;
    private String login;
    
    AccountLoginFailedException() {
        this.password = 0;
        this.login = null;
    }
    AccountLoginFailedException(String errorMsg, String s, int passwd) {
        super(errorMsg);
        this.login = s;
        this.password = passwd;
    }
    public int getPassword() {
        return this.password;
    }

    public String getLogin() {
        return this.login;
    }
}
