package me.nils.engine.main;

import me.nils.engine.state.StateHandler;

import java.util.Arrays;

public class ChessEngine {

    public static void main(String[] args) {
        StateHandler gs = new StateHandler();
        gs.loadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 0");
    }

}
