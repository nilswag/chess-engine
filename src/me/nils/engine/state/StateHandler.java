package me.nils.engine.state;

import java.util.ArrayList;

/**
 * Class that handles chess positions.
 */
public class StateHandler {

    //                                    v - color
    private static final short WHITE  = 0b0001;
    private static final short BLACK  = 0b0000;
    private static final short NONE   = 0b0000;
    private static final short ROOK   = 0b0010;
    private static final short KNIGHT = 0b0100;
    private static final short BISHOP = 0b0110;
    private static final short QUEEN  = 0b1000;
    private static final short PAWN   = 0b1010;
    private static final short KING   = 0b1100;
    //                                     ^^^ - piece type

    private final ArrayList<short[]> states;
    private final int[] pieceMap;

    /**
     * Constructor for the StateHandler class.
     */
    public StateHandler() {
        states = new ArrayList<>();

        pieceMap = new int[256];
        pieceMap['R'] = WHITE | ROOK;    pieceMap['r'] = BLACK | ROOK;
        pieceMap['N'] = WHITE | KNIGHT;  pieceMap['n'] = BLACK | KNIGHT;
        pieceMap['B'] = WHITE | BISHOP;  pieceMap['b'] = BLACK | BISHOP;
        pieceMap['Q'] = WHITE | QUEEN;   pieceMap['q'] = BLACK | QUEEN;
        pieceMap['P'] = WHITE | PAWN;    pieceMap['p'] = BLACK | PAWN;
        pieceMap['K'] = WHITE | KING;    pieceMap['k'] = BLACK | KING;
    }

    /**
     * Loads the stored FEN (Forsyth Edwards Notation) string into the game state.
     * @param fen The FEN string to be loaded.
     */
    public void loadFen(String fen) {
        /*
        0: pieces
        1: active color
        2: castling availability
        3: en passant target square
        4: half move clock
        5: full move number
         */
        String[] tokens = fen.split(" ");
        short[] pieces = new short[33];

        int i = 1, j = 0;
        for (char c : tokens[0].toCharArray()) {
            if (Character.isDigit(c)) {
                j += c - '0';
                continue;
            } else if (c == '/')
                continue;

            // 15-13: piece type, 12: color, 11-6: index, 5-0: metadata
            short piece = (short)((pieceMap[c] << 4 | j) << 6);
            j++;
            pieces[i++] = piece;
        }

        states.add(pieces);
    }

    /**
     * Getter for game states.
     * @return An array list that contains game states.
     */
    public ArrayList<short[]> getStates() {
        return states;
    }

}
