package base;

interface SearchCustomers {
    Customer findByName(String name) 
        throws CustomerNotFoundException;
}
