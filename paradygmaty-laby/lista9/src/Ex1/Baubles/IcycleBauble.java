package Ex1.Baubles;

public class IcycleBauble extends Bauble {
    public IcycleBauble(String color, String pattern) {
        super(color, pattern);
    }

    @Override
    public String toString() {
        return "Bombka sopel {" +
                "color='" + color + '\'' +
                ", pattern='" + pattern + '\'' +
                ", isBroken=" + isBroken +
                '}';
    }
}
