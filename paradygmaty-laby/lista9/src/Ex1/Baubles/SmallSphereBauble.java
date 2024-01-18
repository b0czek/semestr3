package Ex1.Baubles;

public class SmallSphereBauble extends Bauble {
    public SmallSphereBauble(String color, String pattern) {
        super(color, pattern);
    }

    @Override
    public String toString() {
        return "Bombka mała kula {" +
                "color='" + color + '\'' +
                ", pattern='" + pattern + '\'' +
                ", isBroken=" + isBroken +
                '}';
    }
}
