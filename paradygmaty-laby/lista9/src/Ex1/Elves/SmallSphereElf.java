package Ex1.Elves;

import Ex1.Baubles.Bauble;
import Ex1.Baubles.SmallSphereBauble;

public class SmallSphereElf extends Elf {
    public SmallSphereElf(int boxCapacity) {
        super(boxCapacity);
    }
    @Override
    boolean baubleFits(Bauble bauble) {
        return bauble instanceof SmallSphereBauble;
    }
}
