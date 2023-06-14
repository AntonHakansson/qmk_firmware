#undef PERMISSIVE_HOLD
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT

#define COMBO_VARIABLE_LEN   // compute COMBO_LEN from combos.def
#define COMBO_TERM 25        // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger
