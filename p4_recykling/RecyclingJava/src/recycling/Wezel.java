 package recycling;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;

 public class Wezel {
     @Deprecated
     @Override
     protected void finalize() throws Throwable {
         System.out.println("Finalizowanie obiektu");
         super.finalize();
     }

     protected ArrayList<Wezel> polaczenie = new ArrayList<>();
     
     protected HashMap<Wezel, Boolean> polaczeniaH = new HashMap<>();
     protected TreeMap<Wezel, Boolean> polaczeniaT = new TreeMap<>();

     public void dodajPolaczenie(Wezel w) {
        this.polaczenie.add(w);
     }

     public void dodajPolaczenieH(Wezel w) {
         this.polaczeniaH.put(w, true);
     }

     public void dodajPoloczenieT(Wezel w) {
         this.polaczeniaT.put(w, true);
     }

     public static void main(String[] args) {
         Scanner s = new Scanner(System.in);
         for (int i = 0; i <= 1000000; i++) {
             Wezel w1 = new Wezel();
             Wezel w2 = new Wezel();
             w1.dodajPolaczenie(w2);
             w2.dodajPolaczenie(w1);
         }
         s.nextLine();
         s.close();

     }
 }