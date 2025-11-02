package me.nils.engine.main;

import me.nils.engine.state.GameState;

import java.util.Arrays;

public class ChessEngine {

    public static void main(String[] args) {
        GameState gs = new GameState("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        gs.loadFen();
        System.out.println(Arrays.toString(gs.getPieces()));
    }

}
