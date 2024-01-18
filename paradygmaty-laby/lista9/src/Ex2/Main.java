package Ex2;

public class Main {
    public static void main(String[] args) {
        Elf slave1 = new Elf(BaubleType.ICYCLE,1);
        Elf slave2 = new Elf(BaubleType.MUSHROOM,1);
        Elf slave3 = new Elf(BaubleType.SMALL_SPHERE,2);
        Elf master = new Elf(BaubleType.BIG_SPHERE, 3);

        slave3.setNeighbour(slave2);
        master.setNeighbour(slave3);

        Bauble[] baubles = {
                new Bauble(BaubleType.ICYCLE, "niebieski", "paski"),
                new Bauble(BaubleType.MUSHROOM, "czerwony", "kropki"),
                new Bauble(BaubleType.SMALL_SPHERE,"zielony", "wstążki"),
                new Bauble(BaubleType.SMALL_SPHERE, "pomarańczowy", "brak"),
                new Bauble(BaubleType.SMALL_SPHERE, "zielony", "kratka"),
                new Bauble(BaubleType.BIG_SPHERE, "fioletowy", "snowflake"),
                new Bauble(BaubleType.BIG_SPHERE, "żółty", "brokat"),
                new Bauble(BaubleType.ICYCLE, "niebieski", "brak")
        };

        for(Bauble bauble : baubles) {
            System.out.println("pakowana bedzie bombka: " + bauble);
            master.boxBauble(bauble);
        }

    }
}
