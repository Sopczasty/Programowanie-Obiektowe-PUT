package base;

public class Customer {
    private String name;
    private String surname;
    private int pesel;
    private String adres;
    public Customer() {}

    public Customer(String n, String s, int pesel, String adres) {
        this.name = n;
        this.surname = s;
        this.pesel = pesel;
        this.adres = adres;
    }

    public String getName() {
        return this.name;
    }

    public String getSurname() {
        return this.surname;
    }

    public String getAdres() {
        return this.adres;
    }

    public int getPesel() {
        return this.pesel;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setAdres(String adres) {
        this.adres = adres;
    }

    public void setPesel(int pesel) {
        this.pesel = pesel;
    }

    @Override
    public boolean equals(Object c) {
        Customer cust = (Customer)c;
        return this.surname.equals(cust.surname);
    }
}