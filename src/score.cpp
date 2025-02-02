#include "score.h"

Score::Score(uint *_difficulty_level) : difficulty_level(_difficulty_level) {}

void Score::blockDropped(uint lines_broken, bool if_hard_drop)
{
    float score_multiplier = (1. + ((*difficulty_level) * difficulty_multiplier));

    if(if_hard_drop) score += hard_drop_points * score_multiplier;
    
    switch (lines_broken)
    {
    case 0:
        tetris_combo = combo = 0;
        break;
    
    case 4:
        score += (lines_points[lines_broken-1] + (tetris_combo_points*tetris_combo)) * score_multiplier;
        tetris_combo++;
        break;

    default:
        tetris_combo = 0;
        score += lines_points[lines_broken-1] * score_multiplier;
        combo++;
        break;
    }
}

uint Score::returnScore() const
{
    return score;
}
