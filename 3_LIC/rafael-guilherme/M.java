public class M {
    private static final int m = 0x10;
    public static boolean isOn() {
        return HAL.isBit(m);
    }
}