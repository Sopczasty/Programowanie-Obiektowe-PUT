package java;

public class ul {
    public static void main(String[] args){
        //Setting values
        Hive hive = new Hive(100);
        hive.setName("Pasieka Zachodnia");
        hive.setPosition(-4, 15);
        hive.honeyMade(153.54f);
        hive.changeStolenPercent(30);

        //Reads:
        System.out.printf("1. Liczba pszczol: %d\n", hive.getAmountOfBees());
        System.out.printf("1. Srednia ilosc wyprodukowanego miodu: %f\n", hive.getAverageHoney());
        int[] coords = hive.getHiveCoords();
        System.out.printf("1. Polozenie Ula: x: %d; y: %d\n", coords[0], coords[1]);
        System.out.printf("1. Nazwa pasieki: %s\n", hive.getName());
        System.out.printf("1. Miod wyprodukowany w tym roku: %f\n", hive.getRecentlyMadeHoney());
        System.out.printf("1. Poziom szczescia: %d\n", hive.getHappiness());
        
        //Methods:
        hive.changeBeeAmount(-20);
        hive.honeyMade(32.3f);
        System.out.printf("2. Poziom szczescia: %d\n", hive.getHappiness());
        hive. changeStolenPercent(100);

        hive.honeyMade(13.7f);
        System.out.printf("2. Liczba pszczol: %d\n", hive.getAmountOfBees());
        System.out.printf("2. Srednia ilosc wyprodukowanego miodu: %f\n", hive.getAverageHoney());
        System.out.printf("2. Miod wyprodukowany w tym roku: %f", hive.getRecentlyMadeHoney());
        System.out.printf("3. Poziom Szczescia: %d", hive.getHappiness());
    }
}