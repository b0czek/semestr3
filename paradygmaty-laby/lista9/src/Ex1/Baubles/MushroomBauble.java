package Ex1.Baubles;

public class MushroomBauble extends Bauble {
    public MushroomBauble(String color, String pattern) {
        super(color, pattern);
    }

    @Override
    public String toString() {
        return "Bombka grzyb {" +
                "color='" + color + '\'' +
                ", pattern='" + pattern + '\'' +
                ", isBroken=" + isBroken +
                '}';
    }
}
