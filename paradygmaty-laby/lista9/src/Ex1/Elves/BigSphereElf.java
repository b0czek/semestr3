package Ex1.Elves;

import Ex1.Baubles.Bauble;
import Ex1.Baubles.BigSphereBauble;


public class BigSphereElf extends Elf{

    public BigSphereElf(int boxCapacity) {
        super(boxCapacity);
    }

    @Override
    boolean baubleFits(Bauble bauble) {
        return bauble instanceof BigSphereBauble;
    }
}
