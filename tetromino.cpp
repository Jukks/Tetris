#include "tetromino.hh"

Tetromino::Tetromino(int type)
{
    // Hard-coded rotations for tetrominos
    // feel free to hide this section
    // Invalid type number results in a square
    switch (type) {
    // L shape
    case 0:
        rotations =
        {
            {{false, false, true},{true, true, true}},
            {{true, false},{true, false},{true, true}},
            {{true, true, true},{true, false, false}},
            {{true, true},{false, true},{false, true}}
        };
        break;
    // Inverse L
    case 1:
        rotations =
        {
            {{true, false, false}, {true, true, true}},
            {{true, true},{true, false}, {true, false}},
            {{true, true, true},{false, false, true}},
            {{false, true}, {false, true}, {true, true}},

        };
        break;
    // Square block
    // Incorrect type number also results in this,
    // though with a different color
    case 2:
    default:
        rotations =
        {
            {{true, true}, {true, true}},
        };
        break;
    // Capital S shape
    case 3:
        rotations =
        {
            {{false, true, true},{true, true, false}},
            {{true, false}, {true, true}, {false, true}}
        };
        break;
    // Capital Z shape
    case 4:
        rotations =
        {
            {{true, true, false}, {false, true, true}},
            {{false, true}, {true, true}, {true, false}}
        };
        break;
    // Capital T shape
    case 5:
        rotations =
        {
            {{false, true, false},{true, true, true}},
            {{true, false}, {true, true}, {true, false}},
            {{true, true, true}, {false, true, false}},
            {{false, true}, {true, true}, {false, true}}
        };
        break;
    // I shape
    case 6:
        rotations =
        {
            {{true, true, true, true}},
            {{true}, {true}, {true}, {true}}
        };
        break;
    }




}
