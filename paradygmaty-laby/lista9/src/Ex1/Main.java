package Ex1;

import Ex1.Baubles.*;
import Ex1.Elves.*;

public class Main {
    public static void main(String[] args) {
        Elf slave1 = new MushroomBaubleElf(1);
        Elf slave2 = new IcycleElf(1);
        Elf slave3 = new SmallSphereElf(2);
        Elf master = new SphereElf(4,2);

        slave3.setNeighbour(slave2);
        master.setNeighbour(slave3);

        Bauble[] baubles = {
            new IcycleBauble("niebieski", "paski"),
            new MushroomBauble("czerwony", "kropki"),
            new SmallSphereBauble("zielony", "wstążki"),
            new SmallSphereBauble("pomarańczowy", "brak"),
            new SmallSphereBauble("zolty", "brak"),
            new SmallSphereBauble("czerwony", "brak"),
            new SmallSphereBauble("biały", "brak"),
            new BigSphereBauble("zielony", "kratka"),
            new BigSphereBauble("fioletowy", "snowflake"),
            new BigSphereBauble("żółty", "brokat"),
            new IcycleBauble("niebieski", "brak")
        };

        for(Bauble bauble : baubles) {
            System.out.println("pakowana bedzie bombka: " + bauble);
            master.boxBauble(bauble);
        }

    }
}