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
        short[] pieces = new short[34]; // row-major order btw.
        parseMetadata(tokens, pieces);
        parsePieces(tokens[0], pieces);
        states.add(pieces);
    }

    /**
     * Helper method that parses FEN metadata, like: active color, castling, en passant and half move clock.
     * @param tokens Array of FEN tokens.
     * @param pieces Array of pieces.
     */
    // 0: active color, 1-4: castling availability, 5-11: en passant square index, 12-17: half move clock
    private void parseMetadata(String[] tokens, short[] pieces) {
        int clock = 0, index = 0, castling = 0, color = 1;

        // half move counter
        clock = Integer.parseInt(tokens[4]) << 6;

        // en passant target square
        if (!tokens[3].equals("-")) {
            // 0 as en passant index is fine since it is not possible, hence a good value for no en passant
            char[] pos = tokens[3].toCharArray();
            index = pos[0] - 97 + (pos[1] - '0') * 8;
        }

        // castling

        // color
        int metadata = clock << 6;
        metadata |= index << 6;
        metadata |= castling << 4;
        metadata |= color;
        pieces[0] = (short)(metadata << 16);
        pieces[1] = (short)(metadata & 0xFFFF);
    }

    /**
     * Helper method that parses FEN pieces.
     * @param token The FEN token that represents the pieces.
     * @param pieces Array of pieces.
     */
    private void parsePieces(String token, short[] pieces) {
        int i = 2, j = 0;
        for (char c : token.toCharArray()) {
            if (Character.isDigit(c)) {
                j += c - '0';
                continue;
            } else if (c == '/')
                continue;

            // 0-5: index, 6: color, 7-9: piece type
            short piece = (short)(pieceMap[c] << 4 | j);
            j++;
            pieces[i++] = piece;
        }
    }

    /**
     * Getter for game states.
     * @return An array list that contains game states.
     */
    public ArrayList<short[]> getStates() {
        return states;
    }

}
