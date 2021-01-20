package java;

import java.util.ArrayList;

public class Hive {
    public Hive(int startBees){
        if(startBees > 0)
            this.amountOfBees = startBees;
        else
            System.out.println("There cannot be negative bees!");
    }

    public void setName(String name) {
        if(Character.isLetter(name.charAt(0)) && Character.isUpperCase(name.charAt(0))) {
            this.name = name;
        }
        else
            System.out.println("Name needs to start with upper character");
    }

    public void changeStolenPercent(int newPercent) {
        this.percentOfHoneyStolen = newPercent;
    }

    public void setPosition(int x, int y) {
        this.coords[0] = x;
        this.coords[0] = y;
    }

    public void honeyMade(float amount) {
        this.Honey.add(amount);
        this.changeHappinessLevel();

    }

    public int getHappiness() {
        return this.happinessLevel;
    }

    public float getRecentlyMadeHoney() {
        return this.Honey.get(this.Honey.size() - 1);
    }

    public int getAmountOfBees() {
        return this.amountOfBees;
    }

    public int[] getHiveCoords() {
        return this.coords;
    }

    public String getName() {
        return this.name;
    }

    public float getAverageHoney() {
        if(this.Honey.size() > 0) {
            float sum = 0;
            for(float i : this.Honey)
                sum += i;
            return sum / this.Honey.size(); 
        }
        else
            return 0;
    }

    boolean changeBeeAmount(int change) {
        if(this.amountOfBees + change > 0 && change < 100 && change > -100) {
                this.amountOfBees += change;
                return true;
            }
        System.out.println("Error, zla ilosc podana");
        return false;
    }

    protected int amountOfBees; 
    protected int[] coords = new int[2];
    protected String name = "";
    protected ArrayList<Float> Honey = new ArrayList<Float>();
    protected int percentOfHoneyStolen = 50;
    protected int happinessLevel = 50;

    protected void changeHappinessLevel() {
        int change = this.defineChangeOfHappiness();
        if(this.happinessLevel + change > 100)
            this.happinessLevel = 100;
        else if (this.happinessLevel + change < 0)
            this.happinessLevel = 0;
        else this.happinessLevel += change;
    }

    protected int defineChangeOfHappiness() {
        if(this.percentOfHoneyStolen < 50) return (50 - this.percentOfHoneyStolen)/2;
        if(this.percentOfHoneyStolen > 50) return (50 - this.percentOfHoneyStolen)/2;
        return 0;
    }
}