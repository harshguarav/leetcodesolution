import java.util.HashMap;

class Spreadsheet {
    private int rows;
    private final int COLS = 26; // A-Z
    private HashMap<String, Integer> cells; // only store set cells

    public Spreadsheet(int rows) {
        this.rows = rows;
        this.cells = new HashMap<>();
    }

    // Set a cell value
    public void setCell(String cell, int value) {
        cells.put(cell.toUpperCase(), value);
    }

    // Reset a cell to 0
    public void resetCell(String cell) {
        cells.remove(cell.toUpperCase()); // remove from map; default is 0
    }

    // Evaluate a formula "=X+Y"
    public int getValue(String formula) {
        if (!formula.startsWith("=")) {
            throw new IllegalArgumentException("Formula must start with '='");
        }

        String expr = formula.substring(1); // remove '='
        String[] parts = expr.split("\\+"); // split X+Y
        int sum = 0;

        for (String part : parts) {
            part = part.toUpperCase().trim();
            if (isNumber(part)) {
                sum += Integer.parseInt(part);
            } else {
                sum += cells.getOrDefault(part, 0);
            }
        }

        return sum;
    }

    // Check if a string is a number
    private boolean isNumber(String str) {
        return str.matches("\\d+");
    }
}
