package Ex1.Elves;

import Ex1.Baubles.Bauble;
import Ex1.Baubles.IcycleBauble;

public class IcycleElf extends Elf{
    public IcycleElf(int boxCapacity) {
        super(boxCapacity);
    }

    @Override
    boolean baubleFits(Bauble bauble) {
        return bauble instanceof IcycleBauble;
    }
}
